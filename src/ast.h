#ifndef __AST
#define __AST
enum AST {
    AST_NUM,
    AST_UNARY,
    AST_STRING,
    AST_IDENT,
    AST_BINARY,
    AST_TERNARY,
    AST_CALL,
    AST_IF,
    AST_WHILE,
    AST_DOWHILE,
    AST_SWITCH,
    AST_FOR,
    AST_DECL,
    AST_ABSDECL,
    AST_LIST,
    AST_PARAMLIST,
    AST_STRUCT,
    AST_MEMBER,
    AST_UNION,
    AST_ENUM,
    AST_TYPE,
    AST_PTR,
    AST_ARRAY,
    AST_SCALAR,
    AST_FUNC,
    AST_STMTLIST,
    AST_TOKEN,
    AST_FUNCDEF
} AST;



typedef enum STG {
    STG_NONE,
    STG_TYPEDEF,
    STG_STATIC,
    STG_EXTERN,
    STG_AUTO,
    STG_REGISTER
}STG;

typedef enum SCALAR {
    SCALAR_NONE,
    SCALAR_INT,
    SCALAR_LONG,
    SCALAR_LONGINT,
    SCALAR_LONGLONG,
    SCALAR_LONGLONGINT,
    SCALAR_SHORT,
    SCALAR_SHORTINT,
    SCALAR_FLOAT,
    SCALAR_DOUBLE,
    SCALAR_LONGDOUBLE,
    SCALAR_CHAR,
    SCALAR_VOID,
    SCALAR_OBJ
} SCALAR;

typedef enum SIGN {
    SIGN_NONE,
    SIGN_SIGNED,
    SIGN_UNSIGNED
} SIGN;

typedef enum QUAL {
    QUAL_NONE = 0,
    QUAL_CONST = 1,
    QUAL_VOLATILE = 2,
    QUAL_RESTRICT = 4
} QUAL;

typedef enum COMPLETE {
    C_NONE,
    C_COMPLETE,
    C_INCOMPLETE
} COMPLETE;

typedef struct astnode;

enum numtype {
    _integer=1,
    _real=2,
    _complex=3
};

typedef struct astnode_quadop {
    struct astnode* first;
    struct astnode* second;
    struct astnode* third;
    struct astnode* fourth;
}astnode_quadop;

typedef struct astnode_list {
    struct astnode_listnode* head;
    struct astnode_listnode* tail;
    int len;
} astnode_list;

typedef struct astnode_listnode {
    struct astnode_listnode* next;
    struct astnode* value;
    int i;
} astnode_listnode;

typedef struct astnode_uop {
    int op;
    struct astnode* right;
} astnode_uop;

typedef struct astnode_ident {
    char* name;
} astnode_ident;

typedef struct astnode_binop {
    int op;
    struct astnode* left;
    struct astnode* right;
} astnode_binop;

typedef struct astnode_cond {
    struct astnode* cond;
    struct astnode* left;
    struct astnode* right;
} astnode_cond;

typedef struct astnode_num {
    int type;
    union {
        unsigned long long u;
        long long i;
        long double f;
    };
} astnode_num;

typedef struct astnode_call {
    struct astnode* func;
    struct astnode* params;
} astnode_call;

typedef struct astnode_if {
    struct astnode* cond;
    struct astnode* truestmt;
    struct astnode* falsestmt;
} astnode_if;

typedef struct astnode_while {
    struct astnode* cond;
    struct astnode* stmt;
} astnode_while;

typedef struct astnode_switch {
    struct astnode* cond;
    struct astnode* stmt;
} astnode_switch;

typedef struct astnode_for {
    struct astnode* init;
    struct astnode* cond;
    struct astnode* incr;
    struct astnode* stmt;
} astnode_for;

typedef struct astnode_decl {
    struct astnode* type;
    struct astnode* ident;
}astnode_decl;

typedef struct astnode_obj {
    struct astnode* tag;
    struct astnode* members;
} astnode_obj;

typedef struct astnode_member {
    struct astnode* decl;
    struct astnode* bits;
}astnode_member;

typedef struct astnode_type {
    struct astnode* specifier;
    SCALAR scalar;
    QUAL qual;
    STG stg;
    SIGN sign;
    COMPLETE complete;
    int in;
} astnode_type;

typedef struct astnode_array {
     struct astnode* size;
} astnode_array;

typedef struct astnode_func {
     struct astnode* params;
} astnode_func;

typedef struct astnode_ptr {
     STG stg;
     QUAL qual;
} astnode_ptr;

typedef struct astnode_funcdef {
    struct astnode* type;
    struct astnode* ident;
    struct astnode* stmt;
} astnode_funcdef;

typedef struct astnode {
    int nodetype;
    union {
    struct astnode_binop* binop;
    struct astnode_num* num;
    struct astnode_ident* ident;
    struct astnode_uop* uop;
    struct astnode_list* list;
    struct astnode_cond* ternop;
    struct astnode_for* _for;
    struct astnode_type* type;
    struct astnode_decl* decl;
    struct astnode_call* call;
    struct astnode_if* _if;
    struct astnode_while* _while;
    struct astnode_switch* _switch;
    struct astnode_obj* obj;
    struct astnode_array* array;
    struct astnode_ptr* ptr;
    struct astnode_func* func;
    struct astnode_funcdef* funcdef;
    struct astnode_member* member;
    int token;
    char* string;
    };
} astnode;

struct astnode* astIdent(char*);
struct astnode* astFn(struct astnode*,struct astnode*);
struct astnode* astNum(int,void*);
struct astnode* _binop(struct astnode*,struct astnode*,int,int);
struct astnode* _list(struct astnode*,int);
struct astnode* _intlist(int,int);
struct astnode* _cond(struct astnode*,struct astnode*,struct astnode*,int);
struct astnode* _obj(struct astnode*, struct astnode*,int);
struct astnode* astBinary(struct astnode*,struct astnode*,int);
struct astnode* astUnary(int,struct astnode*);
struct astnode* astExps(struct astnode*);
struct astnode* astStmts(struct astnode*);
struct astnode* astIdents(struct astnode*);
struct astnode* astEnums(struct astnode*);
struct astnode* astString(char*);
struct astnode* astCond(struct astnode*,struct astnode*,struct astnode*);
struct astnode* astFuncDef(struct astnode*,struct astnode*,struct astnode*);
struct astnode* astStruct(struct astnode*,struct astnode*);
struct astnode* astUnion(struct astnode*,struct astnode*);
struct astnode* astTypeSpec(struct astnode*);
struct astnode* astTypeQual(QUAL);
struct astnode* astDecl(struct astnode*);
struct astnode* astToken(int);
struct astnode* astType();
void insertAstIntList(struct astnode* left, int i);
void insertAstList(struct astnode* left, struct astnode* right);

void printast(struct astnode* node, int depth);
void _pastdepth(int depth);
#endif