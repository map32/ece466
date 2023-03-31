/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parsing.y"

#include <stdio.h>
#include "ast.h"
#include "symtab.h"
#include "helpers.h"
#include <string.h>
struct astnode *root;
extern int yylex();
extern int yyerror(char*);
extern int yylineno;

#line 83 "parsing.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
#line 14 "parsing.y"

  struct astnode *astnode;
  struct astnode_stmts *astnode_stmt;
  struct s {
    unsigned int l;
    unsigned char* c;
} s;
  unsigned long long int i;
  long double d;

#line 218 "parsing.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* ','  */
  YYSYMBOL_4_ = 4,                         /* '='  */
  YYSYMBOL_PLUSEQ = 5,                     /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 6,                    /* MINUSEQ  */
  YYSYMBOL_TIMESEQ = 7,                    /* TIMESEQ  */
  YYSYMBOL_DIVEQ = 8,                      /* DIVEQ  */
  YYSYMBOL_MODEQ = 9,                      /* MODEQ  */
  YYSYMBOL_ANDEQ = 10,                     /* ANDEQ  */
  YYSYMBOL_XOREQ = 11,                     /* XOREQ  */
  YYSYMBOL_OREQ = 12,                      /* OREQ  */
  YYSYMBOL_LSHIFTEQ = 13,                  /* LSHIFTEQ  */
  YYSYMBOL_RSHIFTEQ = 14,                  /* RSHIFTEQ  */
  YYSYMBOL_15_ = 15,                       /* '?'  */
  YYSYMBOL_16_ = 16,                       /* ':'  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_19_ = 19,                       /* '|'  */
  YYSYMBOL_20_ = 20,                       /* '^'  */
  YYSYMBOL_21_ = 21,                       /* '&'  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '<'  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_LSHIFT = 28,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 29,                    /* RSHIFT  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_PREINC = 35,                    /* PREINC  */
  YYSYMBOL_PREDEC = 36,                    /* PREDEC  */
  YYSYMBOL_UPLUS = 37,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_39_ = 39,                       /* '!'  */
  YYSYMBOL_40_ = 40,                       /* '~'  */
  YYSYMBOL_DEREF = 41,                     /* DEREF  */
  YYSYMBOL_ADDR = 42,                      /* ADDR  */
  YYSYMBOL_SIZEOF = 43,                    /* SIZEOF  */
  YYSYMBOL_CAST = 44,                      /* CAST  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_ARROW = 50,                     /* ARROW  */
  YYSYMBOL_POSTINC = 51,                   /* POSTINC  */
  YYSYMBOL_POSTDEC = 52,                   /* POSTDEC  */
  YYSYMBOL_AUTO = 53,                      /* AUTO  */
  YYSYMBOL_BREAK = 54,                     /* BREAK  */
  YYSYMBOL_CASE = 55,                      /* CASE  */
  YYSYMBOL_CHAR = 56,                      /* CHAR  */
  YYSYMBOL_CONST = 57,                     /* CONST  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 59,                   /* DEFAULT  */
  YYSYMBOL_DO = 60,                        /* DO  */
  YYSYMBOL_DOUBLE = 61,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 62,                      /* ELSE  */
  YYSYMBOL_ENUM = 63,                      /* ENUM  */
  YYSYMBOL_EXTERN = 64,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_FOR = 66,                       /* FOR  */
  YYSYMBOL_GOTO = 67,                      /* GOTO  */
  YYSYMBOL_IF = 68,                        /* IF  */
  YYSYMBOL_INT = 69,                       /* INT  */
  YYSYMBOL_LONG = 70,                      /* LONG  */
  YYSYMBOL_REGISTER = 71,                  /* REGISTER  */
  YYSYMBOL_RETURN = 72,                    /* RETURN  */
  YYSYMBOL_SHORT = 73,                     /* SHORT  */
  YYSYMBOL_SIGNED = 74,                    /* SIGNED  */
  YYSYMBOL_STATIC = 75,                    /* STATIC  */
  YYSYMBOL_STRUCT = 76,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 77,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 78,                   /* TYPEDEF  */
  YYSYMBOL_TYPENAME = 79,                  /* TYPENAME  */
  YYSYMBOL_UNION = 80,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 81,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 82,                      /* VOID  */
  YYSYMBOL_VOLATILE = 83,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 84,                     /* WHILE  */
  YYSYMBOL_BOOL = 85,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 86,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 87,                 /* IMAGINARY  */
  YYSYMBOL_INC = 88,                       /* INC  */
  YYSYMBOL_DEC = 89,                       /* DEC  */
  YYSYMBOL_BOGUS = 90,                     /* BOGUS  */
  YYSYMBOL_NUM = 91,                       /* NUM  */
  YYSYMBOL_NUMF = 92,                      /* NUMF  */
  YYSYMBOL_CH = 93,                        /* CH  */
  YYSYMBOL_STR = 94,                       /* STR  */
  YYSYMBOL_ID = 95,                        /* ID  */
  YYSYMBOL_INLINE = 96,                    /* INLINE  */
  YYSYMBOL_RESTRICT = 97,                  /* RESTRICT  */
  YYSYMBOL_ELLIPSIS = 98,                  /* ELLIPSIS  */
  YYSYMBOL_99_ = 99,                       /* '{'  */
  YYSYMBOL_100_ = 100,                     /* '}'  */
  YYSYMBOL_101_ = 101,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_program = 103,                  /* program  */
  YYSYMBOL_pexp = 104,                     /* pexp  */
  YYSYMBOL_number = 105,                   /* number  */
  YYSYMBOL_constant = 106,                 /* constant  */
  YYSYMBOL_postexp = 107,                  /* postexp  */
  YYSYMBOL_unary = 108,                    /* unary  */
  YYSYMBOL_uop = 109,                      /* uop  */
  YYSYMBOL_castexp = 110,                  /* castexp  */
  YYSYMBOL_binary = 111,                   /* binary  */
  YYSYMBOL_ternary = 112,                  /* ternary  */
  YYSYMBOL_aop = 113,                      /* aop  */
  YYSYMBOL_exp = 114,                      /* exp  */
  YYSYMBOL_aexp = 115,                     /* aexp  */
  YYSYMBOL_decl = 116,                     /* decl  */
  YYSYMBOL_declspec = 117,                 /* declspec  */
  YYSYMBOL_initdecllist = 118,             /* initdecllist  */
  YYSYMBOL_initdeclr = 119,                /* initdeclr  */
  YYSYMBOL_storage_class_specifier = 120,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 121,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 122, /* struct_or_union_specifier  */
  YYSYMBOL_strun = 123,                    /* strun  */
  YYSYMBOL_struct_declaration_list = 124,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 125,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 126, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 127,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 128,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 129,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 130,          /* enumerator_list  */
  YYSYMBOL_enumerator = 131,               /* enumerator  */
  YYSYMBOL_type_qualifier = 132,           /* type_qualifier  */
  YYSYMBOL_declr = 133,                    /* declr  */
  YYSYMBOL_direct_declarator = 134,        /* direct_declarator  */
  YYSYMBOL_pointer = 135,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 136,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 137,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 138,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 139,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 140,          /* identifier_list  */
  YYSYMBOL_type_name = 141,                /* type_name  */
  YYSYMBOL_abstract_declarator = 142,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 143, /* direct_abstract_declarator  */
  YYSYMBOL_init = 144,                     /* init  */
  YYSYMBOL_initlist = 145,                 /* initlist  */
  YYSYMBOL_designation = 146,              /* designation  */
  YYSYMBOL_designator_list = 147,          /* designator_list  */
  YYSYMBOL_designator = 148,               /* designator  */
  YYSYMBOL_stmt = 149,                     /* stmt  */
  YYSYMBOL_labelstmt = 150,                /* labelstmt  */
  YYSYMBOL_exps = 151,                     /* exps  */
  YYSYMBOL_compoundstmt = 152,             /* compoundstmt  */
  YYSYMBOL_block_item_list = 153,          /* block_item_list  */
  YYSYMBOL_block_item = 154,               /* block_item  */
  YYSYMBOL_selects = 155,                  /* selects  */
  YYSYMBOL_iters = 156,                    /* iters  */
  YYSYMBOL_jmps = 157,                     /* jmps  */
  YYSYMBOL_translation_unit = 158,         /* translation_unit  */
  YYSYMBOL_external_declaration = 159,     /* external_declaration  */
  YYSYMBOL_funcdef = 160,                  /* funcdef  */
  YYSYMBOL_declaration_list = 161          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,    34,    21,     2,
      45,    46,    32,    30,     3,    31,    49,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,   101,
      25,     4,    24,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,    19,   100,    40,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    17,    18,
      22,    23,    26,    27,    28,    29,    35,    36,    37,    38,
      41,    42,    43,    44,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   104,   105,   106,   107,   110,   111,   114,
     115,   118,   119,   120,   121,   122,   123,   124,   125,   129,
     130,   131,   132,   133,   134,   137,   138,   139,   140,   141,
     142,   145,   146,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   171,   172,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   188,   189,   192,   193,   197,
     198,   202,   203,   208,   209,   214,   215,   219,   220,   224,
     225,   229,   230,   234,   235,   236,   237,   238,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   259,   260,   261,   263,   264,   268,   269,   273,
     277,   278,   279,   283,   290,   291,   295,   296,   297,   301,
     302,   303,   304,   305,   309,   310,   314,   315,   319,   320,
     321,   325,   326,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   346,   347,   348,   349,
     353,   354,   359,   360,   364,   365,   369,   370,   374,   375,
     379,   380,   384,   385,   386,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   404,   405,   406,   410,
     411,   412,   413,   416,   420,   421,   425,   426,   430,   431,
     432,   433,   434,   435,   439,   440,   441,   444,   445,   449,
     450,   454,   455,   459,   460,   465,   466,   467,   471,   472,
     473,   475,   480,   481,   482,   483,   484,   488,   489,   493,
     494,   498,   499,   505,   506
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "','", "'='", "PLUSEQ",
  "MINUSEQ", "TIMESEQ", "DIVEQ", "MODEQ", "ANDEQ", "XOREQ", "OREQ",
  "LSHIFTEQ", "RSHIFTEQ", "'?'", "':'", "OR", "AND", "'|'", "'^'", "'&'",
  "EQ", "NE", "'>'", "'<'", "LE", "GE", "LSHIFT", "RSHIFT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "PREINC", "PREDEC", "UPLUS", "UMINUS", "'!'", "'~'",
  "DEREF", "ADDR", "SIZEOF", "CAST", "'('", "')'", "'['", "']'", "'.'",
  "ARROW", "POSTINC", "POSTDEC", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "TYPENAME", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "BOOL", "COMPLEX", "IMAGINARY",
  "INC", "DEC", "BOGUS", "NUM", "NUMF", "CH", "STR", "ID", "INLINE",
  "RESTRICT", "ELLIPSIS", "'{'", "'}'", "';'", "$accept", "program",
  "pexp", "number", "constant", "postexp", "unary", "uop", "castexp",
  "binary", "ternary", "aop", "exp", "aexp", "decl", "declspec",
  "initdecllist", "initdeclr", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "strun", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declr",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "init", "initlist", "designation",
  "designator_list", "designator", "stmt", "labelstmt", "exps",
  "compoundstmt", "block_item_list", "block_item", "selects", "iters",
  "jmps", "translation_unit", "external_declaration", "funcdef",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-211)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1301,  -211,  -211,  -211,  -211,    97,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  1301,  -211,    20,  -211,    33,  1301,  1301,
    -211,   146,  -211,  1301,  1301,  -211,  -211,   -63,   -33,  -211,
    -211,   133,    31,  -211,  -211,     6,  -211,   221,   202,   -35,
    -211,  -211,   -31,  1404,  -211,  -211,   -33,    70,    19,  -211,
    -211,  -211,   133,    53,    31,  -211,   601,   284,  -211,    33,
    -211,  1226,  1144,   757,   202,  1404,  1404,  1338,  -211,    38,
    1404,    21,   966,    93,  -211,  -211,  -211,  -211,  -211,    73,
    -211,  -211,  -211,  -211,  -211,  -211,   982,   667,  1048,  1048,
    -211,  -211,  -211,  -211,  -211,   570,  -211,  -211,  -211,   123,
     643,   966,  -211,   653,  -211,  -211,  -211,     5,   966,    62,
     153,   438,   152,    83,   160,   469,   165,   178,   208,  -211,
    -211,     9,  -211,  -211,  -211,  -211,  -211,  -211,   361,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,    35,   194,   240,
    -211,    13,   200,   777,   205,   736,  1371,  -211,  -211,  -211,
     966,    14,  -211,   234,  -211,    94,  -211,  -211,  -211,  -211,
    -211,   667,  -211,    29,    26,   218,   966,  -211,  -211,   966,
     163,  -211,    22,   601,    17,  -211,   846,   966,   167,   170,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   966,  -211,   966,   966,   966,   966,   966,
     966,   966,   966,   966,   966,   966,   966,   966,   966,   966,
     966,   966,   966,   966,  -211,   250,  -211,   438,   183,   504,
     174,   966,  -211,    15,   966,   966,   438,   966,  -211,  -211,
    -211,  1049,   863,  -211,    41,  -211,   212,  -211,  1263,   173,
    -211,  -211,   223,   777,  -211,   228,  -211,   966,   231,  -211,
    -211,    38,  -211,   966,  -211,   237,  -211,  1106,   216,  -211,
     966,   232,  -211,   535,  -211,  -211,  -211,  -211,  -211,    39,
      24,  -211,  -211,  -211,   161,  1502,  1518,  1533,  1547,  1560,
     935,   935,   203,   203,   203,   203,   187,   187,   181,   181,
    -211,  -211,  -211,   438,  -211,   242,   504,  -211,    45,  -211,
      49,    54,  -211,  -211,  -211,   243,   247,   260,  -211,   261,
     212,  1189,   883,  -211,  -211,  -211,  -211,   262,  -211,   263,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   601,  -211,
    -211,   966,  -211,   966,   949,   438,   438,   438,  -211,  -211,
    -211,  -211,  -211,   252,   264,  -211,   271,  -211,  -211,  -211,
    -211,   120,   438,   155,   226,  -211,  -211,  -211,  -211,  -211,
     220,  -211,   438,   438,  -211,  -211,  -211
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    89,   128,    94,     0,    84,    93,    91,    92,
      87,    90,    95,    85,   105,    83,   101,   106,    96,    88,
     129,    97,    98,    77,   130,     0,   220,     0,    71,    73,
      99,     0,   100,    75,     2,   217,   219,   123,     0,    78,
       1,   146,     0,   133,    69,     0,    79,    81,   132,     0,
      72,    74,   104,     0,    76,   218,     0,   126,     0,   124,
     150,   148,   147,     0,     0,    70,     0,     0,   223,     0,
     222,     0,     0,     0,   131,     0,   110,     0,   107,     0,
     111,     0,     0,     0,   119,   151,   149,   134,    80,    81,
      25,    27,    28,    26,    30,    29,     0,     0,     0,     0,
       7,     8,    10,     5,     3,     0,    11,     9,     4,    19,
      31,     0,    33,    52,    67,   176,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,   199,
     197,     0,    65,   203,   204,   188,   190,   189,     0,   201,
     191,   192,   193,   224,   221,   145,   158,     0,     0,   152,
     154,     0,    26,     0,     0,     0,     0,   112,   103,   108,
       0,     0,   114,   116,   113,     0,   120,    31,   127,   121,
     125,     0,    23,     0,   160,     0,     0,    20,    21,     0,
       0,   179,     0,     0,     0,   184,     0,     0,     0,     0,
      17,    18,    54,    55,    56,    57,    58,    59,    62,    63,
      64,    60,    61,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,   213,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,   198,   200,
     202,     0,     0,   156,   162,   157,   163,   143,     0,     0,
     144,   142,     0,     0,   136,    26,   137,     0,     0,   102,
     117,     0,   109,     0,   122,     0,     6,     0,   162,   161,
       0,     0,   187,     0,   177,   180,   183,   185,    13,     0,
       0,    15,    16,    68,     0,    51,    50,    49,    48,    47,
      46,    45,    42,    41,    43,    44,    39,    40,    37,    38,
      34,    35,    36,     0,   196,     0,     0,   212,     0,   216,
       0,     0,   194,    66,   172,     0,     0,    26,   166,     0,
     164,     0,     0,   153,   155,   159,   139,     0,   141,     0,
     135,   115,   118,    24,    32,   186,   178,   181,     0,    14,
      12,     0,   195,     0,     0,     0,     0,     0,   173,   165,
     170,   167,   174,     0,    26,   168,     0,   138,   140,   182,
      53,     0,     0,     0,   205,   207,   208,   175,   171,   169,
       0,   210,     0,     0,   209,   211,   206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,  -211,  -211,   -68,  -211,  -103,  1296,
     -81,  -211,   -74,   -66,   -18,   175,  -211,   258,  -211,   -42,
    -211,  -211,   251,   -62,   -36,  -211,    64,  -211,   272,   -38,
      28,   -23,   -44,   -15,   -60,   -70,  -211,    82,  -211,   162,
      32,   -88,   -99,  -211,    58,  -211,   148,  -118,  -211,  -210,
     115,  -211,   196,  -211,  -211,  -211,  -211,   301,  -211,  -211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   203,   131,   132,    26,   147,    45,    46,    28,    29,
      30,    31,    77,    78,    79,   161,   162,    32,    58,    59,
      33,    63,    48,    49,    62,   315,   149,   150,   151,   175,
     316,   246,   116,   182,   183,   184,   185,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    34,    35,    36,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     115,   168,   148,   228,    47,    74,   181,   154,   204,    64,
      42,    76,   237,   155,   167,   159,   249,   261,   237,   306,
      40,   276,    83,   173,   165,   273,    61,   237,   172,    68,
     177,   178,   237,    76,    76,    76,    56,   225,    76,   115,
     157,    89,   237,   167,   164,   170,    89,    86,   237,   133,
     167,   233,   237,   143,   160,    76,   163,   237,    41,   250,
      43,   174,    57,    41,   179,    41,   180,    41,    75,    60,
      41,   267,   340,   242,    82,   266,    42,    66,    42,   260,
     241,    80,   242,    42,   275,   339,   241,   252,   242,   258,
      85,   345,   167,   253,   159,   346,   344,   173,   271,    87,
     347,    60,   173,    80,    80,    80,   224,    65,    80,   304,
     238,   167,   279,   280,    76,   262,   309,   115,   312,    84,
     133,   166,   274,   237,   243,    80,    43,   170,    43,    76,
      43,   284,   244,    43,    44,   174,    43,   283,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   320,   308,   237,   268,
     310,   311,    70,   226,   237,    41,   370,   334,   186,   227,
     187,   313,   188,   189,   337,    27,   319,   341,   230,   245,
     320,    60,   332,    85,    80,   342,   144,   327,    57,    57,
       3,   329,    37,   169,   264,   167,    38,   229,    39,    80,
      74,   372,   167,    50,    51,   231,   269,   115,    54,    27,
     234,   190,   191,   221,   222,   223,    20,   219,   220,   221,
     222,   223,    69,   235,   236,    66,   244,   364,   365,   366,
      24,   217,   218,   219,   220,   221,   222,   223,   163,   359,
     247,    52,    69,   248,   371,    53,    69,    72,   251,    73,
     263,   353,   268,   254,   375,   376,   356,   321,   272,   322,
     360,   267,   281,   242,   270,   282,   303,   305,   325,   361,
     363,   326,   115,   167,     1,   307,   328,     2,     3,   330,
     335,    85,     4,   333,     5,     6,     7,   343,   373,   348,
       8,     9,    10,   349,    11,    12,    13,    14,   367,    15,
      16,    17,    18,    19,    20,    90,    21,    22,   350,   351,
     357,   358,   368,    69,    91,    92,    93,    23,    24,   369,
      67,   374,    88,    94,    95,   331,   156,    96,    81,    97,
     324,   338,   277,   265,   240,    55,     0,     1,   117,   118,
       2,     3,   119,   120,   121,     4,     0,     5,     6,     7,
     122,   123,   124,     8,     9,    10,   125,    11,    12,    13,
      14,   126,    15,    16,    17,    18,    19,    20,   127,    21,
      22,     0,    98,    99,     0,   100,   101,   102,   103,   128,
      23,    24,    90,    67,   129,   130,     0,     0,     0,     0,
       0,    91,    92,    93,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,    96,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     1,   117,   118,     2,     3,   119,
     120,   121,     4,     0,     5,     6,     7,   122,   123,   124,
       8,     9,    10,   125,    11,    12,    13,    14,   126,    15,
      16,    17,    18,    19,    20,   127,    21,    22,     0,    98,
      99,     0,   100,   101,   102,   103,   128,    23,    24,    90,
      67,   239,   130,     0,     0,     0,     0,     0,    91,    92,
      93,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,    96,     0,    97,     0,     0,     0,     0,     0,     0,
      90,     0,   117,   118,     0,     0,   119,   120,   121,    91,
      92,    93,     0,     0,   122,   123,   124,     0,    94,    95,
     125,     0,    96,     0,    97,   126,     0,     0,     0,     0,
       0,     0,   127,     0,     0,    90,    98,    99,     0,   100,
     101,   102,   103,   128,    91,    92,    93,    67,     0,   130,
       0,     0,     0,    94,    95,     0,     0,    96,     0,    97,
       0,     0,     0,     0,     0,     0,    90,    98,    99,     0,
     100,   101,   102,   103,   104,    91,    92,    93,     0,     0,
     232,     0,     0,     0,    94,    95,     0,     0,    96,     0,
      97,     0,   179,     0,   180,     0,     0,     0,     0,     0,
       0,    90,    98,    99,     0,   100,   101,   102,   103,   104,
      91,    92,    93,     0,     0,   130,     0,     0,     0,    94,
      95,     0,     0,    96,     0,    97,     0,   179,     0,   180,
       0,     0,    90,    98,    99,     0,   100,   101,   102,   103,
     104,    91,    92,    93,   105,   336,     0,     0,     0,     0,
      94,    95,     0,     0,    96,     0,    97,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    98,    99,
       0,   100,   101,   102,   103,   104,     0,     0,   205,   105,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    90,    98,
      99,     0,   100,   101,   102,   103,   104,    91,    92,    93,
     105,     0,     0,     0,     0,     0,    94,    95,     0,     0,
      96,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     7,     0,     0,     0,     8,     9,     0,     0,
      11,    12,     0,    14,     0,     0,    16,    17,    18,    19,
      20,     0,    21,    22,     0,    98,    99,    90,   100,   101,
     102,   103,   104,     0,    24,     0,    91,    92,   255,     0,
       0,     0,     0,     0,     0,    94,    95,     0,    90,    96,
       0,    97,     0,     0,   256,     0,     0,    91,    92,   152,
       0,     0,     0,     3,     0,     0,    94,    95,    90,     0,
      96,     0,    97,     0,     0,     0,     0,    91,    92,    93,
       0,   257,     0,     0,     3,     0,    94,    95,     0,    20,
      96,     0,    97,     0,    98,    99,     0,   100,   101,   102,
     103,   104,   153,    24,     3,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    98,    99,     0,   100,   101,
     102,   103,   104,     0,    24,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    98,    99,    90,   100,   101,
     102,   103,   104,     0,    24,     0,    91,    92,    93,     0,
       0,     0,     0,     0,    90,    94,    95,     0,     0,    96,
       0,    97,   278,    91,    92,   317,     0,     0,     0,     0,
       0,     0,    94,    95,    90,     0,    96,     0,    97,     0,
       0,   318,     0,    91,    92,   354,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,    96,     0,    97,     0,
       0,   355,     0,     0,    98,    99,     0,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,   100,   101,   102,   103,   104,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      90,    98,    99,     0,   100,   101,   102,   103,   104,    91,
      92,    93,     0,     0,     0,     0,     0,    90,    94,    95,
       0,     0,    96,     0,    97,   362,    91,    92,    93,     0,
       0,     0,     0,    90,     0,    94,    95,     0,     0,    96,
       0,    97,    91,    92,    93,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,    96,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,    90,
      98,    99,     0,   100,   101,   102,   103,   104,    91,    92,
      93,    41,     0,     0,     0,     0,     0,    94,    95,     0,
       0,    96,     0,   176,   241,   314,   242,     0,     0,     0,
       0,     0,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,     0,    11,    12,    13,    14,     0,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    98,    99,    41,   100,
     101,   102,   103,   104,    43,    23,    24,     0,     0,     0,
       0,   267,   314,   242,     0,     0,     0,     0,     0,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,     0,    11,
      12,    13,    14,     0,    15,    16,    17,    18,    19,    20,
     145,    21,    22,     0,     0,     0,     0,     1,     0,     0,
       2,     3,    23,    24,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,     0,    11,    12,    13,
      14,     0,    15,    16,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,     0,   352,     0,     0,     0,   146,
      23,    24,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,     0,    11,    12,    13,    14,     0,    15,    16,    17,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     1,
       0,     0,     2,     3,     0,    23,    24,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,     0,    11,
      12,    13,    14,     0,    15,    16,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     0,     1,     0,     0,     2,
       3,     0,    23,    24,     4,    67,     5,     6,     7,     0,
       0,     0,     8,     9,    10,     0,    11,    12,    13,    14,
       0,    15,    16,    17,    18,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     1,     0,     0,     2,     3,    23,
      24,   323,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,    12,    13,    14,     0,    15,
      16,    17,    18,    19,    20,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     2,     3,     0,    23,    24,     4,
       0,     5,     0,     7,     0,     0,     0,     8,     9,     0,
       0,    11,    12,     0,    14,     0,     0,    16,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,    24,     7,     0,   158,     0,
       8,     9,     0,     0,    11,    12,     0,    14,     0,     0,
      16,    17,    18,    19,    20,     0,    21,    22,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,    24,     7,
       0,   259,     0,     8,     9,     0,     0,    11,    12,     0,
      14,     0,     0,    16,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223
};

