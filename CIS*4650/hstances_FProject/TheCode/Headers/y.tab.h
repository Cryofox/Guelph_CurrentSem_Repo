/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    AND = 274,
    OR = 275,
    ASSIGN = 276,
    INCREMENT = 277,
    DECREMENT = 278,
    L_PAREN = 279,
    R_PAREN = 280,
    L_BRACE = 281,
    R_BRACE = 282,
    COMA = 283,
    SEMICOLON = 284,
    L_SQBRACE = 285,
    R_SQBRACE = 286,
    DOT = 287,
    CONSTANT = 288,
    KW_STRUCT = 289,
    KW_VOID = 290,
    KW_FLOAT = 291,
    KW_CHAR = 292,
    KW_INT = 293,
    TYPEDEF = 294,
    SIZEOF = 295,
    RETURN = 296,
    IF = 297,
    ELSE = 298,
    FOR = 299,
    WHILE = 300
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
#define AND 274
#define OR 275
#define ASSIGN 276
#define INCREMENT 277
#define DECREMENT 278
#define L_PAREN 279
#define R_PAREN 280
#define L_BRACE 281
#define R_BRACE 282
#define COMA 283
#define SEMICOLON 284
#define L_SQBRACE 285
#define R_SQBRACE 286
#define DOT 287
#define CONSTANT 288
#define KW_STRUCT 289
#define KW_VOID 290
#define KW_FLOAT 291
#define KW_CHAR 292
#define KW_INT 293
#define TYPEDEF 294
#define SIZEOF 295
#define RETURN 296
#define IF 297
#define ELSE 298
#define FOR 299
#define WHILE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "src/Parser.y" /* yacc.c:1909  */

	float f;
	int i;
	char c;
	char* s;
	expressionTree xprT;

#line 152 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
