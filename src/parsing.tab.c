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
#include "helpers.h"
#include "symtab.h"
#include "quad.h"
#include <string.h>
struct astnode *root;
symtab *symtab_file;
symtab *symtab_cur;
ERROR ** errors;
int errnum;
int funcsym=0;
symtab* prototype;
extern int yylex();
extern int yyerror();
extern int yylineno;
extern quads q;
extern blockss blocks;

#line 92 "parsing.tab.c"

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

#include "parsing.tab.h"
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
  YYSYMBOL_123_1 = 123,                    /* @1  */
  YYSYMBOL_124_2 = 124,                    /* @2  */
  YYSYMBOL_strun = 125,                    /* strun  */
  YYSYMBOL_struct_declaration_list = 126,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 127,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 128, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 129,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 130,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 131,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 132,          /* enumerator_list  */
  YYSYMBOL_enumerator = 133,               /* enumerator  */
  YYSYMBOL_type_qualifier = 134,           /* type_qualifier  */
  YYSYMBOL_declr = 135,                    /* declr  */
  YYSYMBOL_direct_declarator = 136,        /* direct_declarator  */
  YYSYMBOL_137_3 = 137,                    /* $@3  */
  YYSYMBOL_pointer = 138,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 139,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 140,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 141,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 142,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 143,          /* identifier_list  */
  YYSYMBOL_type_name = 144,                /* type_name  */
  YYSYMBOL_abstract_declarator = 145,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 146, /* direct_abstract_declarator  */
  YYSYMBOL_init = 147,                     /* init  */
  YYSYMBOL_initlist = 148,                 /* initlist  */
  YYSYMBOL_designation = 149,              /* designation  */
  YYSYMBOL_designator_list = 150,          /* designator_list  */
  YYSYMBOL_designator = 151,               /* designator  */
  YYSYMBOL_stmt = 152,                     /* stmt  */
  YYSYMBOL_labelstmt = 153,                /* labelstmt  */
  YYSYMBOL_exps = 154,                     /* exps  */
  YYSYMBOL_compoundstmt = 155,             /* compoundstmt  */
  YYSYMBOL_156_4 = 156,                    /* $@4  */
  YYSYMBOL_block_item_list = 157,          /* block_item_list  */
  YYSYMBOL_block_item = 158,               /* block_item  */
  YYSYMBOL_selects = 159,                  /* selects  */
  YYSYMBOL_iters = 160,                    /* iters  */
  YYSYMBOL_jmps = 161,                     /* jmps  */
  YYSYMBOL_translation_unit = 162,         /* translation_unit  */
  YYSYMBOL_external_declaration = 163,     /* external_declaration  */
  YYSYMBOL_funcdef = 164,                  /* funcdef  */
  YYSYMBOL_165_5 = 165,                    /* @5  */
  YYSYMBOL_declaration_list = 166          /* declaration_list  */
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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  232
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  386

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
       0,   115,   115,   118,   123,   124,   125,   128,   129,   132,
     133,   136,   137,   138,   139,   140,   141,   142,   143,   147,
     148,   149,   150,   151,   152,   155,   156,   157,   158,   159,
     160,   163,   164,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   189,   190,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   206,   207,   210,   211,   215,
     216,   220,   221,   226,   227,   234,   235,   239,   240,   244,
     245,   249,   250,   254,   255,   256,   257,   258,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   279,   279,   284,   284,   288,   290,   291,   295,
     296,   300,   304,   305,   306,   310,   317,   318,   322,   323,
     324,   328,   329,   330,   331,   332,   336,   337,   341,   342,
     346,   347,   348,   352,   353,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   367,   368,   369,   373,
     374,   375,   376,   380,   381,   386,   387,   391,   392,   396,
     397,   398,   402,   403,   407,   408,   412,   413,   414,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     432,   433,   434,   438,   439,   440,   441,   444,   448,   449,
     453,   454,   458,   459,   460,   461,   462,   463,   467,   468,
     469,   472,   473,   477,   478,   478,   487,   488,   492,   493,
     498,   499,   500,   504,   505,   506,   508,   513,   514,   515,
     516,   517,   521,   522,   526,   527,   531,   532,   532,   538,
     539,   543,   544
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
  "struct_or_union_specifier", "@1", "@2", "strun",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declr", "direct_declarator", "$@3", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "init", "initlist",
  "designation", "designator_list", "designator", "stmt", "labelstmt",
  "exps", "compoundstmt", "$@4", "block_item_list", "block_item",
  "selects", "iters", "jmps", "translation_unit", "external_declaration",
  "funcdef", "@5", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-236)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-228)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1174,    -9,   131,  -236,  -236,  -236,  -236,   -43,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  1331,  -236,    25,  -236,
      84,  1331,  1331,  -236,   111,  -236,  1331,  1256,   114,   -31,
    1174,  -236,  -236,  -236,  -236,    -9,    26,   -26,   -16,  -236,
    -236,  -236,     7,  -236,   227,  -236,  -236,   -12,  -236,  -236,
       6,  -236,    84,  -236,  1256,   -25,   780,   114,  -236,  -236,
    -236,  -236,   -16,    98,    24,  -236,   131,  -236,   624,    10,
    1256,  -236,  1434,  -236,   384,   126,  -236,  -236,  -236,  -236,
    1331,    77,  -236,  -236,  -236,   110,  -236,  -236,   989,   690,
     800,  1005,  1005,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,   152,   666,  1071,  -236,   676,  -236,   135,   759,    27,
    1071,   -19,  -236,  -236,  -236,   593,  -236,  -236,  -236,  -236,
    1434,  1434,  1368,  -236,    12,  1434,    99,  1071,   112,   120,
     461,   167,   132,   183,   492,   188,   190,   214,  -236,     9,
    -236,  -236,  -236,  -236,  -236,  -236,   307,  -236,  -236,  -236,
    -236,   141,   192,   243,  -236,   154,  -236,  -236,   690,  -236,
      80,   149,   208,   207,   800,  1071,  -236,  -236,   869,  1071,
     163,   168,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  1071,  -236,  -236,  1071,  1071,
    1071,  1071,  1071,  1071,  1071,  1071,  1071,  1071,  1071,  1071,
    1071,  1071,  1071,  1071,  1071,  1071,  1071,  -236,   216,  -236,
    1071,   217,     3,  -236,  -236,  -236,  -236,  1071,   171,  -236,
      31,   624,    35,  -236,  1401,  -236,  -236,  -236,  1071,    16,
    -236,   246,  -236,  -236,   252,  -236,   461,   186,   527,   172,
    1071,  -236,    19,  1071,  1071,   461,  1071,  -236,  -236,  -236,
    1072,   886,  -236,     2,  -236,   144,  -236,  1293,  -236,   223,
    -236,  1129,   164,  -236,  1071,  -236,   229,  -236,    82,    47,
    -236,  -236,  -236,   174,  1532,  1548,  1563,  1577,  1590,   958,
     958,   287,   287,   287,   287,   185,   185,   210,   210,  -236,
    -236,  -236,  -236,   230,  -236,  -236,   231,  -236,   558,  -236,
    -236,  -236,  -236,  -236,  -236,    12,  -236,  1071,   461,  -236,
     236,   527,  -236,    88,  -236,   134,   161,  -236,  -236,  -236,
     240,   247,   234,  -236,   251,   144,  1219,   906,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  1071,  -236,  -236,  -236,  -236,
     624,  -236,  -236,  -236,  1071,   972,   461,   461,   461,  -236,
    -236,  -236,  -236,  -236,   248,   256,  -236,   263,  -236,  -236,
     162,   461,   179,   260,  -236,  -236,  -236,  -236,  -236,   224,
    -236,   461,   461,  -236,  -236,  -236
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   149,     0,    86,    89,   130,    94,     0,    84,    93,
      91,    92,    87,    90,    95,    85,   107,    83,   101,   108,
      96,    88,   131,    97,    98,   135,    77,   132,     0,   225,
       0,    71,    73,    99,     0,   100,    75,     0,   134,     0,
       2,   222,   224,   153,   151,   150,     0,   125,     0,    78,
       1,    69,     0,    79,    81,    72,    74,   106,   104,    76,
     204,   231,     0,   230,     0,   145,     0,   133,   223,   154,
     152,   136,     0,   128,     0,   126,     0,    70,     0,     0,
       0,   102,     0,   203,     0,    81,   232,   229,   148,   162,
       0,     0,    25,    27,    28,    26,    30,    29,     0,     0,
       0,     0,     0,     7,     8,    10,     5,     3,    11,     9,
       4,    19,    31,     0,    33,    52,    67,     0,     0,     0,
       0,     0,   121,    80,    26,     0,   180,    82,   228,   226,
       0,   112,     0,   109,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,   201,     0,
      65,   208,   209,   192,   194,   193,     0,   206,   195,   196,
     197,   161,     0,   155,   157,     0,   147,   144,     0,    23,
       0,   164,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    17,    18,    54,    55,    56,    57,    58,    59,
      62,    63,    64,    60,    61,     0,    31,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,    26,   139,
       0,     0,     0,   122,   129,   123,   127,     0,     0,   183,
       0,     0,     0,   188,     0,   114,   105,   110,     0,     0,
     116,   118,   115,   219,     0,   218,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,   202,   205,   207,
       0,     0,   159,   166,   160,   167,   146,     0,   163,     0,
       6,     0,   166,   165,     0,   141,     0,    13,     0,     0,
      15,    16,    68,     0,    51,    50,    49,    48,    47,    46,
      45,    42,    41,    43,    44,    39,    40,    37,    38,    34,
      35,    36,   143,     0,   137,   124,     0,   191,     0,   181,
     184,   187,   189,   103,   119,     0,   111,     0,     0,   200,
       0,     0,   217,     0,   221,     0,     0,   198,    66,   176,
       0,     0,    26,   170,     0,   168,     0,     0,   156,   158,
      24,    32,   140,    14,    12,     0,   142,   190,   182,   185,
       0,   117,   120,   199,     0,     0,     0,     0,     0,   177,
     169,   174,   171,   178,     0,    26,   172,     0,    53,   186,
       0,     0,     0,   210,   212,   213,   179,   175,   173,     0,
     215,     0,     0,   214,   216,   211
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,  -236,  -236,  -236,  -236,   -60,  -236,  -105,  1333,
    -113,  -236,   -79,   -63,   -21,     0,  -236,   253,  -236,   -64,
    -236,  -236,  -236,  -236,   197,  -121,   -30,  -236,    15,  -236,
     259,  -104,   121,    -1,   -34,  -236,     1,    -8,   -86,  -236,
      65,  -236,   165,    34,  -218,  -116,  -236,    32,  -236,   102,
    -134,  -236,  -235,    14,  -236,  -236,   187,  -236,  -236,  -236,
    -236,   295,  -236,  -236,   288
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    28,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   195,   149,   150,    29,    62,    52,    53,    31,    32,
      33,   130,    82,    34,   132,   133,   134,   239,   240,    35,
      74,    75,    36,    37,    38,    90,    39,    45,   330,   163,
     164,    91,   172,   331,   265,   127,   230,   231,   232,   233,
     152,   153,   154,   155,    84,   156,   157,   158,   159,   160,
      40,    41,    42,    79,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    46,    44,   117,   162,    67,   247,   224,   197,   229,
      76,   237,   256,   321,     2,   126,    61,   226,   131,   315,
     170,    88,   256,     1,   244,    50,    49,   121,   238,    54,
     222,    55,    56,    61,   308,   131,    59,   173,   169,   311,
      30,   176,   177,    86,     1,   335,    70,   260,     5,   261,
     256,    63,    47,   196,   335,   221,    48,     2,   118,    86,
     196,    85,   126,   151,    25,   252,   131,   131,   131,   171,
      89,   131,    71,    72,    22,    85,    73,   196,    87,    73,
     165,   225,   227,   256,   228,   256,   355,    81,    27,   170,
     161,   256,   174,   128,   129,   344,   170,    25,    73,   278,
     279,   235,   120,   305,   131,   242,    83,    25,    77,    60,
     257,   276,   319,   237,   306,   310,     1,   316,   226,   283,
     324,   327,    43,   166,   122,   314,   270,   223,   343,     2,
      78,   309,   282,   241,   356,   151,   246,   256,   171,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   303,   167,    65,
     262,    66,   263,     1,   256,   256,    69,   196,   126,   341,
     131,   323,   272,     1,   325,   326,     2,   256,   196,    25,
     357,     1,   256,   217,   353,    51,   260,    43,   261,   336,
     345,   337,   349,   328,   271,   264,   261,   178,   334,   179,
     243,   180,   181,   135,   352,   273,    57,   358,   379,   271,
      58,   261,   248,   245,   196,   212,   213,   214,   215,   216,
     135,    43,   373,   374,   375,   381,    25,   249,   250,    67,
     255,    78,   368,   253,   369,   254,    25,   380,   266,    69,
     182,   183,   214,   215,   216,   126,   267,   384,   385,   268,
     364,   135,   135,   135,   274,   275,   135,   196,   280,    46,
     161,   263,   317,   281,   302,   304,   307,   161,   318,   340,
     320,   161,   272,   322,   367,   370,   372,   342,   346,   347,
       3,   354,   361,     4,     5,   196,   359,   126,     6,   135,
       7,     8,     9,   360,   376,    69,    10,    11,    12,   362,
      13,    14,    15,    16,   377,    17,    18,    19,    20,    21,
      22,   378,    23,    24,   241,   210,   211,   212,   213,   214,
     215,   216,   382,    26,    27,   383,  -227,   234,    92,   123,
     351,   119,   339,   269,   312,    68,   161,    93,    94,   124,
     350,     0,    80,   259,     0,     0,    96,    97,     0,     0,
      98,     0,    99,     0,     0,   135,     0,     0,     0,     0,
       3,   136,   137,     4,     5,   138,   139,   140,     6,     0,
       7,     8,     9,   141,   142,   143,    10,    11,    12,   144,
      13,    14,    15,    16,   145,    17,    18,    19,    20,    21,
      22,   146,    23,    24,     0,   101,   102,     0,   103,   104,
     105,   106,   147,    26,    27,    92,    60,   258,   148,     0,
       0,     0,     0,     0,    93,    94,   124,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,    98,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     3,   136,   137,
       4,     5,   138,   139,   140,     6,     0,     7,     8,     9,
     141,   142,   143,    10,    11,    12,   144,    13,    14,    15,
      16,   145,    17,    18,    19,    20,    21,    22,   146,    23,
      24,     0,   101,   102,     0,   103,   104,   105,   106,   147,
      26,    27,    92,    60,     0,   148,     0,     0,     0,     0,
       0,    93,    94,   124,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,    98,     0,    99,     0,     0,     0,
       0,     0,     0,    92,     0,   136,   137,     0,     0,   138,
     139,   140,    93,    94,   124,     0,     0,   141,   142,   143,
       0,    96,    97,   144,     0,    98,     0,    99,   145,     0,
       0,     0,     0,     0,     0,   146,     0,     0,    92,   101,
     102,     0,   103,   104,   105,   106,   147,    93,    94,   124,
      60,     0,   148,     0,     0,     0,    96,    97,     0,     0,
      98,     0,    99,     0,     0,     0,     0,     0,     0,    92,
     101,   102,     0,   103,   104,   105,   106,   107,    93,    94,
     124,     0,     0,   251,     0,     0,     0,    96,    97,     0,
       0,    98,     0,    99,     0,   227,     0,   228,     0,     0,
       0,     0,     0,     0,    92,   101,   102,     0,   103,   104,
     105,   106,   107,    93,    94,   124,     0,     0,   148,     0,
       0,     0,    96,    97,     0,     0,    98,     0,    99,     0,
     227,     0,   228,     0,     0,    92,   101,   102,     0,   103,
     104,   105,   106,   107,    93,    94,   124,   125,   348,     0,
       0,     0,     0,    96,    97,     0,     0,    98,     0,    99,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   101,   102,     0,   103,   104,   105,   106,   107,     0,
       0,   198,   125,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    92,   101,   102,     0,   103,   104,   105,   106,   107,
      93,    94,   124,   125,     0,     0,     0,     0,     0,    96,
      97,     0,     0,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    13,    14,     0,    16,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,     0,   101,   102,
      92,   103,   104,   105,   106,   107,     0,    27,     0,    93,
      94,   218,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    92,    98,     0,    99,     0,     0,   219,     0,     0,
      93,    94,    95,     0,     0,     0,     5,     0,     0,    96,
      97,    92,     0,    98,     0,    99,     0,     0,     0,     0,
      93,    94,   124,     0,   220,     0,     0,     5,     0,    96,
      97,     0,    22,    98,     0,    99,     0,   101,   102,     0,
     103,   104,   105,   106,   107,   100,    27,     5,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,   101,   102,
       0,   103,   104,   105,   106,   107,     0,    27,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,   101,   102,
      92,   103,   104,   105,   106,   107,     0,    27,     0,    93,
      94,   124,     0,     0,     0,     0,     0,    92,    96,    97,
       0,     0,    98,     0,    99,   277,    93,    94,   332,     0,
       0,     0,     0,     0,     0,    96,    97,    92,     0,    98,
       0,    99,     0,     0,   333,     0,    93,    94,   365,     0,
       0,     0,     0,     0,     0,    96,    97,     0,     0,    98,
       0,    99,     0,     0,   366,     0,     0,   101,   102,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,     0,   103,   104,   105,
     106,   107,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    92,   101,   102,     0,   103,   104,   105,
     106,   107,    93,    94,   124,     0,     0,     0,     0,     0,
      92,    96,    97,     0,     0,    98,     0,    99,   371,    93,
      94,   124,     0,     0,     0,     0,    92,     0,    96,    97,
       0,     0,    98,     0,   168,    93,    94,   124,     0,     0,
       0,     0,     0,     0,    96,    97,     0,     0,    98,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,    92,   101,   102,     0,   103,   104,   105,   106,
     107,    93,    94,   124,     1,     0,     0,     0,     0,     0,
      96,    97,     0,     0,    98,     0,    99,   260,   329,   261,
       0,     0,     0,     0,     0,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     7,     8,     9,     0,     0,
       0,    10,    11,    12,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,    23,    24,   101,
     102,     1,   103,   104,   105,   106,   107,    25,    26,    27,
       0,     0,     0,     0,   271,   329,   261,     0,     0,     0,
       0,     0,     3,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,     0,     0,     0,    10,    11,
      12,     0,    13,    14,    15,    16,     1,    17,    18,    19,
      20,    21,    22,     0,    23,    24,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    26,    27,     3,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     7,     8,     9,
       0,     0,     0,    10,    11,    12,     0,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,     0,    23,
      24,     0,     0,     0,     0,   363,     0,     0,     0,    25,
      26,    27,     3,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,     0,     0,     0,    10,    11,
      12,     0,    13,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,     0,    23,    24,     0,     0,     0,     3,
       0,     0,     4,     5,     0,    26,    27,     6,     0,     7,
       8,     9,     0,     0,     0,    10,    11,    12,     0,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,    22,
       0,    23,    24,     0,     0,     0,     3,     0,     0,     4,
       5,     0,    26,    27,     6,    60,     7,     8,     9,     0,
       0,     0,    10,    11,    12,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,     0,    23,    24,
       0,     0,     0,     0,     3,     0,     0,     4,     5,    26,
      27,   338,     6,     0,     7,     8,     9,     0,     0,     0,
      10,    11,    12,     0,    13,    14,    15,    16,     0,    17,
      18,    19,    20,    21,    22,     0,    23,    24,     0,     0,
       0,     0,     0,     0,     4,     5,     0,    26,    27,     6,
       0,     7,     0,     9,     0,     0,     0,    10,    11,     0,
       0,    13,    14,     0,    16,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     7,    27,     9,     0,   236,     0,
      10,    11,     0,     0,    13,    14,     0,    16,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     7,    27,     9,
       0,   313,     0,    10,    11,     0,     0,    13,    14,     0,
      16,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216
};

