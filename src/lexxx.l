%option noyywrap
%{
    #include "lexx.h"
    char cbuf = 0;
    string_buf sbuf;
    int sptr = 0;
    int append(string_buf,unsigned char,int);
    void printchar(unsigned char);
    char* gettoken(int);
%}
ident [_a-zA-Z]
digit [0-9]
nonzero [1-9]
octal [0-7]
hex [0-9a-fA-F]
intsuffix ([uU][lL]?)|([uU](ll|LL)?)|([lL][uU]?)|((ll|LL)[uU]?)
exp ([eE][+-]?[0-9]+)
bexp ([Pp][+-]?[0-9]+)
floatsuffix [flFL]
%x SINGLEQ
%x DOUBLEQ
%%
[ \t] ;
(\n|\r|\r\n) { yylineno = yylineno + 1;}
"auto" return AUTO;
"break" return BREAK;
"case" return CASE;
"char" return CHAR;
"const" return CONST;
"continue" return CONTINUE;
"default" return DEFAULT;
"do" return DO;
"double" return DOUBLE;
"else" return ELSE;
"enum" return ENUM;
"extern" return EXTERN;
"float" return FLOAT;
"for" return FOR;
"goto" return GOTO;
"if" return IF;
"inline" return INLINE;
"int" return INT;
"long" return LONG;
"register" return REGISTER;
"restrict" return RESTRICT;
"return" return RETURN;
"short" return SHORT;
"signed" return SIGNED;
"sizeof" return SIZEOF;
"static" return STATIC;
"struct" return STRUCT;
"switch" return SWITCH;
"typedef" return TYPEDEF;
"union" return UNION;
"unsigned" return UNSIGNED;
"void" return VOID;
"volatile" return VOLATILE;
"while" return WHILE;
"_Bool" return BOOL;
"_Complex" return COMPLEX;
"_Imaginary" return IMAGINARY;
({nonzero}{digit}*{intsuffix}?)|(0{intsuffix}?) {yylval.i = strtoull(yytext,NULL,10); return NUM;}
0{octal}+{intsuffix}? {yylval.i = strtoull(yytext,NULL,8); return NUM;}
0(x|X){hex}+{intsuffix}? {yylval.i = strtoull(yytext,NULL,16); return NUM;}
((({digit}*\.{digit}+)|({digit}+\.)){exp}?{floatsuffix}?)|({digit}+{exp}{floatsuffix}?) {
    yylval.d = strtold(yytext,NULL); return NUMF;}
0(x|X)(((({hex}*\.{hex}+)|({hex}+\.)){bexp}?{floatsuffix}?)|({hex}+{bexp}{floatsuffix}?)) {
    sscanf(yytext,"%LA",&(yylval.d)); return NUMF;}
L?'' fprintf(stderr,"error: line %d: char is empty",yylineno);
L?' {
    BEGIN(SINGLEQ);
}
<SINGLEQ>' {
    unsigned char *p;
    p=(char*)calloc(3,sizeof(char));
    if (cbuf == 0){
        p[0]='\\';
        p[1]='0';
    } else p[0] = cbuf;
    cbuf = 0;
    yylval.s = p;
    BEGIN(0);
    return CH;}
<SINGLEQ>[^\\\n']+ {if (!cbuf) cbuf = yytext[0];}
<SINGLEQ>\n fprintf(stderr,"error: line %d: newline not allowed inside char\n",yylineno);
<SINGLEQ>"\\a" {if (!cbuf) cbuf = '\a';}
<SINGLEQ>"\\b" {if (!cbuf) cbuf = '\b';} 
<SINGLEQ>"\\f" {if (!cbuf) cbuf = '\f';}
<SINGLEQ>"\\n" {if (!cbuf) cbuf = '\n';}
<SINGLEQ>"\\r" {if (!cbuf) cbuf = '\r';}
<SINGLEQ>"\\t" {if (!cbuf) cbuf = '\t';}
<SINGLEQ>"\\v" {if (!cbuf) cbuf = '\v';}
<SINGLEQ>"\\'" {if (!cbuf) cbuf = '\'';}
<SINGLEQ>"\\\"" {if (!cbuf) cbuf = '"';}
<SINGLEQ>"\\\?" {if (!cbuf) cbuf = '\?';}
<SINGLEQ>\\{octal}{1,3} {
    if (!cbuf){
        int result;
        sscanf(yytext+1,"%o",&result);
        if (result > 255)
            fprintf(stderr,"warning: line %d: octal constant value %o is too big\n",yylineno,result);
        result = result % 256;
        cbuf = result;
    }
}
<SINGLEQ>\\[xX]{hex}+ {
    if (!cbuf){
        int result;
        sscanf(yytext+2,"%x",&result);
        if (result > 255)
            fprintf(stderr,"warning: line %d: hex constant value %x is too big\n",yylineno,result);
        result = result % 256;
        cbuf = result;
    }
}
<SINGLEQ>"\\\\" {if (!cbuf) cbuf = '\\';} 

L?\" {BEGIN(DOUBLEQ);
    sbuf.len = 4096;
    sbuf.buf = (char *)calloc(4096,sizeof(char));
    sptr = 0;
    //printf("strenter\n");
}
<DOUBLEQ>\" {
    //printf("strexit\n");
    unsigned char *p;
    p=(char*)calloc(sptr,sizeof(char));
    strcpy(p,sbuf.buf);
    free(sbuf.buf);
    yylval.s = p;
    BEGIN(0);
    return STR;}
