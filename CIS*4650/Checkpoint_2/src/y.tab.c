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
#define YYLAST   570

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
     214,   215,   216,   217,   218,   222,   226,   231,   232,   234,
     235,   236,   240,   241,   246,   247,   251,   252,   256,   257,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   277,   278,   279,   281,   283,   286,   289,
     293,   298,   299,   302,   304,   306,   309,   310,   311,   312,
     318,   321,   322,   323,   324,   329,   330,   331,   332
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

#define YYPACT_NINF -236

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-236)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -236,     3,    54,  -236,   -13,   115,  -236,    72,  -236,    45,
       9,    45,    45,    45,     0,   110,    19,    25,   121,   151,
     154,  -236,   190,  -236,  -236,   -15,     8,    45,    15,    22,
      23,   178,  -236,    87,    30,    28,    63,   148,    65,   153,
      68,   167,    98,     0,   104,   132,   133,   140,   161,  -236,
      45,   174,  -236,   159,  -236,  -236,  -236,   226,   226,   226,
     226,   226,   155,   178,   178,   226,   184,  -236,   280,  -236,
     182,   178,   178,  -236,   178,  -236,   178,  -236,   172,   195,
     193,   194,   196,  -236,   200,  -236,    48,  -236,  -236,  -236,
    -236,  -236,   204,  -236,   207,  -236,   215,   178,   299,  -236,
     213,   229,   236,   238,   243,   240,  -236,   249,   252,   256,
    -236,   226,   254,   281,   226,   226,   226,  -236,   262,   277,
     283,   286,    45,   199,  -236,   226,   301,  -236,   111,  -236,
    -236,  -236,  -236,  -236,   296,  -236,  -236,  -236,   331,   291,
     291,   291,   298,   320,   291,   306,   291,   308,   303,   314,
     327,  -236,   329,   389,   328,  -236,   199,  -236,  -236,   199,
     199,   199,   199,  -236,   291,  -236,  -236,    76,   291,   350,
     143,   305,   305,   553,  -236,  -236,   451,   291,   553,   291,
     242,   291,   291,  -236,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   250,  -236,   332,   199,   335,
     367,   368,   369,   553,   365,   431,   384,   355,    96,  -236,
    -236,   468,   485,   381,   387,   386,   390,   391,   403,   410,
     388,   553,   502,   305,   305,   373,   373,   373,   553,   553,
     553,   553,   553,   553,   296,  -236,  -236,   404,  -236,  -236,
    -236,  -236,  -236,    76,  -236,   400,   291,   350,  -236,   407,
    -236,   291,   242,   291,   291,   250,   242,   291,   408,  -236,
    -236,   350,   366,  -236,   242,   519,   409,   406,   536,  -236,
    -236,   422,   553,   242,  -236,   405,   411,   426,   242,   291,
     427,   291,   428,   350,   250,   242,  -236,   425,   242,   432,
     553,   250,  -236,  -236,   429,   291,   444,   446,  -236,   242,
     433,   242,   242,  -236,   447,  -236,   448,   242,   250,   461,
    -236,   242,  -236
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
       0,    26,     0,     0,     0,    92,     0,    38,    25,     0,
       0,     0,     0,    63,     0,    89,    90,     0,     0,     0,
     105,    94,    93,    82,    87,    88,     0,     0,   100,     0,
       0,    64,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    86,     0,    98,     0,     0,   102,    83,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    80,    79,    81,     0,    57,     9,     0,    10,     6,
       7,     5,    99,     0,    95,    84,     0,     0,    91,     0,
      56,     0,     0,    64,     0,     0,     0,    66,     0,     8,
      97,     0,     0,   101,     0,     0,     0,     0,     0,    59,
      51,     0,    67,     0,    85,   103,     0,     0,     0,    66,
       0,    68,     0,     0,     0,     0,    53,     0,     0,     0,
      69,     0,   104,    58,     0,    68,     0,     0,    60,     0,
       0,     0,     0,    52,     0,    54,     0,     0,     0,     0,
      61,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,   392,  -236,  -236,  -236,    -3,   145,  -236,    -5,
    -236,    83,   -44,  -236,  -119,  -155,   158,   208,   177,  -123,
     245,  -236,  -235,  -236
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,     2,     6,    26,   123,     7,   151,
      98,    34,    62,    63,   218,   152,   220,   271,   289,   219,
     206,   154,   209,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     153,   197,    23,     3,   199,   200,   201,   202,    28,    29,
      30,    50,   263,    51,     8,    27,   171,   172,   173,    93,
      94,   176,    31,   178,    53,    35,   274,   100,   101,    32,
     102,    36,   103,   153,    68,    52,   153,   153,   153,   153,
     235,   203,    54,   237,   205,   207,    24,    83,   292,    55,
      56,    25,    69,   109,   211,     4,   212,    67,   221,   222,
     -27,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   153,    14,    65,   153,    66,   204,    15,   135,
     136,   137,   170,   139,   140,    71,   -27,   -27,   -27,   -27,
     -27,     5,    73,   117,   141,    75,   142,   143,   144,   -96,
     269,    38,    40,    42,    16,    17,    18,    19,    20,    64,
      78,    32,    32,    65,   145,    66,    33,    86,    70,   133,
     205,     9,    32,   262,   246,    77,   247,    37,   265,   293,
     221,   268,   153,   266,   272,    69,   298,   270,    79,    80,
      87,    88,    89,    90,    91,   276,    81,    10,    95,    11,
      12,    13,    32,   310,   282,    32,   272,    39,   290,   286,
      41,   153,   164,   165,   166,   167,   294,    82,   153,   296,
      72,   168,   290,   169,    65,    74,    66,    84,    92,    65,
     303,    66,   305,   306,    57,   153,    85,    96,   309,    76,
      -4,    43,   312,    65,    64,    66,    44,    38,    40,    42,
     134,   104,   135,   136,   137,   138,   139,   140,   157,    99,
      58,    70,    59,    60,    61,    72,    74,   141,    76,   142,
     143,   144,    45,    17,    46,    47,    48,    32,   106,   105,
     107,   113,    86,   114,   115,   116,   118,   145,   146,   147,
     148,   149,   150,   213,   108,   135,   136,   137,   170,   139,
     140,   234,   119,   135,   136,   137,   170,   139,   140,   120,
     141,   121,   142,   143,   144,    97,   122,   -50,   141,   156,
     142,   143,   144,   124,   159,   160,   161,   162,   125,   126,
     145,   127,   214,   215,   216,   217,   129,   128,   145,   146,
     147,   148,   149,   150,   135,   136,   137,   170,   139,   140,
     110,   130,    97,   198,   174,   111,    65,   131,    66,   141,
     132,   142,   143,   144,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   163,   112,   158,   175,   180,   177,   145,
     179,   113,    32,   114,   115,   116,   181,    86,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   182,
     164,   165,   166,   167,   183,   196,   208,   236,  -105,   168,
     238,   169,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   245,   189,   190,   191,   192,   193,
     194,   242,   239,   240,   241,   275,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   244,   250,   251,
     252,   267,   253,   254,    49,   257,   195,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   255,   259,
     261,   264,   273,   279,   278,   283,   284,   256,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   281,
     285,   288,   295,   291,   299,   297,   304,   243,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   301,
     302,   307,   300,   308,   210,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   311,   287,   260,     0,
       0,   248,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,   249,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,   258,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,   277,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,     0,     0,     0,     0,   280,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194
};

