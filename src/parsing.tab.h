/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSING_TAB_H_INCLUDED
# define YY_YY_PARSING_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUSEQ = 258,                  /* PLUSEQ  */
    MINUSEQ = 259,                 /* MINUSEQ  */
    TIMESEQ = 260,                 /* TIMESEQ  */
    DIVEQ = 261,                   /* DIVEQ  */
    MODEQ = 262,                   /* MODEQ  */
    ANDEQ = 263,                   /* ANDEQ  */
    XOREQ = 264,                   /* XOREQ  */
    OREQ = 265,                    /* OREQ  */
    LSHIFTEQ = 266,                /* LSHIFTEQ  */
    RSHIFTEQ = 267,                /* RSHIFTEQ  */
    OR = 268,                      /* OR  */
    AND = 269,                     /* AND  */
    EQ = 270,                      /* EQ  */
    NE = 271,                      /* NE  */
    LE = 272,                      /* LE  */
    GE = 273,                      /* GE  */
    LSHIFT = 274,                  /* LSHIFT  */
    RSHIFT = 275,                  /* RSHIFT  */
    PREINC = 276,                  /* PREINC  */
    PREDEC = 277,                  /* PREDEC  */
    UPLUS = 278,                   /* UPLUS  */
    UMINUS = 279,                  /* UMINUS  */
    DEREF = 280,                   /* DEREF  */
    ADDR = 281,                    /* ADDR  */
    SIZEOF = 282,                  /* SIZEOF  */
    CAST = 283,                    /* CAST  */
    ARROW = 284,                   /* ARROW  */
    POSTINC = 285,                 /* POSTINC  */
    POSTDEC = 286,                 /* POSTDEC  */
    AUTO = 287,                    /* AUTO  */
    BREAK = 288,                   /* BREAK  */
    CASE = 289,                    /* CASE  */
    CHAR = 290,                    /* CHAR  */
    CONST = 291,                   /* CONST  */
    CONTINUE = 292,                /* CONTINUE  */
    DEFAULT = 293,                 /* DEFAULT  */
    DO = 294,                      /* DO  */
    DOUBLE = 295,                  /* DOUBLE  */
    ELSE = 296,                    /* ELSE  */
    ENUM = 297,                    /* ENUM  */
    EXTERN = 298,                  /* EXTERN  */
    FLOAT = 299,                   /* FLOAT  */
    FOR = 300,                     /* FOR  */
    GOTO = 301,                    /* GOTO  */
    IF = 302,                      /* IF  */
    INT = 303,                     /* INT  */
    LONG = 304,                    /* LONG  */
    REGISTER = 305,                /* REGISTER  */
    RETURN = 306,                  /* RETURN  */
    SHORT = 307,                   /* SHORT  */
    SIGNED = 308,                  /* SIGNED  */
    STATIC = 309,                  /* STATIC  */
    STRUCT = 310,                  /* STRUCT  */
    SWITCH = 311,                  /* SWITCH  */
    TYPEDEF = 312,                 /* TYPEDEF  */
    TYPENAME = 313,                /* TYPENAME  */
    UNION = 314,                   /* UNION  */
    UNSIGNED = 315,                /* UNSIGNED  */
    VOID = 316,                    /* VOID  */
    VOLATILE = 317,                /* VOLATILE  */
    WHILE = 318,                   /* WHILE  */
    BOOL = 319,                    /* BOOL  */
    COMPLEX = 320,                 /* COMPLEX  */
    IMAGINARY = 321,               /* IMAGINARY  */
    INC = 322,                     /* INC  */
    DEC = 323,                     /* DEC  */
    BOGUS = 324,                   /* BOGUS  */
    NUM = 325,                     /* NUM  */
    NUMF = 326,                    /* NUMF  */
    CH = 327,                      /* CH  */
    STR = 328,                     /* STR  */
    ID = 329,                      /* ID  */
    INLINE = 330,                  /* INLINE  */
    RESTRICT = 331,                /* RESTRICT  */
    ELLIPSIS = 332                 /* ELLIPSIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parsing.y"

  struct astnode *astnode;
  struct s {
    unsigned int l;
    unsigned char* c;
} s;
  struct n {
	int type;
	union {
		unsigned long long int u;
		long long int i;
		long double f;
	};
  } n;
  long long int i;

#line 158 "parsing.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSING_TAB_H_INCLUDED  */
