%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"	// 	Yacc -d

int lineNum=1;
%}



%%
[\n]							{lineNum++;}
[;]								{return TOKEN_SEMICOLON;}
[,]								{return TOKEN_COMA;}
int 							{return TOKEN_INT;}
char							{return TOKEN_CHAR;}
float							{return TOKEN_FLOAT;}
void							{return TOKEN_VOID;}
struct							{return TOKEN_STRUCT;}

typedef							{return TOKEN_TYPEDEF;}
sizeof							{return TOKEN_SIZEOF;}
return							{return TOKEN_RETURN;}

if 								{return TOKEN_IF;}
else							{return TOKEN_ELSE;}
for 							{return TOKEN_FOR;}
while 							{return TOKEN_WHILE;}

[0-9]*							{yylval.i = atoi(yytext); return INT;}

_?[a-zA-Z0-9]+ 					{yylval.s = strdup(yytext); return IDENTIFIER;}

%%

int yywrap (void) {return 1;}