static const yytype_int16 yycheck[] =
{
      66,    82,    72,   121,    27,    49,   105,    73,   111,     3,
      45,    53,     3,    73,    82,    77,     3,     3,     3,   229,
       0,     4,     3,    97,     3,     3,    41,     3,    96,    47,
      98,    99,     3,    75,    76,    77,    99,   118,    80,   105,
      76,    64,     3,   111,    80,    83,    69,    62,     3,    67,
     118,   125,     3,    71,    16,    97,    79,     3,    32,    46,
      95,    97,    95,    32,    47,    32,    49,    32,    99,    41,
      32,    45,    48,    47,     4,    46,    45,     4,    45,   160,
      45,    53,    47,    45,   183,    46,    45,   153,    47,   155,
      62,    46,   160,   153,   156,    46,   306,   171,   179,    46,
      46,    73,   176,    75,    76,    77,   101,   101,    80,   227,
     101,   179,   186,   187,   156,   101,   101,   183,   236,   100,
     138,   100,   100,     3,   147,    97,    95,   165,    95,   171,
      95,   205,   147,    95,   101,   171,    95,   203,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   244,   231,     3,   174,
     234,   235,    47,   101,     3,    32,    46,   270,    45,    16,
      47,   237,    49,    50,   273,     0,   242,    16,    95,   147,
     268,   153,   263,   155,   156,   303,    71,   253,    95,    95,
      57,   257,    95,   100,   100,   263,    99,    45,    23,   171,
     244,    46,   270,    28,    29,    45,   174,   273,    33,    34,
      45,    88,    89,    32,    33,    34,    83,    30,    31,    32,
      33,    34,    47,    45,    16,     4,   241,   345,   346,   347,
      97,    28,    29,    30,    31,    32,    33,    34,   261,   338,
      46,    95,    67,     3,   362,    99,    71,    45,    48,    47,
      16,   321,   267,    48,   372,   373,   322,    45,    95,    47,
     341,    45,    95,    47,    46,    95,    16,    84,    95,   343,
     344,    48,   338,   341,    53,   101,    48,    56,    57,    48,
      48,   253,    61,    46,    63,    64,    65,    45,    62,    46,
      69,    70,    71,    46,    73,    74,    75,    76,    46,    78,
      79,    80,    81,    82,    83,    21,    85,    86,    48,    48,
      48,    48,    48,   138,    30,    31,    32,    96,    97,    48,
      99,   101,    64,    39,    40,   261,    75,    43,    56,    45,
     248,   273,   184,   171,   138,    34,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    21,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    21,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    54,    55,    -1,    -1,    58,    59,    60,    30,
      31,    32,    -1,    -1,    66,    67,    68,    -1,    39,    40,
      72,    -1,    43,    -1,    45,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    21,    88,    89,    -1,    91,
      92,    93,    94,    95,    30,    31,    32,    99,    -1,   101,
      -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    88,    89,    -1,
      91,    92,    93,    94,    95,    30,    31,    32,    -1,    -1,
     101,    -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,
      45,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    88,    89,    -1,    91,    92,    93,    94,    95,
      30,    31,    32,    -1,    -1,   101,    -1,    -1,    -1,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    21,    88,    89,    -1,    91,    92,    93,    94,
      95,    30,    31,    32,    99,   100,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    -1,    45,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    88,    89,
      -1,    91,    92,    93,    94,    95,    -1,    -1,    15,    99,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    21,    88,
      89,    -1,    91,    92,    93,    94,    95,    30,    31,    32,
      99,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,    -1,
      73,    74,    -1,    76,    -1,    -1,    79,    80,    81,    82,
      83,    -1,    85,    86,    -1,    88,    89,    21,    91,    92,
      93,    94,    95,    -1,    97,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    21,    43,
      -1,    45,    -1,    -1,    48,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    57,    -1,    -1,    39,    40,    21,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    75,    -1,    -1,    57,    -1,    39,    40,    -1,    83,
      43,    -1,    45,    -1,    88,    89,    -1,    91,    92,    93,
      94,    95,    75,    97,    57,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    21,    91,    92,
      93,    94,    95,    -1,    97,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    21,    39,    40,    -1,    -1,    43,
      -1,    45,    46,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    21,    -1,    43,    -1,    45,    -1,
      -1,    48,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    43,    -1,    45,    -1,
      -1,    48,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    92,    93,    94,    95,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      21,    88,    89,    -1,    91,    92,    93,    94,    95,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    21,    39,    40,
      -1,    -1,    43,    -1,    45,    46,    30,    31,    32,    -1,
      -1,    -1,    -1,    21,    -1,    39,    40,    -1,    -1,    43,
      -1,    45,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      88,    89,    -1,    91,    92,    93,    94,    95,    30,    31,
      32,    32,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    -1,    45,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    88,    89,    32,    91,
      92,    93,    94,    95,    95,    96,    97,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    -1,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      46,    85,    86,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    96,    97,    -1,    61,    -1,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    71,    -1,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    85,
      86,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    95,
      96,    97,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    96,    97,    61,    -1,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    -1,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      -1,    85,    86,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    96,    97,    61,    99,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    -1,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    -1,    85,    86,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    96,
      97,    98,    61,    -1,    63,    64,    65,    -1,    -1,    -1,
      69,    70,    71,    -1,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    96,    97,    61,
      -1,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    -1,    76,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    85,    86,    -1,    -1,    56,    57,    -1,
      -1,    -1,    61,    -1,    63,    97,    65,    -1,   100,    -1,
      69,    70,    -1,    -1,    73,    74,    -1,    76,    -1,    -1,
      79,    80,    81,    82,    83,    -1,    85,    86,    -1,    -1,
      56,    57,    -1,    -1,    -1,    61,    -1,    63,    97,    65,
      -1,   100,    -1,    69,    70,    -1,    -1,    73,    74,    -1,
      76,    -1,    -1,    79,    80,    81,    82,    83,    -1,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    56,    57,    61,    63,    64,    65,    69,    70,
      71,    73,    74,    75,    76,    78,    79,    80,    81,    82,
      83,    85,    86,    96,    97,   103,   116,   117,   120,   121,
     122,   123,   129,   132,   158,   159,   160,    95,    99,   117,
       0,    32,    45,    95,   101,   118,   119,   133,   134,   135,
     117,   117,    95,    99,   117,   159,    99,    95,   130,   131,
     132,   135,   136,   133,     3,   101,     4,    99,   116,   117,
     152,   161,    45,    47,   134,    99,   121,   124,   125,   126,
     132,   130,     4,     3,   100,   132,   135,    46,   119,   133,
      21,    30,    31,    32,    39,    40,    43,    45,    88,    89,
      91,    92,    93,    94,    95,    99,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   115,   144,    54,    55,    58,
      59,    60,    66,    67,    68,    72,    77,    84,    95,   100,
     101,   114,   115,   116,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   116,   152,    46,    95,   117,   137,   138,
     139,   140,    32,    75,   115,   136,   124,   126,   100,   125,
      16,   127,   128,   133,   126,     3,   100,   108,   112,   100,
     131,    45,   108,   114,   126,   141,    45,   108,   108,    47,
      49,   144,   145,   146,   147,   148,    45,    47,    49,    50,
      88,    89,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   113,   110,    15,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   101,   112,   101,    16,   149,    45,
      95,    45,   101,   114,    45,    45,    16,     3,   101,   100,
     154,    45,    47,   133,   135,   142,   143,    46,     3,     3,
      46,    48,   115,   136,    48,    32,    48,    75,   115,   100,
     112,     3,   101,    16,   100,   141,    46,    45,   135,   142,
      46,   112,    95,     3,   100,   144,     4,   148,    46,   114,
     114,    95,    95,   115,   114,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,    16,   149,    84,   151,   101,   114,   101,
     114,   114,   149,   115,    46,   137,   142,    32,    48,   115,
     143,    45,    47,    98,   139,    95,    48,   115,    48,   115,
      48,   128,   112,    46,   110,    48,   100,   144,   146,    46,
      48,    16,   149,    45,   151,    46,    46,    46,    46,    46,
      48,    48,    46,   137,    32,    48,   115,    48,    48,   144,
     112,   114,    46,   114,   149,   149,   149,    46,    48,    48,
      46,   149,    46,    62,   101,   149,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   144,   144,   144,   145,
     145,   145,   145,   146,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   156,   156,
     156,   156,   157,   157,   157,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       1,     1,     2,     2,     1,     3,     1,     2,     3,     4,
       5,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     1,     3,     5,     4,     4,     6,     5,
       6,     5,     4,     4,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     2,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       3,     4,     2,     3,     3,     4,     1,     3,     4,     1,
       2,     3,     4,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     1,     5,     7,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: translation_unit  */
#line 101 "parsing.y"
                          {root = (yyval.astnode);}
#line 2153 "parsing.tab.c"
    break;

  case 3: /* pexp: ID  */
#line 104 "parsing.y"
         {(yyval.astnode)=astIdent((yyvsp[0].s).c);}
#line 2159 "parsing.tab.c"
    break;

  case 5: /* pexp: STR  */
#line 106 "parsing.y"
       {(yyval.astnode)=astString((yyvsp[0].s).c);}
#line 2165 "parsing.tab.c"
    break;

  case 6: /* pexp: '(' exp ')'  */
#line 107 "parsing.y"
               {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2171 "parsing.tab.c"
    break;

  case 7: /* number: NUM  */
#line 110 "parsing.y"
            {(yyval.astnode)=astNum(_integer,(void *)&(yyvsp[0].i));}
#line 2177 "parsing.tab.c"
    break;

  case 8: /* number: NUMF  */
#line 111 "parsing.y"
        {(yyval.astnode)=astNum(_real,(void *)&(yyvsp[0].d));}
#line 2183 "parsing.tab.c"
    break;

  case 10: /* constant: CH  */
#line 115 "parsing.y"
      {int i; if ((yyvsp[0].s).l==2) i=0; else i=(yyvsp[0].s).c[0]; (yyval.astnode)=astNum(_integer,(void *)&i);}
#line 2189 "parsing.tab.c"
    break;

  case 12: /* postexp: postexp '[' exp ']'  */
#line 119 "parsing.y"
                       {(yyval.astnode) = astBinary((yyvsp[-3].astnode),(yyvsp[-1].astnode),'[');}
#line 2195 "parsing.tab.c"
    break;

  case 13: /* postexp: postexp '(' ')'  */
#line 120 "parsing.y"
                   {(yyval.astnode) = astBinary((yyvsp[-2].astnode),NULL,'(');}
#line 2201 "parsing.tab.c"
    break;

  case 14: /* postexp: postexp '(' exp ')'  */
#line 121 "parsing.y"
                       {(yyval.astnode) = astBinary((yyvsp[-3].astnode),(yyvsp[-1].astnode),'(');}
#line 2207 "parsing.tab.c"
    break;

  case 15: /* postexp: postexp '.' ID  */
#line 122 "parsing.y"
                  {(yyval.astnode) = astBinary((yyvsp[-2].astnode),astIdent((yyvsp[0].s).c),'.');}
#line 2213 "parsing.tab.c"
    break;

  case 16: /* postexp: postexp ARROW ID  */
#line 123 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),astIdent((yyvsp[0].s).c),ARROW);}
#line 2219 "parsing.tab.c"
    break;

  case 17: /* postexp: postexp INC  */
#line 124 "parsing.y"
                             {(yyval.astnode) = astUnary(POSTINC,(yyvsp[-1].astnode));}
#line 2225 "parsing.tab.c"
    break;

  case 18: /* postexp: postexp DEC  */
#line 125 "parsing.y"
                             {(yyval.astnode) = astUnary(POSTDEC,(yyvsp[-1].astnode));}
#line 2231 "parsing.tab.c"
    break;

  case 20: /* unary: INC unary  */
#line 130 "parsing.y"
                          {(yyval.astnode) = astUnary(PREINC,(yyvsp[0].astnode));}
#line 2237 "parsing.tab.c"
    break;

  case 21: /* unary: DEC unary  */
#line 131 "parsing.y"
                          {(yyval.astnode) = astUnary(PREDEC,(yyvsp[0].astnode));}
#line 2243 "parsing.tab.c"
    break;

  case 22: /* unary: uop castexp  */
#line 132 "parsing.y"
               {(yyval.astnode) = astUnary((yyvsp[-1].i),(yyvsp[0].astnode));}
#line 2249 "parsing.tab.c"
    break;

  case 23: /* unary: SIZEOF unary  */
#line 133 "parsing.y"
                {(yyval.astnode) = astUnary(SIZEOF,(yyvsp[0].astnode));}
#line 2255 "parsing.tab.c"
    break;

  case 24: /* unary: SIZEOF '(' type_name ')'  */
#line 134 "parsing.y"
                                         {(yyval.astnode) = astUnary(SIZEOF,(yyvsp[-1].astnode));}
#line 2261 "parsing.tab.c"
    break;

  case 25: /* uop: '&'  */
#line 137 "parsing.y"
         {(yyval.i) = '&';}
#line 2267 "parsing.tab.c"
    break;

  case 26: /* uop: '*'  */
#line 138 "parsing.y"
       {(yyval.i) = '*';}
#line 2273 "parsing.tab.c"
    break;

  case 27: /* uop: '+'  */
#line 139 "parsing.y"
       {(yyval.i) = '+';}
#line 2279 "parsing.tab.c"
    break;

  case 28: /* uop: '-'  */
#line 140 "parsing.y"
       {(yyval.i) = '-';}
#line 2285 "parsing.tab.c"
    break;

  case 29: /* uop: '~'  */
#line 141 "parsing.y"
       {(yyval.i) = '~';}
#line 2291 "parsing.tab.c"
    break;

  case 30: /* uop: '!'  */
#line 142 "parsing.y"
       {(yyval.i) = '!';}
#line 2297 "parsing.tab.c"
    break;

  case 32: /* castexp: '(' type_name ')' castexp  */
#line 147 "parsing.y"
 {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),CAST);}
