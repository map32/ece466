#include "ast.h"
#include "symtab.h"
#include "parsing.tab.h"
#include "quad.h"
#include "stdlib.h"
block* curBlock;
blockss blocks;
int curblock;
void getBlocks() {
    blocks.blocks = (block*)malloc(sizeof(block)*1024);
    blocks.cap = 1024;
    blocks.len = 0;
}

block* newBlock(symrec* sym) {
    block* b = &blocks.blocks[blocks.len];
    b->id = blocks.len;
    b->sym = sym;
    blocks.len++;
    return b;
}
void setCurBlock(block* b) {
    curBlock = b;
}
block* getBlock(int i) {
    return &blocks.blocks[i];
}

astnode* gen_stmt(astnode* node) {
    if (node->nodetype == AST_BLOCKLIST || node->nodetype == AST_LIST) {
        astnode_listnode* l = node->list->head;
        while (l) {
            gen_stmt(l->value);
            l = l->next;
        }
    } else if (node->nodetype == AST_TERNARY) {
        gen_if(node);
    }else if (node->nodetype == AST_UNARY || node->nodetype == AST_BINARY || node->nodetype == AST_CALL) {
        if (node->nodetype == AST_UNARY && node->uop->op == RETURN) {
            gen_ret(node);
        } else if (node->nodetype == AST_BINARY && node->binop->op == WHILE) {
            gen_while(node);
        }else gen_assign(node);
    }
}

astnode* gen_while(astnode* node) {
    block* a = newBlock(0);
    block* b = newBlock(0);
    block* c = newBlock(0);
    block* d = curBlock;
    emit(q_br,0,0,astIntegral(a->id));
    curBlock = a;
    gen_condexpr(node->binop->left,b,c);
    curBlock = b;
    gen_stmt(node->binop->right);
    emit(q_br,0,0,astIntegral(a->id));
    curBlock = c;

}

astnode* gen_if(astnode* node) {
    quads qq;
    block* ccc = curBlock;
    block* aa = newBlock(0);
    block* bb = newBlock(0);
    block* cc;
    gen_condexpr(node->ternop->cond,aa,bb);
    curBlock = aa;
    gen_stmt(node->ternop->left);
    if (node->ternop->right) {
        cc = newBlock(0);
        curBlock = bb;
        gen_stmt(node->ternop->right);
    }
    if (node->ternop->right) {
        curBlock = aa;
    }
    emit(q_br,0,0,node->ternop->right ? astIntegral(cc->id) : astIntegral(bb->id));
    curBlock = node->ternop->right ? cc : bb;
}
void gen_condexpr(astnode* node,block* a, block* b) {
    if (node->nodetype == AST_LIST) {
        node = node->list->head->value;
    }
    if (node->nodetype == AST_BINARY) {
        astnode* l = gen_rval(node->binop->left,0);
        astnode* r = gen_rval(node->binop->right,0);
        if(node->binop->op == EQ) {
            emit(q_cmp,l,r,0);
            emit(q_eq,astIntegral(a->id),astIntegral(b->id),0);
        } else if(node->binop->op == NE) {
            emit(q_cmp,l,r,0);
            emit(q_ne,astIntegral(a->id),astIntegral(b->id),0);
        } else if(node->binop->op == GE) {
            emit(q_cmp,l,r,0);
            emit(q_ge,astIntegral(a->id),astIntegral(b->id),0);
        } else if(node->binop->op == LE) {
            emit(q_cmp,l,r,0);
            emit(q_le,astIntegral(a->id),astIntegral(b->id),0);
        } else if(node->binop->op == '>') {
            emit(q_cmp,l,r,0);
            emit(q_gt,astIntegral(a->id),astIntegral(b->id),0);
        } else if(node->binop->op == '<') {
            emit(q_cmp,l,r,0);
            emit(q_lt,astIntegral(a->id),astIntegral(b->id),0);
        } else {
            astnode* aa = gen_rval(node,0);
            emit(q_cmp,aa,astIntegral(0),0);
            emit(q_ne,astIntegral(a->id),astIntegral(b->id),0);
        }
    } else if (node->nodetype == AST_UNARY) {
        astnode* l = gen_rval(node,0);
        emit(q_cmp,l,astIntegral(0),0);
        emit(q_ne,astIntegral(a->id),astIntegral(b->id),0);
    }
}
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
                if (isPtrOrArr(node->binop->left->t->value)) {
                    emit(q_mul,right,(astnode*)astIntegral(typeSize(node->binop->left->t->next)),target);
                    astnode* target2 = astTemporary();
                    emit(q_add,left,target,target2);
                    return target2;
                } else if (isPtrOrArr(node->binop->right->t->value)) {
                    emit(q_mul,left,(astnode*)astIntegral(typeSize(node->binop->left->t->next)),target);
                    astnode* target2 = astTemporary();
                    emit(q_add,right,target,target2);
                    return target2;
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
                if (isPtrOrArr(node->binop->left->t->value)) {
                    emit(q_mul,right,(astnode*)astIntegral(typeSize(node->binop->left->t->next)),target);
                    astnode* target2 = astTemporary();
                    emit(q_sub,left,target,target2);
                    return target2;
                } else if (isPtrOrArr(node->binop->left->t->value)) {
                    emit(q_mul,left,(astnode*)astIntegral(typeSize(node->binop->left->t->next)),target);
                    astnode* target2 = astTemporary();
                    emit(q_sub,right,target,target2);
                    return target2;
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
            if (node->uop->right->t->next->value->nodetype == AST_ARRAY) {
                return gen_rval(node->uop->right,0);
            }
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
            emit(q_cmp,l,astIntegral(0),target);
            return target;
        }
    } else if (node->nodetype == AST_CALL) {
        if (!target) target = astTemporary();
        astnode* l = gen_rval(node->call->func,0);
        astnode_listnode* p = node->call->params->list->head;
        emit(q_stackinit,astIntegral(node->call->params->list->len),0,0);
        int len = node->call->params->list->len;
        int i=len;
        while (i>0) {
            astnode_listnode* temp = p;
            int j=1;
            while(j<i) {
                temp = temp->next;
                j++;
            }
            astnode *t = gen_rval(temp->value,0);
            emit(q_storestack,t,0,0);
            i--;
        }
        emit(q_call,l,0,target);
        return target;
    } else if (node->nodetype == AST_LIST) {
        astnode* l = node->list->head->value;
        return gen_rval(l,0);
    } else if (node->nodetype == AST_STRING) {
        return node;
    }
}

