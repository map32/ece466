#include "helpers.h"
#include "parsing.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ERROR* getError(int lineno, char* text) {
    ERROR* e = (ERROR*) malloc(sizeof(ERROR));
    e->lineno=lineno;
    e->text=text;
    return e;
}

char* gettoken(int t) {
    char a[] = " ";
    switch(t) {
        case AUTO:
        return "AUTO";
        break;
        case BREAK:
        return "BREAK";
        break;
        case CASE:
        return "CASE";
        break;
        case CHAR:
        return "CHAR";
        break;
        case CONST:
        return "CONST";
        break;
        case CONTINUE:
        return "CONTINUE";
        break;
        case DEFAULT:
        return "DEFAULT";
        break;
        case DO:
        return "DO";
        break;
        case DOUBLE:
        return "DOUBLE";
        break;
        case ELSE:
        return "ELSE";
        break;
        case ENUM:
        return "ENUM";
        break;
        case EXTERN:
        return "EXTERN";
        break;
        case FLOAT:
        return "FLOAT";
        break;
        case FOR:
        return "FOR";
        break;
        case GOTO:
        return "GOTO";
        break;
        case IF:
        return "IF";
        break;
        case INT:
        return "INT";
        break;
        case LONG:
        return "LONG";
        break;
        case REGISTER:
        return "REGISTER";
        break;
        case RETURN:
        return "RETURN";
        break;
        case SHORT:
        return "SHORT";
        break;
        case SIGNED:
        return "SIGNED";
        break;
        case SIZEOF:
        return "SIZEOF";
        break;
        case STATIC:
        return "STATIC";
        break;
        case STRUCT:
        return "STRUCT";
        break;
        case SWITCH:
        return "SWITCH";
        break;
        case TYPEDEF:
        return "TYPEDEF";
        break;
        case UNION:
        return "UNION";
        break;
        case UNSIGNED:
        return "UNSIGNED";
        break;
        case VOID:
        return "VOID";
        break;
        case VOLATILE:
        return "VOLATILE";
        break;
        case WHILE:
        return "WHILE";
        break;
        case BOOL:
        return "BOOL";
        break;
        case COMPLEX:
        return "COMPLEX";
        break;
        case IMAGINARY:
        return "IMAGINARY";
        break;
        case LE:
        return "LE";
        break;
        case GE:
        return "GE";
        break;
        case EQ:
        return "EQ";
        break;
        case NE:
        return "NE";
        break;
        case OR:
        return "OR";
        break;
        case AND:
        return "AND";
        break;
        case INC:
        return "INC";
        break;
        case PREINC:
        return "PREINC";
        break;
        case POSTINC:
        return "POSTINC";
        break;
        case DEC:
        return "DEC";
        break;
        case PREDEC:
        return "PREDEC";
        break;
        case POSTDEC:
        return "POSTDEC";
        break;
        case ARROW:
        return "ARROW";
        break;
        case RSHIFT:
        return "RSHIFT";
        break;
        case LSHIFT:
        return "LSHIFT";
        break;
        case NUM:
        return "NUM";
        break;
        case NUMF:
        return "NUMF";
        break;
        case CH:
        return "CH";
        break;
        case STR:
        return "STR";
        break;
        case ID:
        return "ID";
        break;
        case INLINE:
        return "INLINE";
        break;
        case RESTRICT:
        return "RESTRICT";
        break;
        case ELLIPSIS:
        return "ELLIPSIS";
        break;
        case MODEQ:
        return "MODEQ";
        break;
        case LSHIFTEQ:
        return "LSHIFTEQ";
        break;
        case RSHIFTEQ:
        return "RSHIFTEQ";
        break;
        case PLUSEQ:
        return "PLUSEQ";
        break;
        case MINUSEQ:
        return "MINUSEQ";
        break;
        case DIVEQ:
        return "DIVEQ";
        break;
        case TIMESEQ:
        return "TIMESEQ";
        break;
        case XOREQ:
        return "XOREQ";
        break;
        case OREQ:
        return "OREQ";
        break;
        case ANDEQ:
        return "ANDEQ";
        break;
        case 0:
        return "NULL";
        default:
        return "(UNKNOWN TOKEN)";
    }
}

void printchar(unsigned char c) {
    //printf("[%d]",c);
    if(c>=' ' && c <='~'){
        printf("%c",c);
        return;
    }
    switch (c) {
        case '\a':
        printf("\\a");
        break;
        case '\b':
        printf("\\b");
        break;
        case '\f':
        printf("\\f");
        break;
        case '\n':
        printf("\\n");
        break;
        case '\r':
        printf("\\r");
        break;
        case '\t':
        printf("\\t");
        break;
        case '\v':
        printf("\\v");
        break;
        default:
        printf("\\%o%o%o",c/64,(c%64)/8,c%8);
    }
}

void printtokens(int t,char* filename, int yylineno, YYSTYPE value){
    if (t<256)
        printf("%s  %d  %c      ",filename,yylineno,t);
        else
        printf("%s  %d  %s      ",filename,yylineno,gettoken(t));
            if (t==CH || t==STR || t==ID){
                int l = strlen(value.s.c);
                int k;
                for(k=0;k<l;k++){
                    printchar((value.s.c)[k]);
                }
                printf("\n");
            } else if (t==NUM && value.n.type == 1) {
                printf("%lld\n",value.n.i);

            }  else if (t==NUM && value.n.type == 0) {
                printf("%llu\n",value.n.u);
            }   else if (t==NUMF){
                printf("%Lf\n",(value.n.f));
            } else
                printf("\n");
}