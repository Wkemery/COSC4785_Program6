/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 8 "program6.y" /* yacc.c:339  */



#include <iostream>
#include <FlexLexer.h>
#include "Node.h"
#include "Lexeme.h"

using namespace std;

extern vector<Node*> forest;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *);


#line 87 "program6_bison.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "program6_bison.h".  */
#ifndef YY_YY_PROGRAM6_BISON_H_INCLUDED
# define YY_YY_PROGRAM6_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    THIS = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    RETURN = 263,
    PRINT = 264,
    READ = 265,
    VOID = 266,
    NEW = 267,
    NULLKEYWORD = 268,
    INT = 269,
    ASSIGNOP = 270,
    DOTOP = 271,
    COMMA = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACK = 275,
    RBRACK = 276,
    LBRACE = 277,
    RBRACE = 278,
    PLUS = 279,
    MINUS = 280,
    NOT = 281,
    DOUBEQ = 282,
    NOTEQ = 283,
    LESSEQ = 284,
    GREATEQ = 285,
    LESS = 286,
    GREAT = 287,
    TIMES = 288,
    DIVIDE = 289,
    MOD = 290,
    DOUBAND = 291,
    DOUBBAR = 292,
    IDENTIFIER = 293,
    SEMICO = 294,
    NUM = 295,
    IFEL = 296,
    NAME = 297,
    RE = 298,
    BIN = 299,
    PRO = 300,
    NEG = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "program6.y" /* yacc.c:355  */

  Node* ttype;
  Lexeme* token;


