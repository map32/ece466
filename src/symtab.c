#include "symtab.h"
#include "helpers.h"
#include <stdlib.h>
#include <string.h>

extern ERROR ** errors;
extern errnum;

struct symtab* createTable(struct symtab* parent,int lineno,SCOPE_TYPE scope) {
    struct symrec* l = (struct symrec*)malloc(sizeof(struct symrec)*32);
    struct symtab* table = (struct symtab*)malloc(sizeof(struct symtab));
    table->parent = parent;
    table->row = l;
    table->lineno = lineno;
    table->scope = scope;
    table->rowmax = 32;
    return table;
}

void insertRow(symtab* tab, int rownum, astnode* node, char* ident, SYM_TYPE symtype, int complete, NAMESPACE_TYPE ns, SCOPE_TYPE sc, int lineno, int bits) {
    if (tab->rownum == tab->rowmax) {
        tab->row = realloc(tab->row,sizeof(struct symrec)*(rownum*2));
        tab->rowmax = rownum*2;
    }
    symrec* rec = &(tab->row[rownum]);
    rec->ident = ident;
    rec->symtype = symtype;
    rec->lineno = lineno;
    rec->complete = complete;
    rec->type = node ? node->list : NULL;
    rec->namespace = ns;
    rec->scope = sc;
    rec->parent = tab;
    if (tab->parent) {
        symtab* h = tab;
        while(h->parent->parent) {
            h = h->parent;
        }
        if (ns == NAMESPACE_OTHERS && symtype == SYM_VAR)
        rec->index = h->localtotal;

    }
    if (node) node->tbl = tab;
}

symrec* findsym(symtab* t, char* c, NAMESPACE_TYPE ns) {
    symtab* cur = t;
    while (cur) {
        for(int i=0;i<cur->rownum;i++){
            if ((cur->row)[i].namespace == ns && (cur->row)[i].ident && strcmp(c,(cur->row)[i].ident) == 0) {
                return &((cur->row)[i]);
            }
        }
        cur = cur->parent;
    }
    return NULL;
}

symrec* findsym_obj(symtab* t, char* c, NAMESPACE_TYPE ns) {
    symtab* cur = t;
    while (cur) {
        for(int i=0;i<cur->rownum;i++){
            if ((cur->row)[i].namespace == ns && (cur->row)[i].ident && strcmp(c,(cur->row)[i].ident) == 0) {
                return &((cur->row)[i]);
            }
        }
        if (cur->scope == SCOPE_OBJ) cur = cur->parent;
        else break;
    }
    return NULL;
}

symrec* findsym_nonrecursive(symtab* t, char* c, NAMESPACE_TYPE ns) {
    symtab* cur = t;
    for(int i=0;i<t->rownum;i++){
        if ((cur->row)[i].namespace == ns && (cur->row)[i].ident && strcmp(c,(cur->row)[i].ident) == 0) {
            return &((cur->row)[i]);
        }
    }
    return NULL;
}

struct symrec* insertFuncDef(struct symtab* table, struct astnode* data, int lineno){
    symrec* r = findsym_nonrecursive(table,data->funcdef->ident->ident->name,NAMESPACE_OTHERS);
    if (r) table->rownum -= 1;
    struct symrec* rec = r ? r : &(table->row[table->rownum]);
    rec->ident = data->funcdef->ident->ident->name;
        rec->symtype = SYM_FUNC;
        rec->lineno = lineno;
        rec->complete = 1;
        rec->type = data->funcdef->type->decl->type->list;
        rec->namespace = NAMESPACE_OTHERS;
        rec->parent = table;
        data->tbl = table;
        table->rownum += 1;
    return rec;
}

struct symrec* insertDecl(struct symtab* table, struct astnode* data, int lineno){
    symrec* r = findsym_nonrecursive(table,data->decl->ident->ident->name,NAMESPACE_OTHERS);
    symtab* funct;
    int ind = r ? (r-table->row) : table->rownum;
    data->tbl = table;
    switch(data->decl->type->list->head->value->nodetype){
        case AST_FUNC:
        insertRow(table,ind,data->decl->type,data->decl->ident->ident->name,SYM_FUNC,SCOPE_FILE,NAMESPACE_OTHERS,0,lineno,0);
        break;
        case AST_FUNCDEF:
        insertRow(table,ind,data->funcdef->type,data->decl->ident->ident->name,SYM_FUNC,SCOPE_BLOCK,NAMESPACE_OTHERS,0,lineno,0);
        struct symtab* t = data->funcdef->stmt->tbl;
        insertDecls(t,data->funcdef->type,lineno);
        break;
        default:
        if (table->parent) {
            funct = table;
            while(funct->parent->parent) {
                funct = funct->parent;
            }
            funct->localtotal += 1;
        }
        insertRow(table,ind,data->decl->type,data->decl->ident->ident->name,SYM_VAR,SCOPE_BLOCK,NAMESPACE_OTHERS,1,lineno,0);
        break;
    }
    if (!r) table->rownum += 1;
    return table->row + ind;
}

