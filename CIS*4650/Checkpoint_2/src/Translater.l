%{
#include <stdio.h>
#include <stdlib.h>
#include "AbstractTree.h"


//This must be included last. Because Yacc Jedi Mind Trick
#include "y.tab.h"	// 	Yacc -d

int lineNum=1;

//Credit where Credits due, comment eater : http://flex.sourceforge.net/manual/Start-Conditions.html

%}


%x comment
%%

"/*"         BEGIN(comment);

<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             ++lineNum;
<comment>"*"+"/"        BEGIN(INITIAL);


(\+\+)							{return INCREMENT;}
(--)							{return DECREMENT;}

\[								{return L_SQBRACE;}
\]								{return R_SQBRACE;}
\.								{return DOT;}
[+]								{return ADD;}
[-]								{return MIN;}				
[*]								{return MUL;}
[/]								{return DIV;}
[%]								{return MOD;}
(==)							{return EQ;}
(!=)							{return NE;}
(<)								{return LT;}
(>)								{return GT;}
(<=)							{return LTE;}
(>=)							{return GTE;}
[=]								{return ASSIGN;}
[!]								{return NOT;}


[\n]							{lineNum++;}
[(] 							{return L_PAREN;}
[)] 							{return R_PAREN;}
[{] 							{return L_BRACE;}
[}] 							{return R_BRACE;}

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
[0-9]+[.]([0-9])+([eE][+-]?[0-9]+)?							{yylval.f = atof(yytext); return FLOAT;}
('\\n')							{yylval.c = '\n'; return CHAR;}
('\\0')							{yylval.c = '\0'; return CHAR;}
_?[a-zA-Z0-9_]+ 				{yylval.s = strdup(yytext); return IDENTIFIER;}
'.'								{yylval.c = (yytext[1]); return CHAR;}

%%	
//

int yywrap (void) {return 1;}