#line 180 "program6_bison.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM6_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 197 "program6_bison.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,   100,   108,   115,   120,   125,   130,
     135,   140,   145,   152,   157,   164,   169,   173,   184,   189,
     193,   204,   209,   213,   224,   229,   234,   239,   244,   249,
     254,   259,   264,   268,   272,   280,   287,   294,   301,   308,
     317,   322,   327,   332,   337,   347,   352,   356,   366,   371,
     376,   384,   394,   399,   404,   411,   420,   425,   430,   436,
     441,   448,   455,   463,   474,   479,   486,   492,   497,   504,
     512,   517,   522,   527,   534,   538,   546,   550,   559,   563,
     571,   575,   583,   588,   596,   600,   604,   609,   614,   622,
     631,   636,   641,   646,   654,   662,   667,   672,   679,   687,
     692,   697,   704,   715,   720,   725,   734,   739,   744,   749,
     758,   764,   769,   777,   787,   792,   798,   799,   800,   804,
     805,   806,   807,   808,   809,   812,   813,   814,   815,   817,
     818,   819,   822,   827,   832,   837,   844,   850,   855,   862
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "THIS", "IF", "ELSE", "WHILE",
  "RETURN", "PRINT", "READ", "VOID", "NEW", "NULLKEYWORD", "INT",
  "ASSIGNOP", "DOTOP", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "PLUS", "MINUS", "NOT", "DOUBEQ", "NOTEQ", "LESSEQ",
  "GREATEQ", "LESS", "GREAT", "TIMES", "DIVIDE", "MOD", "DOUBAND",
  "DOUBBAR", "IDENTIFIER", "SEMICO", "NUM", "IFEL", "NAME", "RE", "BIN",
  "PRO", "NEG", "$accept", "input", "classdec", "classbody", "vardecr",
  "constructordecr", "methoddecr", "statement", "block", "statementr",
  "conditionalstatement", "constructordec", "methoddec", "paramlist",
  "param", "vardec", "expression", "name", "newexpression",
  "brackexpression", "arglist", "unaryop", "relationop", "productop",
  "sumop", "type", "multibracks", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     295,  -121,    10,  -121,   -18,  -121,    24,   146,  -121,    -6,
      55,  -121,   102,    96,   124,   449,  -121,  -121,  -121,    11,
      60,    59,    67,    86,    67,  -121,  -121,   454,   470,  -121,
      15,  -121,   474,  -121,    70,  -121,  -121,    55,  -121,    40,
       5,   172,  -121,  -121,    63,    41,   217,  -121,   101,  -121,
    -121,   475,  -121,  -121,    75,  -121,  -121,   243,  -121,    72,
     232,  -121,  -121,  -121,   397,  -121,     0,   139,  -121,  -121,
     149,   256,  -121,  -121,   184,   140,  -121,   163,   169,   105,
     175,  -121,    76,  -121,   408,  -121,  -121,   420,  -121,   133,
      33,  -121,  -121,  -121,  -121,  -121,   194,  -121,  -121,   159,
     228,   228,   140,   197,     2,  -121,   228,  -121,  -121,  -121,
     202,  -121,  -121,   344,   210,  -121,   246,   228,   154,   140,
    -121,   444,   140,  -121,  -121,   275,    34,   164,   228,     8,
    -121,  -121,  -121,   490,   602,    73,  -121,   222,   245,   509,
     228,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,   279,   308,   326,   195,
     140,  -121,   616,   291,   140,   528,  -121,   140,   360,  -121,
    -121,    18,   297,   546,    47,    94,    47,  -121,  -121,   154,
     235,    67,   199,   235,    67,  -121,  -121,   140,   630,   140,
    -121,   140,   289,   182,  -121,   135,   228,    27,  -121,  -121,
    -121,  -121,  -121,  -121,    28,  -121,  -121,  -121,   140,   263,
    -121,   565,   154,    67,   140,  -121,   226,    67,  -121,  -121,
    -121,   616,  -121,  -121,  -121,  -121,    47,  -121,  -121,   583,
    -121,  -121,  -121,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     1,     0,     3,     0,     0,     5,     0,
     132,     6,   133,     0,     0,     0,    18,    21,    15,     0,
       0,     0,   134,     0,   135,    17,     7,     0,     0,    16,
      20,    11,     0,    19,     0,    23,    13,   133,    22,     0,
       0,     0,   138,   136,     0,     0,     0,    64,     0,    20,
       8,     0,    14,    10,     0,    69,    68,     0,    67,     0,
       0,   139,   137,    55,     0,    53,     0,     0,    66,     9,
       0,     0,    63,    59,     0,    44,    90,     0,     0,     0,
       0,    40,    91,    31,     0,    45,    33,     0,    32,     0,
       0,    65,    54,    52,    61,    57,     0,    62,    58,     0,
       0,     0,     0,     0,     0,    71,     0,   116,   117,   118,
      91,    30,    70,     0,    85,    84,     0,     0,     0,    17,
      41,     0,    47,    43,    46,     0,     0,     0,     0,     0,
      60,    56,    94,     0,     0,     0,   109,     0,     0,     0,
       0,    37,   130,   129,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   131,    29,     0,     0,     0,     0,
      75,    74,   114,     0,   138,     0,    42,    35,     0,    93,
      92,     0,     0,     0,     0,     0,     0,    73,    72,     0,
     106,   108,     0,   103,   104,    83,    82,    77,    76,    79,
      78,    81,    80,     0,    87,     0,     0,     0,    97,    96,
      34,    24,    39,    26,     0,    98,    95,    50,    51,    48,
      28,     0,     0,   107,   101,   100,     0,   105,    88,    89,
      86,   115,    36,    27,    38,    25,     0,   112,   110,     0,
     102,    99,    49,   113,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   213,   265,   247,   -85,   -37,   198,
    -121,   132,   216,    85,   224,    -8,   -75,   -63,  -121,   156,
    -120,  -121,  -121,  -121,  -121,     4,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    13,    14,    15,    85,    86,    87,
      88,    16,    17,    46,    47,    18,   162,   114,   115,   180,
     163,   116,   156,   157,   158,    34,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    89,   124,   136,   113,    29,    56,   172,    65,    56,
       3,    19,    39,     4,    10,   -12,   137,    19,   -12,   202,
       6,    89,    73,    57,    89,   133,   134,    48,   222,   224,
      93,   139,    20,    95,    39,   169,   124,    98,    37,   195,
     138,   161,    63,   165,    58,    48,     7,    58,   102,    40,
     168,    76,    77,   173,    78,    79,    80,   203,    89,   131,
      42,    48,   216,    64,    61,   165,   223,   225,    90,    64,
      48,   129,   170,    72,   177,    21,    29,  -133,    41,    55,
      43,   188,   190,   192,    62,   110,    83,    44,    90,   207,
     209,   210,   178,    57,    64,   208,   118,    25,    76,    77,
      10,    78,    79,    80,   211,    45,   102,     9,    54,    76,
      10,    89,    89,    89,  -133,   103,    64,   104,   105,    26,
      23,   221,    21,   106,    37,    30,    60,   181,   184,   107,
     108,   109,   110,    83,    12,     9,   219,   229,    10,    68,
      92,   232,    71,   110,   111,   112,    33,    31,   125,   126,
      94,   127,   196,   128,   220,   164,    99,     9,    76,    33,
      10,    64,    12,    89,   103,   102,   104,   105,    76,    11,
     213,    64,   106,   217,   103,    43,   104,   105,   107,   108,
     109,   100,   106,   171,    12,    97,    10,   101,   107,   108,
     109,    59,   110,   117,   112,   130,   193,   132,    99,    76,
     214,   218,   110,    76,   112,   103,    64,   104,   105,   103,
      37,   104,   105,   106,   194,   135,    64,   106,   215,   107,
     108,   109,   140,   107,   108,   109,   126,   230,   159,   102,
     128,    38,    76,   110,    66,   112,    67,   110,   103,   112,
     104,   105,   179,   196,    38,   231,   106,   160,    38,    66,
      76,    74,   107,   108,   109,   212,   103,    10,   104,   105,
      28,    32,    70,   182,   106,   179,   110,    38,   112,   226,
     107,   108,   109,    66,    51,    96,   167,    84,    27,    76,
     187,    37,   121,    76,   110,   103,   112,   104,   105,   103,
      91,   104,   105,   106,   183,    -2,     1,   106,    -2,   107,
     108,   109,     0,   107,   108,   109,     0,     0,   196,   189,
     197,     0,    76,   110,   196,   112,   204,   110,   103,   112,
     104,   105,   150,   151,   152,   153,   106,   191,     0,     0,
      76,     0,   107,   108,   109,     0,   103,     0,   104,   105,
       0,     0,     0,     0,   106,   141,   110,     0,   112,     0,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,   110,     0,   112,     0,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   142,   143,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    75,   201,
       0,    76,    77,     0,    78,    79,    80,     0,     0,   119,
       0,    10,    76,    77,     0,    78,    79,    80,     0,    64,
      81,   122,    10,     0,    76,    77,     0,    78,    79,    80,
      64,   120,     0,     0,     0,    82,    83,     0,     0,     0,
       0,     0,    64,   123,     0,   122,    82,    83,    76,    77,
      35,    78,    79,    80,     0,    49,     0,     0,   110,    83,
       9,     0,     0,    10,     0,     9,    64,   166,    10,     0,
       0,    35,    36,     0,     0,    35,    35,    50,     0,     0,
       0,     9,   110,    83,    10,     9,     9,    37,    10,    10,
       0,   174,    12,    52,     0,     0,     0,    53,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   175,
     185,     0,    37,    37,   142,   143,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   186,   198,
       0,     0,     0,   142,   143,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   205,     0,   199,
       0,     0,   142,   143,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   227,   206,     0,     0,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   233,     0,   228,     0,     0,   142,
     143,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   234,     0,     0,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   176,     0,     0,     0,     0,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   142,   143,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,   153,   154
};