#line 2303 "parsing.tab.c"
    break;

  case 34: /* binary: binary '*' binary  */
#line 151 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'*');}
#line 2309 "parsing.tab.c"
    break;

  case 35: /* binary: binary '/' binary  */
#line 152 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'/');}
#line 2315 "parsing.tab.c"
    break;

  case 36: /* binary: binary '%' binary  */
#line 153 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'%');}
#line 2321 "parsing.tab.c"
    break;

  case 37: /* binary: binary '+' binary  */
#line 154 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'+');}
#line 2327 "parsing.tab.c"
    break;

  case 38: /* binary: binary '-' binary  */
#line 155 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'-');}
#line 2333 "parsing.tab.c"
    break;

  case 39: /* binary: binary LSHIFT binary  */
#line 156 "parsing.y"
                        {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),LSHIFT);}
#line 2339 "parsing.tab.c"
    break;

  case 40: /* binary: binary RSHIFT binary  */
#line 157 "parsing.y"
                        {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),RSHIFT);}
#line 2345 "parsing.tab.c"
    break;

  case 41: /* binary: binary '<' binary  */
#line 158 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'<');}
#line 2351 "parsing.tab.c"
    break;

  case 42: /* binary: binary '>' binary  */
#line 159 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'>');}
#line 2357 "parsing.tab.c"
    break;

  case 43: /* binary: binary LE binary  */
