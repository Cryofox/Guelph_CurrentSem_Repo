#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.h"
#include "AbstractTree.h"
#include "TypeCheck.h"
#include "IR_Instructions.h"
#define TRUE 1
#define FALSE 0

extern expressionTree root;
extern int errorCount;
void TraverseTree(int depth, expressionTree node)
{
	if(node==NULL)
		return;
	printf("D[%i]:%s\n",depth,node->tokenName);	
	//Traverse Left
	TraverseTree(++depth, (node->u.oper.left));
	//Traverse Right
	TraverseTree(++depth, (node->u.oper.right));	
}
extern int currentLabel;
extern int currentNode;
void PerformTypeCheck(int depth, expressionTree node, char* scope)
{
	if(node==NULL)
		return;


	currentLabel++;
	currentNode++;

	//Call this on Every node, abit in-efficient, but it'll gaurantee scope.
	//Update the Current Scope we are in, based on the Function we just passed.
	scope=functionScope(node, scope);

	//Cycle through each of the FIRST expression containers immediately following a function.
	//This is done to evaluate the Node.
	if(!isFunction_Container(node))
	{
		//If it is, then this violates the Assignment Operator.
		// printf("Semantic Error: Can't Assign an expression to an expression.\n");
		// int evaluateExpr(expressionTree node, char* expectedType, int value)
		evaluateExpr(node,NULL, 0, scope);
	}
	else
	{
		//Create the Function Label
		Add_IR_Instruction(NULL,NULL,NULL,NULL,scope);
		PerformTypeCheck((depth+1), node->u.oper.left, scope);
		PerformTypeCheck((depth+1), node->u.oper.right, scope);
	}

}

//This function prints an error, if an error SHOULD be printed.
void Print_Error_Arithmetic(char* expectedType, char* leftValue, char* rightValue, char* keyword, int linenum)
{
		if(expectedType==NULL)
		{
			if(leftValue!=NULL && rightValue!=NULL)
			{
				if(strcmp(leftValue,rightValue)!=0)
				{
					errorCount++;
					fprintf(stderr, "Type Error: Line[%d] Can't perform %s on[%s] with [%s]\n",linenum, keyword,leftValue,rightValue );	
				}
			}
			else if( leftValue==NULL && rightValue==NULL)
			{

			}
			else
			{
				errorCount++;
				fprintf(stderr, "Type Error: Line[%d] Can't perform %s on [%s] with [%s]\n",linenum, keyword,leftValue,rightValue );	
			}
		}
		else
		{
			if(leftValue!=NULL && rightValue!=NULL)
			{
				if(strcmp(leftValue,expectedType)!=0)
				{
					errorCount++;
					fprintf(stderr,"Type Error: Line[%d] Can't perform %s  Expected:%s instead got:%s\n",linenum,keyword,expectedType, leftValue);
				}
				if(strcmp(rightValue,expectedType)!=0)
				{
					errorCount++;
					fprintf(stderr,"Type Error: Line[%d] Can't perform %s  Expected:%s instead got:%s\n",linenum,keyword,expectedType, rightValue);
				}
			}
			else if( leftValue==NULL && rightValue==NULL)
			{errorCount++;
					//Doesnt matter which one.
					fprintf(stderr,"Type Error: Line[%d] Can't perform %s  Expected:%s instead got:%s\n",linenum,keyword,expectedType, rightValue);
			}
			else
			{
				if(leftValue==NULL)
				{
					errorCount++;
					fprintf(stderr,"Type Error: Line[%d] Can't perform %s  Expected:%s instead got:%s\n",linenum,keyword,expectedType, leftValue);
				}
				if(rightValue==NULL)
				{
					errorCount++;
					fprintf(stderr,"Type Error: Line[%d] Can't perform %s  Expected:%s instead got:%s\n",linenum,keyword,expectedType, rightValue);
				}
			}

		}	
}


