#include "ast.h"
#include "helpers.h"
#include "symtab.h"
#include <stdlib.h>
#include <stdio.h>

extern ERROR ** errors;
extern errnum;

struct astnode* newAst(int type) {
    struct astnode* ast = (struct astnode*)malloc(sizeof(astnode));
    ast->nodetype=type;
    return ast;
}

struct astnode_quadop* newAstQuadop() {
    struct astnode_quadop* ast = (struct astnode_quadop*)malloc(sizeof(astnode_quadop));
    return ast;
}

struct astnode_list* newAstList() {
    struct astnode_list* ast = (struct astnode_list*)malloc(sizeof(astnode_list));
    return ast;
}

struct astnode_listnode* newAstListNode() {
    struct astnode_listnode* ast = (struct astnode_listnode*)malloc(sizeof(astnode_listnode));
    ast->next = NULL;
    ast->value = NULL;
    return ast;
}

struct astnode* astFuncDef(struct astnode* a, struct astnode* b, struct astnode* c){
    struct astnode* mine = newAst(AST_FUNCDEF);
    mine->funcdef = (struct astnode_funcdef*)malloc(sizeof(astnode_funcdef));
    mine->funcdef->type=a;
    mine->funcdef->ident=b;
    mine->funcdef->stmt=c;
    return mine;
}

struct astnode* astNum(int type, void* value) {
    struct astnode* mine = newAst(AST_NUM);
    mine->num = (struct astnode_num*)malloc(sizeof(astnode_num));
    mine->num->type = type;
    if (type==_real){
        mine->num->f = *((long double*)value);
    } else if (type==_integer) {
        mine->num->i = *((long long int*)value);
    } else if (type == _unsigned) {
        mine->num->u = *((unsigned long long int*)value);
    }
    return mine;
}

struct astnode* astUnary(int left, struct astnode* right) {
    struct astnode* mine = newAst(AST_UNARY);
    mine->uop = (struct astnode_uop*)malloc(sizeof(astnode_uop));
    mine->uop->op = left;
    mine->uop->right = right;
    return mine;
}

struct astnode* astString(char* str) {
    struct astnode* mine = newAst(AST_STRING);
    mine->string = str;
    return mine;
}
struct astnode* astIdent(char* id) {
    struct astnode* mine = newAst(AST_IDENT);
    mine->ident = (struct astnode_ident*)malloc(sizeof(astnode_ident));
    mine->ident->name = id;
    return mine;
}

struct astnode* astBinary(struct astnode* left, struct astnode* right, int op) {
    return _binop(left,right,op,AST_BINARY);
}

