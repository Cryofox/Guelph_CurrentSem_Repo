%{
#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"

void yyerror(char *msg);
extern int yylex();
extern int lineNum;

int errorCount=0;

//Node For Accessing



%}


%union{
	float f;
	int i;
	char c;
	char* s;
}



//Union for AST-Tree
%union{
	
	struct ast_node * ast;
	double number;
	int operator;

}





%token <i> INT
%token <f> FLOAT
%token <c> CHAR
%token <s> IDENTIFIER



//Arithmetic
%token ADD MIN MUL DIV MOD

//Relational
%token E NE LT GT LTE GTE

//Assign
%token ASSIGN

//PRE POST INC DEC
%token INCREMENT DECREMENT

//Blocks
%token L_PAREN R_PAREN L_BRACE R_BRACE MAIN COMA SEMICOLON

//KEYWORDS
%token CONSTANT KW_STRUCT KW_VOID KW_FLOAT KW_CHAR KW_INT

//EXTRA
%token TYPEDEF SIZEOF RETURN

//CONTROL FLOW
%token IF ELSE FOR WHILE

%type <i>  Program Expression

%left ADD MIN
%left MUL DIV MOD
///////////////////////////////////////////////
%%

Program		: Expression 					{printf("%d \n", $1);}
			;
			
Expression 	: Expression ADD Expression 	{ $$ = $1 + $3 ;}
			| Expression MIN Expression 	{ $$ = $1 - $3 ;}
			| Expression MUL Expression 	{ $$ = $1 * $3 ;}
			| Expression DIV Expression 	{ $$ = $1 / $3 ;}
			| Expression MOD Expression 	{ $$ = $1 % $3 ;}
			| INT 							{ $$ = $1; } 
			;







%%
///////////////////////////////////////////////

void yyerror(char *msg)
{
	//All Errors are Fatal atm
	//fprintf(stderr, "%s\n", msg);


	printf("Error On Line: %d %s\n", lineNum, msg);


	//exit(1);
}

// error token is yaccs predefined error token used for parsing. 
// It's a freaking masterpiece
int main()
{
	//rootNode = mknode($1, $3, "*")
	yyparse();

	printf("Error Count: %d\n", errorCount);
	return 0;
}