%{
#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"

void yyerror(char *msg);

extern int yylex();
extern int lineNum;



int errorCount=0;
expressionTree root;
%}


%union{
	float f;
	int i;
	char c;
	char* s;
	expressionTree xprT;
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

%type <xprT>  Expression Program




%left ADD MIN
%left MUL DIV MOD
///////////////////////////////////////////////
%%

Program		: Expression 					{ root = $$;}
			;






Expression 	: Expression ADD Expression 	{ $$ = operatorExpression(PlusOp,$1,$3);}
			| Expression MIN Expression 	{ $$ = operatorExpression(MinusOp,$1,$3);}
			| Expression MUL Expression 	{ $$ = operatorExpression(TimesOp,$1,$3);}
			| Expression DIV Expression 	{ $$ = operatorExpression(DivideOp,$1,$3);}
			| Expression MOD Expression 	{ $$ = operatorExpression(ModOp,$1,$3);}
			| IDENTIFIER					{ $$ = IdentifierExpression($1);} 
			| INT 							{ $$ = ConstantExpression($1);} 
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


	printf("Printing Tree:\n");
	PrintTree(root,0);

	return 0;
}

void PrintTree(expressionTree node, int depth)
{
//Operator EXP
	if(node->kind == 0)
	{
		if( node->u.oper.left != NULL)
		{
			PrintTree(node->u.oper.left, (depth+1));
		}
		if( node->u.oper.right != NULL)
		{
			PrintTree(node->u.oper.right, (depth+1));
		}
	}

	printf("At Depth[%d]:%s\n",depth, node->tokenName);

}