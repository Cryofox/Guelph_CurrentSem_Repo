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
    E = 267,
    NE = 268,
    LT = 269,
    GT = 270,
    LTE = 271,
    GTE = 272,
    ASSIGN = 273,
    INCREMENT = 274,
    DECREMENT = 275,
    L_PAREN = 276,
    R_PAREN = 277,
    L_BRACE = 278,
    R_BRACE = 279,
    MAIN = 280,
    COMA = 281,
    SEMICOLON = 282,
    CONSTANT = 283,
    KW_STRUCT = 284,
    KW_VOID = 285,
    KW_FLOAT = 286,
    KW_CHAR = 287,
    KW_INT = 288,
    TYPEDEF = 289,
    SIZEOF = 290,
    RETURN = 291,
    IF = 292,
    ELSE = 293,
    FOR = 294,
    WHILE = 295
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
#define E 267
#define NE 268
#define LT 269
#define GT 270
#define LTE 271
#define GTE 272
#define ASSIGN 273
#define INCREMENT 274
#define DECREMENT 275
#define L_PAREN 276
#define R_PAREN 277
#define L_BRACE 278
#define R_BRACE 279
#define MAIN 280
#define COMA 281
#define SEMICOLON 282
#define CONSTANT 283
#define KW_STRUCT 284
#define KW_VOID 285
#define KW_FLOAT 286
#define KW_CHAR 287
#define KW_INT 288
#define TYPEDEF 289
#define SIZEOF 290
#define RETURN 291
#define IF 292
#define ELSE 293
#define FOR 294
#define WHILE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "src/Parser.y" /* yacc.c:1909  */

	float f;
	int i;
	char c;
	char* s;
	expressionTree xprT;

#line 142 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