static const yytype_int16 yycheck[] =
{
      10,    64,    87,     1,    79,    13,     1,   127,    45,     1,
       0,     7,     1,     3,    14,     0,    14,    13,     3,     1,
      38,    84,    59,    18,    87,   100,   101,    23,     1,     1,
      67,   106,    38,    70,     1,     1,   121,    74,    38,   159,
      38,   116,     1,   118,    39,    41,    22,    39,     1,    38,
     125,     4,     5,   128,     7,     8,     9,    39,   121,    96,
       1,    57,   182,    22,     1,   140,    39,    39,    64,    22,
      66,    38,    38,     1,     1,    20,    84,     1,    18,    39,
      21,   156,   157,   158,    21,    38,    39,    20,    84,   174,
     175,   176,    19,    18,    22,     1,    20,     1,     4,     5,
      14,     7,     8,     9,   179,    19,     1,    11,    38,     4,
      14,   174,   175,   176,    38,    10,    22,    12,    13,    23,
      18,   196,    20,    18,    38,     1,    41,   137,   138,    24,
      25,    26,    38,    39,    38,    11,     1,   212,    14,    38,
       1,   226,    57,    38,    39,    40,    14,    23,    15,    16,
       1,    18,    17,    20,    19,     1,    16,    11,     4,    27,
      14,    22,    38,   226,    10,     1,    12,    13,     4,    23,
     180,    22,    18,   183,    10,    21,    12,    13,    24,    25,
      26,    18,    18,    19,    38,     1,    14,    18,    24,    25,
      26,    19,    38,    18,    40,     1,     1,    38,    16,     4,
       1,    19,    38,     4,    40,    10,    22,    12,    13,    10,
      38,    12,    13,    18,    19,    18,    22,    18,    19,    24,
      25,    26,    20,    24,    25,    26,    16,     1,    18,     1,
      20,    15,     4,    38,    17,    40,    19,    38,    10,    40,
      12,    13,    20,    17,    28,    19,    18,     1,    32,    17,
       4,    19,    24,    25,    26,    20,    10,    14,    12,    13,
      13,    14,    19,    18,    18,    20,    38,    51,    40,     6,
      24,    25,    26,    17,    27,    19,     1,    64,    13,     4,
       1,    38,    84,     4,    38,    10,    40,    12,    13,    10,
      66,    12,    13,    18,   138,     0,     1,    18,     3,    24,
      25,    26,    -1,    24,    25,    26,    -1,    -1,    17,     1,
      19,    -1,     4,    38,    17,    40,    19,    38,    10,    40,
      12,    13,    33,    34,    35,    36,    18,     1,    -1,    -1,
       4,    -1,    24,    25,    26,    -1,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    18,     1,    38,    -1,    40,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    38,    -1,    40,    -1,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     1,    39,
      -1,     4,     5,    -1,     7,     8,     9,    -1,    -1,     1,
      -1,    14,     4,     5,    -1,     7,     8,     9,    -1,    22,
      23,     1,    14,    -1,     4,     5,    -1,     7,     8,     9,
      22,    23,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,     1,    38,    39,     4,     5,
       1,     7,     8,     9,    -1,     1,    -1,    -1,    38,    39,
      11,    -1,    -1,    14,    -1,    11,    22,    23,    14,    -1,
      -1,     1,    23,    -1,    -1,     1,     1,    23,    -1,    -1,
      -1,    11,    38,    39,    14,    11,    11,    38,    14,    14,
      -1,     1,    38,    23,    -1,    -1,    -1,    23,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    19,
       1,    -1,    38,    38,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    19,     1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     1,    -1,    21,
      -1,    -1,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     1,    21,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     1,    -1,    21,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    21,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    48,     0,     3,    49,    38,    22,    50,    11,
      14,    23,    38,    51,    52,    53,    58,    59,    62,    72,
      38,    20,    73,    18,    73,     1,    23,    52,    53,    62,
       1,    23,    53,    58,    72,     1,    23,    38,    59,     1,
      38,    18,     1,    21,    20,    19,    60,    61,    72,     1,
      23,    53,    23,    23,    38,    39,     1,    18,    39,    19,
      60,     1,    21,     1,    22,    55,    17,    19,    38,    23,
      19,    60,     1,    55,    19,     1,     4,     5,     7,     8,
       9,    23,    38,    39,    51,    54,    55,    56,    57,    64,
      72,    61,     1,    55,     1,    55,    19,     1,    55,    16,
      18,    18,     1,    10,    12,    13,    18,    24,    25,    26,
      38,    39,    40,    63,    64,    65,    68,    18,    20,     1,
      23,    56,     1,    23,    54,    15,    16,    18,    20,    38,
       1,    55,    38,    63,    63,    18,     1,    14,    38,    63,
      20,     1,    24,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    69,    70,    71,    18,
       1,    63,    63,    67,     1,    63,    23,     1,    63,     1,
      38,    19,    67,    63,     1,    19,    19,     1,    19,    20,
      66,    73,    18,    66,    73,     1,    19,     1,    63,     1,
      63,     1,    63,     1,    19,    67,    17,    19,     1,    21,
       1,    39,     1,    39,    19,     1,    21,    54,     1,    54,
      54,    63,    20,    73,     1,    19,    67,    73,    19,     1,
      19,    63,     1,    39,     1,    39,     6,     1,    21,    63,
       1,    19,    54,     1,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     3,     2,     3,     4,     5,
       4,     3,     3,     3,     4,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     4,     5,     4,     5,     5,     3,
       2,     1,     1,     1,     4,     3,     5,     3,     5,     4,
       2,     3,     4,     3,     2,     1,     2,     2,     5,     7,
       5,     5,     5,     4,     5,     4,     6,     5,     6,     5,
       6,     5,     6,     5,     1,     3,     2,     3,     3,     3,
       1,     1,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     4,     3,     4,     4,
       1,     1,     3,     3,     3,     4,     4,     4,     4,     5,
       4,     4,     5,     3,     3,     4,     3,     4,     3,     2,
       3,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
  switch (yytype)
    {
          case 3: /* CLASS  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1272 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 4: /* THIS  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1278 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 5: /* IF  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1284 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 6: /* ELSE  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1290 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 7: /* WHILE  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1296 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 8: /* RETURN  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1302 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 9: /* PRINT  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1308 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 10: /* READ  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1314 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 11: /* VOID  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1320 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 12: /* NEW  */
#line 70 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1326 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 13: /* NULLKEYWORD  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1332 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 14: /* INT  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1338 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 15: /* ASSIGNOP  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1344 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 16: /* DOTOP  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1350 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 17: /* COMMA  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1356 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 18: /* LPAREN  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1362 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 19: /* RPAREN  */
#line 71 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1368 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 20: /* LBRACK  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1374 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 21: /* RBRACK  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1380 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 22: /* LBRACE  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1386 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 23: /* RBRACE  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1392 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 24: /* PLUS  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1398 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 25: /* MINUS  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1404 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 26: /* NOT  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1410 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 27: /* DOUBEQ  */
#line 72 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1416 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 28: /* NOTEQ  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1422 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 29: /* LESSEQ  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1428 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 30: /* GREATEQ  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1434 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 31: /* LESS  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1440 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 32: /* GREAT  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1446 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 33: /* TIMES  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1452 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 34: /* DIVIDE  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1458 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 35: /* MOD  */
#line 73 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1464 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 36: /* DOUBAND  */
#line 74 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1470 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 37: /* DOUBBAR  */
#line 74 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1476 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 38: /* IDENTIFIER  */
#line 74 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1482 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 39: /* SEMICO  */
#line 74 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1488 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 40: /* NUM  */
#line 74 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1494 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 49: /* classdec  */
#line 78 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1500 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 50: /* classbody  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1506 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 51: /* vardecr  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1512 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 52: /* constructordecr  */
#line 80 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1518 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 53: /* methoddecr  */
#line 81 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1524 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 54: /* statement  */
#line 78 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1530 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 55: /* block  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1536 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 56: /* statementr  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1542 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 57: /* conditionalstatement  */
#line 78 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1548 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 58: /* constructordec  */
#line 80 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1554 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 59: /* methoddec  */
#line 80 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1560 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 60: /* paramlist  */
#line 80 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1566 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 61: /* param  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1572 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 63: /* expression  */
#line 76 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1578 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 64: /* name  */
#line 76 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1584 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 65: /* newexpression  */
#line 78 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1590 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 66: /* brackexpression  */
#line 77 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1596 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 67: /* arglist  */
#line 77 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1602 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 68: /* unaryop  */
#line 76 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1608 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 69: /* relationop  */
#line 77 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1614 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 70: /* productop  */
#line 77 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1620 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 71: /* sumop  */
#line 77 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1626 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 72: /* type  */
#line 79 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1632 "program6_bison.c" /* yacc.c:1257  */
        break;

    case 73: /* multibracks  */
#line 76 "program6.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1638 "program6_bison.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 96 "program6.y" /* yacc.c:1646  */
    { 
            if(!(yyvsp[0].ttype)->getErr()) forest.push_back((yyvsp[0].ttype));
            else delete (yyvsp[0].ttype);
        }
#line 1905 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "program6.y" /* yacc.c:1646  */
    {
          cerr << ": Unknown Around " << yylval.token->line << ":" 
          << yylval.token->column <<endl << endl; 
          yyclearin;
          yyerrok;
        }
#line 1916 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 5:
#line 108 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new ClassDec((yyvsp[-1].token)->value, (yyvsp[0].ttype));
                (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 1926 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody(CLASSBODYEMPTY);
                  (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
                  delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 1936 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-1].ttype), CLASSBODYVAR);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
                  }
