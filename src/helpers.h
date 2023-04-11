#include "parsing.tab.h"

typedef struct ERROR {
    int lineno;
    char* text;
} ERROR;

char* gettoken(int);
void printchar(unsigned char);
void printtokens(int,char*,int,YYSTYPE);
ERROR* getError(int,char*);