static const yytype_int16 yycheck[] =
{
       0,     2,     1,    66,    90,    39,   140,   120,   113,   125,
       3,   132,     3,   248,    45,    78,    37,   121,    82,     3,
      99,    46,     3,    32,   137,     0,    26,     3,    16,    30,
       3,    31,    32,    54,     3,    99,    36,   100,    98,     4,
      40,   101,   102,    64,    32,   263,    45,    45,    57,    47,
       3,    37,    95,   113,   272,   118,    99,    45,    66,    80,
     120,    62,   125,    84,    95,   144,   130,   131,   132,    99,
      95,   135,    46,    99,    83,    76,    95,   137,    64,    95,
       3,   100,    47,     3,    49,     3,   321,    99,    97,   168,
      90,     3,   100,    79,    80,    48,   175,    95,    95,   178,
     179,   131,     4,   100,   168,   135,   100,    95,   101,    99,
     101,   174,   246,   234,   227,   231,    32,   101,   222,   198,
     101,   255,     1,    46,   100,   238,    46,   100,    46,    45,
       4,   100,   195,   134,    46,   156,    16,     3,   168,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   220,    48,    45,
     161,    47,   161,    32,     3,     3,    45,   227,   231,   274,
     234,   250,   171,    32,   253,   254,    45,     3,   238,    95,
      46,    32,     3,    48,   318,   101,    45,    66,    47,    45,
      16,    47,   308,   256,    45,   161,    47,    45,   261,    47,
     101,    49,    50,    82,   317,   171,    95,    46,    46,    45,
      99,    47,    45,   101,   274,    30,    31,    32,    33,    34,
      99,   100,   356,   357,   358,    46,    95,    95,    45,   263,
      16,     4,   345,    45,   350,    45,    95,   371,    46,   118,
      88,    89,    32,    33,    34,   308,     3,   381,   382,    95,
     336,   130,   131,   132,    46,    48,   135,   317,    95,   260,
     260,   260,    16,    95,    48,    48,    95,   267,    16,    46,
      84,   271,   271,   101,   337,   354,   355,    48,    48,    48,
      53,    45,    48,    56,    57,   345,    46,   350,    61,   168,
      63,    64,    65,    46,    46,   174,    69,    70,    71,    48,
      73,    74,    75,    76,    48,    78,    79,    80,    81,    82,
      83,    48,    85,    86,   315,    28,    29,    30,    31,    32,
      33,    34,    62,    96,    97,   101,    99,   130,    21,    76,
     315,    72,   267,   168,   232,    40,   336,    30,    31,    32,
     308,    -1,    54,   156,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,    45,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    21,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    21,    99,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    54,    55,    -1,    -1,    58,
      59,    60,    30,    31,    32,    -1,    -1,    66,    67,    68,
      -1,    39,    40,    72,    -1,    43,    -1,    45,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    21,    88,
      89,    -1,    91,    92,    93,    94,    95,    30,    31,    32,
      99,    -1,   101,    -1,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      88,    89,    -1,    91,    92,    93,    94,    95,    30,    31,
      32,    -1,    -1,   101,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    -1,    45,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    88,    89,    -1,    91,    92,
      93,    94,    95,    30,    31,    32,    -1,    -1,   101,    -1,
      -1,    -1,    39,    40,    -1,    -1,    43,    -1,    45,    -1,
      47,    -1,    49,    -1,    -1,    21,    88,    89,    -1,    91,
      92,    93,    94,    95,    30,    31,    32,    99,   100,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,    45,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    88,    89,    -1,    91,    92,    93,    94,    95,    -1,
      -1,    15,    99,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    21,    88,    89,    -1,    91,    92,    93,    94,    95,
      30,    31,    32,    99,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,
      -1,    61,    -1,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    -1,    76,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    85,    86,    -1,    88,    89,
      21,    91,    92,    93,    94,    95,    -1,    97,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    21,    43,    -1,    45,    -1,    -1,    48,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    57,    -1,    -1,    39,
      40,    21,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    75,    -1,    -1,    57,    -1,    39,
      40,    -1,    83,    43,    -1,    45,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    75,    97,    57,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    92,    93,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      21,    91,    92,    93,    94,    95,    -1,    97,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    21,    39,    40,
      -1,    -1,    43,    -1,    45,    46,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    21,    -1,    43,
      -1,    45,    -1,    -1,    48,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    43,
      -1,    45,    -1,    -1,    48,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      94,    95,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    21,    88,    89,    -1,    91,    92,    93,
      94,    95,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      21,    39,    40,    -1,    -1,    43,    -1,    45,    46,    30,
      31,    32,    -1,    -1,    -1,    -1,    21,    -1,    39,    40,
      -1,    -1,    43,    -1,    45,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    88,    89,    -1,    91,    92,    93,    94,
      95,    30,    31,    32,    32,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    -1,    45,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    -1,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    85,    86,    88,
      89,    32,    91,    92,    93,    94,    95,    95,    96,    97,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    32,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    96,    97,    53,    -1,    -1,
      56,    57,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
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
      -1,    97,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
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
       0,    32,    45,    53,    56,    57,    61,    63,    64,    65,
      69,    70,    71,    73,    74,    75,    76,    78,    79,    80,
      81,    82,    83,    85,    86,    95,    96,    97,   103,   116,
     117,   120,   121,   122,   125,   131,   134,   135,   136,   138,
     162,   163,   164,   134,   138,   139,   135,    95,    99,   117,
       0,   101,   118,   119,   135,   117,   117,    95,    99,   117,
      99,   116,   117,   155,   166,    45,    47,   136,   163,   134,
     138,    46,    99,    95,   132,   133,     3,   101,     4,   165,
     166,    99,   124,   100,   156,   135,   116,   155,    46,    95,
     137,   143,    21,    30,    31,    32,    39,    40,    43,    45,
      75,    88,    89,    91,    92,    93,    94,    95,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   115,   139,   132,
       4,     3,   100,   119,    32,    99,   115,   147,   155,   155,
     123,   121,   126,   127,   128,   134,    54,    55,    58,    59,
      60,    66,    67,    68,    72,    77,    84,    95,   101,   114,
     115,   116,   152,   153,   154,   155,   157,   158,   159,   160,
     161,   117,   140,   141,   142,     3,    46,    48,    45,   108,
     114,   128,   144,   115,   139,    45,   108,   108,    45,    47,
      49,    50,    88,    89,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   113,   108,   110,    15,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    48,    32,    48,
      75,   115,     3,   100,   112,   100,   133,    47,    49,   147,
     148,   149,   150,   151,   126,   128,   100,   127,    16,   129,
     130,   135,   128,   101,   112,   101,    16,   152,    45,    95,
      45,   101,   114,    45,    45,    16,     3,   101,   100,   158,
      45,    47,   135,   138,   145,   146,    46,     3,    95,   144,
      46,    45,   138,   145,    46,    48,   115,    46,   114,   114,
      95,    95,   115,   114,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,    48,   115,    48,   100,   112,    95,     3,   100,
     147,     4,   151,   100,   112,     3,   101,    16,    16,   152,
      84,   154,   101,   114,   101,   114,   114,   152,   115,    46,
     140,   145,    32,    48,   115,   146,    45,    47,    98,   142,
      46,   110,    48,    46,    48,    16,    48,    48,   100,   147,
     149,   130,   112,   152,    45,   154,    46,    46,    46,    46,
      46,    48,    48,    46,   140,    32,    48,   115,   112,   147,
     114,    46,   114,   152,   152,   152,    46,    48,    48,    46,
     152,    46,    62,   101,   152,   152
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
     121,   121,   123,   122,   124,   122,   122,   125,   125,   126,
     126,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   136,   136,   136,   138,
     138,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   148,   148,   148,   148,   149,   150,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   153,   153,
     153,   154,   154,   155,   156,   155,   157,   157,   158,   158,
     159,   159,   159,   160,   160,   160,   160,   161,   161,   161,
     161,   161,   162,   162,   163,   163,   164,   165,   164,   164,
     164,   166,   166
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
       1,     1,     0,     6,     0,     5,     2,     1,     1,     1,
       2,     3,     1,     1,     2,     2,     1,     3,     1,     2,
       3,     4,     5,     5,     6,     2,     1,     3,     1,     3,
       1,     1,     1,     2,     1,     1,     3,     5,     4,     4,
       6,     5,     6,     5,     4,     0,     5,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     2,     3,     4,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     1,     2,     2,     0,     4,     1,     2,     1,     1,
       5,     7,     5,     5,     7,     6,     7,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     0,     4,     3,
       2,     1,     2
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
#line 115 "parsing.y"
                          {root = (yyval.astnode);}
#line 2054 "parsing.tab.c"
    break;

  case 3: /* pexp: ID  */
#line 118 "parsing.y"
         {(yyval.astnode)=astIdent((yyvsp[0].s).c);
symrec* rec = findsym(symtab_cur,(yyvsp[0].s).c,NAMESPACE_OTHERS);
if (!rec) {errors[errnum] = getError(yylineno,"primary expression not found"); errnum++;}
else {(yyval.astnode)->t = rec->type->head->next; (yyval.astnode)->tbl = symtab_cur;}
}
#line 2064 "parsing.tab.c"
    break;

  case 5: /* pexp: STR  */
#line 124 "parsing.y"
       {(yyval.astnode)=astString((yyvsp[0].s).c);}
#line 2070 "parsing.tab.c"
    break;

  case 6: /* pexp: '(' exp ')'  */
#line 125 "parsing.y"
               {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2076 "parsing.tab.c"
    break;

  case 7: /* number: NUM  */
#line 128 "parsing.y"
            {(yyval.astnode)=astNum((yyvsp[0].n).type == 0 ? _unsigned : _integer,(yyvsp[0].n).type == 0 ? (void *)&(yyvsp[0].n).u : (void *)&(yyvsp[0].n).i);}
#line 2082 "parsing.tab.c"
    break;

  case 8: /* number: NUMF  */
#line 129 "parsing.y"
        {(yyval.astnode)=astNum(_real,(void *)&(yyvsp[0].n).f);}
#line 2088 "parsing.tab.c"
    break;

  case 10: /* constant: CH  */
#line 133 "parsing.y"
      {int i; if ((yyvsp[0].s).l==2) i=0; else i=(yyvsp[0].s).c[0]; (yyval.astnode)=astNum(_unsigned,(void *)&i);}
#line 2094 "parsing.tab.c"
    break;

  case 12: /* postexp: postexp '[' exp ']'  */
#line 137 "parsing.y"
                       {(yyval.astnode) = astUnary('*',astBinary((yyvsp[-3].astnode),(yyvsp[-1].astnode)->list->head->value,'+'));}
#line 2100 "parsing.tab.c"
    break;

  case 13: /* postexp: postexp '(' ')'  */
#line 138 "parsing.y"
                   {(yyval.astnode) = astCall((yyvsp[-2].astnode),NULL);}
#line 2106 "parsing.tab.c"
    break;

  case 14: /* postexp: postexp '(' exp ')'  */
#line 139 "parsing.y"
                       {(yyval.astnode) = astCall((yyvsp[-3].astnode),(yyvsp[-1].astnode));}
#line 2112 "parsing.tab.c"
    break;

  case 15: /* postexp: postexp '.' ID  */
#line 140 "parsing.y"
                  {(yyval.astnode) = astBinary((yyvsp[-2].astnode),astIdent((yyvsp[0].s).c),'.');}
#line 2118 "parsing.tab.c"
    break;

  case 16: /* postexp: postexp ARROW ID  */
#line 141 "parsing.y"
                    {(yyval.astnode) = astBinary(astUnary('*',(yyvsp[-2].astnode)),astIdent((yyvsp[0].s).c),'.');}
#line 2124 "parsing.tab.c"
    break;

  case 17: /* postexp: postexp INC  */
#line 142 "parsing.y"
                             {(yyval.astnode) = astUnary(POSTINC,(yyvsp[-1].astnode));}
#line 2130 "parsing.tab.c"
    break;

  case 18: /* postexp: postexp DEC  */
#line 143 "parsing.y"
                             {(yyval.astnode) = astUnary(POSTDEC,(yyvsp[-1].astnode));}
#line 2136 "parsing.tab.c"
    break;

  case 20: /* unary: INC unary  */
#line 148 "parsing.y"
                          {(yyval.astnode) = astUnary(PREINC,(yyvsp[0].astnode));}
#line 2142 "parsing.tab.c"
    break;

  case 21: /* unary: DEC unary  */
#line 149 "parsing.y"
                          {(yyval.astnode) = astUnary(PREDEC,(yyvsp[0].astnode));}
#line 2148 "parsing.tab.c"
    break;

  case 22: /* unary: uop castexp  */
#line 150 "parsing.y"
               {(yyval.astnode) = astUnary((yyvsp[-1].i),(yyvsp[0].astnode));}
#line 2154 "parsing.tab.c"
    break;

  case 23: /* unary: SIZEOF unary  */
#line 151 "parsing.y"
                {(yyval.astnode) = astUnary(SIZEOF,(yyvsp[0].astnode));}
#line 2160 "parsing.tab.c"
    break;

  case 24: /* unary: SIZEOF '(' type_name ')'  */
#line 152 "parsing.y"
                                         {(yyval.astnode) = astUnary(SIZEOF,(yyvsp[-1].astnode));}
#line 2166 "parsing.tab.c"
    break;

  case 25: /* uop: '&'  */
#line 155 "parsing.y"
         {(yyval.i) = '&';}
#line 2172 "parsing.tab.c"
    break;

  case 26: /* uop: '*'  */
#line 156 "parsing.y"
       {(yyval.i) = '*';}
#line 2178 "parsing.tab.c"
    break;

  case 27: /* uop: '+'  */
#line 157 "parsing.y"
       {(yyval.i) = '+';}
#line 2184 "parsing.tab.c"
    break;

  case 28: /* uop: '-'  */
#line 158 "parsing.y"
       {(yyval.i) = '-';}
#line 2190 "parsing.tab.c"
    break;

  case 29: /* uop: '~'  */
#line 159 "parsing.y"
       {(yyval.i) = '~';}
#line 2196 "parsing.tab.c"
    break;

  case 30: /* uop: '!'  */
#line 160 "parsing.y"
       {(yyval.i) = '!';}
#line 2202 "parsing.tab.c"
    break;

  case 32: /* castexp: '(' type_name ')' castexp  */
#line 165 "parsing.y"
 {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),CAST);}