#line 1946 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 8:
#line 125 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-2].ttype), (yyvsp[-1].ttype), CLASSBODYVARCON);
                  (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                  delete (yyvsp[-3].token); delete (yyvsp[0].token);
                  }
#line 1956 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-3].ttype), (yyvsp[-2].ttype), (yyvsp[-1].ttype), CLASSBODYVARCONMET);
                  (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                  delete (yyvsp[-4].token); delete (yyvsp[0].token);
                  }
#line 1966 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-2].ttype), (yyvsp[-1].ttype), CLASSBODYCONMET);
                  (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                  delete (yyvsp[-3].token); delete (yyvsp[0].token);
                  }
#line 1976 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 11:
#line 140 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-1].ttype), CLASSBODYCON);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
            }
#line 1986 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Missing right brace around " << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
            }
#line 1998 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-1].ttype), CLASSBODYMET);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
                  }
#line 2008 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ClassBody((yyvsp[-2].ttype), (yyvsp[-1].ttype), CLASSBODYVARMET);
                  (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                  delete (yyvsp[-3].token); delete (yyvsp[0].token);
            }
#line 2018 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 15:
#line 164 "program6.y" /* yacc.c:1646  */
    { 
              (yyval.ttype) = new RNode(RECVARDEC);
              (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
              ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
}
#line 2028 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "program6.y" /* yacc.c:1646  */
    {
                ((RNode*)(yyvsp[-1].ttype))->add((yyvsp[0].ttype));
                (yyval.ttype) = (yyvsp[-1].ttype);
                }
#line 2037 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 17:
#line 173 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();  
                  cerr << ": Unexpected token after variable declaration around " 
                  << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyclearin;
                  yyerrok;
                  delete (yyvsp[-1].ttype);
                }
#line 2051 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "program6.y" /* yacc.c:1646  */
    { 
                        (yyval.ttype) = new RNode(RECCONDEC);
                        (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                        ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
                        }
#line 2061 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "program6.y" /* yacc.c:1646  */
    {
                        ((RNode*)(yyvsp[-1].ttype))->add((yyvsp[0].ttype));
                        (yyval.ttype) = (yyvsp[-1].ttype);
                        }
#line 2070 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 20:
#line 193 "program6.y" /* yacc.c:1646  */
    {
                        (yyval.ttype) = new ErrNode();  
                        cerr << ": Unexpected token after constructor declaration around " 
                        << yylval.token->line
                        << ":" << yylval.token->column << endl << endl;
                        yyclearin;
                        yyerrok;
                        delete (yyvsp[-1].ttype);
                        }
#line 2084 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new RNode(RECMETDEC);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
                  }
#line 2094 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 22:
#line 209 "program6.y" /* yacc.c:1646  */
    {
                  ((RNode*)(yyvsp[-1].ttype))->add((yyvsp[0].ttype));
                  (yyval.ttype) = (yyvsp[-1].ttype);
                  }
#line 2103 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 23:
#line 213 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();  
                  cerr << ": Unexpected token after method declaration around " 
                  << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyclearin;
                  yyerrok;
                  delete (yyvsp[-1].ttype);
                  }