<DOUBLEQ>[^\\\n\"]+ {
    int l = strlen(yytext);
    //printf("%s general\n",yytext);
    int j;
    for(j=0;j<l;j++)
        sptr = append(sbuf, yytext[j], sptr);
}
<DOUBLEQ>\n fprintf(stderr,"error: line %d: newline not allowed inside string\n",yylineno);
<DOUBLEQ>"\\a" sptr = append(sbuf,'\a',sptr);
<DOUBLEQ>"\\b" sptr = append(sbuf,'\b',sptr);
<DOUBLEQ>"\\f" sptr = append(sbuf,'\f',sptr);
<DOUBLEQ>"\\n" sptr = append(sbuf,'\n',sptr);
<DOUBLEQ>"\\r" sptr = append(sbuf,'\r',sptr);
<DOUBLEQ>"\\t" sptr = append(sbuf,'\t',sptr);
<DOUBLEQ>"\\v" sptr = append(sbuf,'\v',sptr);
<DOUBLEQ>"\\'" {sptr = append(sbuf,'\'',sptr);}
<DOUBLEQ>"\\\"" {sptr = append(sbuf,'\"',sptr);}
<DOUBLEQ>"\\\?" sptr = append(sbuf,'\?',sptr);
<DOUBLEQ>\\[0-7]{1,3} {
        int result;
        sscanf(yytext+1,"%o",&result);
        //printf("%d oct->dec\n",result);
        if (result > 255)
            fprintf(stderr,"warning %d: octal constant value %o is too big\n",yylineno,result);
        result = result % 256;
        if(result==0){
            sptr = append(sbuf,'\\',sptr);
            sptr = append(sbuf,'0',sptr);
        } else
        sptr = append(sbuf,result,sptr);
    }
<DOUBLEQ>\\[xX]{hex}+ {
        int result;
        sscanf(yytext+2,"%x",&result);
        //printf("%d hex->dec\n",result);
        if (result > 255)
            fprintf(stderr,"warning: line %d: hex constant value %x is too big\n",yylineno,result);
        result = result % 256;
        if(result==0){
            sptr = append(sbuf,'\\',sptr);
            sptr = append(sbuf,'0',sptr);
        } else
        sptr = append(sbuf,result,sptr);
}
<DOUBLEQ>"\\\\" {sptr = append(sbuf,'\\',sptr);}

{ident}({ident}|{digit})* {
    char* p;
    p=(char *)calloc(strlen(yytext)+1,sizeof(char));
    strcpy(p,yytext);
    yylval.s = p;
    return ID;
}
"="     return '=';
"<="    return LE;
">="    return GE;
"=="    return EQ;
"!="    return NE;
"%="    return MODEQ;
"+="    return PLUSEQ;
"-="    return MINUSEQ;
"*="    return TIMESEQ;
"/="    return DIVEQ;
"^="    return XOREQ;
"|="    return OREQ;
"&="    return ANDEQ;
"<<="   return LSHIFTEQ;
">>="   return RSHIFTEQ;
">"	return '>';
"<"	return '<';
"||" 	return OR;
"&&"  	return AND;
"|" 	return '|';
"&"	return '&';
"\^"	return '^';
"[" return '[';
"]" return ']';
"(" return '(';
")" return ')';
"{" return '{';
"}" return '}';
"," return ',';
"\+\+" return INC;
"\." return '.';
"--" return DEC;
"->" return ARROW;
">>" return RSHIFT;
"<<" return LSHIFT;
"\+" return '+';
"-" return '-';
"\*" return '*';
"/" return '/';
"%" return '%';
"~" return '~';
"!" return '!';
"\?" return '?';
";" return ';';
":" return ':';
"\.\.\." return ELLIPSIS;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
. fprintf(stderr,"error: invalid token: %s\n",yytext);
%%
