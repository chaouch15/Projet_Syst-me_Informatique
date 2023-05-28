/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lex.y"

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "tab_instru.h"
#include "Jump_manager.h"
#include "interpreteur.h"
#include "Function_manager.h"
#include "cross_compiler.h"

int yylex (void);
void yyerror (const char *);

extern int la_profondeur;
#define STACKSIZE 200

#line 87 "lex.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_LEX_TAB_H_INCLUDED
# define YY_YY_LEX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tIF = 258,
    tELSE = 259,
    tWHILE = 260,
    tPRINT = 261,
    tRETURN = 262,
    tASSIGN = 263,
    tLBRACE = 264,
    tRBRACE = 265,
    tLPAR = 266,
    tRPAR = 267,
    tSEMI = 268,
    tCOMMA = 269,
    tCOMP = 270,
    tERROR = 271,
    tCONST = 272,
    TYPE = 273,
    PROFONDEUR = 274,
    ADDRESS = 275,
    tTID = 276,
    tADD = 277,
    tMUL = 278,
    tDIV = 279,
    tSUB = 280,
    tEQ = 281,
    tLT = 282,
    tGT = 283,
    tNE = 284,
    tGE = 285,
    tLE = 286,
    tNB = 287,
    tVOID = 288,
    tINT = 289,
    tID = 290,
    tMain = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "lex.y"

    int num;
    char* c;