#line 2117 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 24:
#line 224 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new Statement((yyvsp[-3].ttype), (yyvsp[-1].ttype), STMNTNAMEEXP);
                (yyval.ttype)->setLineNumber((yyvsp[-3].ttype)->getLineNumber());
                delete (yyvsp[-2].token); delete (yyvsp[0].token);
                }
#line 2127 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 25:
#line 229 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[-4].ttype), (yyvsp[-2].ttype), STMNTNAMEARGL);
                  (yyval.ttype)->setLineNumber((yyvsp[-4].ttype)->getLineNumber());
                  delete (yyvsp[-3].token); delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 2137 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 26:
#line 234 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Statement((yyvsp[-3].ttype),STMNTNAMEEMPTY);
                    (yyval.ttype)->setLineNumber((yyvsp[-3].ttype)->getLineNumber());
                    delete (yyvsp[-2].token); delete (yyvsp[-1].token), delete (yyvsp[0].token);
                  }
#line 2147 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 27:
#line 239 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[-2].ttype), STMNTPRNTARGL);
                  (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                  delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 2157 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 28:
#line 244 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[-2].ttype), (yyvsp[0].ttype), STMNTWHILE);
                  (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                  delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
                  }
#line 2167 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 29:
#line 249 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[-1].ttype), SMTNTRETURN);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
                  }
#line 2177 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 30:
#line 254 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement(SMTNTRETURN);
                  (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
                  delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 2187 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 31:
#line 259 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement(STMNTSEMI);
                  (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
                  delete (yyvsp[0].token);
                  }
#line 2197 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 32:
#line 264 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[0].ttype), STMNTCOND);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  }
#line 2206 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 268 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Statement((yyvsp[0].ttype), STMNTBLOCK);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  }
#line 2215 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 34:
#line 272 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon after expression around " 
                  << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                }
#line 2228 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 35:
#line 280 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon before " << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                }
#line 2240 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 36:
#line 287 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon after " << (yyvsp[-1].token)->line
                  << ":" << (yyvsp[-1].token)->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                }
#line 2252 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 37:
#line 294 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon after " << yylval.token->line
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                }
#line 2264 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon after " << (yyvsp[-1].token)->line
                  << ":" << (yyvsp[-1].token)->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-4].ttype); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                }
#line 2276 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 39:
#line 308 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected semicolon after " << (yyvsp[-1].token)->line
                  << ":" << (yyvsp[-1].token)->column << endl << endl;
                  yyerrok;
                  delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 2288 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 40:
#line 317 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new Block(BLOCKEMPTY);
              (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
              delete (yyvsp[-1].token); delete (yyvsp[0].token);
              }
#line 2298 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 41:
#line 322 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new Block((yyvsp[-1].ttype), BLOCKVARDEC);
              (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
              delete (yyvsp[-2].token); delete (yyvsp[0].token);
              }
#line 2308 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 42:
#line 327 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new Block((yyvsp[-2].ttype), (yyvsp[-1].ttype), BLOCKVARSTMNT);
              (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
              delete (yyvsp[-3].token); delete (yyvsp[0].token);
              }
#line 2318 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 43:
#line 332 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new Block((yyvsp[-1].ttype), BLOCKSTMNT);
              (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
              delete (yyvsp[-2].token); delete (yyvsp[0].token);
              }
#line 2328 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 44:
#line 337 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new ErrNode();
            cerr << "Expected right bracket at " << (yyvsp[-1].token)->line
            << ":" << (yyvsp[-1].token)->column << endl << endl;
            yyerrok;
            delete (yyvsp[-1].token);
          
        }
#line 2341 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 45:
#line 347 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new RNode(RECSTMNT);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
                  }
#line 2351 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 352 "program6.y" /* yacc.c:1646  */
    {
                  ((RNode*)(yyvsp[-1].ttype))->add((yyvsp[0].ttype));
                  (yyval.ttype) = (yyvsp[-1].ttype);
                  }
#line 2360 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 47:
#line 356 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Incomplete Statement around " << yylval.token->line << ":" 
                  << yylval.token->column << endl << endl;
                  yyerrok;
                  yyclearin;
                  delete (yyvsp[-1].ttype);
                  }
#line 2373 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 48:
#line 366 "program6.y" /* yacc.c:1646  */
    {
                            (yyval.ttype) = new CondStatement((yyvsp[-2].ttype), (yyvsp[0].ttype), CONDSTMNT);
                            (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                            delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
                            }
#line 2383 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 371 "program6.y" /* yacc.c:1646  */
    {
                            (yyval.ttype) = new CondStatement((yyvsp[-4].ttype), (yyvsp[-2].ttype), (yyvsp[0].ttype), CONDSTMNTELSE);
                            (yyval.ttype)->setLineNumber((yyvsp[-6].token)->line);
                            delete (yyvsp[-6].token); delete (yyvsp[-5].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
                            }
#line 2393 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 50:
#line 376 "program6.y" /* yacc.c:1646  */
    {
                            (yyval.ttype) = new ErrNode();
                            cerr << "Expected right parenthesis after"
                            << " expression around " << (yyvsp[-3].token)->line << ":" 
                            << (yyvsp[-3].token)->column << endl << endl;
                            yyerrok;
                            delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[0].ttype);
                            }
#line 2406 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 384 "program6.y" /* yacc.c:1646  */
    {
                            (yyval.ttype) = new ErrNode();
                            cerr << "Expected statement after"
                            << " conditional statement around " << (yyvsp[-1].token)->line << ":" 
                            << (yyvsp[-1].token)->column << endl << endl;
                            yyerrok;
                            delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                            }
#line 2419 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 52:
#line 394 "program6.y" /* yacc.c:1646  */
    {
                      (yyval.ttype) = new ConstructorDec((yyvsp[-4].token)->value, (yyvsp[-2].ttype), (yyvsp[0].ttype), CONSTDEC);
                      (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                      delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
                      }
#line 2429 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 53:
#line 399 "program6.y" /* yacc.c:1646  */
    {
                      (yyval.ttype) = new ConstructorDec((yyvsp[-3].token)->value, (yyvsp[0].ttype), CONSTDECEMPTY);
                      (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                      delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                      }
#line 2439 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 54:
#line 404 "program6.y" /* yacc.c:1646  */
    {
                      (yyval.ttype) = new ErrNode();
                      cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                      << (yyvsp[-1].token)->column << endl << endl;
                      yyerrok;
                      delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                      }
#line 2451 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 55:
#line 411 "program6.y" /* yacc.c:1646  */
    {
                      (yyval.ttype) = new ErrNode();
                      cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                      << (yyvsp[-1].token)->column << endl << endl;
                      yyerrok;
                      delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                      }
#line 2463 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 420 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new MethodDec((yyvsp[-5].ttype), (yyvsp[-4].token)->value, (yyvsp[-2].ttype), (yyvsp[0].ttype), METHODDECTYPE);
                (yyval.ttype)->setLineNumber((yyvsp[-5].ttype)->getLineNumber());
                delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
                }
#line 2473 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 425 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new MethodDec((yyvsp[-4].ttype), (yyvsp[-3].token)->value, (yyvsp[0].ttype), METHODDECTYPEEMPTY);
                (yyval.ttype)->setLineNumber((yyvsp[-4].ttype)->getLineNumber());
                delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 2483 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 430 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new MethodDec((yyvsp[-4].token)->value, (yyvsp[-2].ttype), (yyvsp[0].ttype), METHODDECVOID);
                (yyval.ttype)->setLineNumber((yyvsp[-5].token)->line);
                delete (yyvsp[-5].token); delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-1].token);
            
                }
