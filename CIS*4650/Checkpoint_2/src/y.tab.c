/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/Parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"
#include "SymbolTable.h"
typedef char letter_1, letter_2;
void yyerror(char *msg);

extern int yylex();
extern int lineNum;

extern int nodesCount;


//HackyMethod to Know what type is used
int globalCalled=0;



char* structName="None";

int errorCount=0;
expressionTree root;

letter_1 l1='c';

#line 93 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    IDENTIFIER = 261,
    ADD = 262,
    MIN = 263,
    MUL = 264,
    DIV = 265,
    MOD = 266,
    EQ = 267,
    NE = 268,
    LT = 269,
    GT = 270,
    LTE = 271,
    GTE = 272,
    NOT = 273,
    ASSIGN = 274,
    INCREMENT = 275,
    DECREMENT = 276,
    L_PAREN = 277,
    R_PAREN = 278,
    L_BRACE = 279,
    R_BRACE = 280,
    COMA = 281,
    SEMICOLON = 282,
    L_SQBRACE = 283,
    R_SQBRACE = 284,
    DOT = 285,
    CONSTANT = 286,
    KW_STRUCT = 287,
    KW_VOID = 288,
    KW_FLOAT = 289,
    KW_CHAR = 290,
    KW_INT = 291,
    TYPEDEF = 292,
    SIZEOF = 293,
    RETURN = 294,
    IF = 295,
    ELSE = 296,
    FOR = 297,
    WHILE = 298
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define CHAR 260
#define IDENTIFIER 261
#define ADD 262
#define MIN 263
#define MUL 264
#define DIV 265
#define MOD 266
#define EQ 267
#define NE 268
#define LT 269
#define GT 270
#define LTE 271
#define GTE 272
#define NOT 273
#define ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define L_PAREN 277
#define R_PAREN 278
#define L_BRACE 279
#define R_BRACE 280
#define COMA 281
#define SEMICOLON 282
#define L_SQBRACE 283
#define R_SQBRACE 284
#define DOT 285
#define CONSTANT 286
#define KW_STRUCT 287
#define KW_VOID 288
#define KW_FLOAT 289
#define KW_CHAR 290
#define KW_INT 291
#define TYPEDEF 292
#define SIZEOF 293
#define RETURN 294
#define IF 295
#define ELSE 296
#define FOR 297
#define WHILE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "src/Parser.y" /* yacc.c:355  */

	float f;
	int i;
	char c;
	char* s;
	expressionTree xprT;