#line 181 "lex.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LEX_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    55,    56,    57,    58,    61,    61,    61,
      62,    62,    73,    76,    76,    77,    77,    77,    78,    78,
      87,    88,    89,    89,    93,    94,    95,   104,   105,   110,
     111,   112,   113,   119,   120,   125,   126,   131,   131,   137,
     137,   138,   138,   139,   140,   143,   147,   151,   154,   155,
     156,   162,   162,   163,   163,   164,   164,   165,   165,   169,
     170,   173,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   184,   183,   191,   198,   197,   213,
     212,   227,   232,   232,   241,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tIF", "tELSE", "tWHILE", "tPRINT",
  "tRETURN", "tASSIGN", "tLBRACE", "tRBRACE", "tLPAR", "tRPAR", "tSEMI",
  "tCOMMA", "tCOMP", "tERROR", "tCONST", "TYPE", "PROFONDEUR", "ADDRESS",
  "tTID", "tADD", "tMUL", "tDIV", "tSUB", "tEQ", "tLT", "tGT", "tNE",
  "tGE", "tLE", "tNB", "tVOID", "tINT", "tID", "tMain", "$accept",
  "Program", "Statement", "Fonction", "$@1", "$@2", "$@3", "Declaration",
  "Main", "$@4", "$@5", "$@6", "$@7", "Args", "$@8", "Body", "BodyDec",
  "BodyInstru", "incr_prof", "decr_prof", "Initialisationc", "Call", "$@9",
  "Initialisation", "$@10", "$@11", "Printf", "Affect", "Val", "Operation",
  "$@12", "$@13", "$@14", "$@15", "LVal", "Logic", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "If", "$@22", "Else", "$@23", "While", "$@24",
  "BodyCond", "Parametre", "Return", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,   -29,   -24,  -126,    22,    67,  -126,  -126,  -126,     8,
    -126,  -126,    51,  -126,  -126,  -126,    52,  -126,  -126,    70,
      64,    48,    78,  -126,    52,    82,    93,    69,    94,    15,
      96,    99,   100,    15,    91,  -126,   101,    76,    79,   105,
     106,    -1,    -1,    65,     4,   102,   108,    30,    30,   107,
    -126,   -12,   105,   109,  -126,   110,    39,   -12,  -126,  -126,
    -126,   112,   113,  -126,  -126,  -126,  -126,   116,   114,   114,
    -126,    48,  -126,  -126,     6,  -126,    92,  -126,    79,    74,
      -8,    -8,  -126,  -126,    15,    34,  -126,   115,  -126,   117,
     -12,   -12,   -12,   -12,  -126,    97,   -12,  -126,   -12,    74,
      62,   119,   121,   124,   -12,    74,   122,   126,  -126,    74,
      74,    74,    74,   118,  -126,    74,    49,    -8,    -8,    -8,
      -8,    -8,    -8,  -126,  -126,  -126,    55,   127,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   129,   129,  -126,  -126,   -12,  -126,  -126,  -126,  -126,
    -126,  -126,    15,   135,  -126,    61,   128,   131,  -126,  -126,
     -12,  -126,  -126,   129,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,     0,    18,     0,     2,     4,     5,    10,     0,
      33,    13,     0,     1,     6,     3,     0,    16,     7,     0,
       0,    20,     0,    33,     0,     0,     0,     0,     0,    33,
       0,     0,     0,    33,    21,    12,     0,     0,     0,     0,
       0,    24,    24,     0,    33,     0,     0,    33,    33,     0,
      22,    47,    35,     0,    36,    44,     0,    47,    11,    26,
      25,     0,     0,    34,    34,    29,    30,     0,     0,     0,
      19,    20,    49,    48,     0,    28,    41,    27,     0,    46,
      47,    47,    32,    31,    33,    47,     8,     0,    23,     0,
      47,    47,    47,    47,    50,     0,    47,    43,    47,    59,
      61,     0,     0,     0,    47,    85,     0,     0,    45,    51,
      53,    55,    57,     0,    40,    42,     0,    47,    47,    47,
      47,    47,    47,    74,    79,    17,     0,     0,    14,    52,
      54,    56,    58,    37,    60,    62,    64,    66,    68,    70,
      72,     0,     0,    84,     9,    47,    63,    65,    67,    69,
      71,    73,    33,    76,    80,    82,     0,     0,    77,    75,
      47,    38,    81,     0,    83,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,   137,  -126,  -126,  -126,   120,   138,  -126,
    -126,  -126,  -126,    75,  -126,   -33,  -126,   103,     3,    81,
    -126,  -126,  -126,    71,  -126,  -126,  -126,    89,   -50,  -126,
    -126,  -126,  -126,  -126,   -62,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -125,   -10,
      83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    24,   106,    16,    22,     7,    19,
       9,    23,    12,    28,    71,    40,    41,    42,    43,    82,
      53,   114,   145,    56,    95,    96,    44,    45,    99,    94,
     129,   130,   131,   132,   100,   101,   146,   147,   148,   149,
     150,   151,    63,   141,   159,   163,    64,   142,   153,   156,
      86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    74,   -33,    98,   -33,    36,     8,    79,    59,    60,
      36,    10,    11,    18,    68,    69,    37,   154,    89,   102,
      72,    36,    13,    73,    72,   -24,    30,    73,    90,    91,
      92,    93,    37,    38,    39,   105,    36,   -24,   165,    39,
     109,   110,   111,   112,    17,   104,   115,    37,   116,    38,
      39,   103,    77,    78,   126,   135,   136,   137,   138,   139,
     140,   134,    20,    21,    38,    39,    72,   143,    61,    73,
      62,    90,    91,    92,    93,   160,    26,    90,    91,    92,
      93,    25,    27,    90,    91,    92,    93,    29,   117,   118,
     119,   120,   121,   122,    32,   155,    90,    91,    92,    93,
       1,     2,    33,     3,    34,    50,    35,    46,    47,    48,
     155,    52,    51,    57,    55,    66,    58,    70,    76,   157,
      67,    85,    75,    80,    81,    84,    54,   -39,   107,   133,
     108,   123,   113,   124,   125,   127,   128,   144,   152,   158,
     161,   162,    14,    15,    31,    83,    88,    65,     0,    97,
     164,     0,    87
};