#line 2494 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 59:
#line 436 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new MethodDec((yyvsp[-3].token)->value, (yyvsp[0].ttype), METHODDECVOIDEMPTY);
                (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 2504 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 60:
#line 441 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new ErrNode();
                cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                << (yyvsp[-1].token)->column << endl << endl;
                yyerrok;
                delete (yyvsp[-5].ttype); delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                }
#line 2516 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 61:
#line 448 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new ErrNode();
                cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                << (yyvsp[-1].token)->column << endl << endl;
                yyerrok;
                delete (yyvsp[-4].ttype); delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 2528 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 455 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new ErrNode();
                cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                << (yyvsp[-1].token)->column << endl << endl;
                yyerrok;
                delete (yyvsp[-5].token); delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                  
                }
#line 2541 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 63:
#line 463 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new ErrNode();
                cerr << "Expected block after " << (yyvsp[-1].token)->line << ":" 
                << (yyvsp[-1].token)->column << endl << endl;
                yyerrok;
                delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                }
#line 2553 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 64:
#line 474 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new RNode(RECPARAM);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
                  }
#line 2563 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 479 "program6.y" /* yacc.c:1646  */
    {
                  ((RNode*)(yyvsp[-2].ttype))->add((yyvsp[0].ttype));
                  (yyval.ttype) = (yyvsp[-2].ttype);
                  delete (yyvsp[-1].token);
                  }
#line 2573 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 66:
#line 486 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new Param((yyvsp[-1].ttype), (yyvsp[0].token)->value);
            (yyval.ttype)->setLineNumber((yyvsp[-1].ttype)->getLineNumber());
            delete (yyvsp[0].token);
            }
#line 2583 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 492 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new VarDec((yyvsp[-2].ttype), (yyvsp[-1].token)->value);
              (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
              delete (yyvsp[-1].token); delete (yyvsp[0].token);
              }
#line 2593 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 68:
#line 497 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new ErrNode();
              cerr << "Expected Semicolon At "<< (yyvsp[-1].token)->line 
              << ":" << (yyvsp[-1].token)->column+(yyvsp[-1].token)->value.length() << endl << endl;
              yyerrok;
              delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
              }
#line 2605 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 69:
#line 504 "program6.y" /* yacc.c:1646  */
    {
              (yyval.ttype) = new ErrNode();
              cerr << "Expected Identifier before "<< (yyvsp[0].token)->line 
              << ":" << (yyvsp[0].token)->column << endl << endl;
              yyerrok;
              delete (yyvsp[-2].ttype); delete (yyvsp[0].token);
              }
#line 2617 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 70:
#line 512 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[0].token)->value, EXPNUM);
                  (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
                  delete (yyvsp[0].token);
                  }
#line 2627 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 71:
#line 517 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression("null", EXPNULL);
                  (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
                  delete (yyvsp[0].token);
                  }
#line 2637 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 72:
#line 522 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression("read", EXPREAD); 
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 2647 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 73:
#line 527 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected Right Parenthesis At "<< (yyvsp[-1].token)->line << ":" 
                  << (yyvsp[-1].token)->column + 1  <<endl << endl;
                  yyerrok;
                  delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                  }
#line 2659 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 74:
#line 534 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[-1].ttype), (yyvsp[0].ttype), EXPUNARY); 
                  (yyval.ttype)->setLineNumber((yyvsp[-1].ttype)->getLineNumber());
                  }
#line 2668 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 75:
#line 538 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected expression at " << yylval.token->line 
                  << ":" << yylval.token->column << endl << endl;
                  delete (yyvsp[-1].ttype);
                  yyclearin;
                  yyerrok;
                  }
#line 2681 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 76:
#line 546 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPRELATION);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
                  }
#line 2690 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 77:
#line 550 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected expression at " << yylval.token->line 
                  << ":" << yylval.token->column << endl << endl;
                  yyclearin;
                  yyerrok;
                  delete (yyvsp[-2].ttype); delete (yyvsp[-1].ttype); 
                  
                  }
#line 2704 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 78:
#line 559 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPPRODUCT);
                    (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
                  }
#line 2713 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 79:
#line 563 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected expression at " << yylval.token->line 
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  yyclearin;
                  delete (yyvsp[-2].ttype); delete (yyvsp[-1].ttype);
                  }
#line 2726 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 80:
#line 571 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPSUMOP); 
                  (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
                  }
#line 2735 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 81:
#line 575 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected expression at " << yylval.token->line 
                  << ":" << yylval.token->column << endl << endl;
                  yyerrok;
                  yyclearin;
                  delete (yyvsp[-2].ttype); delete (yyvsp[-1].ttype);
                  }
#line 2748 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 82:
#line 583 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[-1].ttype), EXPPAREN);
                  (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
            }
