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

#line 92 "y.tab.c" /* yacc.c:339  */

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
#line 28 "src/Parser.y" /* yacc.c:355  */

	float f;
	int i;
	char c;
	char* s;
	expressionTree xprT;

#line 226 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

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
       0,    88,    88,    95,    96,    99,   102,   105,   108,   111,
     114,   117,   121,   122,   126,   127,   128,   130,   131,   132,
     137,   139,   141,   143,   145,   150,   151,   155,   156,   159,
     160,   161,   164,   167,   168,   169,   172,   173,   179,   180,
     181,   182,   183,   197,   198,   202,   203,   204,   205,   206,
     214,   215,   216,   220,   223,   228,   232,   237,   238,   243,
     253,   254,   258,   259,   265,   266,   270,   271,   275,   276,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   296,   297,   298,   300,   302,   305,   308,
     312,   317,   318,   321,   323,   325,   328,   329,   330,   331,
     337,   340,   341,   342,   343,   348,   349,   350,   351
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

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -177,    31,   131,  -177,   -21,    16,  -177,   353,  -177,     9,
      40,     9,     9,     9,    59,    83,    76,    84,   116,   135,
     193,  -177,   175,  -177,  -177,   -19,    64,     9,    67,    71,
      78,    72,  -177,    49,   112,    23,   118,    57,   119,    73,
     132,    74,   134,    59,   156,   163,   165,   171,   173,  -177,
       9,   183,  -177,   170,  -177,  -177,  -177,   194,   194,   194,
     194,   194,   178,    72,    72,   194,   195,  -177,   152,  -177,
     176,    72,    72,  -177,    72,  -177,    72,  -177,   190,   207,
     192,   199,   203,  -177,   186,  -177,     6,  -177,  -177,  -177,
    -177,  -177,   205,  -177,   214,  -177,   188,    72,   359,  -177,
     221,   223,   228,   229,   232,   224,  -177,   234,   233,   238,
    -177,   194,   236,   256,   194,   194,   194,  -177,   240,   247,
     248,   250,     9,   184,  -177,   194,   264,  -177,    34,  -177,
    -177,  -177,  -177,  -177,   253,  -177,  -177,  -177,   391,   335,
     335,   335,   289,   291,   335,   279,   335,   280,   281,   283,
    -177,   284,   449,   285,   294,  -177,   184,  -177,  -177,   184,
     184,   184,   184,  -177,  -177,  -177,   329,   335,   304,   342,
     141,   141,   613,  -177,  -177,   511,   335,   613,   335,   335,
     335,  -177,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   278,  -177,   335,   306,   184,   319,   320,
     321,   333,   293,   491,   343,   415,    88,   349,  -177,   528,
     545,   344,   613,   562,   141,   141,   362,   362,   362,   613,
     613,   613,   613,   613,   613,   253,  -177,   613,  -177,   355,
    -177,  -177,  -177,  -177,  -177,   329,  -177,    11,   335,   304,
    -177,   345,   335,   357,  -177,  -177,   304,   426,  -177,   286,
     356,   613,   286,   363,   360,   369,   387,   392,   393,   395,
     470,   335,   420,   304,  -177,   335,   335,   335,   227,   286,
     394,   613,   278,  -177,   579,   389,   596,   422,  -177,  -177,
     423,  -177,   424,   335,   425,   286,   286,   286,   427,   286,
     428,   442,   443,   335,   444,   278,   278,   235,   429,   286,
    -177,  -177,   446,  -177,   447,  -177,   286,   286,   448,   450,
     286,   286,  -177,  -177
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
      26,     0,     0,     0,     0,    92,     0,    38,    25,     0,
       0,     0,     0,    63,    89,    90,     0,     0,     0,   105,
      94,    93,    82,    87,    88,     0,     0,   100,     0,    64,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,   102,    83,    70,     0,
       0,     0,    65,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    80,    79,    81,     0,    57,    86,     9,     0,
      10,     6,     7,     5,    99,     0,    95,    84,     0,     0,
      91,     0,    66,     0,     8,    97,     0,     0,   101,     0,
       0,    67,     0,    85,   103,     0,     0,     0,     0,     0,
       0,    68,     0,     0,    56,     0,    64,     0,     0,     0,
       0,    69,     0,   104,     0,     0,     0,     0,    58,    51,
       0,    60,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
      59,    61,     0,    52,     0,    54,     0,     0,     0,     0,
       0,     0,    53,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,   452,  -177,  -177,  -177,    -8,  -104,  -177,    -6,
    -177,    68,   251,  -177,  -176,  -148,   185,   167,   179,  -123,
     254,  -177,  -166,  -177
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,     2,     6,    26,   123,     7,   150,
      98,    34,    62,    63,   259,   151,   211,   250,   270,   260,
     204,   153,   154,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,    23,   207,    28,    29,    30,     8,    50,   196,    51,
      24,   198,   199,   200,   201,    25,   170,   171,   172,    53,
     156,   175,     9,   177,    32,   159,   160,   161,   162,    68,
    -103,     3,    65,   152,    66,    32,   152,   152,   152,   152,
      86,   246,    83,   203,   205,   226,    27,    69,    10,   229,
      11,    12,    13,   209,   197,   210,   212,   213,    69,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     152,    64,   227,   248,   152,    65,   262,    66,    57,    72,
     253,    31,    35,    65,    32,    66,    38,    40,    42,    33,
      36,    52,   117,   279,    54,    74,    76,   273,    55,    65,
      65,    66,    66,    70,    58,    56,    59,    60,    61,   290,
     291,   292,   203,   294,   133,   247,   238,    32,   239,   251,
     278,   303,    37,   305,   281,    87,    88,    89,    90,    91,
     308,   309,     4,    95,   312,   313,    32,   -27,   271,    67,
      71,    39,   274,   212,   276,   152,    73,   300,   301,   152,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    75,
     251,    77,    78,   -27,   -27,   -27,   -27,   -27,     5,    79,
     271,    80,   152,   152,    97,    -4,    43,    81,    65,    82,
      66,    44,    38,    40,    42,   134,    84,   135,   136,   137,
     138,   139,   140,   157,    32,    32,    70,    85,    96,    41,
      86,    92,   141,    99,   142,   143,   144,    45,    17,    46,
      47,    48,    64,   104,    72,   105,   113,   108,   114,   115,
     116,    74,   145,   146,   147,    76,   148,   149,   225,   106,
     135,   136,   137,   169,   139,   140,   255,   107,   135,   136,
     137,   169,   139,   140,   118,   141,   119,   142,   143,   144,
     122,   120,   121,   141,    97,   142,   143,   144,   124,   125,
     -50,   126,   128,   127,   129,   145,   146,   147,   277,   148,
     149,   130,   131,   145,   132,   256,   302,   257,   258,   225,
     163,   135,   136,   137,   169,   139,   140,   255,   158,   135,
     136,   137,   169,   139,   140,   173,   141,   174,   142,   143,
     144,   176,   178,   179,   141,   180,   142,   143,   144,   181,
     206,   -50,   194,   195,    93,    94,   145,   146,   147,   234,
     148,   149,   100,   101,   145,   102,   256,   103,   257,   258,
     202,   228,   135,   136,   137,   169,   139,   140,   135,   136,
     137,   169,   139,   140,   230,   231,   232,   141,   109,   142,
     143,   144,   -96,   141,    14,   142,   143,   144,   233,    15,
     110,  -102,   164,   165,   166,   111,   236,   145,  -101,   249,
     167,   242,   168,   145,   187,   188,   189,   190,   191,   192,
     244,   252,  -104,   261,   112,    16,    17,    18,    19,    20,
     263,   113,    32,   114,   115,   116,   264,    86,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   265,
    -102,   164,   165,   166,   266,   267,   283,   280,  -105,   167,
     268,   168,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   237,   272,   285,   286,   287,   289,
     288,   275,   304,   295,   293,   254,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   296,   297,   299,
     306,   307,   298,   310,    49,   311,   193,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   245,
       0,     0,     0,     0,     0,     0,     0,   269,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
       0,     0,     0,     0,   208,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,     0,     0,     0,
       0,   240,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,     0,     0,     0,     0,   241,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,     0,     0,     0,     0,   243,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,     0,     0,
       0,     0,   282,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,     0,     0,     0,     0,   284,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192
};