#line 2208 "parsing.tab.c"
    break;

  case 34: /* binary: binary '*' binary  */
#line 169 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'*');}
#line 2214 "parsing.tab.c"
    break;

  case 35: /* binary: binary '/' binary  */
#line 170 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'/');}
#line 2220 "parsing.tab.c"
    break;

  case 36: /* binary: binary '%' binary  */
#line 171 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'%');}
#line 2226 "parsing.tab.c"
    break;

  case 37: /* binary: binary '+' binary  */
#line 172 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'+');}
#line 2232 "parsing.tab.c"
    break;

  case 38: /* binary: binary '-' binary  */
#line 173 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'-');}
#line 2238 "parsing.tab.c"
    break;

  case 39: /* binary: binary LSHIFT binary  */
#line 174 "parsing.y"
                        {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),LSHIFT);}
#line 2244 "parsing.tab.c"
    break;

  case 40: /* binary: binary RSHIFT binary  */
#line 175 "parsing.y"
                        {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),RSHIFT);}
#line 2250 "parsing.tab.c"
    break;

  case 41: /* binary: binary '<' binary  */
#line 176 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'<');}
#line 2256 "parsing.tab.c"
    break;

  case 42: /* binary: binary '>' binary  */
#line 177 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'>');}
#line 2262 "parsing.tab.c"
    break;

  case 43: /* binary: binary LE binary  */