struct astnode* _binop(struct astnode* left, struct astnode* right, int op, int type) {
    struct astnode* mine = newAst(type);
    mine->binop = (struct astnode_binop*)malloc(sizeof(astnode_binop));
    mine->binop->op = op;
    mine->binop->left = left;
    mine->binop->right = right;
    return mine;
}
struct astnode* astCond(struct astnode* cond, struct astnode* left, struct astnode* right) {
    return _cond(cond,left,right,AST_TERNARY);
}
struct astnode* _cond(struct astnode* cond, struct astnode* left, struct astnode* right, int type) {
    struct astnode* mine = newAst(type);
    mine->ternop = (struct astnode_cond*)malloc(sizeof(astnode_cond));
    mine->ternop->left = left;
    mine->ternop->right = right;
    mine->ternop->cond = cond;
    return mine;
}
struct astnode* astCall(struct astnode* func, struct astnode* params) {
    struct astnode* m = newAst(AST_CALL);
    m->call = (struct astnode_call*)malloc(sizeof(astnode_call));
    m->call->func = func;
    m->call->params=params;
    return m;

}
struct astnode* astIf(struct astnode* cond, struct astnode* truestmt, struct astnode* falsestmt) {
    struct astnode* m = newAst(AST_IF);
    m->_if = (struct astnode_if*)malloc(sizeof(astnode_if));
    m->_if->cond = cond;
    m->_if->truestmt = truestmt;
    m->_if->falsestmt = falsestmt;
    return m;
}
struct astnode* astWhile(struct astnode* cond, struct astnode* stmt) {
    struct astnode* m = newAst(AST_WHILE);
    m->_while = (struct astnode_while*)malloc(sizeof(astnode_while));
    m->_while->cond = cond;
    m->_while->stmt = stmt;
    return m;
}
struct astnode* astDoWhile(struct astnode* stmt, struct astnode* cond) {
    struct astnode* m = newAst(AST_DOWHILE);
    m->_while = (struct astnode_while*)malloc(sizeof(astnode_while));
    m->_while->cond = cond;
    m->_while->stmt = stmt;
    return m;
}
struct astnode* astFor(struct astnode* a, struct astnode* b, struct astnode* c, struct astnode* d) {
    struct astnode* mine = newAst(AST_FOR);
    mine->_for = (struct astnode_for*)malloc(sizeof(astnode_for));
    mine->_for->init = a;
    mine->_for->cond = b;
    mine->_for->incr = c;
    mine->_for->stmt = d;
    return mine;
}
struct astnode* astList(struct astnode* left) {
    return _list(left,AST_LIST);
}
struct astnode* astParamList(struct astnode* left) {
    return _list(left,AST_PARAMLIST);
}
struct astnode* astStmtList(struct astnode* left) {
    return _list(left,AST_STMTLIST);
}
struct astnode* astBlockList(struct astnode* left) {
    return _list(left,AST_BLOCKLIST);
}
struct astnode* _list(struct astnode* left, int type) {
    struct astnode* mine = newAst(type);
    mine->list = newAstList();
    mine->list->head = newAstListNode();
    mine->list->head->value = left;
    mine->list->head->next = NULL;
    mine->list->tail = mine->list->head;
    mine->list->len=1;
    return mine;
}
struct astnode* astStrun(int token,struct astnode* tag, struct astnode* members) {
    if (token==STRUCT) return astStruct(tag,members);
    else if (token==UNION) return astUnion(tag,members);
    else return NULL;
}
struct astnode* astStruct(struct astnode* tag, struct astnode* members) {
    return _obj(tag,members,AST_STRUCT);
}
struct astnode* astUnion(struct astnode* tag, struct astnode* members) {
    return _obj(tag,members,AST_UNION);
}
struct astnode* astEnum(struct astnode* tag, struct astnode* members) {
    return _obj(tag,members,AST_ENUM);
}
struct astnode* _obj(struct astnode* tag, struct astnode* members,int t) {
    struct astnode* mine = newAst(t);
    mine->obj = (struct astnode_obj*)malloc(sizeof(astnode_obj));
    mine->obj->tag = tag;
    mine->obj->members = members;
    return mine;
}
struct astnode* astArray(struct astnode* size) {
    struct astnode* mine = newAst(AST_ARRAY);
    mine->array = (struct astnode_array*)malloc(sizeof(astnode_array));
    mine->array->size = size;
    return mine;
    }

struct astnode* astPtr(enum QUAL qual) {
    struct astnode* mine = newAst(AST_PTR);
    mine->ptr = (struct astnode_ptr*)malloc(sizeof(astnode_ptr));
    mine->ptr->qual = qual;
    return mine;
    }
struct astnode* astFunc(struct astnode* params) {
    struct astnode* mine = newAst(AST_FUNC);
    mine->func = (struct astnode_func*)malloc(sizeof(astnode_func));
    mine->func->params = params;
    return mine;
}
struct astnode* _token(int token, int type) {
    struct astnode* mine = newAst(type);
    mine->token = token;
    return mine;
}

struct astnode* astToken(int t) {
    return _token(t,AST_TOKEN);
}

void bindDeclSpec(struct astnode* declspec, struct astnode* decllist){
    struct astnode_listnode* a = decllist->list->head;
    while(a) {
        insertAstListTail(a->value->decl->type,declspec);
        if (a->value->decl->type->list->head->value->nodetype == AST_IDENT) {
            a->value->decl->type->list->head = a->value->decl->type->list->head->next;
            a->value->decl->type->list->len -= 1;
        }
        a = a->next;
    }
}

void bindDeclDef(struct astnode* declspec, struct astnode* decl){
    struct astnode_listnode* a = decl->funcdef->type->list->head;
    insertAstListTail(decl->funcdef->type,declspec);
    if (a->value->nodetype == AST_IDENT) {
        decl->funcdef->type->list->head = a->next;
        decl->funcdef->type->list->len -= 1;
    }
}

