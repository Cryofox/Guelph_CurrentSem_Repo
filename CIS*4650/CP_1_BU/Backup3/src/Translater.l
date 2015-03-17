%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"	// 	Yacc -d

int lineNum=1;
%}



%%
[+]								{return ADD;}
[-]								{return MIN;}				
[*]								{return MUL;}
[/]								{return DIV;}
[%]								{return MOD;}
(==)							{return E;}
(!=)							{return NE;}
(<)								{return LT;}
(>)								{return GT;}
(<=)							{return LTE;}
(>=)							{return GTE;}
[=]								{return ASSIGN;}

(\+\+)							{return INCREMENT;}
(--)							{return DECREMENT;}

[\n]							{lineNum++;}
[(] 							{return L_PAREN;}
[)] 							{return R_PAREN;}
[{] 							{return L_BRACE;}
[}] 							{return R_BRACE;}
main							{return MAIN;}
[;]								{return SEMICOLON;}
[,]								{return COMA;}
int 							{return KW_INT;}
char							{return KW_CHAR;}
float							{return KW_FLOAT;}
void							{return KW_VOID;}
struct							{return KW_STRUCT;}
constant						{return CONSTANT;}

typedef							{return TYPEDEF;}
sizeof							{return SIZEOF;}
return							{return RETURN;}

if 								{return IF;}
else							{return ELSE;}
for 							{return FOR;}
while 							{return WHILE;}

[0-9]*							{yylval.i = atoi(yytext); return INT;}

_?[a-zA-Z0-9]+ 					{yylval.s = strdup(yytext); return IDENTIFIER;}

%%

int yywrap (void) {return 1;}