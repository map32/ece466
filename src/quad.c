#include "ast.h"
#include "symtab.h"
#include "parsing.tab.h"
int quads[128][1024][4];

typedef enum q {
    q_add,
    q_sub,
    q_mul,
    q_div,
    q_fdiv,
    q_mod,
    q_load,
    q_store,
    q_eq,
    q_ne,
    q_ge,
    q_le,
    q_lt,
    q_rt,
    q_and,
    q_or,
    q_xor,
    q_not,
    q_lea,
    q_lsh,
    q_rsh
} q;
typedef struct val {
    int symnum;
    astnode_listnode* type;
    int typesize;
    int offset;
    int num;
    double dnum;
} val;

int typeSize(astnode_listnode* node) {
    int i = 1;
    astnode* type = node->value;
    astnode_listnode* h;
    if (!type) return i;
    switch(type->nodetype) {
        case AST_PTR:
            return 8;
        case AST_ARRAY:
            return type->array->size->num->i * typeSize(node->next);
        case AST_TYPE:
            switch(type->type->scalar){
                case SCALAR_CHAR:
                    return 1;
                    break;
                case SCALAR_SHORT:
                case SCALAR_SHORTINT:
                case SCALAR_INT:
                case SCALAR_LONG:
                case SCALAR_LONGINT:
                case SCALAR_FLOAT:
                case SCALAR_NONE:
                    return 4;
                    break;
                case SCALAR_LONGLONG:
                case SCALAR_LONGLONGINT:
                    return 8;
                    break;
                case SCALAR_LONGDOUBLE:
                    return 10;
                    break;
                case SCALAR_OBJ:
                    h = type->type->specifier->obj->members->list->head;
                    i=0;
                    while(h) {
                        i += typeSize(h->value->member->decl->decl->type->list->head);
                        h = h->next;
                    }
                    return i;
                    break;
            }
    }
    return -1;
}
val generate(symtab* root_tbl, astnode* root_node, int b, int r) {
    symtab* cur_tbl = root_tbl;
    astnode* cur_node = root_node;
    int block = b;
    int row = r;
    val v;
    symrec* rec;
    astnode_listnode* h;
    switch(cur_node->nodetype) {
        case AST_FUNCDEF:
            b++;
            findsym(cur_tbl,cur_node->funcdef->ident->ident->name,NAMESPACE_OTHERS)->key = b;
            generate(cur_tbl,cur_node,b,r);
        break;
        case AST_IDENT:
            rec = findsym(cur_tbl,cur_node->funcdef->ident->ident->name,NAMESPACE_OTHERS);
            v.symnum = rec->key;
            v.type = rec->type->head;
            v.typesize = typeSize(v.type);
            return v;
        break;
        case AST_NUM:
        break;
        case AST_BINARY:
            val lval = generate(cur_tbl,cur_node->binop->left,b,r);
            val rval = generate(cur_tbl,cur_node->binop->right,b,r);
            switch (cur_node->binop->op) {
                case '+':
                    quads[block][row][0] = q_add;
                    quads[block][row][1] = rval.symnum ? lval.num + rval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case '-':
                    quads[block][row][0] = q_sub;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case '*':
                    quads[block][row][0] = q_mul;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case '/':
                    quads[block][row][0] = q_div;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case '%':
                    quads[block][row][0] = q_mod;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case LSHIFT:
                    quads[block][row][0] = q_lsh;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
                case RSHIFT:
                    quads[block][row][0] = q_rsh;
                    quads[block][row][1] = lval.symnum ? lval.symnum + lval.offset : lval.num;
                    quads[block][row][2] = rval.symnum ? rval.symnum + rval.offset : rval.num;
                    quads[block][row][3] = lval.symnum;
                break;
            }
            val v;
        break;
    }
    return 0;
}