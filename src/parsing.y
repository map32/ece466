/* simplest version of calculator */
%{
#include <stdio.h>
#include "ast.h"
#include "helpers.h"
#include "symtab.h"
#include "quad.h"
#include <string.h>
#include <signal.h>
struct astnode *root;
symtab *symtab_file;
symtab *symtab_cur;
ERROR ** errors;
FILE *f;
int errnum;
int funcsym=0;
symtab* prototype;
extern int yylex();
extern int yyerror();
extern int yylineno;
extern blockss blocks;
extern block* curBlock;

%}
%define parse.error verbose
%union{
  struct astnode *astnode;
  struct s {
    unsigned int l;
    unsigned char* c;
} s;
  struct n {
	int type;
	union {
		unsigned long long int u;
		long long int i;
		long double f;
	};
  } n;
  long long int i;
}
%start program
/* declare tokens */
%left ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ ANDEQ XOREQ OREQ LSHIFTEQ RSHIFTEQ
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%left '>' '<' LE GE
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right PREINC PREDEC UPLUS UMINUS '!' '~' DEREF ADDR SIZEOF CAST
%left '(' ')' '[' ']' '.' ARROW POSTINC POSTDEC
%nonassoc IF ELSE
%token AUTO
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INT
%token LONG
%token REGISTER
%token RETURN
%token SHORT
%token SIGNED
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token TYPENAME
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE
%token BOOL
%token COMPLEX
%token IMAGINARY
%token INC
%token DEC
%token BOGUS
%token NUM
%token NUMF
%token CH
%token STR
%token ID
%token INLINE
%token RESTRICT
%token ELLIPSIS
%token '{' '}'

%type<astnode> pexp number constant postexp unary castexp binary ternary exp aexp CAST exps stmts stmt program
%type<astnode> type_name labelstmt selects iters jmps specifier_qualifier_list declspec decl declr init initdecllist initdeclr
%type<astnode> struct_declaration struct_declaration_list struct_declarator struct_or_union_specifier compoundstmt
%type<astnode> parameter_type_list parameter_declaration pointer initlist type_specifier block_item block_item_list
%type<astnode> direct_abstract_declarator direct_declarator parameter_list enum_specifier enumerator enumerator_list
%type<astnode> funcdef external_declaration translation_unit declaration_list struct_declarator_list identifier_list abstract_declarator
%type<s> CH ID STR TYPENAME
%type<n> NUM NUMF
%type<i> uop aop type_qualifier type_qualifier_list storage_class_specifier strun
%%
program: translation_unit {root = $$;}
;

pexp: ID {$$=astIdent($1.c);
symrec* rec = findsym(symtab_cur,$1.c,NAMESPACE_OTHERS);
if (!rec) {errors[errnum] = getError(yylineno,"primary expression not found"); errnum++;}
else {$$->t = rec->type->head->next; $$->tbl = symtab_cur;}
}
 | constant
 | STR {$$=astString($1.c);}
 | '(' exp ')' {$$=$2;}
;

number: NUM {$$=astNum($1.type == 0 ? _unsigned : _integer,$1.type == 0 ? (void *)&$1.u : (void *)&$1.i);}
 | NUMF {$$=astNum(_real,(void *)&$1.f);}
;

constant: number
 | CH {int i; if ($1.l==2) i=0; else i=$1.c[0]; $$=astNum(_unsigned,(void *)&i);}
; 

postexp: pexp
 | postexp '[' exp ']' {$$ = astUnary('*',astBinary($1,$3->list->head->value,'+'));}
 | postexp '(' ')' {$$ = astCall($1,NULL);}
 | postexp '(' exp ')' {$$ = astCall($1,$3);}
 | postexp '.' ID {$$ = astBinary($1,astIdent($3.c),'.');}
 | postexp ARROW ID {$$ = astBinary(astUnary('*',$1),astIdent($3.c),'.');}
 | postexp INC %prec POSTINC {$$ = astUnary(POSTINC,$1);}
 | postexp DEC %prec POSTDEC {$$ = astUnary(POSTDEC,$1);}
 ;


unary: postexp
 | INC unary %prec PREINC {$$ = astUnary(PREINC,$2);}
 | DEC unary %prec PREDEC {$$ = astUnary(PREDEC,$2);}
 | uop castexp {$$ = astUnary($1,$2);}
 | SIZEOF unary {$$ = astUnary(SIZEOF,$2);}
 | SIZEOF '(' type_name ')' %prec PREDEC {$$ = astUnary(SIZEOF,$3);}
 ;

