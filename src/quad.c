#include "ast.h"
#include "symtab.h"
#include "parsing.tab.h"
int quads[128][1024][4];

typedef enum q {
    q_add,
    q_addq,
    q_addf,
    q_sub,
    q_subq,
    q_subf,
    q_mul,
    q_mulf,
    q_div,
    q_divf,
    q_mod,
    q_load,
    q_store,
    q_eq,
    q_ne,
    q_ge,
    q_le,
    q_lt,
    q_gt,
    q_rt,
    q_and,
    q_or,
    q_xor,
    q_not,
    q_lea,
    q_lsh,
    q_rsh,
    q_mov,
    q_itof,
    q_ftoi,
    q_lea,
    q_call
} q;

typedef struct quad {
    int opcode;
    astnode* dest;
    astnode* src1;
    astnode* src2;
} quad;

typedef struct val {
    int symnum;
    astnode_listnode* type;
    int typesize;
    int offset;
    int num;
    double dnum;
} val;

astnode* gen_rval(astnode* node, astnode* target) {
    if (node->nodetype == AST_NUM) {
        return node;
    } else if (node->nodetype == AST_IDENT) {
        if (isArr(node->t->value)) {
            if (!target) target = astTemporary();
            emit(q_lea,node,0,target);
            return target;
        }
        return node;
    } else if (node->nodetype == AST_BINARY) {
        astnode* left = gen_rval(node->binop->left,0);
        astnode* right = gen_rval(node->binop->right,0);
        if (!target) target = astTemporary();
        switch (node->binop->op) {
            case '+':
                if (isPtrOrArr(node->binop->left)) {
                    emit(q_mul,right,astIntegral(typeSize(node->binop->left->t->value)),target);
                    target = astTemporary();
                    emit(q_add,left,right,target);
                    return target;
                } else if (isPtrOrArr(node->binop->right)) {
                    emit(q_mul,left,astIntegral(typeSize(node->binop->left->t->value)),target);
                    target = astTemporary();
                    emit(q_add,right,left,target);
                    return target;
                } else {
                    if (isIntegral(node->t->value)) {
                        emit(q_add,left,right,target);
                    } else {
                        emit(q_addf,left,right,target);
                    }
                    return target;
                }
                break;
            case '-':
                if (isPtrOrArr(node->binop->left)) {
                    emit(q_mul,right,astIntegral(typeSize(node->binop->left->t->value)),target);
                    target = astTemporary();
                    emit(q_sub,left,right,target);
                    return target;
                } else if (isPtrOrArr(node->binop->left)) {
                    emit(q_mul,left,astIntegral(typeSize(node->binop->left->t->value)),target);
                    target = astTemporary();
                    emit(q_sub,right,left,target);
                    return target;
                } else {
                    if (isIntegral(node->t->value)) {
                        emit(q_sub,left,right,target);
                    } else {
                        emit(q_subf,left,right,target);
                    }
                    return target;
                }
                break;
            case '*':
                if (isIntegral(node->t->value)) {
                    emit(q_mul,left,right,target);
                } else {
                    emit(q_mulf,left,right,target);
                }
                return target;
                break;
            case '/':
                if (isIntegral(node->t->value)) {
                    emit(q_div,left,right,target);
                } else {
                    emit(q_divf,left,right,target);
                }
                return target;
                break;
            case '%':
                emit(q_mod,left,right,target);
                return target;
                break;
            case LSHIFT:
                emit(q_lsh,left,right,target);
                return target;
                break;
            case RSHIFT:
                emit(q_rsh,left,right,target);
                return target;
                break;
            case '>':
                emit(q_gt,left,right,target);
                return target;
                break;
            case '<':
                emit(q_lt,left,right,target);
                return target;
                break;
            case EQ:
                emit(q_eq,left,right,target);
                return target;
                break;
            case NE:
                emit(q_ne,left,right,target);
                return target;
                break;
            case GE:
                emit(q_ge,left,right,target);
                return target;
                break;
            case LE:
                emit(q_le,left,right,target);
                return target;
                break;
            case '&':
                emit(q_and,left,right,target);
                return target;
                break;
            case '|':
                emit(q_or,left,right,target);
                return target;
                break;
            case '^':
                emit(q_xor,left,right,target);
                return target;
                break;
        }
        return target;
    } else if (node->nodetype == AST_UNARY) {
        if (node->uop->op == CAST) {
            astnode* left = gen_rval(node->uop->right,0);
            if (!target) target = astTemporary();
            if (isFloating(node->uop->right->t->value) && isIntegral(node->t->value)) {
                emit(q_ftoi,left,0,target);
            } else if (isIntegral(node->uop->right->t->value) && isFloating(node->t->value)) {
                emit(q_itof,left,0,target);
            }
            return target;
        } else if (node->uop->op == SIZEOF) {
            if (!target) target = astTemporary();
            astnode* size = astIntegral(typeSize(node->uop->right->list->head));
            emit(q_add,size,0,target);
            return target;
        } else if (node->uop->op == POSTINC || node->uop->op == PREINC) {
            astnode* n = astIntegral(1);
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_add,n,l,target);
            return target;
        } else if (node->uop->op == POSTDEC || node->uop->op == PREDEC) {
            astnode* n = astIntegral(-1);
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_add,n,l,target);
            return target;
        } else if (node->uop->op == '*') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_load,l,0,target);
            return target;
        } else if (node->uop->op == '&') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_lea,l,0,target);
            return target;
        } else if (node->uop->op == '~') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_not,l,0,target);
            return target;
        } else if (node->uop->op == '-') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_mul,l,astIntegral(-1),target);
            return target;
        } else if (node->uop->op == '!') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_eq,l,astIntegral(0),target);
            return target;
        }
    } else if (node->nodetype == AST_FUNC) {
        if (!target) target = astTemporary();
        astnode* l = gen_rval(node->uop->right,0);
        emit(q_call,node->func->)
        return target;
    }
}