void bindDeclSpecStruct(struct astnode* declspec, struct astnode* decllist){
    struct astnode_listnode* a = decllist->list->head;
    while(a) {
        insertAstListTail(a->value->member->decl->decl->type,declspec);
        if (a->value->member->decl->decl->type->list->head->value && a->value->member->decl->decl->type->list->head->value->nodetype == AST_IDENT) {
            a->value->member->decl->decl->type->list->head = a->value->member->decl->decl->type->list->head->next;
            a->value->member->decl->decl->type->list->len -= 1;
        }
        a = a->next;
    }
}


struct astnode* _type() {
    struct astnode* mine = newAst(AST_TYPE);
    struct astnode_type* ast = (struct astnode_type*)malloc(sizeof(astnode_type));
    mine->type=ast;
    mine->type->qual = QUAL_NONE;
    mine->type->specifier=NULL;
    mine->type->in=0;
    mine->type->stg=STG_NONE;
    mine->type->complete=C_NONE;
    mine->type->sign=SIGN_NONE;
    mine->type->scalar=SCALAR_NONE;
    return mine;
}

struct astnode* astTypeStg(enum STG stg) {
    struct astnode* mine = _type();
    mine->type->stg = stg;
    return mine;
}

struct astnode* astTypeQual(enum QUAL q) {
    struct astnode* mine = _type();
    mine->type->qual = q;
    return mine;
}

struct astnode* astTypeSpec(struct astnode* spec) {
    struct astnode* mine = _type();
    if (spec->nodetype == AST_TOKEN) {
        if(spec->token == UNSIGNED || spec->token == SIGNED) {
            mine->type->sign = _convspec(spec->token);
        } else mine->type->scalar = _convspec(spec->token);
    } else {
        mine->type->specifier = spec;
        mine->type->scalar = SCALAR_OBJ;
    }
    return mine;
}

struct astnode* astTypeInline(int i) {
    struct astnode* mine = _type();
    mine->type->in = i;
    return mine;
}

int _convspec(int token) {
    switch(token) {
        case VOID:
        return SCALAR_VOID;
        case LONG:
        return SCALAR_LONG;
        case INT:
        return SCALAR_INT;
        case FLOAT:
        return SCALAR_FLOAT;
        case CHAR:
        return SCALAR_CHAR;
        case SHORT:
        return SCALAR_SHORT;
        case DOUBLE:
        return SCALAR_DOUBLE;
        case SIGNED:
        return SIGN_SIGNED;
        case UNSIGNED:
        return SIGN_UNSIGNED;
        case CONST:
        return QUAL_CONST;
        case VOLATILE:
        return QUAL_VOLATILE;
        case RESTRICT:
        return QUAL_RESTRICT;
        case TYPEDEF:
        return STG_TYPEDEF;
        case AUTO:
        return STG_AUTO;
        case REGISTER:
        return STG_REGISTER;
        case EXTERN:
        return STG_EXTERN;
        case STATIC:
        return STG_STATIC;
        default:
        return -1;
    };
}

int addTypeStg(struct astnode* type, int stg) {
    if (type->type->stg == STG_NONE) type->type->stg = _convspec(stg);
    else return 1;

    return 0;
}