uop: '&' {$$ = '&';}
 | '*' {$$ = '*';}
 | '+' {$$ = '+';}
 | '-' {$$ = '-';}
 | '~' {$$ = '~';}
 | '!' {$$ = '!';}
 ;
 
castexp: unary
 | '(' type_name ')' castexp %prec CAST
 {$$ = astBinary($2,$4,CAST);}
 ;

binary: castexp
 | binary '*' binary {$$ = astBinary($1,$3,'*');}
 | binary '/' binary {$$ = astBinary($1,$3,'/');}
 | binary '%' binary {$$ = astBinary($1,$3,'%');}
 | binary '+' binary {$$ = astBinary($1,$3,'+');}
 | binary '-' binary {$$ = astBinary($1,$3,'-');}
 | binary LSHIFT binary {$$ = astBinary($1,$3,LSHIFT);}
 | binary RSHIFT binary {$$ = astBinary($1,$3,RSHIFT);}
 | binary '<' binary {$$ = astBinary($1,$3,'<');}
 | binary '>' binary {$$ = astBinary($1,$3,'>');}
 | binary LE binary {$$ = astBinary($1,$3,LE);}
 | binary GE binary {$$ = astBinary($1,$3,GE);}
 | binary NE binary {$$ = astBinary($1,$3,NE);}
 | binary EQ binary {$$ = astBinary($1,$3,EQ);}
 | binary '&' binary {$$ = astBinary($1,$3,'&');}
 | binary '^' binary {$$ = astBinary($1,$3,'^');}
 | binary '|' binary {$$ = astBinary($1,$3,'|');}
 | binary AND binary {$$ = astBinary($1,$3,AND);}
 | binary OR binary {$$ = astBinary($1,$3,OR);}
;

ternary: binary
 | binary '?' exp ':' ternary {$$ = astCond($1,$3,$5);}
;

aop: '=' {$$ = '=';}
 | PLUSEQ {$$ = PLUSEQ;}
 | MINUSEQ {$$ = MINUSEQ;}
 | TIMESEQ {$$ = TIMESEQ;}
 | DIVEQ {$$ = DIVEQ;}
 | MODEQ {$$ = MODEQ;}
 | LSHIFTEQ {$$ = LSHIFTEQ;}
 | RSHIFTEQ {$$ = RSHIFTEQ;}
 | ANDEQ {$$ = ANDEQ;}
 | XOREQ {$$ = XOREQ;}
 | OREQ {$$ = OREQ;}
;

exp: aexp {$$ = astList($1);}
 | exp ',' aexp {insertAstListTail($1,$3);}
 ;

aexp: ternary
 | unary aop aexp {$$ = astBinary($1,$3,$2);}
;

decl
	: declspec ';' {$$=astList($1);}
	| declspec initdecllist ';' {$$=$2; bindDeclSpec($1,$2); insertDecls(symtab_cur,$2,yylineno);}
	;

declspec
	: storage_class_specifier {$$=astTypeStg(_convspec($1));}
	| storage_class_specifier declspec
	{$$=$2;
	if (addTypeStg($2,$1)) {
		yyerror("more than one stg: %s %s",gettoken($1),gettoken($2->type->stg));
	}}
	| type_specifier {$$=astTypeSpec($1);}
	| type_specifier declspec {
		int i = 0;
		if (i=addTypeSpec($2,$1)) {
			fprintf(stderr,"invalid specifier combination %d, %d %s",i, $2->type->scalar,gettoken($1->token));
		}
		$$=$2;
	}
	| type_qualifier {$$=astTypeQual(_convspec($1));}
	| type_qualifier declspec {
		$$=$2;
		addTypeQual($2,$1);
	}
	| INLINE
	| INLINE declspec
	;

initdecllist
	: initdeclr {$$=astList($1);}
	| initdecllist ',' initdeclr {insertAstListTail($1,$3);}
	;

initdeclr
	: declr 
	| declr '=' init {$$=astBinary($1,$3,'=');}
	;

storage_class_specifier
	: TYPEDEF {$$=TYPEDEF;}
	| EXTERN {$$=EXTERN;}
	| STATIC {$$=STATIC;}
	| AUTO {$$=AUTO;}
	| REGISTER {$$=REGISTER;}
	;

