#ifndef __quads
#define __quads
#include "ast.h"
typedef enum qq {
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
    q_call,
    q_storestack,
    q_stackinit,
    q_cmp
} qq;

typedef struct quad {
    qq opcode;
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

typedef struct quads {
    quad* quads;
    int cap;
    int len;
} quads;

typedef struct block {
    int id;
    quads q;
    symrec* sym;
} block;

typedef struct blockss {
    block* blocks;
    int cap;
    int len;
} blockss;

void printQuads(quads i);
astnode* gen_rval(astnode*,astnode*);
void gen_condexpr(astnode* node,block* a, block* b);
#endif