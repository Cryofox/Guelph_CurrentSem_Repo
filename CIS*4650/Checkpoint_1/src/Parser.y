%{
#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"

void yyerror(char *msg);

extern int yylex();
extern int lineNum;

extern int nodesCount;

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
%token EQ NE LT GT LTE GTE NOT

//Assign
%token ASSIGN

//PRE POST INC DEC
%token INCREMENT DECREMENT

//Blocks
%token L_PAREN R_PAREN L_BRACE R_BRACE COMA SEMICOLON L_SQBRACE R_SQBRACE DOT

//KEYWORDS 
%token CONSTANT KW_STRUCT KW_VOID KW_FLOAT KW_CHAR KW_INT

//EXTRA
%token TYPEDEF SIZEOF RETURN

//CONTROL FLOW
%token IF ELSE FOR WHILE

%type <xprT> Expressions Expression Program Var Accessor Functions Function Expression_RTRN  


//These values do not affect the ABS tree
%type <xprT> TypeDefs TypeDef Declerations Decleration Cont_Decl Arguments Argument




%left ADD MIN
%left MUL DIV MOD
%left L_PAREN R_PAREN

///////////////////////////////////////////////
%%

Program		: TypeDefs Declerations Functions								{ root = $3;}
			; 




//Expressions are What get Added to the ABS Tree.
Functions	: Function Functions								{ $$ = ContainerExpression("_",$1,$2, Function);}
			| Function											{ $$ = $1;}
			;

Function 	: KW_INT 		IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE 	{ $$ = ContainerExpression($2,$8,NULL, Function);}
			| KW_FLOAT 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	{ $$ = ContainerExpression($2,$8,NULL, Function);}
			| KW_CHAR 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE 	{ $$ = ContainerExpression($2,$8,NULL, Function);}	 
			| KW_STRUCT  	IDENTIFIER	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	{ $$ = ContainerExpression($2,$8,NULL, Function);}
			| IDENTIFIER 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	{    $$ = ContainerExpression($2,$8,NULL, Function);  }
			| KW_VOID 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	{    $$ = ContainerExpression($2,$8,NULL, Function);  }			
			| error   L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	{    $$ = ContainerExpression("ERROR",$7,NULL, Function);  }
			;

TypeDefs	:%empty 								{$$= NULL;} 
			|TypeDefs TypeDef						{ $$ = NULL;}
			;


TypeDef 	: TYPEDEF KW_INT 	 			Cont_Decl SEMICOLON		{ $$ = NULL;}
			| TYPEDEF KW_FLOAT 	 			Cont_Decl SEMICOLON		{ $$ = NULL;}
			| TYPEDEF KW_CHAR 	 			Cont_Decl SEMICOLON		{ $$ = NULL;}

			| TYPEDEF KW_STRUCT  IDENTIFIER Cont_Decl SEMICOLON 	{ $$ = NULL;}
			| TYPEDEF IDENTIFIER 			Cont_Decl SEMICOLON 	{ $$ = NULL;}
			|  error  		SEMICOLON								{$$ = NULL;}
			;



//Trick Yacc into Right Recursion by using the SEMICOLON for reducing
Declerations:%empty {$$= NULL;}
			|Declerations Decleration					{ $$ = NULL;}
			;


Decleration : KW_INT 	 Cont_Decl SEMICOLON								{ $$ = NULL;}
			| KW_FLOAT 	 Cont_Decl SEMICOLON								{ $$ = NULL;}
			| KW_CHAR 	 Cont_Decl SEMICOLON								{ $$ = NULL;}
			| KW_STRUCT  IDENTIFIER L_BRACE Declerations R_BRACE SEMICOLON 	{ $$ = NULL;}
			| IDENTIFIER Cont_Decl SEMICOLON 								{ $$ = NULL;}
			| error 														{ $$ = NULL;}
			;

Cont_Decl	: IDENTIFIER L_SQBRACE INT R_SQBRACE COMA Cont_Decl	{ $$ = NULL;}
			| IDENTIFIER L_SQBRACE INT R_SQBRACE 				{ $$ = NULL;}
			| IDENTIFIER COMA Cont_Decl							{ $$ = NULL;}
			| IDENTIFIER 										{ $$ = NULL;}
			| error 											{ $$ = NULL;}
			;		

Arguments  : %empty							{ $$ = NULL;}		
		   | Argument Arguments				{ $$ = NULL;}
		   ;


Argument	: KW_INT 	 Cont_Decl		{ $$ = NULL;}
			| KW_FLOAT 	 Cont_Decl		{ $$ = NULL;}
			| KW_CHAR 	 Cont_Decl		{ $$ = NULL;}
			| KW_STRUCT  Cont_Decl 		{ $$ = NULL;}
			| IDENTIFIER Cont_Decl 		{ $$ = NULL;}
			;

//Functions








Expressions	: Expression SEMICOLON Expressions 				{ $$ = ContainerExpression(NULL,$1,$3, Expression);}
			| Expression_RTRN  SEMICOLON   					{ $$ = ContainerExpression(NULL,$1,NULL, Expression);}
			| error SEMICOLON	 			 						{ $$ = NULL;}
			;

Expression 	: L_PAREN Expression R_PAREN			{ $$ = $2;}
			| Expression ADD Expression 			{ $$ = operatorExpression(PlusOp,$1,$3);}
			| Expression MIN Expression 			{ $$ = operatorExpression(MinusOp,$1,$3);}
			| Expression MUL Expression 			{ $$ = operatorExpression(TimesOp,$1,$3);}
			| Expression DIV Expression 			{ $$ = operatorExpression(DivideOp,$1,$3);}
			| Expression MOD Expression 			{ $$ = operatorExpression(ModOp,$1,$3);}
			| Expression EQ Expression 				{ $$ = operatorExpression(EQ_OP,$1,$3);}
			| Expression NE Expression 				{ $$ = operatorExpression(NE_OP,$1,$3);}
			| Expression LT Expression 				{ $$ = operatorExpression(LT_OP,$1,$3);}
			| Expression LTE Expression 			{ $$ = operatorExpression(LTE_OP,$1,$3);}
			| Expression GT Expression 				{ $$ = operatorExpression(GT_OP,$1,$3);}
			| Expression GTE Expression 			{ $$ = operatorExpression(GTE_OP,$1,$3);}
			| NOT Expression 						{ $$ = operatorExpression(NOT_OP,$2,NULL);}

			
			| IDENTIFIER DOT Accessor						{ $$ = operatorExpression(ACCESS_OP,IdentifierExpression($1),$3);}
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE 	{ $$ = operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3); }
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE DOT Accessor	{ $$ = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3),$6); }

			| IDENTIFIER ASSIGN Expression 			{ $$ = operatorExpression(AssignOp,IdentifierExpression($1),$3);}

			|INCREMENT IDENTIFIER 					{int i= 1; void*v=&i; $$ = operatorExpression(AssignOp,IdentifierExpression($2),operatorExpression(PlusOp,IdentifierExpression($2),ConstantExpression(v,_Int)) ); }


			|DECREMENT IDENTIFIER 					{int i= 1; void*v=&i; $$ = operatorExpression(AssignOp,IdentifierExpression($2),operatorExpression(MinusOp,IdentifierExpression($2),ConstantExpression(v,_Int)) ); }


			|IDENTIFIER INCREMENT 					{int i= 1; void*v=&i; 

			$$ = operatorExpression(RETURN_OP,IdentifierExpression($1),operatorExpression(AssignOp,IdentifierExpression($1),operatorExpression(PlusOp,IdentifierExpression($1),ConstantExpression(v,_Int)) )); }


			|IDENTIFIER DECREMENT 					{int i= 1; void*v=&i; $$ = operatorExpression(RETURN_OP,IdentifierExpression($1),
			operatorExpression(AssignOp,IdentifierExpression($1),operatorExpression(MinusOp,IdentifierExpression($1),ConstantExpression(v,_Int)) )); }




			| SIZEOF L_PAREN Expression R_PAREN		{ $$ = operatorExpression(SIZE_OP,$3,NULL);} 
			| Var									{ $$ = $1;}

			//Placed here to Remove Ambiguity. 
			| MIN Expression 						{int i=-1; void*v=&i; $$ = operatorExpression(TimesOp, $2,ConstantExpression(v,_Int)); }	
			//Consistency
			| ADD Expression 						{int i= 1; void*v=&i; $$ = operatorExpression(TimesOp, $2,ConstantExpression(v,_Int)); }	

			;	