#line 227 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    96,    97,   100,   103,   106,   109,   112,
     115,   118,   122,   123,   127,   128,   129,   131,   132,   133,
     138,   140,   142,   144,   146,   151,   152,   156,   157,   160,
     161,   162,   164,   167,   168,   169,   172,   173,   179,   180,
     181,   182,   183,   197,   198,   202,   203,   204,   205,   206,
     214,   215,   216,   220,   223,   228,   232,   237,   238,   245,
     248,   249,   253,   254,   260,   261,   265,   266,   270,   271,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   291,   292,   293,   295,   297,   300,   303,
     307,   312,   313,   316,   318,   320,   323,   324,   325,   326,
     332,   335,   336,   337,   338,   343,   344,   345,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "IDENTIFIER",
  "ADD", "MIN", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "GT", "LTE", "GTE",
  "NOT", "ASSIGN", "INCREMENT", "DECREMENT", "L_PAREN", "R_PAREN",
  "L_BRACE", "R_BRACE", "COMA", "SEMICOLON", "L_SQBRACE", "R_SQBRACE",
  "DOT", "CONSTANT", "KW_STRUCT", "KW_VOID", "KW_FLOAT", "KW_CHAR",
  "KW_INT", "TYPEDEF", "SIZEOF", "RETURN", "IF", "ELSE", "FOR", "WHILE",
  "$accept", "Program", "Functions", "Function", "TypeDefs", "TypeDef",
  "Cont_TDecl", "Declerations", "Global_Decl", "Decleration",
  "Struct_Decl", "Cont_Decl", "Arguments", "Argument", "Brace_Expr",
  "Expressions", "For_1stParam", "For_2ndParam", "For_3rdParam",
  "Expression", "Func_Vars", "Expression_RTRN", "Accessor", "Var", YY_NULLPTR
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
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -224,    14,    45,  -224,    -7,   164,  -224,   352,  -224,     3,
      24,     3,     3,     3,     9,    27,    35,    44,    28,    41,
      94,  -224,   129,  -224,  -224,   -23,    31,     3,    56,    57,
      64,   339,  -224,   -20,    76,    48,    49,   123,    77,   223,
      85,   235,    93,     9,    88,   133,   134,   144,   146,  -224,
       3,   150,  -224,   130,  -224,  -224,  -224,   104,   104,   104,
     104,   104,   137,   339,   339,   104,   170,  -224,   274,  -224,
     140,   339,   339,  -224,   339,  -224,   339,  -224,   152,   171,
     156,   172,   175,  -224,   173,  -224,   105,  -224,  -224,  -224,
    -224,  -224,   169,  -224,   193,  -224,   191,   339,   358,  -224,
     201,   205,   213,   220,   228,   227,  -224,   236,   232,   239,
    -224,   104,   243,   265,   104,   104,   104,  -224,   249,   255,
     263,   270,     3,   183,  -224,   104,   280,  -224,    92,  -224,
    -224,  -224,  -224,  -224,   281,  -224,  -224,  -224,   390,   334,
     334,   334,   295,   303,   334,   289,   334,   290,   291,   292,
    -224,   293,   448,   294,  -224,   183,  -224,  -224,   183,   183,
     183,   183,  -224,   334,  -224,  -224,   328,   334,   316,    87,
     197,   197,   612,  -224,  -224,   510,   334,   612,   334,   334,
     334,  -224,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   277,  -224,   299,   183,   301,   305,   318,
     319,   612,   321,   490,   337,   414,   106,  -224,  -224,   527,
     544,   330,   612,   561,   197,   197,   364,   364,   364,   612,
     612,   612,   612,   612,   612,   281,  -224,  -224,   336,  -224,
    -224,  -224,  -224,  -224,   328,  -224,   332,   334,   316,  -224,
     341,   334,   343,  -224,  -224,   316,   425,  -224,   285,   342,
     612,   285,  -224,   333,   355,   346,   348,   367,   370,   469,
     334,   383,   316,  -224,   334,   334,   334,   226,   285,   391,
     612,   277,  -224,   578,   386,   595,   392,  -224,  -224,   395,
    -224,   420,   334,   421,   285,   285,   285,   388,   285,   422,
     423,   424,   334,   426,   277,   277,   234,   427,   285,  -224,
    -224,   428,  -224,   429,  -224,   285,   285,   441,   442,   285,
     285,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,     0,     1,     0,     0,    13,     0,    19,     0,
       0,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     2,     0,    28,    24,    23,     0,     0,     0,     0,
       0,    43,    42,    41,     0,     0,     0,    41,     0,    41,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,    18,     0,    15,    16,    14,     0,     0,     0,
       0,     0,     0,    43,    43,     0,     0,    34,    41,    36,
       0,    43,    43,    30,    43,    31,    43,    29,     0,     0,
       0,     0,     0,    22,     0,    17,    41,    49,    48,    46,
      47,    45,     0,    44,     0,    40,     0,    43,     0,    33,
       0,     0,     0,     0,     0,    21,    25,     0,    39,     0,
      35,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    32,     0,    25,
      25,    25,    25,    20,    35,   106,   108,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,    92,     0,    38,    25,     0,     0,
       0,     0,    63,     0,    89,    90,     0,     0,     0,   105,
      94,    93,    82,    87,    88,     0,     0,   100,     0,    64,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    86,     0,    98,     0,     0,   102,    83,    70,     0,
       0,     0,    65,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    80,    79,    81,     0,    57,     9,     0,    10,
       6,     7,     5,    99,     0,    95,    84,     0,     0,    91,
       0,    66,     0,     8,    97,     0,     0,   101,     0,     0,
      67,     0,    85,   103,     0,     0,     0,     0,     0,     0,
      68,     0,     0,    56,     0,    64,     0,     0,     0,     0,
      69,     0,   104,     0,     0,     0,     0,    58,    51,     0,
      60,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,    59,
      61,     0,    52,     0,    54,     0,     0,     0,     0,     0,
       0,    53,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,   446,  -224,  -224,  -224,    63,  -105,  -224,    -6,
    -224,    67,    25,  -224,  -130,  -148,   181,   187,   178,  -123,
     237,  -224,  -223,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,     2,     6,    26,   123,     7,   150,
      98,    34,    62,    63,   258,   151,   211,   249,   269,   259,
     204,   153,   207,   154
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,    23,    64,    50,    24,    51,    65,   195,    66,    25,
     197,   198,   199,   200,     3,   247,   170,   171,   172,   155,
       8,   175,   252,   177,   158,   159,   160,   161,    32,    32,
      27,    31,   152,    33,    37,   152,   152,   152,   152,   272,
     201,    35,    32,   203,   205,   226,     4,    39,   228,    32,
      36,   -27,   196,   209,    68,   210,   212,   213,    52,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     152,    71,    69,   152,    28,    29,    30,   -27,   -27,   -27,
     -27,   -27,     5,    54,    55,    38,    40,    42,    93,    94,
      53,    56,   117,    32,    78,    32,   100,   101,    86,   102,
      41,   103,    70,    67,    73,    32,   163,   164,   165,   166,
      86,   203,    75,    83,   246,   167,    69,   168,   250,   277,
      77,   261,   109,   280,    87,    88,    89,    90,    91,    -4,
      43,    65,    95,    66,   237,    44,   238,   270,   278,    79,
      80,   273,   212,   275,   152,    72,   299,   300,   152,    65,
      81,    66,    82,    84,   289,   290,   291,    85,   293,   250,
      92,    45,    17,    46,    47,    48,   302,    99,   304,   270,
       9,   152,   152,    96,    64,   307,   308,   104,    72,   311,
     312,    38,    40,    42,   134,   133,   135,   136,   137,   138,
     139,   140,   156,   106,    74,    70,    10,    76,    11,    12,
      13,   141,   105,   142,   143,   144,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   113,   107,   114,   115,   116,
     108,   145,   146,   147,   118,   148,   149,   225,   119,   135,
     136,   137,   169,   139,   140,   254,   120,   135,   136,   137,
     169,   139,   140,   121,   141,    74,   142,   143,   144,    65,
      97,    66,   141,   122,   142,   143,   144,    76,   125,   -50,
     124,    65,   126,    66,   145,   146,   147,   276,   148,   149,
     127,   128,   145,   129,   255,   301,   256,   257,   225,   130,
     135,   136,   137,   169,   139,   140,   254,   131,   135,   136,
     137,   169,   139,   140,   132,   141,    97,   142,   143,   144,
      65,   173,    66,   141,   157,   142,   143,   144,   162,   174,
     -50,   176,   178,   179,   180,   145,   146,   147,   181,   148,
     149,   194,   206,   145,   227,   255,   229,   256,   257,   202,
     230,   135,   136,   137,   169,   139,   140,   135,   136,   137,
     169,   139,   140,   231,   232,    57,   141,   233,   142,   143,
     144,   -96,   141,    14,   142,   143,   144,   241,    15,   110,
     235,   243,   245,   262,   111,   248,   145,   251,   264,   260,
     265,    58,   145,    59,    60,    61,   187,   188,   189,   190,
     191,   192,   263,   112,    16,    17,    18,    19,    20,   266,
     113,    32,   114,   115,   116,   267,    86,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   271,   163,
     164,   165,   166,   282,   279,   292,   284,  -105,   167,   285,
     168,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   236,   286,   288,   274,   294,   295,   296,
     303,   298,   305,   306,   253,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   309,   310,    49,   287,
     297,   244,     0,     0,     0,   193,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,     0,
       0,     0,     0,   208,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,     0,     0,     0,     0,
     239,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,     0,     0,     0,     0,   240,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
       0,     0,     0,     0,   242,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,     0,     0,     0,
       0,   281,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,     0,     0,     0,     0,   283,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192
};

