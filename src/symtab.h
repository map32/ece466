#ifndef __SYMTAB
#define __SYMTAB
#include "ast.h"

typedef enum SYM_TYPE {
    SYM_VAR,
    SYM_FUNC,
    SYM_TAG,
    SYM_MEMBER,
    SYM_LABEL,
    SYM_PROTOVAR
} SYM_TYPE;

typedef enum NAMESPACE_TYPE {
    NAMESPACE_OTHERS,
    NAMESPACE_LABELS,
    NAMESPACE_TAGS,
} NAMESPACE_TYPE;

typedef enum SCOPE_TYPE {
    SCOPE_FILE,
    SCOPE_FUNC,
    SCOPE_BLOCK,
    SCOPE_PROTO,
    SCOPE_OBJ
} SCOPE_TYPE;
typedef struct symtab {
    struct symtab* parent;
    struct symrec* row;
    int rowmax;
    int rownum;
    int lineno;
    int localtotal; //all local variables under function block
    int protototal; //all parameters under func block
    SCOPE_TYPE scope;
    struct symtab* root;
} symtab;
typedef struct symrec {
    int key;
    char* ident;
    struct astnode_list* type;
    SYM_TYPE symtype;
    SCOPE_TYPE scope;
    int complete;
    int lineno;
    NAMESPACE_TYPE namespace;
    int bits;
    symtab* parent;
    symtab* func;
    int index;
} symrec;
struct symtab* createTable(struct symtab* parent,int lineno,SCOPE_TYPE scope);
struct symrec* insertDecls(struct symtab* table, struct astnode* data, int lineno);
symrec *findsym(symtab*, char*, NAMESPACE_TYPE);
void setPrototype(symtab*);
#endif