astnode* gen_lval(astnode* node, astnode* target) {
    if (node->nodetype == AST_UNARY) {
        if (node->uop->op == POSTINC || node->uop->op == PREINC) {
            astnode* n = astIntegral(1);
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_add,n,l,target);
            return target;
        } else if (node->uop->op == POSTDEC || node->uop->op == PREDEC) {
            astnode* n = astIntegral(-1);
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_add,n,l,target);
            return target;
        } else if (node->uop->op == '*') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_load,l,0,target);
            return target;
        } else if (node->uop->op == '&') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_lea,l,0,target);
            return target;
        } else if (node->uop->op == '~') {
            if (!target) target = astTemporary();
            astnode* l = gen_rval(node->uop->right,0);
            emit(q_not,l,0,target);
            return target;
        }
    }
}

void emit(int op, astnode* src1, astnode* src2, astnode* dest) {

}

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
                    if (type->type->specifier->nodetype == AST_STRUCT) {
                        i=0;
                        while(h) {
                            i += typeSize(h->value->member->decl->decl->type->list->head);
                            h = h->next;
                        }
                        return i;
                    } else {
                        i=0;
                        while(h) {
                            int j = typeSize(h->value->member->decl->decl->type->list->head);
                            if (j > i) i = j;
                            h = h->next;
                        }
                        return i;
                    }
                    break;
            }
    }
    return -1;
}



val generate(symtab* root_tbl, astnode* root_node, int b, int r, int s) {
    symtab* cur_tbl = root_tbl;
    astnode* cur_node = root_node;
    int block = b;
    int row = r;
    val v;
    v.type=0;
    symrec* rec;
    astnode_listnode* h;
    switch(cur_node->nodetype) {
        case AST_FUNCDEF:
            b++;
            findsym(cur_tbl,cur_node->funcdef->ident->ident->name,NAMESPACE_OTHERS)->key = b;
            generate(cur_tbl,cur_node->funcdef->stmt,b,r,s);
        break;
        case AST_IDENT:
            rec = findsym(cur_tbl,cur_node->funcdef->ident->ident->name,NAMESPACE_OTHERS);
            v.symnum = rec->key;
            v.type = rec->type->head;
            v.typesize = typeSize(v.type);
            return v;
        break;
        case AST_DECL:
            rec = findsym(cur_tbl,cur_node->decl->ident->ident->name,NAMESPACE_OTHERS);
            rec->key = s;
            s++;
            v.symnum = rec->key;
            v.type = rec->type->head;
            v.typesize = typeSize(v.type);
        case AST_NUM:
        v.symnum = 0;
        if (cur_node->num->type == _real) {v.dnum = (double)cur_node->num->f;}
        else v.num = cur_node->num->i | cur_node->num->u;
        break;
        case AST_BINARY:
            val lval = generate(cur_tbl,cur_node->binop->left,b,r,s);
            val rval = generate(cur_tbl,cur_node->binop->right,b,r,s);
            switch (cur_node->binop->op) {
                case '+':
                    quads[b][r][0] = q_add;
                    quads[b][r][1] = rval.type && rval.type->value->nodetype == AST_PTR ? lval.num * 8 : lval.num;
                    quads[b][r][2] = lval.type && lval.type->value->nodetype == AST_PTR ? rval.symnum + rval.offset : rval.num;
                    quads[b][r][3] = s;
                    s++;
                break;
                case '=':
                    quads[b][r][0] = q_add;
                    quads[b][r][1] = rval.
            }
        break;
    }
    return v;
}