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
    TOKEN_INT = 262,
    TOKEN_CHAR = 263,
    TOKEN_FLOAT = 264,
    TOKEN_VOID = 265,
    TOKEN_STRUCT = 266,
    TOKEN_TYPEDEF = 267,
    TOKEN_SIZEOF = 268,
    TOKEN_RETURN = 269,
    TOKEN_IF = 270,
    TOKEN_ELSE = 271,
    TOKEN_FOR = 272,
    TOKEN_WHILE = 273,
    TOKEN_SEMICOLON = 274,
    COMA = 275,
    TOKEN_EOF = 276,
    L_PAREN = 277,
    R_PAREN = 278,
    L_BRACE = 279,
    R_BRACE = 280
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define CHAR 260
#define IDENTIFIER 261
#define TOKEN_INT 262
#define TOKEN_CHAR 263
#define TOKEN_FLOAT 264
#define TOKEN_VOID 265
#define TOKEN_STRUCT 266
#define TOKEN_TYPEDEF 267
#define TOKEN_SIZEOF 268
#define TOKEN_RETURN 269
#define TOKEN_IF 270
#define TOKEN_ELSE 271
#define TOKEN_FOR 272
#define TOKEN_WHILE 273
#define TOKEN_SEMICOLON 274
#define COMA 275
#define TOKEN_EOF 276
#define L_PAREN 277
#define R_PAREN 278
#define L_BRACE 279
#define R_BRACE 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "src/Parser.y" /* yacc.c:1909  */

	float f;
	int i;
	char c;
	char* s;
#line 30 "src/Parser.y" /* yacc.c:1909  */

	
	struct ast_node * ast;
	double number;
	int operator;


#line 118 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
