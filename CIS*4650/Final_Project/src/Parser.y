%{
#include <stdio.h>
#include <stdlib.h>	
#include "AbstractTree.h"
#include "SymbolTable.h"
#include "IR_Instructions.h"
typedef char letter_1, letter_2;
void yyerror(char *msg);

extern int yylex();
extern int lineNum;

extern int nodesCount;


//HackyMethod to Know what type is used
int globalCalled=0;


char* structName="None";

int errorCount=0;
expressionTree root;

letter_1 l1='c';
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
%token EQ NE LT GT LTE GTE NOT AND OR

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
%type <xprT> TypeDefs TypeDef Declerations Decleration Cont_Decl Arguments Argument Brace_Expr Func_Vars For_1stParam For_2ndParam For_3rdParam Cont_TDecl Global_Decl  Struct_Decl ExpressionOrder ArgumentIn



%left AND OR
%left ADD MIN
%left MUL DIV MOD
%left L_PAREN R_PAREN

///////////////////////////////////////////////
%%

Program		: TypeDefs Global_Decl Functions								{ root = $3;}
			; 




//Expressions are What get Added to the ABS Tree.
Functions	: Function Functions								{ $$ = ContainerExpression("_",$1,$2, Function);}
			| Function											{ $$ = $1;}
			;

Function 	: KW_INT 		IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE 		
			{Add_Scope($2,"int"); $$ = ContainerExpression($2,$8,NULL, Function); }

			| KW_FLOAT 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE		
			{Add_Scope($2,"float"); $$ = ContainerExpression($2,$8,NULL, Function);}
			
			| KW_CHAR 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE 		
			{Add_Scope($2,"char"); $$ = ContainerExpression($2,$8,NULL, Function);}	 
			
			| KW_STRUCT  	IDENTIFIER	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE	
			{Add_Scope($3,$2); $$ = ContainerExpression($2,$8,NULL, Function);}
			
			| IDENTIFIER 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE		
			{Add_Scope($2,$1);    $$ = ContainerExpression($2,$8,NULL, Function);  }
			
			| KW_VOID 	 	IDENTIFIER L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE		
			{Add_Scope($2,"void");    $$ = ContainerExpression($2,$8,NULL, Function);  }			
			
			| error   L_PAREN Arguments R_PAREN L_BRACE Declerations Expressions R_BRACE						
			{    $$ = ContainerExpression("ERROR",$7,NULL, Function);  }
			;

TypeDefs	:%empty 								{ $$= NULL;} 
			|TypeDefs TypeDef						{ $$ = NULL;}
			;


TypeDef 	: TYPEDEF KW_INT 	 			Cont_TDecl SEMICOLON		{Set_TypeDefs("int"); $$ = NULL;}
			| TYPEDEF KW_FLOAT 	 			Cont_TDecl SEMICOLON		{Set_TypeDefs("float"); $$ = NULL;}
			| TYPEDEF KW_CHAR 	 			Cont_TDecl SEMICOLON		{Set_TypeDefs("char"); $$ = NULL;}

			| TYPEDEF KW_STRUCT  IDENTIFIER Cont_TDecl SEMICOLON 	{Set_TypeDefs($3); $$ = NULL;}
			| TYPEDEF IDENTIFIER 			Cont_TDecl SEMICOLON 	{Set_TypeDefs($2); $$ = NULL;}
			|  error  SEMICOLON										{ $$ = NULL;}
			;


//Modify Grammar for Simpler Function Calls
Cont_TDecl	: IDENTIFIER L_SQBRACE INT R_SQBRACE COMA Cont_TDecl
			{Add_TYPEDEF_Array($1,"None",$3);$$ = NULL;}
			| IDENTIFIER L_SQBRACE INT R_SQBRACE 					
			{Add_TYPEDEF_Array($1,"None",$3);$$ = NULL;}
			| IDENTIFIER COMA Cont_TDecl							
			{Add_TYPEDEF($1,"None");$$ = NULL;}
			| IDENTIFIER 											
			{Add_TYPEDEF($1,"None");$$ = NULL;}
			| error 												{$$ = NULL;}
			;	


//Trick Yacc into Right Recursion by using the SEMICOLON for reducing
Declerations:%empty 									{if(globalCalled==0)Add_Scope("Global","void");  globalCalled=1; $$= NULL;}
			|Declerations Decleration					{$$ = NULL;}
			;


Global_Decl :%empty													{$$=NULL; }
			|Global_Decl Decleration								{$$ = NULL;}
			;

Decleration : KW_INT 	 Cont_Decl SEMICOLON								{Set_Type("int"); $$ = NULL;	 	 }
			| KW_FLOAT 	 Cont_Decl SEMICOLON								{Set_Type("float");$$ = NULL;    	 }
			| KW_CHAR 	 Cont_Decl SEMICOLON								{Set_Type("char");$$ = NULL;    	 }
			//Add Variable as Part of Struct
			//Here we are declaring what is Inside of a struct
			| KW_STRUCT  IDENTIFIER L_BRACE Struct_Decl R_BRACE SEMICOLON 	
			{Add_Variable($2, "struct"); Link_StructVariables($2); Add_TYPEDEF($2,$2); $$ = NULL;    	 }

			| KW_STRUCT IDENTIFIER Cont_Decl SEMICOLON						{Set_Type($2);$$=NULL; }
			| IDENTIFIER Cont_Decl SEMICOLON 								{Set_Type($1);$$ = NULL;   	 }
			| error 														{$$ = NULL;  	 }
			;

Struct_Decl :%empty 									{Add_Variable("$TART", "struct");$$= NULL;}
			|Struct_Decl Decleration					{$$ = NULL;}
			;



//Modify Grammar for Simpler Function Calls
Cont_Decl	: IDENTIFIER L_SQBRACE INT R_SQBRACE COMA Cont_Decl	{Add_Array	 ($1, "1Standby",$3); $$ = NULL;}
			| IDENTIFIER L_SQBRACE INT R_SQBRACE 				{Add_Array	 ($1, "1Standby",$3); $$ = NULL;}
			| IDENTIFIER COMA Cont_Decl							{Add_Variable($1, "1Standby"); $$ = NULL;}
			| IDENTIFIER 										{Add_Variable($1, "1Standby"); $$ = NULL;}
			| error 											{ $$ = NULL;}
			;		












Arguments  : %empty		{ $$ = NULL;}
		   | ArgumentIn { $$ = NULL;}
		   ;

ArgumentIn  : Argument COMA ArgumentIn				{ $$ = NULL;}
			| Argument 								{ $$ = NULL;}
			;
//Same as Declerations
Argument	: KW_INT 	 IDENTIFIER  							{Add_Variable($2,"int"); $$ = NULL;	 	 }
			| KW_FLOAT 	 IDENTIFIER  							{Add_Variable($2,"float");$$ = NULL;    	 }
			| KW_CHAR 	 IDENTIFIER  							{Add_Variable($2,"char");$$ = NULL;    	 }
			| KW_STRUCT IDENTIFIER IDENTIFIER					{Add_Variable($3,$2);$$=NULL; }
			| IDENTIFIER IDENTIFIER  							{Add_Variable($2,$1);$$ = NULL;   	 }
			;
//Functions




Brace_Expr	: %empty											{ $$ = NULL;}
			| Expression  SEMICOLON Brace_Expr 					{ $$ = ContainerExpression(NULL,$1,$3, Expression);}	
			| IF L_PAREN Expression R_PAREN L_BRACE Brace_Expr R_BRACE Brace_Expr 
			{ $$ = ContainerExpression(NULL,(operatorExpression(IF_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),$8, Expression);}

			//This clusterf*ck is if/else
			| IF L_PAREN Expression R_PAREN L_BRACE Brace_Expr R_BRACE  ELSE L_BRACE  Brace_Expr  R_BRACE Brace_Expr
			{ $$ = ContainerExpression(NULL,(operatorExpression(IF_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),(ContainerExpression(NULL,(operatorExpression(IF_OP, operatorExpression(NOT_OP,$3,NULL) ,ContainerExpression(NULL,$10,NULL, Expression))),$12, Expression)), Expression);}

			| WHILE L_PAREN Expression R_PAREN L_BRACE Brace_Expr R_BRACE Brace_Expr{ $$ = ContainerExpression(NULL,(operatorExpression(WHILE_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),$8, Expression);}
				


			//For Loops will be converted to WHILE Loops
			| FOR L_PAREN For_1stParam SEMICOLON For_2ndParam SEMICOLON For_3rdParam R_PAREN L_BRACE Brace_Expr R_BRACE Brace_Expr
			{$$=ContainerExpression(NULL,$3,ContainerExpression(NULL,(operatorExpression(WHILE_OP,$5,
			  ContainerExpression(NULL,$10,$7, Expression))),$12, Expression), Expression);}

			| error SEMICOLON	 			 					{ $$ = NULL;}
			;



Expressions	: ExpressionOrder SEMICOLON Expressions 				{ $$ = ContainerExpression(NULL,$1,$3, Expression);}
			| IF L_PAREN ExpressionOrder R_PAREN L_BRACE Brace_Expr R_BRACE  Expressions 
			{ $$ = ContainerExpression(NULL,(operatorExpression(IF_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),$8, Expression);}


			//This clusterf*ck is if/else
			| IF L_PAREN ExpressionOrder R_PAREN L_BRACE Brace_Expr R_BRACE ELSE L_BRACE  Brace_Expr  R_BRACE  Expressions
			{ $$ = ContainerExpression(NULL,(operatorExpression(IF_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),(ContainerExpression(NULL,(operatorExpression(IF_OP, operatorExpression(NOT_OP,$3,NULL) ,ContainerExpression(NULL,$10,NULL, Expression))),$12, Expression)), Expression);}






//			{ $$ = ContainerExpression(NULL,(operatorExpression(IF_OP,$3,ContainerExpression(NULL,$6, /**/(operatorExpression(IF_OP, operatorExpression(NOT_OP,$3,NULL) ,ContainerExpression(NULL,$10,NULL, Expression))) /**/, Expression))),$12, Expression);}

			| WHILE L_PAREN ExpressionOrder R_PAREN L_BRACE Brace_Expr R_BRACE Expressions{ $$ = ContainerExpression(NULL,(operatorExpression(WHILE_OP,$3,ContainerExpression(NULL,$6,NULL, Expression))),$8, Expression);}
			| FOR L_PAREN For_1stParam SEMICOLON For_2ndParam SEMICOLON For_3rdParam R_PAREN L_BRACE Brace_Expr R_BRACE Expressions
			{$$=ContainerExpression(NULL,$3,ContainerExpression(NULL,(operatorExpression(WHILE_OP,$5,
			  ContainerExpression(NULL,$10,$7, Expression))),$12, Expression), Expression);}

			| Expression_RTRN  SEMICOLON   					{ $$ = ContainerExpression(NULL,$1,NULL, Expression);}			
			| error SEMICOLON	 			 				{ $$ = NULL;}
			;



//Assign a Variable before the loop is created
For_1stParam:%empty	{$$=NULL;}
			|Expression {$$=$1;}
			;

//Return 1 if nothing is inside
For_2ndParam:%empty {int i=1; void*v=&i; $$ = ConstantExpression(v,_Int); }	
			| ExpressionOrder {$$=$1;}
			;

//This command executes at the start of each Loop
For_3rdParam:%empty {$$=NULL;}
			| Expression {$$=$1;}
			;

ExpressionOrder: ExpressionOrder AND ExpressionOrder { $$ = operatorExpression(AND_OP,$1,$3);}
			   | ExpressionOrder OR ExpressionOrder  { $$ = operatorExpression(OR_OP,$1,$3);}
			   | Expression 							{ $$ = $1;}
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

			
			| IDENTIFIER DOT Accessor									{ $$ = operatorExpression(ACCESS_OP,IdentifierExpression($1),$3);}
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE 				{ $$ = operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3); }
			| IDENTIFIER L_SQBRACE Expression R_SQBRACE DOT Accessor	{ $$ = operatorExpression(ACCESS_OP,operatorExpression( ARRAYACCESS_OP,IdentifierExpression($1),$3),$6); }

			| Accessor ASSIGN Expression 			{ $$ = operatorExpression(AssignOp,$1,$3);}

			|INCREMENT IDENTIFIER 					{int i= 1; void*v=&i; $$ = operatorExpression(AssignOp,IdentifierExpression($2),operatorExpression(PlusOp,IdentifierExpression($2),ConstantExpression(v,_Int)) ); }


			|DECREMENT IDENTIFIER 					{int i= 1; void*v=&i; $$ = operatorExpression(AssignOp,IdentifierExpression($2),operatorExpression(MinusOp,IdentifierExpression($2),ConstantExpression(v,_Int)) ); }


			|IDENTIFIER INCREMENT 					{int i= 1; void*v=&i; 

			$$ = operatorExpression(USE_OP,IdentifierExpression($1),operatorExpression(AssignOp,IdentifierExpression($1),operatorExpression(PlusOp,IdentifierExpression($1),ConstantExpression(v,_Int)) )); }

			|IDENTIFIER DECREMENT 					{int i= 1; void*v=&i; $$ = operatorExpression(USE_OP,IdentifierExpression($1),
			operatorExpression(AssignOp,IdentifierExpression($1),operatorExpression(MinusOp,IdentifierExpression($1),ConstantExpression(v,_Int)) )); }
			


			| SIZEOF L_PAREN Expression R_PAREN		{ $$ = operatorExpression(SIZE_OP,$3,NULL);} 
			| Var									{ $$ = $1;}

			//Placed here to Remove Ambiguity. 
			| MIN Expression 						{int i=-1; void*v=&i; $$ = operatorExpression(TimesOp, $2,ConstantExpression(v,_Int)); }	
			//Consistency
			| ADD Expression 						{int i= 1; void*v=&i; $$ = operatorExpression(TimesOp, $2,ConstantExpression(v,_Int)); }

			| IDENTIFIER L_PAREN Func_Vars R_PAREN	{$$ =  operatorExpression(Call_OP, IdentifierExpression($1),$3);}
			;	

Func_Vars	: %empty											{ $$ = NULL;}
			| Expression COMA Func_Vars 						{ $$ = ContainerExpression(NULL,$1,$3, Expression);}	
			| Expression 										{ $$ = $1;}	
			| error COMA 		 			 					{ $$ = NULL;}
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

	PrintTree(root,0,f);
	fclose(f);
}

void PrintSYM()
{
 	FILE *f = fopen("Table.sym", "w");

 	if(f==NULL)
 	{
 		printf("fopen failed, errno = n");
 		return;
 	}
 	else
 	{
 		Print_SymbolTable(f);
 		fclose(f);
 	}
}
void PrintIR()
{
 	FILE *f = fopen("Code.inr", "w");

 	if(f==NULL)
 	{
 		printf("fopen failed, errno = n");
 		return;
 	}
 	else
 	{
 		Print_IR_Instructions(f);
 		fclose(f);
 	}
}


int main(int argc, char* argv[])
{
	printf("Starting Compiler..\n");
	//Init the Symbol Table
	Initialize_HashTable();

	yyparse();
	printf("\nCompilation finished.\n");


	if(argc>1)
	{
		if(strcmp(argv[1],"-a")==0)
		{
		PrintABS();
		printf("ABS file created.\n");
		}

		else if(strcmp(argv[1],"-s")==0)
		{
			if(errorCount==0)
			{	

				printf("Symbol Table File Created.\n");

				//Perform TypeChecking on Tree
				PerformTypeCheck(0,root,NULL);


				//Print AFTER our Code
				PrintSYM();

			}
			else
			{
				printf("The file contains errors,please fix in order to continue.\n");
			}
		}

		else if(strcmp(argv[1],"-i")==0)
		{
			if(errorCount==0)
			{	


				
				//Initialize our IR_Node
				InitializeIR_Node();
				//Perform TypeChecking on Tree
				PerformTypeCheck(0,root,NULL);


				//Print AFTER our Code

				//Print IR_Instructions
				PrintIR();

				Free_IR_Instructions();
			}
			else
			{
				printf("The file contains errors,please fix in order to continue.\n");
			}
		}



		else if(strcmp(argv[1],"-c")==0)
		{
			if(errorCount==0)
			{	


				PrintABS();
				//Initialize our IR_Node
				InitializeIR_Node();
				//Perform TypeChecking on Tree
				PerformTypeCheck(0,root,NULL);


				//Print AFTER our Code
				PrintSYM();
				//Print IR_Instructions
				PrintIR();


				if(errorCount==0)
					CreateAssembly();
				else
					printf("The file contains errors,please fix in order to continue.\n");
				Free_IR_Instructions();
			}
			else
			{
				printf("The file contains errors,please fix in order to continue.\n");
			}
		}

	}

	FreeTree(root);
 	Free_HashTable();

	return 0;
}

