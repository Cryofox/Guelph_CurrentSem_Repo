%{
#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"

void yyerror(char *msg);
extern int yylex();
extern int lineNum;

int errorCount=0;

//Node For Accessing

node rootNode;

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

// The var type
%token TOKEN_INT TOKEN_CHAR TOKEN_FLOAT TOKEN_VOID TOKEN_STRUCT

//Commands and Return
%token TOKEN_TYPEDEF TOKEN_SIZEOF TOKEN_RETURN 

//Structure Flow
%token TOKEN_IF TOKEN_ELSE TOKEN_FOR TOKEN_WHILE

%token TOKEN_SEMICOLON COMA TOKEN_EOF L_PAREN R_PAREN L_BRACE R_BRACE MAIN

%type  <i> Start Decl_TypeDef Def_TypeDef Decl_Global Def_Global Identifiers
%type  <i> DataType 

//Function 
%type <i>  Decl_Functions Func_Arguments Arguments Def_Function Def_MainFunction Def_Local
//Statements
%type <i>  Statements Statement_Return Expr_Stmnt	Compound_Stmnt Expression	
///////////////////////////////////////////////
%%

Start			: Decl_TypeDef Decl_Global Decl_Functions						{}
				| Decl_Global Decl_Functions 									{}
				| Decl_Functions
				;

Decl_TypeDef	: Def_TypeDef Decl_TypeDef
				| Def_TypeDef
				;


Def_TypeDef 	: TOKEN_TYPEDEF TOKEN_INT    Identifiers	 					{}
				| TOKEN_TYPEDEF TOKEN_CHAR   Identifiers	 					{}
				| TOKEN_TYPEDEF TOKEN_FLOAT  Identifiers	 					{}
				| TOKEN_TYPEDEF TOKEN_STRUCT Identifiers	 					{}
				| error TOKEN_SEMICOLON											{errorCount++;}
				;				


Decl_Global		: Def_Global Decl_Global
				| Def_Global
				;

Def_Global 		: DataType  Identifiers	TOKEN_SEMICOLON							{}
				| error TOKEN_SEMICOLON											{errorCount++;}
				;	





Decl_Functions 	: Def_Function Decl_Functions												{}
				| Def_MainFunction															{}
				;



Def_MainFunction: DataType MAIN Func_Arguments L_BRACE Statements R_BRACE					{}
				;

Def_Function 	: DataType IDENTIFIER Func_Arguments L_BRACE Def_Local Statements R_BRACE	{}
				;

Def_Local		: DataType  Identifiers	TOKEN_SEMICOLON										{}
				| error TOKEN_SEMICOLON														{errorCount++;}
				;


//This is where the Biggest ABS Tree HeadAche Occurs
Statements		: Statement Statements
				| Statement_Return
				;

Statement 		: Compound_Stmnt;
				| Expr_Stmnt
				;



Compound_Stmnt 	: L_Brace Statement R_Brace
				;


Expr_Stmnt	 	: Expression
				;


Expression		: 


Statement_Return: TOKEN_RETURN Expression TOKEN_SEMICOLON
				;



Func_Arguments 	: L_PAREN R_PAREN
				| L_PAREN Arguments R_PAREN
				;



Arguments 		: DataType Identifiers COMA Arguments
				| DataType Identifiers
				;



DataType		: TOKEN_INT 
				| TOKEN_CHAR
				| TOKEN_FLOAT
				| TOKEN_STRUCT
				| IDENTIFIER 
				;





Identifiers		: IDENTIFIER COMA Identifiers						{}	
				| IDENTIFIER 										{}
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