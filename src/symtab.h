#include "ast.h"

typedef struct symrec {
    int key;
    struct astnode_ident* ident;
    struct astnode_type* type;
    int scope;
    
} symrec;

typedef struct symtab {
    struct symtab* parent;
    struct symtab** children;
    struct symrec* row;
    int rownum;
    int childnum;
} symtab;