static const yytype_int16 yycheck[] =
{
     123,   156,     7,     0,   159,   160,   161,   162,    11,    12,
      13,    26,   247,    28,    27,     6,   139,   140,   141,    63,
      64,   144,    22,   146,    27,     6,   261,    71,    72,     1,
      74,     6,    76,   156,     6,    27,   159,   160,   161,   162,
     195,   164,    27,   198,   167,   168,     1,    50,   283,    27,
      27,     6,    24,    97,   177,     1,   179,    27,   181,   182,
       6,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     1,    26,   198,    28,     1,     6,     3,
       4,     5,     6,     7,     8,    22,    32,    33,    34,    35,
      36,    37,    27,    98,    18,    27,    20,    21,    22,    23,
     255,    18,    19,    20,    32,    33,    34,    35,    36,    22,
       6,     1,     1,    26,    38,    28,     6,     6,    35,   122,
     243,     6,     1,   246,    28,    27,    30,     6,   251,   284,
     253,   254,   255,   252,   257,    24,   291,   256,     6,     6,
      57,    58,    59,    60,    61,   264,     6,    32,    65,    34,
      35,    36,     1,   308,   273,     1,   279,     6,   281,   278,
       6,   284,    19,    20,    21,    22,   285,     6,   291,   288,
      22,    28,   295,    30,    26,    22,    28,     3,    23,    26,
     299,    28,   301,   302,     6,   308,    27,     3,   307,    22,
       0,     1,   311,    26,    22,    28,     6,   114,   115,   116,
       1,     6,     3,     4,     5,     6,     7,     8,   125,    27,
      32,   128,    34,    35,    36,    22,    22,    18,    22,    20,
      21,    22,    32,    33,    34,    35,    36,     1,    24,    29,
      23,    32,     6,    34,    35,    36,    23,    38,    39,    40,
      41,    42,    43,     1,    29,     3,     4,     5,     6,     7,
       8,     1,    23,     3,     4,     5,     6,     7,     8,    23,
      18,    23,    20,    21,    22,    22,    26,    25,    18,   124,
      20,    21,    22,    24,   129,   130,   131,   132,    26,    23,
      38,    27,    40,    41,    42,    43,    24,     6,    38,    39,
      40,    41,    42,    43,     3,     4,     5,     6,     7,     8,
       1,    24,    22,   158,     6,     6,    26,    24,    28,    18,
      24,    20,    21,    22,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    27,    25,    24,     6,    24,    22,    38,
      22,    32,     1,    34,    35,    36,    22,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    22,
      19,    20,    21,    22,    25,    27,     6,    25,    27,    28,
      25,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    29,    12,    13,    14,    15,    16,
      17,    26,    25,    25,    25,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    23,    27,    22,
      24,   253,    22,    22,    22,    27,    27,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    25,    25,
      30,    24,    24,    27,    25,    30,    25,    27,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    27,
      24,    24,    27,    25,    25,    23,    23,    26,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    25,
      24,    24,   295,    25,    23,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    25,   279,   243,    -1,
      -1,    23,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17
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
       8,    18,    20,    21,    22,    38,    39,    40,    41,    42,
      43,    53,    59,    63,    65,    67,    51,    55,    24,    51,
      51,    51,    51,    27,    19,    20,    21,    22,    28,    30,
       6,    63,    63,    63,     6,     6,    63,    22,    63,    22,
      24,    22,    22,    25,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    27,    27,    59,    51,    59,
      59,    59,    59,    63,     1,    63,    64,    63,     6,    66,
      23,    63,    63,     1,    40,    41,    42,    43,    58,    63,
      60,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,     1,    59,    25,    59,    25,    25,
      25,    25,    26,    26,    23,    29,    28,    30,    23,    23,
      27,    22,    24,    22,    22,    25,    27,    27,    23,    25,
      64,    30,    63,    66,    24,    63,    58,    60,    63,    59,
      58,    61,    63,    24,    66,    29,    58,    23,    25,    27,
      23,    27,    58,    30,    25,    24,    58,    61,    24,    62,
      63,    25,    66,    59,    58,    27,    58,    23,    59,    25,
      62,    25,    24,    58,    23,    58,    58,    24,    25,    58,
      59,    25,    58
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
       0,     3,     8,     5,     8,    12,     2,     3,     8,     5,
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
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression("_",(yyvsp[-1].xprT),(yyvsp[0].xprT), Function);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s)); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression((yyvsp[-8].s),(yyvsp[-2].xprT),NULL, Function);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "src/Parser.y" /* yacc.c:1646  */
    {    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "src/Parser.y" /* yacc.c:1646  */
    {    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "src/Parser.y" /* yacc.c:1646  */
    {    (yyval.xprT) = ContainerExpression("ERROR",(yyvsp[-1].xprT),NULL, Function);  }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT)= NULL;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("int"); (yyval.xprT) = NULL;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("float"); (yyval.xprT) = NULL;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("char"); (yyval.xprT) = NULL;}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-5].s),"None",(yyvsp[-3].i));(yyval.xprT) = NULL;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-3].s),"None",(yyvsp[-1].i));(yyval.xprT) = NULL;}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[-2].s),"None");(yyval.xprT) = NULL;}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[0].s),"None");(yyval.xprT) = NULL;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "src/Parser.y" /* yacc.c:1646  */
    {if(globalCalled==0)Add_Scope("Global");  globalCalled=1; (yyval.xprT)= NULL;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL; }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 160 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("int"); (yyval.xprT) = NULL;	 	 }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("float");(yyval.xprT) = NULL;    	 }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("char");(yyval.xprT) = NULL;    	 }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-4].s), "struct"); Link_StructVariables((yyvsp[-4].s)); Add_TYPEDEF((yyvsp[-4].s),(yyvsp[-4].s)); (yyval.xprT) = NULL;    	 }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT)=NULL; }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT) = NULL;   	 }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;  	 }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 172 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable("$TART", "struct");(yyval.xprT)= NULL;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-5].s), "1Standby",(yyvsp[-3].i)); (yyval.xprT) = NULL;}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-3].s), "1Standby",(yyvsp[-1].i)); (yyval.xprT) = NULL;}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-2].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[0].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 203 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 204 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 205 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 206 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 215 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 217 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(ELSE_OP,NULL,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 218 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 223 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 231 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 232 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 234 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(ELSE_OP,NULL,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 235 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 237 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-1].xprT),NULL, Expression);}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 241 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 246 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 251 "src/Parser.y" /* yacc.c:1646  */
    {int i=1; void*v=&i; (yyval.xprT) = ConstantExpression(v,_Int); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 252 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 256 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 257 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 262 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[-1].xprT);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 263 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(PlusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 264 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(MinusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 265 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(TimesOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 266 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(DivideOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 267 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ModOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 268 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(EQ_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 269 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 270 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 271 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 272 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 273 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 274 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NOT_OP,(yyvsp[0].xprT),NULL);}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 277 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 279 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 281 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 283 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 286 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 289 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; 

			(yyval.xprT) = operatorExpression(RETURN_OP,IdentifierExpression((yyvsp[-1].s)),operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 293 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(RETURN_OP,IdentifierExpression((yyvsp[-1].s)),
			operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 298 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(SIZE_OP,(yyvsp[-1].xprT),NULL);}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 299 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 302 "src/Parser.y" /* yacc.c:1646  */
    {int i=-1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 304 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 306 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) =  operatorExpression(Call_OP, IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT));}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 309 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 310 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 311 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 312 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 318 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(RETURN_OP,(yyvsp[0].xprT),NULL);}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 321 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 322 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 323 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 324 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 329 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 330 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].i),_Int);}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 331 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].c),_Char);}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 332 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].f),_Float);}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2210 "y.tab.c" /* yacc.c:1646  */
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
#line 335 "src/Parser.y" /* yacc.c:1906  */

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
	fprintf(f,"Printing Tree:\n");
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
				{	Print_SymbolTable();
					printf("Symbol Table File Created.\n");
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