astnode* gen_ret(astnode* node) {
    if(node->uop->right) {
        astnode* val = gen_rval(node->uop->right->list->head->value,0);
        emit(q_rt,val,0,0);
    }
}

astnode* gen_lval(astnode* node, astnode* target, int* indirect) {
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
            *indirect = 1;
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
    } else if (node->nodetype == AST_IDENT) {
        return node;
    } else if (node->nodetype == AST_NUM) {
        return 0;
    }
}

astnode* gen_assign(astnode* node) {
    if (node->nodetype == AST_BINARY) {
        int indirect = 0;
        astnode* r = gen_rval(node->binop->right,0);
        astnode* l = gen_lval(node->binop->left,0,&indirect);
        if (indirect) {
            emit(q_store,r,0,l);
        } else {
            emit(q_mov,r,0,l);
        }
        return l;
    } else return gen_rval(node,0);
}

void gen_expr(astnode* node) {
    if (node->nodetype == AST_LIST) {
        astnode_listnode* n = node->list->head;
        while(n) {
            gen_assign(n->value);
            n = n->next;
        }
    } else return gen_rval(node,0);
}

void emit(qq op, astnode* src1, astnode* src2, astnode* dest) {
    quads* q = &((*curBlock).q);
    if (q->cap == 0) {
        q->quads = (quad*)malloc(sizeof(quad)*4096);
        q->cap = 4096;
    } else if (q->len == q->cap) {
        q->quads = realloc(q->quads,sizeof(quad)*(q->cap*2));
        q->cap *= 2;
    }
    quad* i = &q->quads[q->len];
    i->opcode = op;
    i->src1 = src1;
    i->src2 = src2;
    i->dest = dest;
    q->len++;
}

void printBlocks() {
    int i = 0;
    for(;i<blocks.len;i++) {
        printf(".BB%d\n\n",i);
        printQuads(blocks.blocks[i].q);
    }
}

void printQuads(quads q) {
    int j=0;
    for(;j<q.len;j++){
        quad* i = &(q.quads[(int)j]);
        switch(i->opcode) {
            case q_add:
                printf("q_add ");
                break;
            case q_addf:
                printf("q_addf ");
                break;
            case q_and:
                printf("q_and ");
                break;
            case q_call:
                printf("q_call ");
                break;
            case q_div:
                printf("q_div ");
                break;
            case q_divf:
                printf("q_divf ");
                break;
            case q_eq:
                printf("q_eq ");
                break;
            case q_ftoi:
                printf("q_ftoi ");
                break;
            case q_ge:
                printf("q_ge ");
                break;
            case q_itof:
                printf("q_itof ");
                break;
            case q_gt:
                printf("q_gt ");
                break;
            case q_le:
                printf("q_le ");
                break;
            case q_lea:
                printf("q_lea ");
                break;
            case q_load:
                printf("q_load ");
                break;
            case q_lsh:
                printf("q_lsh ");
                break;
            case q_lt:
                printf("q_lt ");
                break;
            case q_mod:
                printf("q_mod ");
                break;
            case q_mov:
                printf("q_mov ");
                break;
            case q_mul:
                printf("q_mul ");
                break;
            case q_mulf:
                printf("q_mulf ");
                break;
            case q_ne:
                printf("q_ne ");
                break;
            case q_not:
                printf("q_not ");
                break;
            case q_or:
                printf("q_or ");
                break;
            case q_rsh:
                printf("q_rsh ");
                break;
            case q_store:
                printf("q_store ");
                break;
            case q_sub:
                printf("q_sub ");
                break;
            case q_subf:
                printf("q_subf");
                break;
            case q_storestack:
                printf("q_storestack ");
                break;
            case q_stackinit:
                printf("q_stackinit ");
                break;
            case q_xor:
                printf("q_xor ");
                break;
            case q_cmp:
                printf("q_cmp ");
                break;
            case q_rt:
                printf("q_rt ");
                break;
            case q_br:
                printf("q_br ");
                break;
            default:
                printf("unknown op ");
                break;
        }
        printast_quad(i->src1);
        printast_quad(i->src2);
        printast_quad(i->dest);
        printf("\n");

    }
}

void printast_quad(astnode* a) {
    if (!a) return;
    switch(a->nodetype) {
        case AST_NUM:
            printf("%d ",a->num->i);
            break;
        case AST_TEMPORARY:
            printf("%%%d ",a->tempnum);
            break;
        case AST_IDENT:
            printf("%s ",a->ident->name);
            break;
        case AST_STRING:
            printf("%s ",a->string);
            break;
        default:
            printf("unknown ast type in quad ");
            
    }
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