type_specifier
	: VOID {$$ = astToken(VOID);}
	| CHAR {$$ = astToken(CHAR);}
	| SHORT {$$ = astToken(SHORT);}
	| INT {$$ = astToken(INT);}
	| LONG {$$ = astToken(LONG);}
	| FLOAT {$$ = astToken(FLOAT);}
	| DOUBLE {$$ = astToken(DOUBLE);}
	| SIGNED {$$ = astToken(SIGNED);}
	| UNSIGNED {$$ = astToken(UNSIGNED);}
    | BOOL {$$ = astToken(BOOL);}
    | COMPLEX {$$ = astToken(COMPLEX);}
	| struct_or_union_specifier
	| enum_specifier
	| TYPENAME {$$ = astIdent($1.c);}
	;

struct_or_union_specifier
	: strun ID '{' {
		$<astnode>$ = astStrun($1,astIdent($2.c),NULL);
		insertStrun(symtab_cur,$<astnode>$,yylineno);
	symtab_cur = createTable(symtab_cur,yylineno,SCOPE_OBJ);
		} struct_declaration_list '}' {$<astnode>4->obj->members=$5; symtab_cur = symtab_cur->parent; setSymComplete(symtab_cur,$<astnode>4); $$=$<astnode>4;}
	| strun '{' {
		$<astnode>$ = astStrun($1,astIdent("(anonymous)"),NULL);
		insertStrun(symtab_cur,$<astnode>$,yylineno);
	symtab_cur = createTable(symtab_cur,yylineno,SCOPE_OBJ);} struct_declaration_list '}' {$<astnode>3->obj->members=$4; symtab_cur = symtab_cur->parent; setSymComplete(symtab_cur,$<astnode>3); $<astnode>$=$<astnode>3;}
	| strun ID {$<astnode>$=astStrun($1,astIdent($2.c),NULL); insertStrun(symtab_cur,$<astnode>$,yylineno);}
	;
strun: STRUCT {$$=STRUCT;}
	| UNION {$$=UNION;}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration {mergeLists($1,$2);}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {$$=$2; bindDeclSpecStruct($1,$2); insertMembers(symtab_cur,$2,yylineno);}
	;

specifier_qualifier_list
	: type_specifier {$$ = astTypeSpec($1);}
	| type_qualifier {$$ = astTypeQual(_convspec($1));}
	| type_specifier specifier_qualifier_list {$$=$2; 
	if (addTypeSpec($2,$1)) {
		yyerror("specificer error");
	}}
	| type_qualifier specifier_qualifier_list {$$=$2;
	if (addTypeQual($2,$1)){
		yyerror("qualifier error");
	}}
	;

struct_declarator_list
	: struct_declarator  {$$ = astList($1);}
	| struct_declarator_list ',' struct_declarator {insertAstListTail($1,$3);}
	;

struct_declarator
	: declr {$$ = astMember($1,0);}
	| ':' ternary {$$ = astMember(astDecl(NULL),$2);}
	| declr ':' ternary {$$ = astMember($1,$3);}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {$$=astBinary(NULL,$3,ENUM);}
	| ENUM ID '{' enumerator_list '}' {$$=astBinary(astIdent($2.c),$4,ENUM);}
	| ENUM '{' enumerator_list ',' '}' {$$=astBinary(NULL,$3,ENUM);}
	| ENUM ID '{' enumerator_list ',' '}' {$$=astBinary(astIdent($2.c),$4,ENUM);}
	| ENUM ID {$$=astBinary(astIdent($2.c),NULL,ENUM);}
	;

enumerator_list
	: enumerator {$$ = astList($1);}
	| enumerator_list ',' enumerator {insertAstList($1,$3);}
	;

enumerator
	: ID {$$=astIdent($1.c);}
	| ID '=' ternary  {$$ = astBinary(astIdent($1.c),$3,'=');}
	;

type_qualifier
	: CONST {$$=CONST;}
	| VOLATILE {$$=VOLATILE;}
	| RESTRICT {$$=RESTRICT;}
	;

declr
	: pointer direct_declarator {mergeLists($2->decl->type,$1); $$=$2;}
	| direct_declarator
	;

direct_declarator
	: ID {$$=astDecl(astIdent($1.c));}
	| '(' declr ')' {$$=$2;}
	| direct_declarator '[' type_qualifier_list aexp ']'
	| direct_declarator '[' aexp ']' {checkdeclr($1,AST_ARRAY,yylineno); insertAstListTail($1->decl->type,astArray($3));}
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' STATIC type_qualifier_list aexp ']'
	| direct_declarator '[' STATIC aexp ']'
	| direct_declarator '[' type_qualifier_list STATIC aexp ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '(' {symtab* tab = createTable(symtab_cur,yylineno,SCOPE_BLOCK);
		(&symtab_file->row[symtab_file->rownum-1])->func = tab;
		prototype = tab; symtab_cur = prototype;} parameter_type_list ')' {checkdeclr($1,AST_FUNC,yylineno); insertAstListTail($1->decl->type,astFunc($4)); symtab_cur = symtab_cur->parent;}
	| direct_declarator '(' identifier_list ')' {checkdeclr($1,AST_FUNC,yylineno); insertAstListTail($1->decl->type,astFunc($3));}
	| direct_declarator '(' {
		symtab* tab = createTable(symtab_cur,yylineno,SCOPE_BLOCK);
		(&symtab_file->row[symtab_file->rownum-1])->func = tab;
		prototype = tab; symtab_cur = prototype;} ')' {checkdeclr($1,AST_FUNC,yylineno); insertAstListTail($1->decl->type,astFunc(NULL)); symtab_cur = symtab_cur->parent;}
	;

