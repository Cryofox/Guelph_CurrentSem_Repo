%{
#include <stdio.h>
#include <stdlib.h>	

void yyerror(char *msg);
extern int yylex();
extern int lineNum;

int errorCount=0;
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

%token TOKEN_SEMICOLON TOKEN_COMA TOKEN_EOF
%type  <i> Start Decl_TypeDef Def_TypeDef Decl_Global Def_Global Identifiers
%type  <i> Decl_Functions Def_Function
%type  <i> Statements Statement Data_Type
///////////////////////////////////////////////
%%

Start			: Decl_TypeDef Decl_Global Decl_Functions
				| Decl_Global Decl_Functions
				| Decl_Functions
				;

Decl_TypeDef	: Def_TypeDef Decl_TypeDef
				| Def_TypeDef
				;


Def_TypeDef 	: TOKEN_TYPEDEF TOKEN_INT    Identifiers	 	{}
				| TOKEN_TYPEDEF TOKEN_CHAR   Identifiers	 	{}
				| TOKEN_TYPEDEF TOKEN_FLOAT  Identifiers	 	{}
				| TOKEN_TYPEDEF TOKEN_STRUCT Identifiers	 	{}
				| error TOKEN_SEMICOLON							{errorCount++;}
				;				


Decl_Global		: Def_Global Decl_Global
				| Def_Global
				;

Def_Global 		: TOKEN_INT    Identifiers	 TOKEN_SEMICOLON					{}
				| TOKEN_CHAR   Identifiers	 TOKEN_SEMICOLON					{}
				| TOKEN_FLOAT  Identifiers	 TOKEN_SEMICOLON					{}
				| TOKEN_STRUCT Identifiers	 TOKEN_SEMICOLON					{}
				| error TOKEN_SEMICOLON											{errorCount++;}
				;	

Identifiers		: IDENTIFIER TOKEN_COMA Identifiers				{}	
				| IDENTIFIER 									{}
				;

Decl_Functions	: Def_Function Decl_Functions
				;


//A function can start with an identifier if the Identifier was TypeDef
// Type Name ( type id, type id ... ){}

Def_Function	: Data_Type IDENTIFIER '(' Identifiers ')' '{' Statements '}' 
				;


Statements		: Statement Statements
				| TOKEN_RETURN 
				;

Statement 		: Data_Type
				;


Data_Type		: TOKEN_INT
				| TOKEN_CHAR
				| TOKEN_FLOAT
				| TOKEN_STRUCT
				| IDENTIFIER
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
	yyparse();

	printf("Error Count: %d\n", errorCount);
	return 0;
}