#line 2758 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 83:
#line 588 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected Right Parenthesis at "
                  << yylval.token->line << ":" << yylval.token->column 
                  <<endl << endl;
                  delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                  yyerrok;
                  }
#line 2771 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 84:
#line 596 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[0].ttype), EXPNEW); 
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  }
#line 2780 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 85:
#line 600 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Expression((yyvsp[0].ttype), EXPNAME);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  }
#line 2789 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 86:
#line 604 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Expression((yyvsp[-3].ttype), (yyvsp[-1].ttype), EXPNAMEARG);
                  (yyval.ttype)->setLineNumber((yyvsp[-3].ttype)->getLineNumber());
                  delete (yyvsp[-2].token); delete (yyvsp[0].token);
                  }
#line 2799 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 87:
#line 609 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Expression((yyvsp[-2].ttype), EXPNAMEEMPTY);
                    (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
                    delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 2809 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 88:
#line 614 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected ArgList before ')' at "
                  << (yyvsp[0].token)->line << ":" << (yyvsp[0].token)->column <<endl << endl;
                  yyclearin;
                  yyerrok;
                  delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[0].token);
                  }
#line 2822 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 89:
#line 622 "program6.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new ErrNode();
                  cerr << "Expected Right Parenthesis At "
                  << yylval.token->line << ":" << yylval.token->column 
                  <<endl << endl;
                  yyerrok;
                  delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                  }
#line 2835 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 90:
#line 631 "program6.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name("this", NAMETHIS);
            (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
            delete (yyvsp[0].token);
            }
#line 2845 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 91:
#line 636 "program6.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[0].token)->value, NAMEID);
            (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
            delete (yyvsp[0].token);
            }
#line 2855 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 92:
#line 641 "program6.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[-2].ttype), (yyvsp[0].token)->value, NAMEDOTID);
            (yyval.ttype)->setLineNumber((yyvsp[-2].ttype)->getLineNumber());
            delete (yyvsp[-1].token); delete (yyvsp[0].token);
            }
#line 2865 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 93:
#line 646 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new ErrNode();
            cerr << "Expected Identifier After '.' at " << (yyvsp[-1].token)->line << ":" 
            << (yyvsp[-1].token)->column + 1<< endl << endl;
            yyclearin;
            yyerrok;
            delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
            }
#line 2878 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 94:
#line 654 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new ErrNode();
            cerr << "Expected name before '.' at " << (yyvsp[-1].token)->line << ":" 
            << (yyvsp[-1].token)->column << endl << endl;
            yyclearin;
            yyerrok;
            delete (yyvsp[-1].token); delete (yyvsp[0].token);
            }
#line 2891 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 95:
#line 662 "program6.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[-3].ttype), (yyvsp[-1].ttype), NAMEEXP);
            (yyval.ttype)->setLineNumber((yyvsp[-3].ttype)->getLineNumber());
            delete (yyvsp[-2].token); delete (yyvsp[0].token);
            }
#line 2901 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 96:
#line 667 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new Name((yyvsp[-1].ttype), (yyvsp[-3].token)->value, NAMEIDEXP);
            (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
            delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[0].token);
            }
#line 2911 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 97:
#line 672 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new ErrNode();
            cerr << "Expected Right Bracket At " << yylval.token->line << ":" 
            << yylval.token->column << endl << endl;
            yyerrok;
            delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
            }
#line 2923 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 98:
#line 679 "program6.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new ErrNode();
            cerr<< "Expected Right Bracket At " << yylval.token->line << ":"
            << yylval.token->column << endl << endl;
            yyerrok;
            delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
            }
#line 2935 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 99:
#line 687 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression((yyvsp[-3].token)->value, (yyvsp[-1].ttype), NEWEXPARG);
                    (yyval.ttype)->setLineNumber((yyvsp[-4].token)->line);
                    delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[0].token);
                    }
#line 2945 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 100:
#line 692 "program6.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new NewExpression((yyvsp[-2].token)->value, NEWEXPPAREN);
                    (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                    delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token); delete (yyvsp[0].token);
                    }
#line 2955 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 101:
#line 697 "program6.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new ErrNode();
                    cerr << "Expected Right Parenthesis After '(' at " 
                    << (yyvsp[-1].token)->line << ":" << (yyvsp[-1].token)->column << endl << endl;
                    yyerrok;
                    delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].token);
                    }
#line 2967 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 102:
#line 704 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new ErrNode();
                    cerr << "Expected Right Parenthesis At " << yylval.token->line 
                    << ":" << yylval.token->column << endl << endl;
                    yyerrok;
                    delete (yyvsp[-4].token); delete (yyvsp[-3].token); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                    }
#line 2979 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 103:
#line 715 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression((yyvsp[-1].token)->value, (yyvsp[0].ttype), NEWEXPBRACK);
                    (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                    delete (yyvsp[-2].token); delete (yyvsp[-1].token);
              }
#line 2989 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 104:
#line 720 "program6.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new NewExpression((yyvsp[-1].token)->value, (yyvsp[0].ttype), NEWEXPMULTI);
                (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                delete (yyvsp[-2].token); delete (yyvsp[-1].token);
              }
#line 2999 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 105:
#line 725 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression((yyvsp[-2].token)->value, (yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPBRACKMULTI);
                    (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                    delete (yyvsp[-3].token); delete (yyvsp[-2].token);
              }
#line 3009 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 106:
#line 734 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) =  new NewExpression((yyvsp[0].ttype),NEWEXPBRACK);
                    (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                    delete (yyvsp[-2].token); delete (yyvsp[-1].token);
              }
#line 3019 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 107:
#line 739 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) =  new NewExpression((yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPBRACKMULTI);
                    (yyval.ttype)->setLineNumber((yyvsp[-3].token)->line);
                    delete (yyvsp[-3].token); delete (yyvsp[-2].token);
              }
#line 3029 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 108:
#line 744 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression((yyvsp[0].ttype), NEWEXPMULTI);
                    (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                    delete (yyvsp[-2].token); delete (yyvsp[-1].token);
              }
