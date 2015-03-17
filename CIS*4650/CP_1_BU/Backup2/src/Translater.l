%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"	// 	Yacc -d

int lineNum=1;
%}



%%

'+'							{return ADD;}
-								{return MIN;}				
'*'								{return MUL;}
'/'								{return DIV;}
'%'								{return MOD;}

'=='								{return E;}
'!='								{return NE;}
'<'								{return LT;}
'>'								{return GT;}
'<='								{return LTE;}
'>='								{return GTE;}

'='								{return ASSIGN;}

'++'								{return INCREMENT;}
'--'								{return DECREMENT;}





[\n]							{lineNum++;}
[(] 							{return L_PAREN;}
[)] 							{return R_PAREN;}
[{] 							{return L_BRACE;}
[}] 							{return R_BRACE;}
main							{return MAIN;}
[;]								{return TOKEN_SEMICOLON;}
[,]								{return COMA;}
int 							{return TOKEN_INT;}
char							{return TOKEN_CHAR;}
float							{return TOKEN_FLOAT;}
void							{return TOKEN_VOID;}
struct							{return TOKEN_STRUCT;}
constant						{return CONSTANT;}

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