static const yytype_int16 yycheck[] =
{
     123,     7,    22,    26,     1,    28,    26,   155,    28,     6,
     158,   159,   160,   161,     0,   238,   139,   140,   141,   124,
      27,   144,   245,   146,   129,   130,   131,   132,     1,     1,
       6,    22,   155,     6,     6,   158,   159,   160,   161,   262,
     163,     6,     1,   166,   167,   193,     1,     6,   196,     1,
       6,     6,   157,   176,     6,   178,   179,   180,    27,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    22,    24,   196,    11,    12,    13,    32,    33,    34,
      35,    36,    37,    27,    27,    18,    19,    20,    63,    64,
      27,    27,    98,     1,     6,     1,    71,    72,     6,    74,
       6,    76,    35,    27,    27,     1,    19,    20,    21,    22,
       6,   234,    27,    50,   237,    28,    24,    30,   241,   267,
      27,   251,    97,   271,    57,    58,    59,    60,    61,     0,
       1,    26,    65,    28,    28,     6,    30,   260,   268,     6,
       6,   264,   265,   266,   267,    22,   294,   295,   271,    26,
       6,    28,     6,     3,   284,   285,   286,    27,   288,   282,
      23,    32,    33,    34,    35,    36,   296,    27,   298,   292,
       6,   294,   295,     3,    22,   305,   306,     6,    22,   309,
     310,   114,   115,   116,     1,   122,     3,     4,     5,     6,
       7,     8,   125,    24,    22,   128,    32,    22,    34,    35,
      36,    18,    29,    20,    21,    22,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    32,    23,    34,    35,    36,
      29,    38,    39,    40,    23,    42,    43,     1,    23,     3,
       4,     5,     6,     7,     8,     1,    23,     3,     4,     5,
       6,     7,     8,    23,    18,    22,    20,    21,    22,    26,
      22,    28,    18,    26,    20,    21,    22,    22,    26,    25,
      24,    26,    23,    28,    38,    39,    40,    41,    42,    43,
      27,     6,    38,    24,    40,    41,    42,    43,     1,    24,
       3,     4,     5,     6,     7,     8,     1,    24,     3,     4,
       5,     6,     7,     8,    24,    18,    22,    20,    21,    22,
      26,     6,    28,    18,    24,    20,    21,    22,    27,     6,
      25,    22,    22,    22,    22,    38,    39,    40,    25,    42,
      43,    27,     6,    38,    25,    40,    25,    42,    43,     1,
      25,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    25,    25,     6,    18,    26,    20,    21,
      22,    23,    18,     1,    20,    21,    22,    27,     6,     1,
      23,    25,    30,    30,     6,    24,    38,    24,    22,    27,
      22,    32,    38,    34,    35,    36,    12,    13,    14,    15,
      16,    17,    27,    25,    32,    33,    34,    35,    36,    22,
      32,     1,    34,    35,    36,    25,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    25,    19,
      20,    21,    22,    27,    23,    27,    24,    27,    28,    24,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    29,    24,    24,   265,    25,    25,    25,
      23,    25,    24,    24,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    25,    25,    22,   282,
     292,   234,    -1,    -1,    -1,    27,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    23,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    23,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    23,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    48,     0,     1,    37,    49,    52,    27,     6,
      32,    34,    35,    36,     1,     6,    32,    33,    34,    35,
      36,    46,    47,    53,     1,     6,    50,     6,    50,    50,
      50,    22,     1,     6,    55,     6,     6,     6,    55,     6,
      55,     6,    55,     1,     6,    32,    34,    35,    36,    46,
      26,    28,    27,    50,    27,    27,    27,     6,    32,    34,
      35,    36,    56,    57,    22,    26,    28,    27,     6,    24,
      55,    22,    22,    27,    22,    27,    22,    27,     6,     6,
       6,     6,     6,    50,     3,    27,     6,    55,    55,    55,
      55,    55,    23,    56,    56,    55,     3,    22,    54,    27,
      56,    56,    56,    56,     6,    29,    24,    23,    29,    56,
       1,     6,    25,    32,    34,    35,    36,    53,    23,    23,
      23,    23,    26,    51,    24,    26,    23,    27,     6,    24,
      24,    24,    24,    50,     1,     3,     4,     5,     6,     7,
       8,    18,    20,    21,    22,    38,    39,    40,    42,    43,
      53,    59,    63,    65,    67,    51,    55,    24,    51,    51,
      51,    51,    27,    19,    20,    21,    22,    28,    30,     6,
      63,    63,    63,     6,     6,    63,    22,    63,    22,    22,
      22,    25,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    27,    27,    59,    51,    59,    59,    59,
      59,    63,     1,    63,    64,    63,     6,    66,    23,    63,
      63,    60,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,     1,    59,    25,    59,    25,
      25,    25,    25,    26,    26,    23,    29,    28,    30,    23,
      23,    27,    23,    25,    64,    30,    63,    66,    24,    61,
      63,    24,    66,    29,     1,    40,    42,    43,    58,    63,
      27,    58,    30,    27,    22,    22,    22,    25,    27,    62,
      63,    25,    66,    63,    60,    63,    41,    59,    58,    23,
      59,    23,    27,    23,    24,    24,    24,    61,    24,    58,
      58,    58,    27,    58,    25,    25,    25,    62,    25,    59,
      59,    41,    58,    23,    58,    24,    24,    58,    58,    25,
      25,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      50,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      65,    66,    66,    66,    66,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     9,     9,     9,    10,     9,
       9,     8,     0,     2,     4,     4,     4,     5,     4,     2,
       6,     4,     3,     1,     1,     0,     2,     0,     2,     3,
       3,     3,     6,     4,     3,     1,     0,     2,     6,     4,
       3,     1,     1,     0,     2,     2,     2,     2,     2,     2,
       0,     3,     8,    12,     8,    12,     2,     3,     8,    12,
       8,    12,     2,     2,     0,     1,     0,     1,     0,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     4,     6,     3,     2,     2,     2,
       2,     4,     1,     2,     2,     4,     0,     3,     1,     2,
       2,     3,     1,     4,     6,     1,     1,     1,     1
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
        case 2:
#line 89 "src/Parser.y" /* yacc.c:1646  */
    { root = (yyvsp[0].xprT);}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression("_",(yyvsp[-1].xprT),(yyvsp[0].xprT), Function);}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"int"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"float"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"char"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),(yyvsp[-8].s)); (yyval.xprT) = ContainerExpression((yyvsp[-8].s),(yyvsp[-2].xprT),NULL, Function);}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),(yyvsp[-8].s));    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"void");    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "src/Parser.y" /* yacc.c:1646  */
    {    (yyval.xprT) = ContainerExpression("ERROR",(yyvsp[-1].xprT),NULL, Function);  }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT)= NULL;}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("int"); (yyval.xprT) = NULL;}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("float"); (yyval.xprT) = NULL;}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("char"); (yyval.xprT) = NULL;}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-5].s),"None",(yyvsp[-3].i));(yyval.xprT) = NULL;}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-3].s),"None",(yyvsp[-1].i));(yyval.xprT) = NULL;}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[-2].s),"None");(yyval.xprT) = NULL;}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[0].s),"None");(yyval.xprT) = NULL;}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "src/Parser.y" /* yacc.c:1646  */
    {if(globalCalled==0)Add_Scope("Global","void");  globalCalled=1; (yyval.xprT)= NULL;}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL; }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 160 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("int"); (yyval.xprT) = NULL;	 	 }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("float");(yyval.xprT) = NULL;    	 }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("char");(yyval.xprT) = NULL;    	 }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-4].s), "struct"); Link_StructVariables((yyvsp[-4].s)); Add_TYPEDEF((yyvsp[-4].s),(yyvsp[-4].s)); (yyval.xprT) = NULL;    	 }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT)=NULL; }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT) = NULL;   	 }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;  	 }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 172 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable("$TART", "struct");(yyval.xprT)= NULL;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-5].s), "1Standby",(yyvsp[-3].i)); (yyval.xprT) = NULL;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-3].s), "1Standby",(yyvsp[-1].i)); (yyval.xprT) = NULL;}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-2].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[0].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 203 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 204 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 205 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 206 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 215 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-9].xprT),ContainerExpression(NULL,(yyvsp[-6].xprT), /**/(operatorExpression(IF_OP, operatorExpression(NOT_OP,(yyvsp[-9].xprT),NULL) ,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))) /**/, Expression))),(yyvsp[0].xprT), Expression);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 223 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 229 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 232 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 237 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 239 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 246 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-9].xprT),ContainerExpression(NULL,(yyvsp[-6].xprT), /**/(operatorExpression(IF_OP, operatorExpression(NOT_OP,(yyvsp[-9].xprT),NULL) ,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))) /**/, Expression))),(yyvsp[0].xprT), Expression);}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 248 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 250 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 253 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-1].xprT),NULL, Expression);}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 254 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 260 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 261 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "src/Parser.y" /* yacc.c:1646  */
    {int i=1; void*v=&i; (yyval.xprT) = ConstantExpression(v,_Int); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 270 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 271 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 276 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[-1].xprT);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 277 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(PlusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 278 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(MinusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 279 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(TimesOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 280 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(DivideOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 281 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ModOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 282 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(EQ_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 283 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 284 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 285 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 286 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 287 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 288 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NOT_OP,(yyvsp[0].xprT),NULL);}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 291 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 292 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 293 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 295 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 297 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 300 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 303 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; 

			(yyval.xprT) = operatorExpression(USE_OP,IdentifierExpression((yyvsp[-1].s)),operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 307 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(USE_OP,IdentifierExpression((yyvsp[-1].s)),
			operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 312 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(SIZE_OP,(yyvsp[-1].xprT),NULL);}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 313 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 316 "src/Parser.y" /* yacc.c:1646  */
    {int i=-1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 318 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 320 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) =  operatorExpression(Call_OP, IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT));}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 323 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 324 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 325 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 326 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 332 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(RETURN_OP,(yyvsp[0].xprT),NULL);}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 335 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 336 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 337 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 338 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 343 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 344 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].i),_Int);}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 345 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].c),_Char);}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 346 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].f),_Float);}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2220 "y.tab.c" /* yacc.c:1646  */
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
#line 349 "src/Parser.y" /* yacc.c:1906  */

