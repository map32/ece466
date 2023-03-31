#include "symtab.h"
#include <stdlib.h>

struct symtab* createTable(struct symtab* parent) {
    struct symrec* l = (struct symrec*)malloc(sizeof(struct symrec)*32);
    struct symtab* table = (struct symtab*)malloc(sizeof(struct symtab));
    if (parent) {
        table->children = (struct symtab**)malloc(sizeof(struct symtab*)*32);
        (table->parent->children)[table->parent->childnum] = table;
        table->parent->childnum += 1;
    }
    return table;
}