//Here we recursively traverse the expression, updating the Value, and returning the Type of the evaluated token
char* evaluateExpr(expressionTree node, char* expectedType, int value, char*scope)
{
	//Traverse all Branches
	if(node==NULL)
		return NULL;

	currentNode++;
	// printf("==========================================\n" );
	// printf("Evaluating:%s\n", node->tokenName);


	if(strcmp(node->tokenName,"+")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic(expectedType, leftValue,rightValue,"+",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"+", rightNode, temp,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);


		return leftValue;
	}

	else if(strcmp(node->tokenName,"-")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic(expectedType, leftValue,rightValue,"-",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"-", rightNode, temp,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);


		return leftValue;		
	}
	else if(strcmp(node->tokenName,"/")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic(expectedType, leftValue,rightValue,"/",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"/", rightNode, temp,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}
	else if(strcmp(node->tokenName,"*")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic(expectedType, leftValue,rightValue,"*",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"*", rightNode, temp,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}

	else if(strcmp(node->tokenName,"%")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"%",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"%", rightNode, temp,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}

	//Need to traverse left branch incase of dot accessors
	else if(strcmp(node->tokenName,"=")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic(expectedType, leftValue,rightValue,"=",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"*t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(rightNode,"=", NULL,leftNode ,NULL);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}

	//Relational operators require INTS as a type
	else if(strcmp(node->tokenName,">")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,">",node->lineCreated);

		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.




		return leftValue;
	}
	else if(strcmp(node->tokenName,"<")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,"<",node->lineCreated);
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}
	else if(strcmp(node->tokenName,">=")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,">=",node->lineCreated);	
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}
	else if(strcmp(node->tokenName,"<=")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,"<=",node->lineCreated);	
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}	
	else if(strcmp(node->tokenName,"==")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,"==",node->lineCreated);	
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}
	else if(strcmp(node->tokenName,"!=")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,rightValue,"!=",node->lineCreated);	
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}	
	else if(strcmp(node->tokenName,"!")==0)
	{
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		//NOT does not have a secondary branch. So we can just feed the left side twice.
		// char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);

		Print_Error_Arithmetic("int", leftValue,leftValue,"!",node->lineCreated);	
		//They should both be Int if no error was made. If an error was made and printed.
		//The user should expect the compiler to produce buggy IR code.
		return leftValue;
	}
	else if(strcmp(node->tokenName,"Arr[]")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);
		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", rightValue,rightValue,"[Index]",node->lineCreated);	

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(rightNode,"*", "4", temp,NULL);

		currentNode++;

		char* temp2= malloc(sizeof(char)*20);
		sprintf(temp2,"t%d",currentNode);


		Add_IR_Instruction(leftNode,"+", temp, temp2,NULL);


		free(temp2);
		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
		// //Arrays are typed the same as if they weren't arrays. The difference is the node will have a size >0

	}

	else if(strcmp(node->tokenName,"dot:")==0)
	{
		//For Dot things MIGHT get a bit weird.
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		char* varName 		= node->u.oper.right->tokenName;

		//The Right token is a dot, meaning we need to check if the left variable
		// of the dot belongs to our struct
		if( strcmp(varName,"dot:")==0)
		{
			varName = node->u.oper.right->u.oper.left->tokenName;
		}
		//Since structs are typed to "themselves", all that is needed is to check if the variable on the Right
		//belongs to the struct

		if(doesVar_Belongto_Struct(varName,leftValue,scope))
		{
			//Var is part of same Struct.
			return evaluateExpr(node->u.oper.right,  expectedType, value,scope);
		}
		else
		{
			//This var is not inside the struct
			fprintf(stderr,"Type Error: Line[%d] Could not find [%s] inside struct:%s\n",node->lineCreated,varName, leftValue);
			errorCount++;
			return NULL;
		}
	}


	else if(strcmp(node->tokenName,"Return:")==0)
	{
		//Returning from Function, need to typecheck scope with return argument
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		char* scopeType = getScopeType(scope);

		if(strcmp(leftValue,scopeType)!=0)
		{
			fprintf(stderr,"Type Error: Line[%d] Can't Return type [%s] from function type [%s]\n",node->lineCreated,leftValue, scopeType);
			errorCount++;
			return NULL;
		}
	}

	else if(strcmp(node->tokenName,"Use:")==0)
	{
		//Go Right first to get params then go Left
		char* rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value,scope);
		char* leftValue		= 	evaluateExpr(node->u.oper.left,  expectedType, value,scope);	


		//Return the Left Value, but as you can see we traverse the right side aswell so those instructions do their thing.
		return leftValue;			
	}

	else if(strcmp(node->tokenName,"IF:")==0)
	{
		//This one's tough. Because If ELSE have a slight difference
		//than a sole if.

		//This is the Logic Check
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);			

		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		//Now we go into the If Branch clause
		char* rightValue=evaluateExpr(node->u.oper.right,  expectedType, value,scope);			

		return leftValue;
	}

	else if(strcmp(node->tokenName,"while:")==0)
	{
		//This one's tough. Because If ELSE have a slight difference
		//than a sole if.

		//This is the Logic Check
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);			

		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		//Now we go into the If Branch clause
		char* rightValue=evaluateExpr(node->u.oper.right,  expectedType, value,scope);			

		return leftValue;
	}

	else if(strcmp(node->tokenName,"Call:")==0)
	{
		//Go Right first to get params then go Left
		//char* leftValue		= 	evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		if( strcmp(getScopeType(node->u.oper.left->tokenName),"None")==0)
		{
			fprintf(stderr, "Type Error: Line[%d] No such Function exists:%s\n",node->lineCreated, node->u.oper.left->tokenName);
			errorCount++;
			return NULL;			
		}
		char* rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value,scope);
 	}

	else if(isExpression_Container(node))
	{
		currentLabel++;
		//If we hit an Expression Node Recall this function with NULL
		//Basically reset our typechecking
		evaluateExpr(node->u.oper.left, NULL, value,scope);
		evaluateExpr(node->u.oper.right, NULL, value,scope);
		return NULL;		
	}
	//If it's none of the above its eithor an identifier or a constant
	else
	{
		if(node->kind==constantExp)
		{
			//It's a constant, but of what type.
			//Char?
			if(node->constantType==c)
			{
				char* temp= malloc(sizeof(char)*20);
				sprintf(temp,"t%d",currentNode);
				Add_IR_Instruction(node->tokenName,"&", NULL, temp,NULL);
				free(temp);
				return ("char");
			}
			//Int?
			else if(node->constantType==i)
			{
				char* temp= malloc(sizeof(char)*20);
				sprintf(temp,"t%d",currentNode);
				Add_IR_Instruction(node->tokenName,"&", NULL, temp,NULL);
				free(temp);
				return ("int");
			}
			//Float?
			else if(node->constantType==f)
			{
				char* temp= malloc(sizeof(char)*20);
				sprintf(temp,"t%d",currentNode);
				Add_IR_Instruction(node->tokenName,"&", NULL, temp,NULL);
				free(temp);

				return ("float");
			}
		}
		else if(node->kind == variableExp)
		{

			if(isInScope(node->tokenName, scope))
			{
				// fprintf(stderr, "Variable exists :/   [%s]\n",node->tokenName);	
				//We have a variable, we can perform a lookup to see if the type matches.
				char* variableType= Get_Var_AssignedType(node->tokenName,scope);
				// printf("VarType=%s\n",variableType);
				if( strcmp(variableType,"None")==0)
				{	
					fprintf(stderr, "Variable Error: Variable [%s] was not initialized.\n",node->tokenName);	
					errorCount++;
					return NULL;
				}
				else
				{	
					char* temp= malloc(sizeof(char)*20);
					sprintf(temp,"t%d",currentNode);
					Add_IR_Instruction(node->tokenName,"&", NULL, temp,NULL);
					free(temp);


					return variableType;
				}
			}
			else
			{
				fprintf(stderr, "Scope Error: Can't find variable:[%s]\n",node->tokenName);	
				errorCount++;
				return NULL;	
			}
		}
	}
	return NULL;
	// evaluateChar(node->u.oper.left);
	// evaluateChar(node->u.oper.right);
	// return NULL;
}