pointer
	: '*' {$$=astList(astPtr(0));}
	| '*' type_qualifier_list {$$=astList(astPtr($2));}
	| '*' pointer {insertAstListTail($2,astPtr(0)); $$=$2;}
	| '*' type_qualifier_list pointer {insertAstListTail($3,astPtr($2)); $$=$3;}
	;

type_qualifier_list
	: type_qualifier {$$ = _convspec($1);}
	| type_qualifier_list type_qualifier {$$ = $$ | _convspec($2);}
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS {insertAstListTail($1,astToken(ELLIPSIS));}
	;

parameter_list
	: parameter_declaration {$$=astList($1);}
	| parameter_list ',' parameter_declaration {insertAstListTail($1,$3);}
	;

parameter_declaration
	: declspec declr {$$=$2; insertAstListTail($2->decl->type,$1); insertDecl(symtab_cur,$2,yylineno);}
	| declspec abstract_declarator {$$=$2; insertAstListTail($2->decl->type,$1);}
	| declspec {$$=astList($1);}
	;

identifier_list
	: ID {$$=astList(astIdent($1.c));}
	| identifier_list ',' ID {insertAstListTail($1,astIdent($3.c));}
	;

type_name
	: specifier_qualifier_list {$$=astAbsDecl($1);}
	| specifier_qualifier_list abstract_declarator {$$=$2; insertAstListTail($2->decl->type,$1);}
	;

abstract_declarator
	: pointer {$$=astAbsDeclfromList($1);}
	| direct_abstract_declarator
	| pointer direct_abstract_declarator {mergeLists($2->decl->type,$1); $$=$2; }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {$$=$2;}
	| '[' ']' {$$=astAbsDecl(astArray(astNum(_integer,0)));}
	| '[' aexp ']' {$$=astAbsDecl(astArray($2));}
	| direct_abstract_declarator '[' ']' {checkdeclr($1,AST_ARRAY,yylineno); insertAstListTail($1,astArray(astNum(_integer,0)));}
	| direct_abstract_declarator '[' aexp ']' {checkdeclr($1,AST_ARRAY,yylineno); insertAstListTail($1,astArray($3));}
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' ')' {$$=astList(astFunc(NULL));}
	| '(' parameter_type_list ')' {$$=astList(astFunc($2));}
	| direct_abstract_declarator '(' ')' {checkdeclr($1,AST_FUNC,yylineno); insertAstListTail($1,astFunc(NULL));}
	| direct_abstract_declarator '(' parameter_type_list ')' {checkdeclr($1,AST_FUNC,yylineno); insertAstListTail($1,astFunc($3));}
	;

init
	: aexp
	| '{' initlist '}' {$$=$2;}
	| '{' initlist ',' '}' {$$=$2;}
	;

initlist
	: init {$$=astList($1);}
	| designation init
	| initlist ',' init {insertAstList($1,$3);}
	| initlist ',' designation init {insertAstList($1,$4);}
	;

designation: designator_list '='
;

designator_list
 : designator
 | designator_list designator
 ;

designator
 : '[' ternary ']'
 | '.' ID
 ;

stmt
	: labelstmt
	| compoundstmt
	| exps
	| selects
	| iters
	| jmps
	;

labelstmt
	: ID ':' stmt {$$=astBinary(astIdent($1.c),$3,':'); insertLabel(symtab_cur,$$,yylineno);}
	| CASE ternary ':' stmt {$$=astBinary($2,$4,CASE);}
	| DEFAULT ':' stmt {$$=astBinary(NULL,$3,DEFAULT);}
	;

exps: ';' {$$ = NULL;}
 | exp ';' {$$ = $1;}
;