///////////////////////////////////////////////

void yyerror(char *msg)
{
	//All Errors are Fatal atm
	fprintf(stderr, "\nError On Line: %d %s\n", lineNum, msg);


	//printf("\nError On Line: %d %s\n", lineNum, msg);

	errorCount++;
	//errorCount++;
	//exit(1);
}

// error token is yaccs predefined error token used for parsing. 
// It's a freaking masterpiece

void PrintABS()
{
 	FILE *f = fopen("Tree.abs", "w");
	//fprintf(f,"Printing Tree:\n");
	PrintTree(root,0,f);
	fclose(f);
}


int main(int argc, char* argv[])
{
	printf("Starting Compiler..\n");
	//Init the Symbol Table
	Initialize_HashTable();

	yyparse();
	printf("\nCompilation finished.\n");


	if(argc>1)
	{
		if(strcmp(argv[1],"-a")==0)
		{
		PrintABS();
		printf("ABS file created.\n");
		}

		else if(strcmp(argv[1],"-s")==0)
		{
				if(errorCount==0)
				{	
					Print_SymbolTable();
					printf("Symbol Table File Created.\n");

					TraverseTree(0,root);
					//Perform TypeChecking on Tree
					//PerformTypeCheck(0,root,NULL);
				}
				else
				{
					printf("The file contains errors,please fix in order to continue.\n");
				}
		}


		else if(strcmp(argv[1],"-c")==0)
		{
			printf("\nError Count: %d\n", errorCount);

			if(errorCount==0)
				printf("The Program is free of syntax errors! :)\n");
		}
	}

	FreeTree(root);
 	Free_HashTable();

	return 0;
}