int isExpression_Container(expressionTree node)
{
	if(node==NULL)
		return FALSE;

	if(node->tokenName[0]=='E')
	if(node->tokenName[1]=='x')
	if(node->tokenName[2]=='p')
	if(node->tokenName[3]==':')
		return TRUE;

	return FALSE;		
}

int isFunction_Container(expressionTree node)
{
	if(node==NULL)
		return FALSE;

	if(node->tokenName[0]=='F')
	if(node->tokenName[1]=='C')
	if(node->tokenName[2]==':')
		return TRUE;

	return FALSE;	
}



char* functionScope(expressionTree node, char* curScope)
{
	if(node->tokenName[0]=='F')
		if(node->tokenName[1]=='C')	
			if(node->tokenName[2]==':')
				if(strlen(node->tokenName)>3 && node->tokenName[3]!='_')
				{
					if(curScope!=NULL)
						free(curScope);

					//200 Size function
					char* scope = malloc(sizeof(char)*200);
					int i;
					for(i=3;i< strlen(node->tokenName);i++)
					{
						// printf("i=%d\n",i);
						// printf("Max=%d\n", strlen(node->tokenName));
						// printf("C@i=%c\n", node->tokenName[i]);
						scope[i-3]= node->tokenName[i];
					}
					scope[i]='\0';
					return scope;
				}
	return curScope;
}


expressionTree TraverseLeft(expressionTree node)
{
	return node->u.oper.left;
}
expressionTree TraverseRight(expressionTree node)
{
	return node->u.oper.right;
}