compoundstmt
 : '{' '}' {$$=astBlockList(NULL);}
 | '{' {
	if (funcsym == 0){
		symtab* tab = createTable(symtab_cur,yylineno,SCOPE_BLOCK);
		(&symtab_file->row[symtab_file->rownum-1])->func = tab;
 		symtab_cur = tab;
	}
	else {
		symtab_cur = prototype;
		setPrototype(symtab_cur);
		funcsym = 0;
	}
	} block_item_list '}' {$$=$3; $<astnode>$->tbl = symtab_cur; symtab_cur = symtab_cur->parent;}
 ;

block_item_list
 : block_item {if ($1->nodetype != AST_LIST) $$=astBlockList($1); else $1->nodetype = AST_BLOCKLIST;}
 | block_item_list block_item {$$=$1; if ($2->nodetype != AST_LIST) insertAstListTail($1,$2); else mergeLists($1,$2);}
 ;

block_item
 : decl
 | stmt
 ;


selects
	: IF '(' exp ')' stmt {$$=astCond($3,$5,NULL); }
	| IF '(' exp ')' stmt ELSE stmt {$$=astCond($3,$5,$7);}
	| SWITCH '(' exp ')' stmt {$$=astBinary($3,$5,SWITCH);}
	;

iters
	: WHILE '(' exp ')' stmt {$$=astBinary($3,$5,WHILE);}
	| DO stmt WHILE '(' exp ')' ';' {$$=astBinary($5,$2,DO);}
	| FOR '(' exps exps ')' stmt
	{$$=astFor($3,$4,NULL,$6);}
	| FOR '(' exps exps exp ')' stmt
	{$$=astFor($3,$4,$5,$7);}
	;

jmps
	: GOTO ID ';' {$$=astUnary(GOTO,astIdent($2.c));}
	| CONTINUE ';' {$$=astUnary(CONTINUE,NULL);}
	| BREAK ';' {$$=astUnary(BREAK,NULL);}
	| RETURN ';' {$$=astUnary(RETURN,NULL);}
	| RETURN exp ';' {$$=astUnary(RETURN,$2);}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration {mergeLists($1,$2);}
	;

external_declaration
	: funcdef {$$=astList($1); setCurBlock(blocks.blocks[0]);}
	| decl
	;

funcdef
	: declspec declr declaration_list compoundstmt {$$=astFuncDef($2,$2->decl->ident,$4); insertFuncDef(symtab_cur,$$,yylineno);}
	| declspec declr {funcsym=1;
	$<astnode>$=astFuncDef($2,$2->decl->ident,0);
	bindDeclDef($1,$<astnode>$);
	
	//free($2->decl);
	insertFuncDef(symtab_cur,$<astnode>$,yylineno);
	symrec* rec = findsym(symtab_cur,$2->decl->ident->ident->name,NAMESPACE_OTHERS);
	curBlock = newBlock(rec);
	rec->key = curBlock->id;
	} compoundstmt {funcsym=0; $<astnode>3->funcdef->stmt = $4; $$ = $<astnode>3; gen_stmt($4);}
	| declr declaration_list compoundstmt {insertAstListTail($1->decl->type,astTypeSpec(astToken(INT))); $$=astFuncDef($1,$1->decl->ident,$3);}
	| declr compoundstmt {insertAstListTail($1->decl->type,astTypeSpec(astToken(INT))); $$=astFuncDef($1,$1->decl->ident,$2);}
	;

declaration_list
	: decl
	| declaration_list decl {mergeLists($1,$2);}
	;

%%
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    fclose(f);
    printf("Caught segfault at address %p\n", si->si_addr);
    exit(0);
}
main(int argc, char **argv)
{
  extern FILE *yyin, *yyout;
    if(argc < 2) {
        fprintf(stderr,"not enough arguments");
        return 1;
    }
	struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags   = SA_SIGINFO;

    sigaction(SIGSEGV, &sa, NULL);
 
    /* yyin points to the file input.txt
    and opens it in read mode*/
    yyin = fopen(argv[1], "r");
    if (argc>2 && strcmp(argv[2],"-l")==0) {
      int t=0;
      while(t=yylex()){
        printtokens(t,argv[1],yylineno,yylval);
      }
      return 0;
    }
	symtab_file = createTable(NULL,0,SCOPE_FILE);
	symtab_file->root = symtab_file;
	symtab_cur = symtab_file;
	errors = (ERROR**) malloc(sizeof(ERROR*)*1024);
	errnum=0;
	getBlocks();
    setCurBlock(newBlock(NULL));
	yyparse();
	printErrors(errors,errnum);
    printast(root,0);
	
	printBlocks();
	char buf[1024];
	sprintf(buf,"%s.s",argv[1]);
	generate(buf);
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}