#line 160 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),LE);}
#line 2363 "parsing.tab.c"
    break;

  case 44: /* binary: binary GE binary  */
#line 161 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),GE);}
#line 2369 "parsing.tab.c"
    break;

  case 45: /* binary: binary NE binary  */
#line 162 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),NE);}
#line 2375 "parsing.tab.c"
    break;

  case 46: /* binary: binary EQ binary  */
#line 163 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),EQ);}
#line 2381 "parsing.tab.c"
    break;

  case 47: /* binary: binary '&' binary  */
#line 164 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'&');}
#line 2387 "parsing.tab.c"
    break;

  case 48: /* binary: binary '^' binary  */
#line 165 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'^');}
#line 2393 "parsing.tab.c"
    break;

  case 49: /* binary: binary '|' binary  */
#line 166 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'|');}
#line 2399 "parsing.tab.c"
    break;

  case 50: /* binary: binary AND binary  */
#line 167 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),AND);}
#line 2405 "parsing.tab.c"
    break;

  case 51: /* binary: binary OR binary  */
#line 168 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),OR);}
#line 2411 "parsing.tab.c"
    break;

  case 53: /* ternary: binary '?' exp ':' ternary  */
#line 172 "parsing.y"
                              {(yyval.astnode) = astCond((yyvsp[-4].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2417 "parsing.tab.c"
    break;

  case 54: /* aop: '='  */
#line 175 "parsing.y"
         {(yyval.i) = '=';}
#line 2423 "parsing.tab.c"
    break;

  case 55: /* aop: PLUSEQ  */
#line 176 "parsing.y"
          {(yyval.i) = PLUSEQ;}
#line 2429 "parsing.tab.c"
    break;

  case 56: /* aop: MINUSEQ  */
#line 177 "parsing.y"
           {(yyval.i) = MINUSEQ;}
#line 2435 "parsing.tab.c"
    break;

  case 57: /* aop: TIMESEQ  */
#line 178 "parsing.y"
           {(yyval.i) = TIMESEQ;}
#line 2441 "parsing.tab.c"
    break;

  case 58: /* aop: DIVEQ  */
#line 179 "parsing.y"
         {(yyval.i) = DIVEQ;}
#line 2447 "parsing.tab.c"
    break;

  case 59: /* aop: MODEQ  */
#line 180 "parsing.y"
         {(yyval.i) = MODEQ;}
#line 2453 "parsing.tab.c"
    break;

  case 60: /* aop: LSHIFTEQ  */
#line 181 "parsing.y"
            {(yyval.i) = LSHIFTEQ;}
#line 2459 "parsing.tab.c"
    break;

  case 61: /* aop: RSHIFTEQ  */
#line 182 "parsing.y"
            {(yyval.i) = RSHIFTEQ;}
#line 2465 "parsing.tab.c"
    break;

  case 62: /* aop: ANDEQ  */
#line 183 "parsing.y"
         {(yyval.i) = ANDEQ;}
#line 2471 "parsing.tab.c"
    break;

  case 63: /* aop: XOREQ  */
#line 184 "parsing.y"
         {(yyval.i) = XOREQ;}
#line 2477 "parsing.tab.c"
    break;

  case 64: /* aop: OREQ  */
#line 185 "parsing.y"
        {(yyval.i) = OREQ;}
#line 2483 "parsing.tab.c"
    break;

  case 65: /* exp: aexp  */
#line 188 "parsing.y"
          {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2489 "parsing.tab.c"
    break;

  case 66: /* exp: exp ',' aexp  */
#line 189 "parsing.y"
                {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2495 "parsing.tab.c"
    break;

  case 68: /* aexp: unary aop aexp  */
#line 193 "parsing.y"
                  {(yyval.astnode) = astAssign((yyvsp[-2].astnode),(yyvsp[0].astnode),(yyvsp[-1].i));}
#line 2501 "parsing.tab.c"
    break;

  case 70: /* decl: declspec initdecllist ';'  */
#line 198 "parsing.y"
                                    {(yyval.astnode)=(yyvsp[-1].astnode); bindDeclSpec((yyvsp[-2].astnode),(yyvsp[-1].astnode));}
#line 2507 "parsing.tab.c"
    break;

  case 71: /* declspec: storage_class_specifier  */
#line 202 "parsing.y"
                                  {(yyval.astnode)=astTypeStg(_convspec((yyvsp[0].i)));}
#line 2513 "parsing.tab.c"
    break;

  case 72: /* declspec: storage_class_specifier declspec  */
#line 204 "parsing.y"
        {(yyval.astnode)=(yyvsp[0].astnode);
	if (addTypeStg((yyvsp[0].astnode),(yyvsp[-1].i))) {
		yyerror("more than one stg: %s %s",gettoken((yyvsp[-1].i)),gettoken((yyvsp[0].astnode)->type->stg));
	}}
#line 2522 "parsing.tab.c"
    break;

  case 73: /* declspec: type_specifier  */
#line 208 "parsing.y"
                         {(yyval.astnode)=astTypeSpec((yyvsp[0].astnode));}
#line 2528 "parsing.tab.c"
    break;

  case 74: /* declspec: type_specifier declspec  */
#line 209 "parsing.y"
                                  {
		if (addTypeSpec((yyvsp[0].astnode),(yyvsp[-1].astnode))) {
			yyerror("invalid specifier combination");
		}
	}
#line 2538 "parsing.tab.c"
    break;

  case 75: /* declspec: type_qualifier  */
#line 214 "parsing.y"
                         {(yyval.astnode)=astTypeQual(_convspec((yyvsp[0].i)));}
#line 2544 "parsing.tab.c"
    break;

  case 76: /* declspec: type_qualifier declspec  */
#line 215 "parsing.y"
                                  {
		(yyval.astnode)=(yyvsp[0].astnode);
		addTypeQual((yyvsp[0].astnode),_convspec((yyvsp[-1].i)));
	}
#line 2553 "parsing.tab.c"
    break;

  case 79: /* initdecllist: initdeclr  */
#line 224 "parsing.y"
                    {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2559 "parsing.tab.c"
    break;

  case 80: /* initdecllist: initdecllist ',' initdeclr  */
#line 225 "parsing.y"
                                     {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2565 "parsing.tab.c"
    break;

  case 82: /* initdeclr: declr '=' init  */
#line 230 "parsing.y"
                         {(yyval.astnode)=astAssign((yyvsp[-2].astnode),(yyvsp[0].astnode),'=');}
#line 2571 "parsing.tab.c"
    break;

  case 83: /* storage_class_specifier: TYPEDEF  */
#line 234 "parsing.y"
                  {(yyval.i)=TYPEDEF;}
#line 2577 "parsing.tab.c"
    break;

  case 84: /* storage_class_specifier: EXTERN  */
#line 235 "parsing.y"
                 {(yyval.i)=EXTERN;}
#line 2583 "parsing.tab.c"
    break;

  case 85: /* storage_class_specifier: STATIC  */
#line 236 "parsing.y"
                 {(yyval.i)=STATIC;}
#line 2589 "parsing.tab.c"
    break;

  case 86: /* storage_class_specifier: AUTO  */
#line 237 "parsing.y"
               {(yyval.i)=AUTO;}
#line 2595 "parsing.tab.c"
    break;

  case 87: /* storage_class_specifier: REGISTER  */
#line 238 "parsing.y"
                   {(yyval.i)=REGISTER;}
#line 2601 "parsing.tab.c"
    break;

  case 88: /* type_specifier: VOID  */
#line 242 "parsing.y"
               {(yyval.astnode) = astToken(VOID);}
#line 2607 "parsing.tab.c"
    break;

  case 89: /* type_specifier: CHAR  */
#line 243 "parsing.y"
               {(yyval.astnode) = astToken(CHAR);}
#line 2613 "parsing.tab.c"
    break;

  case 90: /* type_specifier: SHORT  */
#line 244 "parsing.y"
                {(yyval.astnode) = astToken(SHORT);}
#line 2619 "parsing.tab.c"
    break;

  case 91: /* type_specifier: INT  */
#line 245 "parsing.y"
              {(yyval.astnode) = astToken(INT);}
#line 2625 "parsing.tab.c"
    break;

  case 92: /* type_specifier: LONG  */
#line 246 "parsing.y"
               {(yyval.astnode) = astToken(LONG);}
#line 2631 "parsing.tab.c"
    break;

  case 93: /* type_specifier: FLOAT  */
#line 247 "parsing.y"
                {(yyval.astnode) = astToken(FLOAT);}
#line 2637 "parsing.tab.c"
    break;

  case 94: /* type_specifier: DOUBLE  */
#line 248 "parsing.y"
                 {(yyval.astnode) = astToken(DOUBLE);}
#line 2643 "parsing.tab.c"
    break;

  case 95: /* type_specifier: SIGNED  */
#line 249 "parsing.y"
                 {(yyval.astnode) = astToken(SIGNED);}
#line 2649 "parsing.tab.c"
    break;

  case 96: /* type_specifier: UNSIGNED  */
#line 250 "parsing.y"
                   {(yyval.astnode) = astToken(UNSIGNED);}
#line 2655 "parsing.tab.c"
    break;

  case 97: /* type_specifier: BOOL  */
#line 251 "parsing.y"
           {(yyval.astnode) = astToken(BOOL);}
#line 2661 "parsing.tab.c"
    break;

  case 98: /* type_specifier: COMPLEX  */
#line 252 "parsing.y"
              {(yyval.astnode) = astToken(COMPLEX);}
#line 2667 "parsing.tab.c"
    break;

  case 101: /* type_specifier: TYPENAME  */
#line 255 "parsing.y"
                   {(yyval.astnode) = astIdent((yyvsp[0].s).c);}
#line 2673 "parsing.tab.c"
    break;

  case 102: /* struct_or_union_specifier: strun ID '{' struct_declaration_list '}'  */
#line 259 "parsing.y"
                                                   {(yyval.astnode) = astStrun((yyvsp[-4].i),astIdent((yyvsp[-3].s).c),(yyvsp[-1].astnode));}
#line 2679 "parsing.tab.c"
    break;

  case 103: /* struct_or_union_specifier: strun '{' struct_declaration_list '}'  */
#line 260 "parsing.y"
                                                {(yyval.astnode) = astStrun((yyvsp[-3].i),NULL,(yyvsp[-1].astnode));}
#line 2685 "parsing.tab.c"
    break;

  case 104: /* struct_or_union_specifier: strun ID  */
#line 261 "parsing.y"
                   {(yyval.astnode)=astStrun((yyvsp[-1].i),astIdent((yyvsp[0].s).c),NULL);}
#line 2691 "parsing.tab.c"
    break;

  case 105: /* strun: STRUCT  */
#line 263 "parsing.y"
              {(yyval.i)=STRUCT;}
#line 2697 "parsing.tab.c"
    break;

  case 106: /* strun: UNION  */
#line 264 "parsing.y"
                {(yyval.i)=UNION;}
#line 2703 "parsing.tab.c"
    break;

  case 107: /* struct_declaration_list: struct_declaration  */
#line 268 "parsing.y"
                             {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2709 "parsing.tab.c"
    break;

  case 108: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 269 "parsing.y"
                                                     {insertAstList((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 2715 "parsing.tab.c"
    break;

  case 109: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 273 "parsing.y"
                                                              {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[-1].astnode),0);}
#line 2721 "parsing.tab.c"
    break;

  case 110: /* specifier_qualifier_list: type_specifier  */
#line 277 "parsing.y"
                         {(yyval.astnode) = astTypeSpec((yyvsp[0].astnode));}
#line 2727 "parsing.tab.c"
    break;

  case 111: /* specifier_qualifier_list: type_qualifier  */
#line 278 "parsing.y"
                         {(yyval.astnode) = astTypeQual(_convspec((yyvsp[0].i)));}
#line 2733 "parsing.tab.c"
    break;

  case 112: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 279 "parsing.y"
                                                  {(yyval.astnode)=(yyvsp[0].astnode); 
	if (addTypeSpec((yyvsp[0].astnode),(yyvsp[-1].astnode))) {
		yyerror("specificer error");
	}}
#line 2742 "parsing.tab.c"
    break;

  case 113: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 283 "parsing.y"
                                                  {(yyval.astnode)=(yyvsp[0].astnode);
	if (addTypeQual((yyvsp[0].astnode),(yyvsp[-1].i))){
		yyerror("qualifier error");
	}}
#line 2751 "parsing.tab.c"
    break;

  case 114: /* struct_declarator_list: struct_declarator  */
#line 290 "parsing.y"
                             {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2757 "parsing.tab.c"
    break;

  case 115: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 291 "parsing.y"
                                                       {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2763 "parsing.tab.c"
    break;

  case 116: /* struct_declarator: declr  */
#line 295 "parsing.y"
                {(yyval.astnode) = astMember((yyvsp[0].astnode),0)}
#line 2769 "parsing.tab.c"
    break;

  case 117: /* struct_declarator: ':' ternary  */
#line 296 "parsing.y"
                      {(yyval.astnode) = astMember(NULL,(yyvsp[0].astnode))}
#line 2775 "parsing.tab.c"
    break;

  case 118: /* struct_declarator: declr ':' ternary  */
#line 297 "parsing.y"
                            {(yyval.astnode) = astMember((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2781 "parsing.tab.c"
    break;

  case 119: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 301 "parsing.y"
                                       {(yyval.astnode)=astBinary(NULL,(yyvsp[-1].astnode),ENUM);}
#line 2787 "parsing.tab.c"
    break;

  case 120: /* enum_specifier: ENUM ID '{' enumerator_list '}'  */
#line 302 "parsing.y"
                                          {(yyval.astnode)=astBinary(astIdent((yyvsp[-3].s).c),(yyvsp[-1].astnode),ENUM);}
#line 2793 "parsing.tab.c"
    break;

  case 121: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 303 "parsing.y"
                                           {(yyval.astnode)=astBinary(NULL,(yyvsp[-2].astnode),ENUM);}
#line 2799 "parsing.tab.c"
    break;

  case 122: /* enum_specifier: ENUM ID '{' enumerator_list ',' '}'  */
#line 304 "parsing.y"
                                              {(yyval.astnode)=astBinary(astIdent((yyvsp[-4].s).c),(yyvsp[-2].astnode),ENUM);}
#line 2805 "parsing.tab.c"
    break;

  case 123: /* enum_specifier: ENUM ID  */
#line 305 "parsing.y"
                  {(yyval.astnode)=astBinary(astIdent((yyvsp[0].s).c),NULL,ENUM);}
#line 2811 "parsing.tab.c"
    break;

  case 124: /* enumerator_list: enumerator  */
#line 309 "parsing.y"
                     {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2817 "parsing.tab.c"
    break;

  case 125: /* enumerator_list: enumerator_list ',' enumerator  */
#line 310 "parsing.y"
                                         {insertAstList((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2823 "parsing.tab.c"
    break;

  case 126: /* enumerator: ID  */
#line 314 "parsing.y"
             {(yyval.astnode)=astIdent((yyvsp[0].s).c);}
#line 2829 "parsing.tab.c"
    break;

  case 127: /* enumerator: ID '=' ternary  */
#line 315 "parsing.y"
                          {(yyval.astnode) = astAssign(astIdent((yyvsp[-2].s).c),(yyvsp[0].astnode),'=');}
#line 2835 "parsing.tab.c"
    break;

  case 128: /* type_qualifier: CONST  */
#line 319 "parsing.y"
                {(yyval.i)=CONST;}
#line 2841 "parsing.tab.c"
    break;

  case 129: /* type_qualifier: VOLATILE  */
#line 320 "parsing.y"
                   {(yyval.i)=VOLATILE;}
#line 2847 "parsing.tab.c"
    break;

  case 130: /* type_qualifier: RESTRICT  */
#line 321 "parsing.y"
                   {(yyval.i)=RESTRICT;}
#line 2853 "parsing.tab.c"
    break;

  case 131: /* declr: pointer direct_declarator  */
#line 325 "parsing.y"
                                    {(yyval.astnode)=mergeLists((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2859 "parsing.tab.c"
    break;

  case 133: /* direct_declarator: ID  */
#line 330 "parsing.y"
             {(yyval.astnode)=astDecl(astIdent((yyvsp[0].s).c));}
#line 2865 "parsing.tab.c"
    break;

  case 134: /* direct_declarator: '(' declr ')'  */
#line 331 "parsing.y"
                        {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2871 "parsing.tab.c"
    break;

  case 136: /* direct_declarator: direct_declarator '[' aexp ']'  */
#line 333 "parsing.y"
                                         {insertAstListTail((yyvsp[-3].astnode)->type,astArray((yyvsp[-1].astnode)));}
#line 2877 "parsing.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 340 "parsing.y"
                                                        {insertAstListTail((yyvsp[-3].astnode)->type,astFunc((yyvsp[-1].astnode)));}
#line 2883 "parsing.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 341 "parsing.y"
                                                    {insertAstListTail((yyvsp[-3].astnode)->type,astFunc((yyvsp[-1].astnode)));}
#line 2889 "parsing.tab.c"
    break;

  case 145: /* direct_declarator: direct_declarator '(' ')'  */
#line 342 "parsing.y"
                                    {insertAstListTail((yyvsp[-2].astnode)->type,astFunc(NULL)); (yyvsp[-2].astnode)->tail->value->len=0;}
#line 2895 "parsing.tab.c"
    break;

  case 146: /* pointer: '*'  */
#line 346 "parsing.y"
              {(yyval.astnode)=astList(astPtr(0));}
#line 2901 "parsing.tab.c"
    break;

  case 147: /* pointer: '*' type_qualifier_list  */
#line 347 "parsing.y"
                                  {(yyval.astnode)=astList(astPtr((yyvsp[0].i)));}
#line 2907 "parsing.tab.c"
    break;

  case 148: /* pointer: '*' pointer  */
#line 348 "parsing.y"
                      {insertAstList((yyvsp[0].astnode),astPtr(0)); (yyval.astnode)=(yyvsp[0].astnode);}
#line 2913 "parsing.tab.c"
    break;

  case 149: /* pointer: '*' type_qualifier_list pointer  */
#line 349 "parsing.y"
                                          {insertAstList((yyvsp[0].astnode),astPtr((yyvsp[-1].i))); (yyval.astnode)=(yyvsp[0].astnode);}
#line 2919 "parsing.tab.c"
    break;

  case 150: /* type_qualifier_list: type_qualifier  */
#line 353 "parsing.y"
                         {(yyval.i) = _convspec((yyvsp[0].i));}
#line 2925 "parsing.tab.c"
    break;

  case 151: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 354 "parsing.y"
                                             {(yyval.i) = (yyval.i) | _convspec((yyvsp[0].i));}
#line 2931 "parsing.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 360 "parsing.y"
                                      {insertAstListTail((yyvsp[-2].astnode),astToken(ELLIPSIS));}
#line 2937 "parsing.tab.c"
    break;

  case 154: /* parameter_list: parameter_declaration  */
#line 364 "parsing.y"
                                {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2943 "parsing.tab.c"
    break;

  case 155: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 365 "parsing.y"
                                                   {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2949 "parsing.tab.c"
    break;

  case 156: /* parameter_declaration: declspec declr  */
#line 369 "parsing.y"
                         {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2955 "parsing.tab.c"
    break;

  case 157: /* parameter_declaration: declspec abstract_declarator  */
#line 370 "parsing.y"
                                       {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2961 "parsing.tab.c"
    break;

  case 158: /* identifier_list: ID  */
#line 374 "parsing.y"
             {(yyval.astnode)=astList(astIdent((yyvsp[0].s).c));}
#line 2967 "parsing.tab.c"
    break;

  case 159: /* identifier_list: identifier_list ',' ID  */
#line 375 "parsing.y"
                                 {insertAstListTail((yyvsp[-2].astnode),astIdent((yyvsp[0].s).c));}
#line 2973 "parsing.tab.c"
    break;

  case 160: /* type_name: specifier_qualifier_list  */
#line 379 "parsing.y"
                                   {(yyval.astnode)=astAbsDecl((yyvsp[0].astnode));}
#line 2979 "parsing.tab.c"
    break;

  case 161: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 380 "parsing.y"
                                                       {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2985 "parsing.tab.c"
    break;

  case 162: /* abstract_declarator: pointer  */
#line 384 "parsing.y"
                  {(yyval.astnode)=astAbsDeclfromList((yyvsp[0].astnode));}
#line 2991 "parsing.tab.c"
    break;

  case 164: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 386 "parsing.y"
                                             {(yyval.astnode)=(yyvsp[0].astnode); mergeLists((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2997 "parsing.tab.c"
    break;

  case 165: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 390 "parsing.y"
                                      {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 3003 "parsing.tab.c"
    break;

  case 166: /* direct_abstract_declarator: '[' ']'  */
#line 391 "parsing.y"
                  {(yyval.astnode)=astAbsDecl(astArray(astNum(_integer,0)));}
#line 3009 "parsing.tab.c"
    break;

  case 167: /* direct_abstract_declarator: '[' aexp ']'  */
#line 392 "parsing.y"
                       {(yyval.astnode)=astAbsDecl(astArray((yyvsp[-1].astnode)));}
#line 3015 "parsing.tab.c"
    break;

  case 168: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 393 "parsing.y"
                                             {insertAstListTail((yyvsp[-2].astnode),astArray(astNum(_integer,0)));}
#line 3021 "parsing.tab.c"
    break;

  case 169: /* direct_abstract_declarator: direct_abstract_declarator '[' aexp ']'  */
#line 394 "parsing.y"
                                                  {insertAstListTail((yyvsp[-3].astnode),astArray((yyvsp[-1].astnode)));}
#line 3027 "parsing.tab.c"
    break;

  case 172: /* direct_abstract_declarator: '(' ')'  */
#line 397 "parsing.y"
                  {(yyval.astnode)=astList(astFunc(NULL));}
#line 3033 "parsing.tab.c"
    break;

  case 173: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 398 "parsing.y"
                                      {(yyval.astnode)=astList(astFunc((yyvsp[-1].astnode)));}
#line 3039 "parsing.tab.c"
    break;

  case 174: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 399 "parsing.y"
                                             {insertAstListTail((yyvsp[-2].astnode),astFunc(NULL));}
#line 3045 "parsing.tab.c"
    break;

  case 175: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 400 "parsing.y"
                                                                 {insertAstListTail((yyvsp[-3].astnode),astFunc((yyvsp[-1].astnode)));}
#line 3051 "parsing.tab.c"
    break;

  case 177: /* init: '{' initlist '}'  */
#line 405 "parsing.y"
                           {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 3057 "parsing.tab.c"
    break;

  case 178: /* init: '{' initlist ',' '}'  */
#line 406 "parsing.y"
                               {(yyval.astnode)=(yyvsp[-2].astnode);}
#line 3063 "parsing.tab.c"
    break;

  case 179: /* initlist: init  */
#line 410 "parsing.y"
               {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 3069 "parsing.tab.c"
    break;

  case 181: /* initlist: initlist ',' init  */
#line 412 "parsing.y"
                            {insertAstList((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3075 "parsing.tab.c"
    break;

  case 182: /* initlist: initlist ',' designation init  */
#line 413 "parsing.y"
                                        {insertAstList((yyvsp[-3].astnode),(yyvsp[0].astnode));}
#line 3081 "parsing.tab.c"
    break;

  case 194: /* labelstmt: ID ':' stmt  */
#line 439 "parsing.y"
                      {(yyval.astnode)=astBinary(astIdent((yyvsp[-2].s).c),(yyvsp[0].astnode),':');}
#line 3087 "parsing.tab.c"
    break;

  case 195: /* labelstmt: CASE ternary ':' stmt  */
#line 440 "parsing.y"
                                {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),CASE);}
#line 3093 "parsing.tab.c"
    break;

  case 196: /* labelstmt: DEFAULT ':' stmt  */
#line 441 "parsing.y"
                           {(yyval.astnode)=astBinary(NULL,(yyvsp[0].astnode),DEFAULT);}
#line 3099 "parsing.tab.c"
    break;

  case 197: /* exps: ';'  */
#line 444 "parsing.y"
          {(yyval.astnode) = NULL;}
#line 3105 "parsing.tab.c"
    break;

  case 198: /* exps: exp ';'  */
#line 445 "parsing.y"
           {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 3111 "parsing.tab.c"
    break;

  case 199: /* compoundstmt: '{' '}'  */
#line 449 "parsing.y"
           {(yyval.astnode)=astList(NULL);}
#line 3117 "parsing.tab.c"
    break;

  case 200: /* compoundstmt: '{' block_item_list '}'  */
#line 450 "parsing.y"
                           {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 3123 "parsing.tab.c"
    break;

  case 201: /* block_item_list: block_item  */
#line 454 "parsing.y"
              {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 3129 "parsing.tab.c"
    break;

  case 202: /* block_item_list: block_item_list block_item  */
#line 455 "parsing.y"
                              {(yyval.astnode)=(yyvsp[-1].astnode); insertAstListTail((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3135 "parsing.tab.c"
    break;

  case 205: /* selects: IF '(' exp ')' stmt  */
#line 465 "parsing.y"
                              {(yyval.astnode)=astCond((yyvsp[-2].astnode),(yyvsp[0].astnode),NULL);}
#line 3141 "parsing.tab.c"
    break;

  case 206: /* selects: IF '(' exp ')' stmt ELSE stmt  */
#line 466 "parsing.y"
                                        {(yyval.astnode)=astCond((yyvsp[-4].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3147 "parsing.tab.c"
    break;

  case 207: /* selects: SWITCH '(' exp ')' stmt  */
#line 467 "parsing.y"
                                  {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),SWITCH);}
#line 3153 "parsing.tab.c"
    break;

  case 208: /* iters: WHILE '(' exp ')' stmt  */
#line 471 "parsing.y"
                                 {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),WHILE);}
#line 3159 "parsing.tab.c"
    break;

  case 209: /* iters: DO stmt WHILE '(' exp ')' ';'  */
#line 472 "parsing.y"
                                        {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[-5].astnode),DO);}
#line 3165 "parsing.tab.c"
    break;

  case 210: /* iters: FOR '(' exps exps ')' stmt  */
#line 474 "parsing.y"
        {(yyval.astnode)=astFor((yyvsp[-3].astnode),(yyvsp[-2].astnode),NULL,(yyvsp[0].astnode));}
#line 3171 "parsing.tab.c"
    break;

  case 211: /* iters: FOR '(' exps exps exp ')' stmt  */
#line 476 "parsing.y"
        {(yyval.astnode)=astFor((yyvsp[-4].astnode),(yyvsp[-3].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3177 "parsing.tab.c"
    break;

  case 212: /* jmps: GOTO ID ';'  */
#line 480 "parsing.y"
                      {(yyval.astnode)=astUnary(GOTO,astIdent((yyvsp[-1].s).c));}
#line 3183 "parsing.tab.c"
    break;

  case 213: /* jmps: CONTINUE ';'  */
#line 481 "parsing.y"
                       {(yyval.astnode)=astUnary(CONTINUE,NULL);}
#line 3189 "parsing.tab.c"
    break;

  case 214: /* jmps: BREAK ';'  */
#line 482 "parsing.y"
                    {(yyval.astnode)=astUnary(BREAK,NULL);}
#line 3195 "parsing.tab.c"
    break;

  case 215: /* jmps: RETURN ';'  */
#line 483 "parsing.y"
                     {(yyval.astnode)=astUnary(RETURN,NULL);}
#line 3201 "parsing.tab.c"
    break;

  case 216: /* jmps: RETURN exp ';'  */
#line 484 "parsing.y"
                         {(yyval.astnode)=astUnary(RETURN,(yyvsp[-1].astnode));}
#line 3207 "parsing.tab.c"
    break;

  case 217: /* translation_unit: external_declaration  */
#line 488 "parsing.y"
                               {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 3213 "parsing.tab.c"
    break;

  case 218: /* translation_unit: translation_unit external_declaration  */
#line 489 "parsing.y"
                                                {insertAstListTail((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3219 "parsing.tab.c"
    break;

  case 222: /* funcdef: declspec declr compoundstmt  */
#line 499 "parsing.y"
                                      {insertAstListTail((yyvsp[-1].astnode)->decl->type,(yyvsp[-2].astnode)); (yyval.astnode)=astFuncDef((yyvsp[-1].astnode),(yyvsp[-1].astnode)->decl->ident,(yyvsp[0].astnode));}
#line 3225 "parsing.tab.c"
    break;

  case 223: /* declaration_list: decl  */
#line 505 "parsing.y"
               {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 3231 "parsing.tab.c"
    break;

  case 224: /* declaration_list: declaration_list decl  */
#line 506 "parsing.y"
                                {insertAstList((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3237 "parsing.tab.c"
    break;


#line 3241 "parsing.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 512 "parsing.y"

main(int argc, char **argv)
{
  extern FILE *yyin, *yyout;
    if(argc < 2) {
        fprintf(stderr,"not enough arguments");
        return 1;
    }
 
    /* yyin points to the file input.txt
    and opens it in read mode*/
    yyin = fopen(argv[1], "r");
    if (argc>2 && strcmp(argv[2],"-l")==0) {
      int t=0;
      while(t=yylex()){
        printtokens(t,argv[1],yylineno,yylval);
      }
      return 0;
    }
    yyparse();
    printast(root,0);
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