void setPrototype(struct symtab* table){
    int a = table->rownum;
    int i=0;
    table->protototal = table->localtotal;
        table->localtotal = 0;
    for(;i<a;i++){
        symrec* rec = &table->row[i];
        rec->symtype = SYM_PROTOVAR;
    }
}

void setSymComplete(struct symtab* table, struct astnode* a) {
    char* c;
    struct astnode_list* t;
    NAMESPACE_TYPE ns = NAMESPACE_OTHERS;
    if (a->nodetype == AST_STRUCT ||a->nodetype == AST_UNION) {
        c = a->obj->tag->ident->name;
        ns = NAMESPACE_TAGS;
        t = a->obj->members->list;
    } else if (a->nodetype == AST_FUNC) {
        c = a->decl->ident->ident->name;
        t = a->decl->type->list;
    } else if (a->nodetype == AST_FUNCDEF) {
        c = a->funcdef->ident->ident->name;
        t = a->funcdef->type->list;
    }
    symrec* rec = findsym(table,c,ns);
    rec->complete = 1;
    rec->type = t;
    a->tbl = table;
}

struct symrec* _insertStrun(struct symtab* table, struct astnode* obj, int lineno, int complete){
    symrec* r = obj->obj->tag ? findsym_obj(table,obj->obj->tag->ident->name,NAMESPACE_TAGS) : NULL;
    obj->tbl = table;
    if (r != NULL && r->complete) return r;
    while (table->scope == SCOPE_OBJ) table = table->parent;
    int ind = r ? r-table->row : table->rownum;
    insertRow(table,ind,obj->obj->members,obj->obj->tag ? obj->obj->tag->ident->name : NULL,
    SYM_TAG,complete,NAMESPACE_TAGS,0,lineno,0);
    if (!r) table->rownum += 1;
    return table->row+ind;
}

struct symrec* insertStrun(struct symtab* table, struct astnode* obj, int lineno){
    return _insertStrun(table,obj,lineno,0);
}
struct symrec* insertStrunComplete(struct symtab* table, struct astnode* obj, int lineno){
    return _insertStrun(table,obj,lineno,1);
}


struct symrec* insertDecls(struct symtab* table, struct astnode* data, int lineno){
    astnode_listnode* c = data->list->head;
    while(c){
        insertDecl(table,c->value,lineno);
        c->value->tbl = table;
        c = c->next;
    }
}

struct symrec* insertMember(struct symtab* table, struct astnode* data_, int lineno){
    symrec* r = data_->member->decl->decl->ident ? 
    findsym_nonrecursive(table,data_->member->decl->decl->ident->ident->name,NAMESPACE_OTHERS) : NULL;
    int ind = r ? r - table->row : table->rownum;
    data_->decl->type->tbl = table;
    insertRow(table,ind,data_->member->decl->decl->type,data_->member->decl->decl->ident ? data_->member->decl->decl->ident->ident->name : NULL,
    SYM_TAG,1,NAMESPACE_OTHERS,1,lineno,data_->member->bits);
    if(!r) table->rownum += 1;
    return table->row + ind;
}

void insertMembers(struct symtab* table, struct astnode* data, int lineno){
    astnode_listnode* c = data->list->head;
    while(c){
        insertMember(table,c->value,lineno);
        c = c->next;
    }
}

void insertLabel(symtab* table, astnode* data, int lineno) {
    //inserting the symbol either at the file scope, or the outermost block scope (for function scope)
    while(table->parent && table->parent->scope != SCOPE_FILE) table = table->parent;
    symrec* r = findsym_nonrecursive(table,data->binop->left->ident->name,NAMESPACE_LABELS);
    int ind = r ? (r-table->row) : table->rownum;
    data->tbl = table;
    insertRow(table,ind,data->binop->right,data->binop->left->ident->name,SYM_LABEL,1,NAMESPACE_LABELS,0,lineno,0);
    if (!r) table->rownum += 1;
    return table->row + ind;
}