int addTypeSpec(struct astnode* type, struct astnode* spec) {
    if (spec->nodetype == AST_TOKEN && (spec->token != SIGNED && spec->token != UNSIGNED)) {
        int t = spec->token;
        int k = type->type->scalar;
        if (k == SCALAR_OBJ || k == SCALAR_CHAR || k == SCALAR_FLOAT ||
        k == SCALAR_LONGDOUBLE || k == SCALAR_LONGLONGINT || k == SCALAR_SHORTINT 
        || k == SCALAR_VOID) return 1;
        if (k == SCALAR_NONE) {k = _convspec(t); type->type->scalar = k; return 0;}
        else if (t == LONG) {
            if (k == SCALAR_INT) k = SCALAR_LONGINT;
            else if (k == SCALAR_DOUBLE) k = SCALAR_LONGDOUBLE;
            else if (k == SCALAR_LONGINT) k = SCALAR_LONGLONGINT;
            else if (k == SCALAR_LONG) k = SCALAR_LONGLONG;
            else return 2;
        } else if (t == INT) {
            if (k == SCALAR_LONG) k = SCALAR_LONGINT;
            else if (k == SCALAR_LONGLONG) k = SCALAR_LONGLONGINT;
            else if (k == SCALAR_SHORT) k = SCALAR_SHORTINT;
            else return 3;
        } else if (t == SHORT) {
            if (k == SCALAR_INT) k = SCALAR_SHORTINT;
            return 4;
        } else return 5;
        type->type->scalar = k;
        return 0;
    } else if (spec->nodetype == AST_TOKEN) {
        printast(spec,0);
        printast(type,0);
        if (type->type->sign == SIGN_NONE) type->type->sign = _convspec(spec->token);
        else return 6;
    } else {
        if (type->type->scalar == SCALAR_NONE) {
            type->type->scalar = SCALAR_OBJ;
            type->type->specifier = spec;
            return 0;
        }
        return 7;
    }
    return 0;
}

int addTypeQual(struct astnode* type, int qual) {
    type->type->qual |= _convspec(qual);
    return 0;
}

struct astnode* astDecl(struct astnode* id) {
    struct astnode* m = newAst(AST_DECL);
    m->decl = (struct astnode_decl*)malloc(sizeof(astnode_decl));
    m->decl->ident=id;
    m->decl->type = astList(id);
    return m;
}

struct astnode* astAbsDecl(struct astnode* t) {
    struct astnode* m = newAst(AST_ABSDECL);
    m->decl = (struct astnode_decl*)malloc(sizeof(astnode_decl));
    m->decl->type = astList(t);
    return m;
}

struct astnode* astAbsDeclfromList(struct astnode* l) {
    struct astnode* m = newAst(AST_ABSDECL);
    m->decl = (struct astnode_decl*)malloc(sizeof(astnode_decl));
    m->decl->type = l;
    return m;
}

void insertAstList(struct astnode* l, struct astnode* right) {
    struct astnode_listnode* h;
    struct astnode_list* left = l->list;
    h = left->head;
    left->head = newAstListNode();
    left->head->value = right;
    left->head->next = h;
    left->len += 1;
}
void insertAstListTail(struct astnode* l, struct astnode* right) {
    struct astnode_list* left = l->list;
    left->tail->next = newAstListNode();
    left->tail->next->value = right;
    left->tail = left->tail->next;
    left->len += 1;
}
void insertAstIntList(struct astnode* l, int i) {
     struct astnode_list* left = l->list;
    struct astnode_listnode* h = left->head;
    left->head = newAstListNode();
    left->head->i = i;
    left->head->next = h;
    left->len += 1;
}
struct astnode* mergeLists(struct astnode* l, struct astnode* r) {
    l->list->tail->next = r->list->head;
    l->list->len += r->list->len;
    l->list->tail = r->list->tail;
    free(r);
    return l;
}

struct astnode* astMember(struct astnode* decl, struct astnode* bits) {
    struct astnode* m = newAst(AST_MEMBER);
    m->member=(struct astnode_member*)malloc(sizeof(astnode_member));
    m->member->bits=bits;
    m->member->decl=decl;
    return m;
}

void checkdeclr(astnode* declr, _A asttype, int lineno) {
    _A declrtail = declr->list->tail->value->nodetype;
    if (declrtail == AST_FUNC) {
        if (asttype == AST_FUNC || asttype == AST_ARRAY) {
            errors[errnum] = getError(lineno, "A function cannot return a function or an array.\n");
        }
    }
}

void _pastdepth(int depth) {
    int i;
    for(i=0;i<depth;i++) fprintf(stderr,"  ");
}