static const yytype_int16 yycheck[] =
{
     123,     7,   168,    11,    12,    13,    27,    26,   156,    28,
       1,   159,   160,   161,   162,     6,   139,   140,   141,    27,
     124,   144,     6,   146,     1,   129,   130,   131,   132,     6,
      19,     0,    26,   156,    28,     1,   159,   160,   161,   162,
       6,    30,    50,   166,   167,   193,     6,    24,    32,   197,
      34,    35,    36,   176,   158,   178,   179,   180,    24,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    22,   195,   239,   197,    26,   252,    28,     6,    22,
     246,    22,     6,    26,     1,    28,    18,    19,    20,     6,
       6,    27,    98,   269,    27,    22,    22,   263,    27,    26,
      26,    28,    28,    35,    32,    27,    34,    35,    36,   285,
     286,   287,   235,   289,   122,   238,    28,     1,    30,   242,
     268,   297,     6,   299,   272,    57,    58,    59,    60,    61,
     306,   307,     1,    65,   310,   311,     1,     6,   261,    27,
      22,     6,   265,   266,   267,   268,    27,   295,   296,   272,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    27,
     283,    27,     6,    32,    33,    34,    35,    36,    37,     6,
     293,     6,   295,   296,    22,     0,     1,     6,    26,     6,
      28,     6,   114,   115,   116,     1,     3,     3,     4,     5,
       6,     7,     8,   125,     1,     1,   128,    27,     3,     6,
       6,    23,    18,    27,    20,    21,    22,    32,    33,    34,
      35,    36,    22,     6,    22,    29,    32,    29,    34,    35,
      36,    22,    38,    39,    40,    22,    42,    43,     1,    24,
       3,     4,     5,     6,     7,     8,     1,    23,     3,     4,
       5,     6,     7,     8,    23,    18,    23,    20,    21,    22,
      26,    23,    23,    18,    22,    20,    21,    22,    24,    26,
      25,    23,     6,    27,    24,    38,    39,    40,    41,    42,
      43,    24,    24,    38,    24,    40,    41,    42,    43,     1,
      27,     3,     4,     5,     6,     7,     8,     1,    24,     3,
       4,     5,     6,     7,     8,     6,    18,     6,    20,    21,
      22,    22,    22,    22,    18,    22,    20,    21,    22,    25,
       6,    25,    27,    19,    63,    64,    38,    39,    40,    26,
      42,    43,    71,    72,    38,    74,    40,    76,    42,    43,
       1,    25,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    25,    25,    25,    18,    97,    20,
      21,    22,    23,    18,     1,    20,    21,    22,    25,     6,
       1,    19,    20,    21,    22,     6,    23,    38,    19,    24,
      28,    27,    30,    38,    12,    13,    14,    15,    16,    17,
      25,    24,    19,    27,    25,    32,    33,    34,    35,    36,
      30,    32,     1,    34,    35,    36,    27,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    22,
      19,    20,    21,    22,    22,    22,    27,    23,    27,    28,
      25,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    29,    25,    24,    24,    24,    24,
     283,   266,    23,    25,    27,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    25,    25,    25,
      24,    24,   293,    25,    22,    25,    27,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    23,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
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
       8,    18,    20,    21,    22,    38,    39,    40,    42,    43,
      53,    59,    63,    65,    66,    67,    51,    55,    24,    51,
      51,    51,    51,    27,    20,    21,    22,    28,    30,     6,
      63,    63,    63,     6,     6,    63,    22,    63,    22,    22,
      22,    25,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    27,    27,    19,    59,    51,    59,    59,
      59,    59,     1,    63,    64,    63,     6,    66,    23,    63,
      63,    60,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,     1,    59,    63,    25,    59,
      25,    25,    25,    25,    26,    26,    23,    29,    28,    30,
      23,    23,    27,    23,    25,    64,    30,    63,    66,    24,
      61,    63,    24,    66,    29,     1,    40,    42,    43,    58,
      63,    27,    58,    30,    27,    22,    22,    22,    25,    27,
      62,    63,    25,    66,    63,    60,    63,    41,    59,    58,
      23,    59,    23,    27,    23,    24,    24,    24,    61,    24,
      58,    58,    58,    27,    58,    25,    25,    25,    62,    25,
      59,    59,    41,    58,    23,    58,    24,    24,    58,    58,
      25,    25,    58,    58
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
#line 88 "src/Parser.y" /* yacc.c:1646  */
    { root = (yyvsp[0].xprT);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression("_",(yyvsp[-1].xprT),(yyvsp[0].xprT), Function);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"int"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"float"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"char"); (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),(yyvsp[-8].s)); (yyval.xprT) = ContainerExpression((yyvsp[-8].s),(yyvsp[-2].xprT),NULL, Function);}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),(yyvsp[-8].s));    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "src/Parser.y" /* yacc.c:1646  */
    {Add_Scope((yyvsp[-7].s),"void");    (yyval.xprT) = ContainerExpression((yyvsp[-7].s),(yyvsp[-1].xprT),NULL, Function);  }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "src/Parser.y" /* yacc.c:1646  */
    {    (yyval.xprT) = ContainerExpression("ERROR",(yyvsp[-1].xprT),NULL, Function);  }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT)= NULL;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("int"); (yyval.xprT) = NULL;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("float"); (yyval.xprT) = NULL;}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs("char"); (yyval.xprT) = NULL;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "src/Parser.y" /* yacc.c:1646  */
    {Set_TypeDefs((yyvsp[-2].s)); (yyval.xprT) = NULL;}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-5].s),"None",(yyvsp[-3].i));(yyval.xprT) = NULL;}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF_Array((yyvsp[-3].s),"None",(yyvsp[-1].i));(yyval.xprT) = NULL;}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[-2].s),"None");(yyval.xprT) = NULL;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "src/Parser.y" /* yacc.c:1646  */
    {Add_TYPEDEF((yyvsp[0].s),"None");(yyval.xprT) = NULL;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 145 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "src/Parser.y" /* yacc.c:1646  */
    {if(globalCalled==0)Add_Scope("Global","void");  globalCalled=1; (yyval.xprT)= NULL;}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 155 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL; }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 159 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("int"); (yyval.xprT) = NULL;	 	 }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 160 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("float");(yyval.xprT) = NULL;    	 }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 161 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type("char");(yyval.xprT) = NULL;    	 }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-4].s), "struct"); Link_StructVariables((yyvsp[-4].s)); Add_TYPEDEF((yyvsp[-4].s),(yyvsp[-4].s)); (yyval.xprT) = NULL;    	 }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT)=NULL; }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "src/Parser.y" /* yacc.c:1646  */
    {Set_Type((yyvsp[-2].s));(yyval.xprT) = NULL;   	 }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;  	 }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 172 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable("$TART", "struct");(yyval.xprT)= NULL;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) = NULL;}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-5].s), "1Standby",(yyvsp[-3].i)); (yyval.xprT) = NULL;}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "src/Parser.y" /* yacc.c:1646  */
    {Add_Array	 ((yyvsp[-3].s), "1Standby",(yyvsp[-1].i)); (yyval.xprT) = NULL;}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[-2].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "src/Parser.y" /* yacc.c:1646  */
    {Add_Variable((yyvsp[0].s), "1Standby"); (yyval.xprT) = NULL;}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 203 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 204 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 205 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 206 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 215 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-9].xprT),ContainerExpression(NULL,(yyvsp[-6].xprT),NULL, Expression))),(ContainerExpression(NULL,(operatorExpression(IF_OP, operatorExpression(NOT_OP,(yyvsp[-9].xprT),NULL) ,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression)), Expression);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 223 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 229 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 232 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 237 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 239 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 244 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(IF_OP,(yyvsp[-9].xprT),ContainerExpression(NULL,(yyvsp[-6].xprT),NULL, Expression))),(ContainerExpression(NULL,(operatorExpression(IF_OP, operatorExpression(NOT_OP,(yyvsp[-9].xprT),NULL) ,ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression)), Expression);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 253 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-5].xprT),ContainerExpression(NULL,(yyvsp[-2].xprT),NULL, Expression))),(yyvsp[0].xprT), Expression);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 255 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=ContainerExpression(NULL,(yyvsp[-9].xprT),ContainerExpression(NULL,(operatorExpression(WHILE_OP,(yyvsp[-7].xprT),
			  ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[-5].xprT), Expression))),(yyvsp[0].xprT), Expression), Expression);}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 258 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-1].xprT),NULL, Expression);}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 259 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 265 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 266 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 270 "src/Parser.y" /* yacc.c:1646  */
    {int i=1; void*v=&i; (yyval.xprT) = ConstantExpression(v,_Int); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 271 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 275 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=NULL;}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 276 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT)=(yyvsp[0].xprT);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 281 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[-1].xprT);}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 282 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(PlusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(MinusOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(TimesOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 285 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(DivideOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 286 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ModOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 287 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(EQ_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 288 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 289 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 290 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(LTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 291 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GT_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 292 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(GTE_OP,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 293 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(NOT_OP,(yyvsp[0].xprT),NULL);}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 296 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 297 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 298 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 300 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(AssignOp,(yyvsp[-2].xprT),(yyvsp[0].xprT));}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 302 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 305 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(AssignOp,IdentifierExpression((yyvsp[0].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[0].s)),ConstantExpression(v,_Int)) ); }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 308 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; 

			(yyval.xprT) = operatorExpression(USE_OP,IdentifierExpression((yyvsp[-1].s)),operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(PlusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 312 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(USE_OP,IdentifierExpression((yyvsp[-1].s)),
			operatorExpression(AssignOp,IdentifierExpression((yyvsp[-1].s)),operatorExpression(MinusOp,IdentifierExpression((yyvsp[-1].s)),ConstantExpression(v,_Int)) )); }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 317 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(SIZE_OP,(yyvsp[-1].xprT),NULL);}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 318 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 321 "src/Parser.y" /* yacc.c:1646  */
    {int i=-1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 323 "src/Parser.y" /* yacc.c:1646  */
    {int i= 1; void*v=&i; (yyval.xprT) = operatorExpression(TimesOp, (yyvsp[0].xprT),ConstantExpression(v,_Int)); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 325 "src/Parser.y" /* yacc.c:1646  */
    {(yyval.xprT) =  operatorExpression(Call_OP, IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT));}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 328 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 329 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ContainerExpression(NULL,(yyvsp[-2].xprT),(yyvsp[0].xprT), Expression);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 330 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = (yyvsp[0].xprT);}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 331 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = NULL;}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 337 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(RETURN_OP,(yyvsp[0].xprT),NULL);}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 340 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,IdentifierExpression((yyvsp[-2].s)),(yyvsp[0].xprT));}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 341 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 342 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-3].s)),(yyvsp[-1].xprT)); }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 343 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression((yyvsp[-5].s)),(yyvsp[-3].xprT)),(yyvsp[0].xprT)); }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 348 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = IdentifierExpression((yyvsp[0].s));}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 349 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].i),_Int);}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 350 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].c),_Char);}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 351 "src/Parser.y" /* yacc.c:1646  */
    { (yyval.xprT) = ConstantExpression(&(yyvsp[0].f),_Float);}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2221 "y.tab.c" /* yacc.c:1646  */
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
#line 354 "src/Parser.y" /* yacc.c:1906  */

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

	PrintTree(root,0,f);
	fclose(f);
}

void PrintSYM()
{
 	FILE *f = fopen("Table.sym", "w");

 	if(f==NULL)
 	{
 		printf("fopen failed, errno = n");
 		return;
 	}
 	else
 	{
 	
 		Print_SymbolTable(f);
 		fclose(f);
 	}
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

				printf("Symbol Table File Created.\n");

				//TraverseTree(0,root);
				//Perform TypeChecking on Tree
				PerformTypeCheck(0,root,NULL);

				PrintSYM();
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