Expression_RTRN 	: RETURN Expression				{ $$ = operatorExpression(RETURN_OP,$2,NULL);}
					;

Accessor	: IDENTIFIER DOT Accessor									{ $$ = operatorExpression(ACCESS_OP,IdentifierExpression($1),$3);}
			| IDENTIFIER 												{ $$ = IdentifierExpression($1);}
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE 				{ $$ = operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3); }
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE DOT Accessor	{ $$ = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3),$6); }
			;


Var			: IDENTIFIER					{ $$ = IdentifierExpression($1);} 
			| INT 							{ $$ = ConstantExpression(&$1,_Int);} 
			| CHAR 							{ $$ = ConstantExpression(&$1,_Char);} 
			| FLOAT 						{ $$ = ConstantExpression(&$1,_Float);} 			
			;

%%
///////////////////////////////////////////////

void yyerror(char *msg)
{
	//All Errors are Fatal atm
	fprintf(stderr, "\nError On Line: %d %s\n", lineNum, msg);


	//printf("\nError On Line: %d %s\n", lineNum, msg);

	errorCount++;
	//errorCount++;
	//exit(1);
}

// error token is yaccs predefined error token used for parsing. 
// It's a freaking masterpiece

void PrintABS()
{
 	FILE *f = fopen("Tree.abs", "w");
	fprintf(f,"Printing Tree:\n");
	PrintTree(root,0,f);
	fclose(f);
}


int main(int argc, char* argv[])
{
	printf("Starting Compiler..\n");
	yyparse();
	printf("\nCompilation finished.\n");

	if(argc>1)
	{
		if(strcmp(argv[1],"-a")==0)
		{
		PrintABS();
		printf("ABS file created.\n");}

		else if(strcmp(argv[1],"-c")==0)
		{
			printf("\nError Count: %d\n", errorCount);

			if(errorCount==0)
				printf("The Program is free of syntax errors! :)\n");
		}
	}

	FreeTree(root);


	return 0;
}