#line 178 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),LE);}
#line 2268 "parsing.tab.c"
    break;

  case 44: /* binary: binary GE binary  */
#line 179 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),GE);}
#line 2274 "parsing.tab.c"
    break;

  case 45: /* binary: binary NE binary  */
#line 180 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),NE);}
#line 2280 "parsing.tab.c"
    break;

  case 46: /* binary: binary EQ binary  */
#line 181 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),EQ);}
#line 2286 "parsing.tab.c"
    break;

  case 47: /* binary: binary '&' binary  */
#line 182 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'&');}
#line 2292 "parsing.tab.c"
    break;

  case 48: /* binary: binary '^' binary  */
#line 183 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'^');}
#line 2298 "parsing.tab.c"
    break;

  case 49: /* binary: binary '|' binary  */
#line 184 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'|');}
#line 2304 "parsing.tab.c"
    break;

  case 50: /* binary: binary AND binary  */
#line 185 "parsing.y"
                     {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),AND);}
#line 2310 "parsing.tab.c"
    break;

  case 51: /* binary: binary OR binary  */
#line 186 "parsing.y"
                    {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),OR);}
#line 2316 "parsing.tab.c"
    break;

  case 53: /* ternary: binary '?' exp ':' ternary  */
#line 190 "parsing.y"
                              {(yyval.astnode) = astCond((yyvsp[-4].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2322 "parsing.tab.c"
    break;

  case 54: /* aop: '='  */
#line 193 "parsing.y"
         {(yyval.i) = '=';}
#line 2328 "parsing.tab.c"
    break;

  case 55: /* aop: PLUSEQ  */
#line 194 "parsing.y"
          {(yyval.i) = PLUSEQ;}
#line 2334 "parsing.tab.c"
    break;

  case 56: /* aop: MINUSEQ  */
#line 195 "parsing.y"
           {(yyval.i) = MINUSEQ;}
#line 2340 "parsing.tab.c"
    break;

  case 57: /* aop: TIMESEQ  */
#line 196 "parsing.y"
           {(yyval.i) = TIMESEQ;}
#line 2346 "parsing.tab.c"
    break;

  case 58: /* aop: DIVEQ  */
#line 197 "parsing.y"
         {(yyval.i) = DIVEQ;}
#line 2352 "parsing.tab.c"
    break;

  case 59: /* aop: MODEQ  */
#line 198 "parsing.y"
         {(yyval.i) = MODEQ;}
#line 2358 "parsing.tab.c"
    break;

  case 60: /* aop: LSHIFTEQ  */
#line 199 "parsing.y"
            {(yyval.i) = LSHIFTEQ;}
#line 2364 "parsing.tab.c"
    break;

  case 61: /* aop: RSHIFTEQ  */
#line 200 "parsing.y"
            {(yyval.i) = RSHIFTEQ;}
#line 2370 "parsing.tab.c"
    break;

  case 62: /* aop: ANDEQ  */
#line 201 "parsing.y"
         {(yyval.i) = ANDEQ;}
#line 2376 "parsing.tab.c"
    break;

  case 63: /* aop: XOREQ  */
#line 202 "parsing.y"
         {(yyval.i) = XOREQ;}
#line 2382 "parsing.tab.c"
    break;

  case 64: /* aop: OREQ  */
#line 203 "parsing.y"
        {(yyval.i) = OREQ;}
#line 2388 "parsing.tab.c"
    break;

  case 65: /* exp: aexp  */
#line 206 "parsing.y"
          {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2394 "parsing.tab.c"
    break;

  case 66: /* exp: exp ',' aexp  */
#line 207 "parsing.y"
                {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2400 "parsing.tab.c"
    break;

  case 68: /* aexp: unary aop aexp  */
#line 211 "parsing.y"
                  {(yyval.astnode) = astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),(yyvsp[-1].i));}
#line 2406 "parsing.tab.c"
    break;

  case 69: /* decl: declspec ';'  */
#line 215 "parsing.y"
                       {(yyval.astnode)=astList((yyvsp[-1].astnode));}
#line 2412 "parsing.tab.c"
    break;

  case 70: /* decl: declspec initdecllist ';'  */
#line 216 "parsing.y"
                                    {(yyval.astnode)=(yyvsp[-1].astnode); bindDeclSpec((yyvsp[-2].astnode),(yyvsp[-1].astnode)); insertDecls(symtab_cur,(yyvsp[-1].astnode),yylineno);}
#line 2418 "parsing.tab.c"
    break;

  case 71: /* declspec: storage_class_specifier  */
#line 220 "parsing.y"
                                  {(yyval.astnode)=astTypeStg(_convspec((yyvsp[0].i)));}
#line 2424 "parsing.tab.c"
    break;

  case 72: /* declspec: storage_class_specifier declspec  */
#line 222 "parsing.y"
        {(yyval.astnode)=(yyvsp[0].astnode);
	if (addTypeStg((yyvsp[0].astnode),(yyvsp[-1].i))) {
		yyerror("more than one stg: %s %s",gettoken((yyvsp[-1].i)),gettoken((yyvsp[0].astnode)->type->stg));
	}}
#line 2433 "parsing.tab.c"
    break;

  case 73: /* declspec: type_specifier  */
#line 226 "parsing.y"
                         {(yyval.astnode)=astTypeSpec((yyvsp[0].astnode));}
#line 2439 "parsing.tab.c"
    break;

  case 74: /* declspec: type_specifier declspec  */
#line 227 "parsing.y"
                                  {
		int i = 0;
		if (i=addTypeSpec((yyvsp[0].astnode),(yyvsp[-1].astnode))) {
			fprintf(stderr,"invalid specifier combination %d, %d %s",i, (yyvsp[0].astnode)->type->scalar,gettoken((yyvsp[-1].astnode)->token));
		}
		(yyval.astnode)=(yyvsp[0].astnode);
	}
#line 2451 "parsing.tab.c"
    break;

  case 75: /* declspec: type_qualifier  */
#line 234 "parsing.y"
                         {(yyval.astnode)=astTypeQual(_convspec((yyvsp[0].i)));}
#line 2457 "parsing.tab.c"
    break;

  case 76: /* declspec: type_qualifier declspec  */
#line 235 "parsing.y"
                                  {
		(yyval.astnode)=(yyvsp[0].astnode);
		addTypeQual((yyvsp[0].astnode),(yyvsp[-1].i));
	}
#line 2466 "parsing.tab.c"
    break;

  case 79: /* initdecllist: initdeclr  */
#line 244 "parsing.y"
                    {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2472 "parsing.tab.c"
    break;

  case 80: /* initdecllist: initdecllist ',' initdeclr  */
#line 245 "parsing.y"
                                     {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2478 "parsing.tab.c"
    break;

  case 82: /* initdeclr: declr '=' init  */
#line 250 "parsing.y"
                         {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),'=');}
#line 2484 "parsing.tab.c"
    break;

  case 83: /* storage_class_specifier: TYPEDEF  */
#line 254 "parsing.y"
                  {(yyval.i)=TYPEDEF;}
#line 2490 "parsing.tab.c"
    break;

  case 84: /* storage_class_specifier: EXTERN  */
#line 255 "parsing.y"
                 {(yyval.i)=EXTERN;}
#line 2496 "parsing.tab.c"
    break;

  case 85: /* storage_class_specifier: STATIC  */
#line 256 "parsing.y"
                 {(yyval.i)=STATIC;}
#line 2502 "parsing.tab.c"
    break;

  case 86: /* storage_class_specifier: AUTO  */
#line 257 "parsing.y"
               {(yyval.i)=AUTO;}
#line 2508 "parsing.tab.c"
    break;

  case 87: /* storage_class_specifier: REGISTER  */
#line 258 "parsing.y"
                   {(yyval.i)=REGISTER;}
#line 2514 "parsing.tab.c"
    break;

  case 88: /* type_specifier: VOID  */
#line 262 "parsing.y"
               {(yyval.astnode) = astToken(VOID);}
#line 2520 "parsing.tab.c"
    break;

  case 89: /* type_specifier: CHAR  */
#line 263 "parsing.y"
               {(yyval.astnode) = astToken(CHAR);}
#line 2526 "parsing.tab.c"
    break;

  case 90: /* type_specifier: SHORT  */
#line 264 "parsing.y"
                {(yyval.astnode) = astToken(SHORT);}
#line 2532 "parsing.tab.c"
    break;

  case 91: /* type_specifier: INT  */
#line 265 "parsing.y"
              {(yyval.astnode) = astToken(INT);}
#line 2538 "parsing.tab.c"
    break;

  case 92: /* type_specifier: LONG  */
#line 266 "parsing.y"
               {(yyval.astnode) = astToken(LONG);}
#line 2544 "parsing.tab.c"
    break;

  case 93: /* type_specifier: FLOAT  */
#line 267 "parsing.y"
                {(yyval.astnode) = astToken(FLOAT);}
#line 2550 "parsing.tab.c"
    break;

  case 94: /* type_specifier: DOUBLE  */
#line 268 "parsing.y"
                 {(yyval.astnode) = astToken(DOUBLE);}
#line 2556 "parsing.tab.c"
    break;

  case 95: /* type_specifier: SIGNED  */
#line 269 "parsing.y"
                 {(yyval.astnode) = astToken(SIGNED);}
#line 2562 "parsing.tab.c"
    break;

  case 96: /* type_specifier: UNSIGNED  */
#line 270 "parsing.y"
                   {(yyval.astnode) = astToken(UNSIGNED);}
#line 2568 "parsing.tab.c"
    break;

  case 97: /* type_specifier: BOOL  */
#line 271 "parsing.y"
           {(yyval.astnode) = astToken(BOOL);}
#line 2574 "parsing.tab.c"
    break;

  case 98: /* type_specifier: COMPLEX  */
#line 272 "parsing.y"
              {(yyval.astnode) = astToken(COMPLEX);}
#line 2580 "parsing.tab.c"
    break;

  case 101: /* type_specifier: TYPENAME  */
#line 275 "parsing.y"
                   {(yyval.astnode) = astIdent((yyvsp[0].s).c);}
#line 2586 "parsing.tab.c"
    break;

  case 102: /* @1: %empty  */
#line 279 "parsing.y"
                       {
		(yyval.astnode) = astStrun((yyvsp[-2].i),astIdent((yyvsp[-1].s).c),NULL);
		insertStrun(symtab_cur,(yyval.astnode),yylineno);
	symtab_cur = createTable(symtab_cur,yylineno,SCOPE_OBJ);
		}
#line 2596 "parsing.tab.c"
    break;

  case 103: /* struct_or_union_specifier: strun ID '{' @1 struct_declaration_list '}'  */
#line 283 "parsing.y"
                                              {(yyvsp[-2].astnode)->obj->members=(yyvsp[-1].astnode); symtab_cur = symtab_cur->parent; setSymComplete(symtab_cur,(yyvsp[-2].astnode)); (yyval.astnode)=(yyvsp[-2].astnode);}
#line 2602 "parsing.tab.c"
    break;

  case 104: /* @2: %empty  */
#line 284 "parsing.y"
                    {
		(yyval.astnode) = astStrun((yyvsp[-1].i),astIdent("(anonymous)"),NULL);
		insertStrun(symtab_cur,(yyval.astnode),yylineno);
	symtab_cur = createTable(symtab_cur,yylineno,SCOPE_OBJ);}
#line 2611 "parsing.tab.c"
    break;

  case 105: /* struct_or_union_specifier: strun '{' @2 struct_declaration_list '}'  */
#line 287 "parsing.y"
                                                                                              {(yyvsp[-2].astnode)->obj->members=(yyvsp[-1].astnode); symtab_cur = symtab_cur->parent; setSymComplete(symtab_cur,(yyvsp[-2].astnode)); (yyval.astnode)=(yyvsp[-2].astnode);}
#line 2617 "parsing.tab.c"
    break;

  case 106: /* struct_or_union_specifier: strun ID  */
#line 288 "parsing.y"
                   {(yyval.astnode)=astStrun((yyvsp[-1].i),astIdent((yyvsp[0].s).c),NULL); insertStrun(symtab_cur,(yyval.astnode),yylineno);}
#line 2623 "parsing.tab.c"
    break;

  case 107: /* strun: STRUCT  */
#line 290 "parsing.y"
              {(yyval.i)=STRUCT;}
#line 2629 "parsing.tab.c"
    break;

  case 108: /* strun: UNION  */
#line 291 "parsing.y"
                {(yyval.i)=UNION;}
#line 2635 "parsing.tab.c"
    break;

  case 110: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 296 "parsing.y"
                                                     {mergeLists((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 2641 "parsing.tab.c"
    break;

  case 111: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 300 "parsing.y"
                                                              {(yyval.astnode)=(yyvsp[-1].astnode); bindDeclSpecStruct((yyvsp[-2].astnode),(yyvsp[-1].astnode)); insertMembers(symtab_cur,(yyvsp[-1].astnode),yylineno);}
#line 2647 "parsing.tab.c"
    break;

  case 112: /* specifier_qualifier_list: type_specifier  */
#line 304 "parsing.y"
                         {(yyval.astnode) = astTypeSpec((yyvsp[0].astnode));}
#line 2653 "parsing.tab.c"
    break;

  case 113: /* specifier_qualifier_list: type_qualifier  */
#line 305 "parsing.y"
                         {(yyval.astnode) = astTypeQual(_convspec((yyvsp[0].i)));}
#line 2659 "parsing.tab.c"
    break;

  case 114: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 306 "parsing.y"
                                                  {(yyval.astnode)=(yyvsp[0].astnode); 
	if (addTypeSpec((yyvsp[0].astnode),(yyvsp[-1].astnode))) {
		yyerror("specificer error");
	}}
#line 2668 "parsing.tab.c"
    break;

  case 115: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 310 "parsing.y"
                                                  {(yyval.astnode)=(yyvsp[0].astnode);
	if (addTypeQual((yyvsp[0].astnode),(yyvsp[-1].i))){
		yyerror("qualifier error");
	}}
#line 2677 "parsing.tab.c"
    break;

  case 116: /* struct_declarator_list: struct_declarator  */
#line 317 "parsing.y"
                             {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2683 "parsing.tab.c"
    break;

  case 117: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 318 "parsing.y"
                                                       {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2689 "parsing.tab.c"
    break;

  case 118: /* struct_declarator: declr  */
#line 322 "parsing.y"
                {(yyval.astnode) = astMember((yyvsp[0].astnode),0);}
#line 2695 "parsing.tab.c"
    break;

  case 119: /* struct_declarator: ':' ternary  */
#line 323 "parsing.y"
                      {(yyval.astnode) = astMember(astDecl(NULL),(yyvsp[0].astnode));}
#line 2701 "parsing.tab.c"
    break;

  case 120: /* struct_declarator: declr ':' ternary  */
#line 324 "parsing.y"
                            {(yyval.astnode) = astMember((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2707 "parsing.tab.c"
    break;

  case 121: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 328 "parsing.y"
                                       {(yyval.astnode)=astBinary(NULL,(yyvsp[-1].astnode),ENUM);}
#line 2713 "parsing.tab.c"
    break;

  case 122: /* enum_specifier: ENUM ID '{' enumerator_list '}'  */
#line 329 "parsing.y"
                                          {(yyval.astnode)=astBinary(astIdent((yyvsp[-3].s).c),(yyvsp[-1].astnode),ENUM);}
#line 2719 "parsing.tab.c"
    break;

  case 123: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 330 "parsing.y"
                                           {(yyval.astnode)=astBinary(NULL,(yyvsp[-2].astnode),ENUM);}
#line 2725 "parsing.tab.c"
    break;

  case 124: /* enum_specifier: ENUM ID '{' enumerator_list ',' '}'  */
#line 331 "parsing.y"
                                              {(yyval.astnode)=astBinary(astIdent((yyvsp[-4].s).c),(yyvsp[-2].astnode),ENUM);}
#line 2731 "parsing.tab.c"
    break;

  case 125: /* enum_specifier: ENUM ID  */
#line 332 "parsing.y"
                  {(yyval.astnode)=astBinary(astIdent((yyvsp[0].s).c),NULL,ENUM);}
#line 2737 "parsing.tab.c"
    break;

  case 126: /* enumerator_list: enumerator  */
#line 336 "parsing.y"
                     {(yyval.astnode) = astList((yyvsp[0].astnode));}
#line 2743 "parsing.tab.c"
    break;

  case 127: /* enumerator_list: enumerator_list ',' enumerator  */
#line 337 "parsing.y"
                                         {insertAstList((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2749 "parsing.tab.c"
    break;

  case 128: /* enumerator: ID  */
#line 341 "parsing.y"
             {(yyval.astnode)=astIdent((yyvsp[0].s).c);}
#line 2755 "parsing.tab.c"
    break;

  case 129: /* enumerator: ID '=' ternary  */
#line 342 "parsing.y"
                          {(yyval.astnode) = astBinary(astIdent((yyvsp[-2].s).c),(yyvsp[0].astnode),'=');}
#line 2761 "parsing.tab.c"
    break;

  case 130: /* type_qualifier: CONST  */
#line 346 "parsing.y"
                {(yyval.i)=CONST;}
#line 2767 "parsing.tab.c"
    break;

  case 131: /* type_qualifier: VOLATILE  */
#line 347 "parsing.y"
                   {(yyval.i)=VOLATILE;}
#line 2773 "parsing.tab.c"
    break;

  case 132: /* type_qualifier: RESTRICT  */
#line 348 "parsing.y"
                   {(yyval.i)=RESTRICT;}
#line 2779 "parsing.tab.c"
    break;

  case 133: /* declr: pointer direct_declarator  */
#line 352 "parsing.y"
                                    {mergeLists((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode)); (yyval.astnode)=(yyvsp[0].astnode);}
#line 2785 "parsing.tab.c"
    break;

  case 135: /* direct_declarator: ID  */
#line 357 "parsing.y"
             {(yyval.astnode)=astDecl(astIdent((yyvsp[0].s).c));}
#line 2791 "parsing.tab.c"
    break;

  case 136: /* direct_declarator: '(' declr ')'  */
#line 358 "parsing.y"
                        {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2797 "parsing.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator '[' aexp ']'  */
#line 360 "parsing.y"
                                         {checkdeclr((yyvsp[-3].astnode),AST_ARRAY,yylineno); insertAstListTail((yyvsp[-3].astnode)->decl->type,astArray((yyvsp[-1].astnode)));}
#line 2803 "parsing.tab.c"
    break;

  case 145: /* $@3: %empty  */
#line 367 "parsing.y"
                                {prototype = createTable(symtab_cur,yylineno,SCOPE_BLOCK); symtab_cur = prototype;}
#line 2809 "parsing.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator '(' $@3 parameter_type_list ')'  */
#line 367 "parsing.y"
                                                                                                                                            {checkdeclr((yyvsp[-4].astnode),AST_FUNC,yylineno); insertAstListTail((yyvsp[-4].astnode)->decl->type,astFunc((yyvsp[-1].astnode))); symtab_cur = symtab_cur->parent;}
#line 2815 "parsing.tab.c"
    break;

  case 147: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 368 "parsing.y"
                                                    {checkdeclr((yyvsp[-3].astnode),AST_FUNC,yylineno); insertAstListTail((yyvsp[-3].astnode)->decl->type,astFunc((yyvsp[-1].astnode)));}
#line 2821 "parsing.tab.c"
    break;

  case 148: /* direct_declarator: direct_declarator '(' ')'  */
#line 369 "parsing.y"
                                    {checkdeclr((yyvsp[-2].astnode),AST_FUNC,yylineno); insertAstListTail((yyvsp[-2].astnode)->decl->type,astFunc(NULL));}
#line 2827 "parsing.tab.c"
    break;

  case 149: /* pointer: '*'  */
#line 373 "parsing.y"
              {(yyval.astnode)=astList(astPtr(0));}
#line 2833 "parsing.tab.c"
    break;

  case 150: /* pointer: '*' type_qualifier_list  */
#line 374 "parsing.y"
                                  {(yyval.astnode)=astList(astPtr((yyvsp[0].i)));}
#line 2839 "parsing.tab.c"
    break;

  case 151: /* pointer: '*' pointer  */
#line 375 "parsing.y"
                      {insertAstListTail((yyvsp[0].astnode),astPtr(0)); (yyval.astnode)=(yyvsp[0].astnode);}
#line 2845 "parsing.tab.c"
    break;

  case 152: /* pointer: '*' type_qualifier_list pointer  */
#line 376 "parsing.y"
                                          {insertAstListTail((yyvsp[0].astnode),astPtr((yyvsp[-1].i))); (yyval.astnode)=(yyvsp[0].astnode);}
#line 2851 "parsing.tab.c"
    break;

  case 153: /* type_qualifier_list: type_qualifier  */
#line 380 "parsing.y"
                         {(yyval.i) = _convspec((yyvsp[0].i));}
#line 2857 "parsing.tab.c"
    break;

  case 154: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 381 "parsing.y"
                                             {(yyval.i) = (yyval.i) | _convspec((yyvsp[0].i));}
#line 2863 "parsing.tab.c"
    break;

  case 156: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 387 "parsing.y"
                                      {insertAstListTail((yyvsp[-2].astnode),astToken(ELLIPSIS));}
#line 2869 "parsing.tab.c"
    break;

  case 157: /* parameter_list: parameter_declaration  */
#line 391 "parsing.y"
                                {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2875 "parsing.tab.c"
    break;

  case 158: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 392 "parsing.y"
                                                   {insertAstListTail((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 2881 "parsing.tab.c"
    break;

  case 159: /* parameter_declaration: declspec declr  */
#line 396 "parsing.y"
                         {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode)); insertDecl(symtab_cur,(yyvsp[0].astnode),yylineno);}
#line 2887 "parsing.tab.c"
    break;

  case 160: /* parameter_declaration: declspec abstract_declarator  */
#line 397 "parsing.y"
                                       {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2893 "parsing.tab.c"
    break;

  case 161: /* parameter_declaration: declspec  */
#line 398 "parsing.y"
                   {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 2899 "parsing.tab.c"
    break;

  case 162: /* identifier_list: ID  */
#line 402 "parsing.y"
             {(yyval.astnode)=astList(astIdent((yyvsp[0].s).c));}
#line 2905 "parsing.tab.c"
    break;

  case 163: /* identifier_list: identifier_list ',' ID  */
#line 403 "parsing.y"
                                 {insertAstListTail((yyvsp[-2].astnode),astIdent((yyvsp[0].s).c));}
#line 2911 "parsing.tab.c"
    break;

  case 164: /* type_name: specifier_qualifier_list  */
#line 407 "parsing.y"
                                   {(yyval.astnode)=astAbsDecl((yyvsp[0].astnode));}
#line 2917 "parsing.tab.c"
    break;

  case 165: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 408 "parsing.y"
                                                       {(yyval.astnode)=(yyvsp[0].astnode); insertAstListTail((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode));}
#line 2923 "parsing.tab.c"
    break;

  case 166: /* abstract_declarator: pointer  */
#line 412 "parsing.y"
                  {(yyval.astnode)=astAbsDeclfromList((yyvsp[0].astnode));}
#line 2929 "parsing.tab.c"
    break;

  case 168: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 414 "parsing.y"
                                             {mergeLists((yyvsp[0].astnode)->decl->type,(yyvsp[-1].astnode)); (yyval.astnode)=(yyvsp[0].astnode); }
#line 2935 "parsing.tab.c"
    break;

  case 169: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 418 "parsing.y"
                                      {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2941 "parsing.tab.c"
    break;

  case 170: /* direct_abstract_declarator: '[' ']'  */
#line 419 "parsing.y"
                  {(yyval.astnode)=astAbsDecl(astArray(astNum(_integer,0)));}
#line 2947 "parsing.tab.c"
    break;

  case 171: /* direct_abstract_declarator: '[' aexp ']'  */
#line 420 "parsing.y"
                       {(yyval.astnode)=astAbsDecl(astArray((yyvsp[-1].astnode)));}
#line 2953 "parsing.tab.c"
    break;

  case 172: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 421 "parsing.y"
                                             {checkdeclr((yyvsp[-2].astnode),AST_ARRAY,yylineno); insertAstListTail((yyvsp[-2].astnode),astArray(astNum(_integer,0)));}
#line 2959 "parsing.tab.c"
    break;

  case 173: /* direct_abstract_declarator: direct_abstract_declarator '[' aexp ']'  */
#line 422 "parsing.y"
                                                  {checkdeclr((yyvsp[-3].astnode),AST_ARRAY,yylineno); insertAstListTail((yyvsp[-3].astnode),astArray((yyvsp[-1].astnode)));}
#line 2965 "parsing.tab.c"
    break;

  case 176: /* direct_abstract_declarator: '(' ')'  */
#line 425 "parsing.y"
                  {(yyval.astnode)=astList(astFunc(NULL));}
#line 2971 "parsing.tab.c"
    break;

  case 177: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 426 "parsing.y"
                                      {(yyval.astnode)=astList(astFunc((yyvsp[-1].astnode)));}
#line 2977 "parsing.tab.c"
    break;

  case 178: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 427 "parsing.y"
                                             {checkdeclr((yyvsp[-2].astnode),AST_FUNC,yylineno); insertAstListTail((yyvsp[-2].astnode),astFunc(NULL));}
#line 2983 "parsing.tab.c"
    break;

  case 179: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 428 "parsing.y"
                                                                 {checkdeclr((yyvsp[-3].astnode),AST_FUNC,yylineno); insertAstListTail((yyvsp[-3].astnode),astFunc((yyvsp[-1].astnode)));}
#line 2989 "parsing.tab.c"
    break;

  case 181: /* init: '{' initlist '}'  */
#line 433 "parsing.y"
                           {(yyval.astnode)=(yyvsp[-1].astnode);}
#line 2995 "parsing.tab.c"
    break;

  case 182: /* init: '{' initlist ',' '}'  */
#line 434 "parsing.y"
                               {(yyval.astnode)=(yyvsp[-2].astnode);}
#line 3001 "parsing.tab.c"
    break;

  case 183: /* initlist: init  */
#line 438 "parsing.y"
               {(yyval.astnode)=astList((yyvsp[0].astnode));}
#line 3007 "parsing.tab.c"
    break;

  case 185: /* initlist: initlist ',' init  */
#line 440 "parsing.y"
                            {insertAstList((yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3013 "parsing.tab.c"
    break;

  case 186: /* initlist: initlist ',' designation init  */
#line 441 "parsing.y"
                                        {insertAstList((yyvsp[-3].astnode),(yyvsp[0].astnode));}
#line 3019 "parsing.tab.c"
    break;

  case 194: /* stmt: exps  */
#line 460 "parsing.y"
               {gen_expr((yyvsp[0].astnode));}
#line 3025 "parsing.tab.c"
    break;

  case 195: /* stmt: selects  */
#line 461 "parsing.y"
                  {gen_if((yyvsp[0].astnode));}
#line 3031 "parsing.tab.c"
    break;

  case 198: /* labelstmt: ID ':' stmt  */
#line 467 "parsing.y"
                      {(yyval.astnode)=astBinary(astIdent((yyvsp[-2].s).c),(yyvsp[0].astnode),':'); insertLabel(symtab_cur,(yyval.astnode),yylineno);}
#line 3037 "parsing.tab.c"
    break;

  case 199: /* labelstmt: CASE ternary ':' stmt  */
#line 468 "parsing.y"
                                {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),CASE);}
#line 3043 "parsing.tab.c"
    break;

  case 200: /* labelstmt: DEFAULT ':' stmt  */
#line 469 "parsing.y"
                           {(yyval.astnode)=astBinary(NULL,(yyvsp[0].astnode),DEFAULT);}
#line 3049 "parsing.tab.c"
    break;

  case 201: /* exps: ';'  */
#line 472 "parsing.y"
          {(yyval.astnode) = NULL;}
#line 3055 "parsing.tab.c"
    break;

  case 202: /* exps: exp ';'  */
#line 473 "parsing.y"
           {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 3061 "parsing.tab.c"
    break;

  case 203: /* compoundstmt: '{' '}'  */
#line 477 "parsing.y"
           {(yyval.astnode)=astBlockList(NULL);}
#line 3067 "parsing.tab.c"
    break;

  case 204: /* $@4: %empty  */
#line 478 "parsing.y"
       {
	if (funcsym == 0)
 		symtab_cur = createTable(symtab_cur,yylineno,SCOPE_BLOCK);
	else
		symtab_cur = prototype;
	}
#line 3078 "parsing.tab.c"
    break;

  case 205: /* compoundstmt: '{' $@4 block_item_list '}'  */
#line 483 "parsing.y"
                              {(yyval.astnode)=(yyvsp[-1].astnode); (yyval.astnode)->tbl = symtab_cur; symtab_cur = symtab_cur->parent;}
#line 3084 "parsing.tab.c"
    break;

  case 206: /* block_item_list: block_item  */
#line 487 "parsing.y"
              {if ((yyvsp[0].astnode)->nodetype != AST_LIST) (yyval.astnode)=astBlockList((yyvsp[0].astnode)); else (yyvsp[0].astnode)->nodetype = AST_BLOCKLIST;}
#line 3090 "parsing.tab.c"
    break;

  case 207: /* block_item_list: block_item_list block_item  */
#line 488 "parsing.y"
                              {(yyval.astnode)=(yyvsp[-1].astnode); if ((yyvsp[0].astnode)->nodetype != AST_LIST) insertAstListTail((yyvsp[-1].astnode),(yyvsp[0].astnode)); else mergeLists((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3096 "parsing.tab.c"
    break;

  case 210: /* selects: IF '(' exp ')' stmt  */
#line 498 "parsing.y"
                              {(yyval.astnode)=astCond((yyvsp[-2].astnode),(yyvsp[0].astnode),NULL); }
#line 3102 "parsing.tab.c"
    break;

  case 211: /* selects: IF '(' exp ')' stmt ELSE stmt  */
#line 499 "parsing.y"
                                        {(yyval.astnode)=astCond((yyvsp[-4].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3108 "parsing.tab.c"
    break;

  case 212: /* selects: SWITCH '(' exp ')' stmt  */
#line 500 "parsing.y"
                                  {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),SWITCH);}
#line 3114 "parsing.tab.c"
    break;

  case 213: /* iters: WHILE '(' exp ')' stmt  */
#line 504 "parsing.y"
                                 {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[0].astnode),WHILE);}
#line 3120 "parsing.tab.c"
    break;

  case 214: /* iters: DO stmt WHILE '(' exp ')' ';'  */
#line 505 "parsing.y"
                                        {(yyval.astnode)=astBinary((yyvsp[-2].astnode),(yyvsp[-5].astnode),DO);}
#line 3126 "parsing.tab.c"
    break;

  case 215: /* iters: FOR '(' exps exps ')' stmt  */
#line 507 "parsing.y"
        {(yyval.astnode)=astFor((yyvsp[-3].astnode),(yyvsp[-2].astnode),NULL,(yyvsp[0].astnode));}
#line 3132 "parsing.tab.c"
    break;

  case 216: /* iters: FOR '(' exps exps exp ')' stmt  */
#line 509 "parsing.y"
        {(yyval.astnode)=astFor((yyvsp[-4].astnode),(yyvsp[-3].astnode),(yyvsp[-2].astnode),(yyvsp[0].astnode));}
#line 3138 "parsing.tab.c"
    break;

  case 217: /* jmps: GOTO ID ';'  */
#line 513 "parsing.y"
                      {(yyval.astnode)=astUnary(GOTO,astIdent((yyvsp[-1].s).c));}
#line 3144 "parsing.tab.c"
    break;

  case 218: /* jmps: CONTINUE ';'  */
#line 514 "parsing.y"
                       {(yyval.astnode)=astUnary(CONTINUE,NULL);}
#line 3150 "parsing.tab.c"
    break;

  case 219: /* jmps: BREAK ';'  */
#line 515 "parsing.y"
                    {(yyval.astnode)=astUnary(BREAK,NULL);}
#line 3156 "parsing.tab.c"
    break;

  case 220: /* jmps: RETURN ';'  */
#line 516 "parsing.y"
                     {(yyval.astnode)=astUnary(RETURN,NULL); gen_ret((yyval.astnode));}
#line 3162 "parsing.tab.c"
    break;

  case 221: /* jmps: RETURN exp ';'  */
#line 517 "parsing.y"
                         {(yyval.astnode)=astUnary(RETURN,(yyvsp[-1].astnode)); gen_ret((yyval.astnode));}
#line 3168 "parsing.tab.c"
    break;

  case 223: /* translation_unit: translation_unit external_declaration  */
#line 522 "parsing.y"
                                                {mergeLists((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3174 "parsing.tab.c"
    break;

  case 224: /* external_declaration: funcdef  */
#line 526 "parsing.y"
                  {(yyval.astnode)=astList((yyvsp[0].astnode)); newBlock(NULL);}
#line 3180 "parsing.tab.c"
    break;

  case 226: /* funcdef: declspec declr declaration_list compoundstmt  */
#line 531 "parsing.y"
                                                       {(yyval.astnode)=astFuncDef((yyvsp[-2].astnode),(yyvsp[-2].astnode)->decl->ident,(yyvsp[0].astnode)); insertFuncDef(symtab_cur,(yyval.astnode),yylineno);}
#line 3186 "parsing.tab.c"
    break;

  case 227: /* @5: %empty  */
#line 532 "parsing.y"
                         {funcsym=1;
	(yyval.astnode)=astFuncDef((yyvsp[0].astnode),(yyvsp[0].astnode)->decl->ident,0);
	bindDeclDef((yyvsp[-1].astnode),(yyval.astnode));
	//free($2->decl);
	insertFuncDef(symtab_cur,(yyval.astnode),yylineno);
	}
#line 3197 "parsing.tab.c"
    break;

  case 228: /* funcdef: declspec declr @5 compoundstmt  */
#line 537 "parsing.y"
                       {funcsym=0; (yyvsp[-1].astnode)->funcdef->stmt = (yyvsp[0].astnode);}
#line 3203 "parsing.tab.c"
    break;

  case 229: /* funcdef: declr declaration_list compoundstmt  */
#line 538 "parsing.y"
                                              {insertAstListTail((yyvsp[-2].astnode)->decl->type,astTypeSpec(astToken(INT))); (yyval.astnode)=astFuncDef((yyvsp[-2].astnode),(yyvsp[-2].astnode)->decl->ident,(yyvsp[0].astnode));}
#line 3209 "parsing.tab.c"
    break;

  case 230: /* funcdef: declr compoundstmt  */
#line 539 "parsing.y"
                             {insertAstListTail((yyvsp[-1].astnode)->decl->type,astTypeSpec(astToken(INT))); (yyval.astnode)=astFuncDef((yyvsp[-1].astnode),(yyvsp[-1].astnode)->decl->ident,(yyvsp[0].astnode));}
#line 3215 "parsing.tab.c"
    break;

  case 232: /* declaration_list: declaration_list decl  */
#line 544 "parsing.y"
                                {mergeLists((yyvsp[-1].astnode),(yyvsp[0].astnode));}
#line 3221 "parsing.tab.c"
    break;


#line 3225 "parsing.tab.c"

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

#line 547 "parsing.y"

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
	symtab_file = createTable(NULL,0,SCOPE_FILE);
	symtab_file->root = symtab_file;
	symtab_cur = symtab_file;
	errors = (ERROR**) malloc(sizeof(ERROR*)*1024);
	errnum=0;
	getBlocks();
     newBlock(NULL);
	yyparse();
	printErrors(errors,errnum);
    printast(root,0);
	
	printBlocks();
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