static const yytype_int16 yycheck[] =
{
      33,    51,     3,    11,     5,     6,    35,    57,    41,    42,
       6,    35,    36,    10,    47,    48,    17,   142,    12,    81,
      32,     6,     0,    35,    32,    10,    23,    35,    22,    23,
      24,    25,    17,    34,    35,    85,     6,     7,   163,    35,
      90,    91,    92,    93,    36,    11,    96,    17,    98,    34,
      35,    84,    13,    14,   104,   117,   118,   119,   120,   121,
     122,    12,    11,    11,    34,    35,    32,    12,     3,    35,
       5,    22,    23,    24,    25,    14,    12,    22,    23,    24,
      25,    11,    34,    22,    23,    24,    25,     9,    26,    27,
      28,    29,    30,    31,    12,   145,    22,    23,    24,    25,
      33,    34,     9,    36,    35,    14,    12,    11,     9,     9,
     160,    35,    11,     8,    35,    13,    10,    10,     8,   152,
      12,     7,    13,    11,    11,     9,    37,    35,    13,    11,
      13,    12,    35,    12,    10,    13,    10,    10,     9,     4,
      12,    10,     5,     5,    24,    64,    71,    44,    -1,    78,
     160,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,    36,    38,    39,    40,    45,    35,    47,
      35,    36,    49,     0,    40,    45,    43,    36,    55,    46,
      11,    11,    44,    48,    41,    11,    12,    34,    50,     9,
      55,    44,    12,     9,    35,    12,     6,    17,    34,    35,
      52,    53,    54,    55,    63,    64,    11,     9,     9,    52,
      14,    11,    35,    57,    64,    35,    60,     8,    10,    52,
      52,     3,     5,    79,    83,    54,    13,    12,    52,    52,
      10,    51,    32,    35,    65,    13,     8,    13,    14,    65,
      11,    11,    56,    56,     9,     7,    87,    87,    50,    12,
      22,    23,    24,    25,    66,    61,    62,    60,    11,    65,
      71,    72,    71,    52,    11,    65,    42,    13,    13,    65,
      65,    65,    65,    35,    58,    65,    65,    26,    27,    28,
      29,    30,    31,    12,    12,    10,    65,    13,    10,    67,
      68,    69,    70,    11,    12,    71,    71,    71,    71,    71,
      71,    80,    84,    12,    10,    59,    73,    74,    75,    76,
      77,    78,     9,    85,    85,    65,    86,    52,     4,    81,
      14,    12,    10,    82,    86,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    41,    42,    40,
      43,    40,    44,    46,    45,    47,    48,    45,    49,    45,
      50,    50,    51,    50,    52,    52,    52,    53,    53,    54,
      54,    54,    54,    55,    56,    57,    57,    59,    58,    61,
      60,    62,    60,    60,    60,    63,    64,    65,    65,    65,
      65,    67,    66,    68,    66,    69,    66,    70,    66,    71,
      71,    72,    73,    72,    74,    72,    75,    72,    76,    72,
      77,    72,    78,    72,    80,    79,    81,    82,    81,    84,
      83,    85,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     0,    11,
       0,     7,     3,     0,    10,     0,     0,    10,     0,     7,
       0,     2,     0,     5,     0,     2,     2,     3,     3,     2,
       2,     3,     3,     0,     0,     1,     1,     0,     5,     0,
       4,     0,     4,     3,     1,     5,     3,     0,     1,     1,
       2,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       3,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     7,     0,     0,     3,     0,
       6,     3,     1,     3,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 7:
#line 61 "lex.y"
                               { start_func();decla_var_TI((yyvsp[-1].c), la_profondeur); /*int line = insert_TI("JMP",-1,-1,-1);insert_tjump(line); $<num>1 = get_nbr_instrus_TI() ;*/printf("Function done\n"); }
#line 1472 "lex.tab.c"
    break;

  case 8:
#line 61 "lex.y"
                                                                                                                                                                                                                                               {affect_TI ((yyvsp[-6].c));insert_TI("RET",0,0,0);}
#line 1478 "lex.tab.c"
    break;

  case 9:
#line 61 "lex.y"
                                                                                                                                                                                                                                                                                                        { /*actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);insert_TI("RET",0,0,0);/*  insert_TI("JMP",-1,-1,-1); */Add_Func((yyvsp[-9].c),  search((yyvsp[-9].c)), get_nbr_instrus_TI());}
#line 1484 "lex.tab.c"
    break;

  case 10:
#line 62 "lex.y"
                    {start_func(); (yyvsp[-1].num) = get_nbr_instrus_TI() + 1;}
#line 1490 "lex.tab.c"
    break;

  case 11:
#line 62 "lex.y"
                                                                                                          {Add_Func((yyvsp[-5].c), (yyvsp[-6].num), get_nbr_instrus_TI());}
#line 1496 "lex.tab.c"
    break;

  case 13:
#line 76 "lex.y"
                   { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2); }