void printast(struct astnode* node,int depth) {
    if (node == NULL) return;
    if (node->nodetype != AST_LIST && node->nodetype != AST_BLOCKLIST ) _pastdepth(depth);
    struct symrec* rec;
    switch(node->nodetype) {
        case AST_IDENT:
        printf("ID %s\n",node->ident->name);
        break;
        case AST_STRING:
        printf("STR %s\n",node->string);
        break;
        case AST_NUM:
        if (node->num->type==_integer) {
            printf("NUM %lld\n",(node->num->i));

        } else if (node->num->type==_real){
            printf("NUM %Lf\n",(node->num->f));
        }
        break;
        case AST_TOKEN:
        printf("TOKEN %s\n",gettoken(node->token));
        break;
        case AST_UNARY:
        if (node->uop->op<256) printf("UNARY %c\n",node->uop->op);
        else printf("UNARY %s\n",gettoken(node->uop->op));
        printast(node->uop->right,depth+1);
        break;
        case AST_BINARY:
        if (node->binop->op<256) printf("BINARY %c\n",node->binop->op);
        else printf("BINARY %s\n",gettoken(node->binop->op));
        printast(node->binop->left,depth+1);
        printast(node->binop->right,depth+1);
        break;
        case AST_LIST:
        case AST_BLOCKLIST:
        if (node->list->len>0){
            struct astnode_listnode* cur;
            cur = node->list->head;
            _pastdepth(depth);
            if (node->nodetype == AST_BLOCKLIST) {printf("START OF BLOCK: ");}
            printf("LIST, length: %d\n",node->list->len);
            while (cur) {
                printast(cur->value,depth+1);
                cur = cur->next;
            }
        } else if (node->list->len>0){
            printast(node->list->head->value,depth);
        }
        break;
        case AST_CALL:
        printf("CALL\n");
        printast(node->call->func,depth+1);
        printast(node->call->params,depth+1);
        break;
        case AST_PTR:
        printf("POINTER\n");
        break;
        case AST_ARRAY:
        printf("ARRAY, SIZE=%d\n",(int)(node->array->size->num->i));
        break;
        case AST_FUNC:
        printf("FUNC\n");
        printast(node->func->params,depth+1);
        break;
        case AST_TERNARY:
        printf("TERNARY\n");
        printast(node->ternop->cond,depth+1);
        printast(node->ternop->left,depth+1);
        printast(node->ternop->right,depth+1);
        break;
        case AST_DECL:
        if (node->decl->ident) {
            rec = findsym(node->tbl,node->decl->ident->ident->name,NAMESPACE_OTHERS);
            printf("DECLARATION line:%d\n",rec ? rec->lineno : -1);
            printast(node->decl->ident,depth+1);
        }
        printast(node->decl->type,depth+1);
        break;
        case AST_ABSDECL:
        printf("ABSTRACT DECLARATION\n");
        printast(node->decl->type,depth+1);
        break;
        case AST_STRUCT:
        rec = findsym(node->tbl,node->obj->tag->ident->name,NAMESPACE_TAGS);
        printf("STRUCT DECLARATION line:%d,\n",rec->lineno);
        printast(node->obj->tag,depth+1);
        printast(node->obj->members,depth+1);
        break;
        case AST_UNION:
        rec = findsym(node->tbl,node->obj->tag->ident->name,NAMESPACE_TAGS);
        printf("UNION DECLARATION line:%d\n",rec->lineno);
        printast(node->obj->tag,depth+1);
        printast(node->obj->members,depth+1);
        break;
        case AST_TYPE:
        astnode_type* t = node->type;
        printf("%s %s %s %s\n",TEXT_STG[t->stg],TEXT_QUAL[t->qual],TEXT_SIGN[t->sign],TEXT_SCALAR[t->scalar]);
        printast(node->type->specifier,depth+1);
        break;
        case AST_FUNCDEF:
        rec = findsym(node->tbl,node->funcdef->ident->ident->name,NAMESPACE_OTHERS);
        printf("FUNCTION DEFINITION line: %d\n",rec->lineno);
        printf("1.TYPE\n");
        printast(node->funcdef->type,depth+1);
        printf("2.IDENT\n");
        printast(node->funcdef->ident,depth+1);
        printf("3.STATEMENT BLOCK\n");
        printast(node->funcdef->stmt,depth+1);
        break;
        case AST_MEMBER:
        printf("STRUCT/UNION/ENUM MEMBER\n");
        printast(node->member->bits,depth+1);
        printast(node->member->decl,depth+1);
        break;
        default:
        printf("unknown astnode encountered! nodetype: %d",node->nodetype);
    }
}