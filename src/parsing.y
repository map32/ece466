/* simplest version of calculator */
%{
#include <stdio.h>
#include "ast.h"
#include "helpers.h"
#include <string.h>
struct astnode *root;
extern int yylex();
extern int yyerror(char*);
extern int yylineno;
%}
%define parse.error verbose
%union{
  struct astnode *astnode;
  struct astnode_stmts *astnode_stmt;
  struct s {
    unsigned int l;
    unsigned char* c;
} s;
  unsigned long long int i;
  long double d;
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
%type<i> NUM
%type<d> NUMF
%type<i> uop aop type_qualifier type_qualifier_list storage_class_specifier strun
%%
program: translation_unit {root = $$;}
;

pexp: ID {$$=astIdent($1.c);}
 | constant
 | STR {$$=astString($1.c);}
 | '(' exp ')' {$$=$2;}
;

number: NUM {$$=astNum(_integer,(void *)&$1);}
 | NUMF {$$=astNum(_real,(void *)&$1);}
;

constant: number
 | CH {int i; if ($1.l==2) i=0; else i=$1.c[0]; $$=astNum(_integer,(void *)&i);}
; 

postexp: pexp
 | postexp '[' exp ']' {$$ = astBinary($1,$3,'[');}
 | postexp '(' ')' {$$ = astBinary($1,NULL,'(');}
 | postexp '(' exp ')' {$$ = astBinary($1,$3,'(');}
 | postexp '.' ID {$$ = astBinary($1,astIdent($3.c),'.');}
 | postexp ARROW ID {$$ = astBinary($1,astIdent($3.c),ARROW);}
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
 | unary aop aexp {$$ = astAssign($1,$3,$2);}
;

decl
	: declspec ';'
	| declspec initdecllist ';' {$$=$2; bindDeclSpec($1,$2);}
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
		if (addTypeSpec($2,$1)) {
			yyerror("invalid specifier combination");
		}
	}
	| type_qualifier {$$=astTypeQual(_convspec($1));}
	| type_qualifier declspec {
		$$=$2;
		addTypeQual($2,_convspec($1));
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
	| declr '=' init {$$=astAssign($1,$3,'=');}
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
	: strun ID '{' struct_declaration_list '}' {$$ = astStrun($1,astIdent($2.c),$4);}
	| strun '{' struct_declaration_list '}' {$$ = astStrun($1,NULL,$3);}
	| strun ID {$$=astStrun($1,astIdent($2.c),NULL);}
	;
strun: STRUCT {$$=STRUCT;}
	| UNION {$$=UNION;}
	;

struct_declaration_list
	: struct_declaration {$$=astList($1);}
	| struct_declaration_list struct_declaration {insertAstList($1,$2);}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {$$ = astBinary($1,$2,0);}
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
	: declr {$$ = astMember($1,0)}
	| ':' ternary {$$ = astMember(NULL,$2)}
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
	| ID '=' ternary  {$$ = astAssign(astIdent($1.c),$3,'=');}
	;

type_qualifier
	: CONST {$$=CONST;}
	| VOLATILE {$$=VOLATILE;}
	| RESTRICT {$$=RESTRICT;}
	;

declr
	: pointer direct_declarator {$$=mergeLists($2->decl->type,$1);}
	| direct_declarator
	;

direct_declarator
	: ID {$$=astDecl(astIdent($1.c));}
	| '(' declr ')' {$$=$2;}
	| direct_declarator '[' type_qualifier_list aexp ']'
	| direct_declarator '[' aexp ']' {insertAstListTail($1->type,astArray($3));}
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' STATIC type_qualifier_list aexp ']'
	| direct_declarator '[' STATIC aexp ']'
	| direct_declarator '[' type_qualifier_list STATIC aexp ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '(' parameter_type_list ')' {insertAstListTail($1->type,astFunc($3));}
	| direct_declarator '(' identifier_list ')' {insertAstListTail($1->type,astFunc($3));}
	| direct_declarator '(' ')' {insertAstListTail($1->type,astFunc(NULL)); $1->tail->value->len=0;}
	;

pointer
	: '*' {$$=astList(astPtr(0));}
	| '*' type_qualifier_list {$$=astList(astPtr($2));}
	| '*' pointer {insertAstList($2,astPtr(0)); $$=$2;}
	| '*' type_qualifier_list pointer {insertAstList($3,astPtr($2)); $$=$3;}
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
	: declspec declr {$$=$2; insertAstListTail($2->decl->type,$1);}
	| declspec abstract_declarator {$$=$2; insertAstListTail($2->decl->type,$1);}
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
	| pointer direct_abstract_declarator {$$=$2; mergeLists($2->decl->type,$1);}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {$$=$2;}
	| '[' ']' {$$=astAbsDecl(astArray(astNum(_integer,0)));}
	| '[' aexp ']' {$$=astAbsDecl(astArray($2));}
	| direct_abstract_declarator '[' ']' {insertAstListTail($1,astArray(astNum(_integer,0)));}
	| direct_abstract_declarator '[' aexp ']' {insertAstListTail($1,astArray($3));}
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' ')' {$$=astList(astFunc(NULL));}
	| '(' parameter_type_list ')' {$$=astList(astFunc($2));}
	| direct_abstract_declarator '(' ')' {insertAstListTail($1,astFunc(NULL));}
	| direct_abstract_declarator '(' parameter_type_list ')' {insertAstListTail($1,astFunc($3));}
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
	: ID ':' stmt {$$=astBinary(astIdent($1.c),$3,':');}
	| CASE ternary ':' stmt {$$=astBinary($2,$4,CASE);}
	| DEFAULT ':' stmt {$$=astBinary(NULL,$3,DEFAULT);}
	;

exps: ';' {$$ = NULL;}
 | exp ';' {$$ = $1;}
;

compoundstmt
 : '{' '}' {$$=astList(NULL);}
 | '{' block_item_list '}' {$$=$2;}
 ;

block_item_list
 : block_item {$$=astList($1);}
 | block_item_list block_item {$$=$1; insertAstListTail($1,$2);}
 ;

block_item
 : decl
 | stmt
 ;


selects
	: IF '(' exp ')' stmt {$$=astCond($3,$5,NULL);}
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
	: external_declaration {$$ = astList($1);}
	| translation_unit external_declaration {insertAstListTail($1,$2);}
	;

external_declaration
	: funcdef
	| decl
	;

funcdef
	: declspec declr declaration_list compoundstmt
	| declspec declr compoundstmt {insertAstListTail($2->decl->type,$1); $$=astFuncDef($2,$2->decl->ident,$3);}
	//| declr declaration_list stmtblock {$$=astFuncDef(NULL,$1,$2,$3);}
	//| declr stmtblock {$$=astFuncDef(NULL,$1,NULL,$2);}
	;

declaration_list
	: decl {$$=astList($1);}
	| declaration_list decl {insertAstList($1,$2);}
	;

stmts: stmt {$$ = astList($1);}
 | stmts stmt {insertAstList($1,$2);}
;
%%
main(int argc, char **argv)
{
  extern FILE *yyin, *yyout;
    if(argc < 2) {
        fprintf(stderr,"not enough arguments");
        return 1;
    }
 
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
    yyparse();
    printast(root,0);
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}