#line 1502 "lex.tab.c"
    break;

  case 14:
#line 76 "lex.y"
                                                                                                                     {insert_TI("RET",0,0,0);}
#line 1508 "lex.tab.c"
    break;

  case 15:
#line 77 "lex.y"
             {printf("START MAIN\n");}
#line 1514 "lex.tab.c"
    break;

  case 16:
#line 77 "lex.y"
                                            {actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  }
#line 1520 "lex.tab.c"
    break;

  case 17:
#line 77 "lex.y"
                                                                                                                                           {insert_TI("NOP",0,0,0);}
#line 1526 "lex.tab.c"
    break;

  case 18:
#line 78 "lex.y"
            { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  }
#line 1532 "lex.tab.c"
    break;

  case 19:
#line 78 "lex.y"
                                                                                                  {insert_TI("NOP",0,0,0);}
#line 1538 "lex.tab.c"
    break;

  case 21:
#line 88 "lex.y"
              {decla_var_TI((yyvsp[0].c), la_profondeur); /*RST_arg();*/}
#line 1544 "lex.tab.c"
    break;

  case 22:
#line 89 "lex.y"
                      {decla_var_TI((yyvsp[-1].c), la_profondeur);}
#line 1550 "lex.tab.c"
    break;

  case 33:
#line 119 "lex.y"
                   {la_profondeur++;}
#line 1556 "lex.tab.c"
    break;

  case 34:
#line 120 "lex.y"
                    {la_profondeur--;}
#line 1562 "lex.tab.c"
    break;

  case 37:
#line 131 "lex.y"
               {push_addr_return(la_profondeur);}
#line 1568 "lex.tab.c"
    break;

  case 38:
#line 131 "lex.y"
                                                                 {insert_TI("PUSH",search("returnADDR"),-1,-1);insert_TI("CALL",search((yyvsp[-4].c)),-1,-1); insert_TI("POP",search("returnADDR"),-1,-1);}
#line 1574 "lex.tab.c"
    break;

  case 39:
#line 137 "lex.y"
                   {save_addr_return();  decla_var_TI((yyvsp[-1].c), la_profondeur); }
#line 1580 "lex.tab.c"
    break;

  case 40:
#line 137 "lex.y"
                                                                                     {affect_TI ((yyvsp[-3].c)); }
#line 1586 "lex.tab.c"
    break;

  case 41:
#line 138 "lex.y"
                   { decla_var_TI((yyvsp[-1].c), la_profondeur);}
#line 1592 "lex.tab.c"
    break;

  case 42:
#line 138 "lex.y"
                                                               {affect_TI ((yyvsp[-3].c)); }
#line 1598 "lex.tab.c"
    break;

  case 44:
#line 140 "lex.y"
            {decla_var_TI((yyvsp[0].c), la_profondeur);}
#line 1604 "lex.tab.c"
    break;

  case 45:
#line 143 "lex.y"
                                      {printf_TI((yyvsp[-2].c));}
#line 1610 "lex.tab.c"
    break;

  case 46:
#line 147 "lex.y"
                      {affect_TI ((yyvsp[-2].c));}
#line 1616 "lex.tab.c"
    break;

  case 48:
#line 154 "lex.y"
         {var_TI((yyvsp[0].c), la_profondeur);}
#line 1622 "lex.tab.c"
    break;

  case 49:
#line 155 "lex.y"
         {nb_TI((yyvsp[0].num), la_profondeur);}
#line 1628 "lex.tab.c"
    break;

  case 51:
#line 162 "lex.y"
               {add_TI();}
#line 1634 "lex.tab.c"
    break;

  case 52:
#line 162 "lex.y"
                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("ADD  %%%d %%%d \n ",addr1, add*/}
#line 1640 "lex.tab.c"
    break;

  case 53:
#line 163 "lex.y"
               {mul_TI();}
#line 1646 "lex.tab.c"
    break;

  case 54:
#line 163 "lex.y"
                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("MUL  %%%d %%%d \n ",addr1, add*/}
#line 1652 "lex.tab.c"
    break;

  case 55:
#line 164 "lex.y"
                {div_TI();}
#line 1658 "lex.tab.c"
    break;

  case 56:
#line 164 "lex.y"
                            {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("DIV  %%%d %%%d \n ",addr1, add*/}
#line 1664 "lex.tab.c"
    break;

  case 57:
#line 165 "lex.y"
                {sub_TI();}
#line 1670 "lex.tab.c"
    break;

  case 58:
#line 165 "lex.y"
                            {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUB  %%%d %%%d \n ",addr1, add*/}
#line 1676 "lex.tab.c"
    break;

  case 62:
#line 174 "lex.y"
                      {  condi_eq_TI() ; }
#line 1682 "lex.tab.c"
    break;

  case 63:
#line 174 "lex.y"
                                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("EQU  %%%d %%%d \n ",addr1, add*/}
#line 1688 "lex.tab.c"
    break;

  case 64:
#line 175 "lex.y"
                      {  condi_lt_TI() ; }
#line 1694 "lex.tab.c"
    break;

  case 65:
#line 175 "lex.y"
                                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("INF  %%%d %%%d \n ",addr1, add*/}
#line 1700 "lex.tab.c"
    break;

  case 66:
#line 176 "lex.y"
                       {  condi_gt_TI() ; }
#line 1706 "lex.tab.c"
    break;

  case 67:
#line 176 "lex.y"
                                            {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUP  %%%d %%%d \n ",addr1, add*/}
#line 1712 "lex.tab.c"
    break;

  case 68:
#line 177 "lex.y"
                      {  condi_ne_TI() ; }
#line 1718 "lex.tab.c"
    break;

  case 69:
#line 177 "lex.y"
                                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("NEQ  %%%d %%%d \n ",addr1, add*/}
#line 1724 "lex.tab.c"
    break;

  case 70:
#line 178 "lex.y"
                      {  condi_ge_TI() ; }
#line 1730 "lex.tab.c"
    break;

  case 71:
#line 178 "lex.y"
                                           {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("GE  %%%d %%%d \n ",addr1, add*/}
#line 1736 "lex.tab.c"
    break;

  case 72:
#line 179 "lex.y"
                        {  condi_le_TI() ; }
#line 1742 "lex.tab.c"
    break;

  case 73:
#line 179 "lex.y"
                                             {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("LE  %%%d %%%d \n ",addr1, add*/}
#line 1748 "lex.tab.c"
    break;

  case 74:
#line 184 "lex.y"
        {  
               jmf_body();
                       }
#line 1756 "lex.tab.c"
    break;

  case 76:
#line 192 "lex.y"
        {
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+1);
        }
#line 1765 "lex.tab.c"
    break;

  case 77:
#line 198 "lex.y"
        {              
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+2);
                int line = insert_TI("JMP",-1,-1,-1);
                insert_tjump(line);
        }
#line 1776 "lex.tab.c"
    break;

  case 78:
#line 205 "lex.y"
        {
                int current = get_nbr_instrus_TI();
                actu_jump(pop_tjump(), current+1);
        }
#line 1785 "lex.tab.c"
    break;

  case 79:
#line 213 "lex.y"
        {
                (yyvsp[-3].num) = get_nbr_instrus_TI()-2;
               jmf_body();
        }
#line 1794 "lex.tab.c"
    break;

  case 80:
#line 218 "lex.y"
        {
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+2);
                insert_TI("JMP",(yyvsp[-5].num),-1,-1);
        }
#line 1804 "lex.tab.c"
    break;


#line 1808 "lex.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 249 "lex.y"


void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  
    pile_init();
   // yydebug = 1;
    init_TI();
    init_tjump();
    init_TF();
    yyparse();
   print_TI();
   // afficherPile();
   
    create_file_TI();

   // 
    interpreteuree();
   cross();
    return 0;
}