#line 3039 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 109:
#line 749 "program6.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new ErrNode();
                    cerr << "After 'new' at " << (yyvsp[-1].token)->line << ":" 
                    << (yyvsp[-1].token)->column + 3 << endl << endl;
                    yyerrok;
                    delete (yyvsp[-1].token);
              }
#line 3051 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 110:
#line 758 "program6.y" /* yacc.c:1646  */
    { 
                        (yyval.ttype) = new RNode(RECBRACKEXP);
                        (yyval.ttype)->setLineNumber((yyvsp[-2].token)->line);
                        ((RNode*)(yyval.ttype))->add((yyvsp[-1].ttype));
                        delete (yyvsp[-2].token); delete (yyvsp[0].token);
                        }
#line 3062 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 111:
#line 764 "program6.y" /* yacc.c:1646  */
    {
                        ((RNode*)(yyvsp[-3].ttype))->add((yyvsp[-1].ttype));
                        (yyval.ttype) = (yyvsp[-3].ttype);
                        delete (yyvsp[-2].token); delete (yyvsp[0].token);
                        }
#line 3072 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 112:
#line 769 "program6.y" /* yacc.c:1646  */
    {
                        (yyval.ttype) = new ErrNode();
                        cerr << "Expected right Bracket at " 
                        << yylval.token->line << ":" << yylval.token->column 
                        << endl << endl;
                        yyerrok;
                        delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                        }
#line 3085 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 113:
#line 777 "program6.y" /* yacc.c:1646  */
    {
                        (yyval.ttype) = new ErrNode();
                        cerr << "Expected right Bracket at " 
                        << yylval.token->line << ":" << yylval.token->column 
                        << endl << endl;
                        yyerrok;
                        delete (yyvsp[-3].ttype); delete (yyvsp[-2].token); delete (yyvsp[-1].ttype);
                        }
#line 3098 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 114:
#line 787 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new RNode(RECARG);
                  (yyval.ttype)->setLineNumber((yyvsp[0].ttype)->getLineNumber());
                  ((RNode*)(yyval.ttype))->add((yyvsp[0].ttype));
                  }
#line 3108 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 115:
#line 792 "program6.y" /* yacc.c:1646  */
    {
                  ((RNode*)(yyvsp[-2].ttype))->add((yyvsp[0].ttype));
                  (yyval.ttype) = (yyvsp[-2].ttype);
                  delete (yyvsp[-1].token);
                  }
#line 3118 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 116:
#line 798 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("+"); (yyval.ttype)->setLineNumber((yyvsp[0].token)->line); delete (yyvsp[0].token);}
#line 3124 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 117:
#line 799 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("-"); (yyval.ttype)->setLineNumber((yyvsp[0].token)->line); delete (yyvsp[0].token);}
#line 3130 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 118:
#line 800 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("!"); (yyval.ttype)->setLineNumber((yyvsp[0].token)->line); delete (yyvsp[0].token);}
#line 3136 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 119:
#line 804 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("=="); delete (yyvsp[0].token);}
#line 3142 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 120:
#line 805 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("!="); delete (yyvsp[0].token);}
#line 3148 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 121:
#line 806 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("<="); delete (yyvsp[0].token);}
#line 3154 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 122:
#line 807 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp(">="); delete (yyvsp[0].token);}
#line 3160 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 123:
#line 808 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("<"); delete (yyvsp[0].token);}
#line 3166 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 124:
#line 809 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp(">"); delete (yyvsp[0].token);}
#line 3172 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 125:
#line 812 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("*"); delete (yyvsp[0].token);}
#line 3178 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 126:
#line 813 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("/"); delete (yyvsp[0].token);}
#line 3184 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 127:
#line 814 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("%"); delete (yyvsp[0].token);}
#line 3190 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 128:
#line 815 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("&&"); delete (yyvsp[0].token);}
#line 3196 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 129:
#line 817 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("-"); delete (yyvsp[0].token);}
#line 3202 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 130:
#line 818 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("+"); delete (yyvsp[0].token);}
#line 3208 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 131:
#line 819 "program6.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("||"); delete (yyvsp[0].token);}
#line 3214 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 132:
#line 822 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new TypeNode("int", TYPE);
            (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
            delete (yyvsp[0].token);
            }
#line 3224 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 133:
#line 827 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new TypeNode((yyvsp[0].token)->value, TYPE);
            (yyval.ttype)->setLineNumber((yyvsp[0].token)->line);
            delete (yyvsp[0].token);
            }
#line 3234 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 134:
#line 832 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new TypeNode("int", (yyvsp[0].ttype), TYPEBRACKS);
            (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
            delete (yyvsp[-1].token);
            }
#line 3244 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 135:
#line 837 "program6.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new TypeNode((yyvsp[-1].token)->value, (yyvsp[0].ttype), TYPEBRACKS);
            (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
            delete (yyvsp[-1].token);
            }
#line 3254 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 136:
#line 844 "program6.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Multibracks();
                  ((Multibracks*)(yyval.ttype))->add();
                  (yyval.ttype)->setLineNumber((yyvsp[-1].token)->line);
                  delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 3265 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 137:
#line 850 "program6.y" /* yacc.c:1646  */
    {
                  ((Multibracks*)(yyvsp[-2].ttype))->add();
                  (yyval.ttype) = (yyvsp[-2].ttype);
                  delete (yyvsp[-1].token); delete (yyvsp[0].token);
                  }
#line 3275 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 138:
#line 855 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new ErrNode();
                    cerr << "Expected Right Bracket at " << yylval.token->line 
                    << ":" << yylval.token->column <<endl << endl;
                    yyerrok;
                    delete (yyvsp[-1].token);
                    }
#line 3287 "program6_bison.c" /* yacc.c:1646  */
    break;

  case 139:
#line 862 "program6.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new ErrNode();
                    cerr << "Expected Right Bracket at " << yylval.token->line 
                    << ":" << yylval.token->column <<endl << endl;
                    yyerrok;
                    delete (yyvsp[-2].ttype); delete (yyvsp[-1].token);
                    }
#line 3299 "program6_bison.c" /* yacc.c:1646  */
    break;


#line 3303 "program6_bison.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 871 "program6.y" /* yacc.c:1906  */

