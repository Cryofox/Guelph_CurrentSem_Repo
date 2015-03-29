#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.h"
#include "AbstractTree.h"
#include "TypeCheck.h"
#include "IR_Instructions.h"
#include <signal.h>
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
		Add_IR_Instruction(NULL,NULL,NULL,NULL,scope,scope);
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
int param=FALSE;
int paramCount=0;
int accessFromStruct=0;
int dotAccess=FALSE;
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

		Add_IR_Instruction(leftNode,"+", rightNode, temp,NULL,scope);


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

		Add_IR_Instruction(leftNode,"-", rightNode, temp,NULL,scope);


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

		Add_IR_Instruction(leftNode,"/", rightNode, temp,NULL,scope);


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

		Add_IR_Instruction(leftNode,"*", rightNode, temp,NULL,scope);


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

		Add_IR_Instruction(leftNode,"%", rightNode, temp,NULL,scope);


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



		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));



		//We can check if the Right Node is a USE here. If it is we assign to rightleft
		if(node->u.oper.right->u.oper.left!= NULL && strcmp(node->u.oper.right->tokenName,"Use:")==0)
		{
			Add_IR_Instruction(node->u.oper.right->u.oper.left->tokenName,"*=", NULL,leftNode ,NULL,scope);
			evaluateExpr(node->u.oper.right, expectedType, value,scope);	
		}
		else
		{
			char* rightNode= malloc(sizeof(char)*20);
			//Current Node is now updated with what the right branch WOULD be
			sprintf(rightNode,"t%d",(currentNode+1));	
 			
			evaluateExpr(node->u.oper.right, expectedType, value,scope);	
 			Add_IR_Instruction(rightNode,"*=", NULL,leftNode ,NULL,scope);

 			free(rightNode);
		}
		free(leftNode);
		free(temp);
	}

	else if(strcmp(node->tokenName,"Arr[]")==0)
	{
		int paraminUse= param;

		if(paraminUse==1)
			param=0;

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

		

		currentNode++;

		char* temp2= malloc(sizeof(char)*20);
		sprintf(temp2,"t%d",currentNode);
		
		Add_IR_Instruction(rightNode,"*", "4", temp2,NULL,scope);
		Add_IR_Instruction(leftNode,"+", temp2, temp,NULL,scope);

		if(paraminUse==1)
		{
			//Add 2 Extra Instructions. 1 for *= and 1 for param
			Add_IR_Instruction(temp,"=", NULL, temp,NULL,scope);
			Add_IR_Instruction(temp,"param", NULL, temp,NULL,scope);	
			param=1;//Reset Param			
		}



		free(temp2);
		free(temp);
		free(leftNode);
		free(rightNode);



		return leftValue;
		// //Arrays are typed the same as if they weren't arrays. The difference is the node will have a size >0
	}
	else if(strcmp(node->tokenName,"dot:")==0)
	{
		int paraminUse= param;

		if(paraminUse==1)
			param=0;

		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		//For Dot things MIGHT get a bit weird.

		//Since structs are typed to "themselves", all that is needed is to check if the variable on the Right

		//belongs to the struct
		char* leftNode= malloc(sizeof(char)*20);
		sprintf(leftNode,"t%d",(currentNode+1));

		
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);
		accessFromStruct=1;
		char* varName 		= node->u.oper.right->tokenName;
		char * rightValue;


		//The Right token is a dot, meaning we need to check if the left variable
		// of the dot belongs to our struct
		if( strcmp(varName,"dot:")==0)
		{
			varName = node->u.oper.right->u.oper.left->tokenName;
		}


		if(doesVar_Belongto_Struct(varName,leftValue,scope))
		{
			//Var is part of same Struct.
			rightValue= evaluateExpr(node->u.oper.right,  expectedType, value,scope);
		}
		else
		{
			//This var is not inside the struct
			fprintf(stderr,"Type Error: Line[%d] Could not find [%s] inside struct:%s\n",node->lineCreated,varName, leftValue);
			errorCount++;
			return NULL;
		}
		char* rightNode= malloc(sizeof(char)*20);
		int postLeft=currentNode;
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft));

		Add_IR_Instruction(rightNode,"+", leftNode, temp,NULL,scope);

		//This is our Param


		accessFromStruct=0;
		if(paraminUse==1)
		{
			//Add 2 Extra Instructions. 1 for *= and 1 for param
			Add_IR_Instruction(temp,"=", NULL, temp,NULL,scope);
			Add_IR_Instruction(temp,"param", NULL, temp,NULL,scope);	
			param=1;//Reset Param			
		}

		free(leftNode);
		free(rightNode);
		return rightValue;
	}

	else if(strcmp(node->tokenName,"&&")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"&&",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"&&", rightNode, temp,NULL,scope);


		free(leftNode);
		free(rightNode);
		//Now need to add an == Instruction

		char* newNode= malloc(sizeof(char)*20);
		sprintf(newNode,"t%d",(++currentNode));

		//This will get reversed once promoted
		Add_IR_Instruction(temp,"!=", "0", newNode,NULL,scope);

		free(newNode);
		free(temp);
		return leftValue;
	}
	else if(strcmp(node->tokenName,"||")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"||",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"||", rightNode, temp,NULL,scope);


		free(leftNode);
		free(rightNode);
		//Now need to add an == Instruction

		char* newNode= malloc(sizeof(char)*20);
		sprintf(newNode,"t%d",(++currentNode));

		//This will get reversed once promoted
		Add_IR_Instruction(temp,"!=", "0", newNode,NULL,scope);

		free(newNode);
		free(temp);
		return leftValue;
	}
	else if(strcmp(node->tokenName,"!")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,leftValue,"!",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"!", NULL, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}
	//Relational operators require INTS as a type
	else if(strcmp(node->tokenName,">")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,">",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,">", rightNode, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}



	else if(strcmp(node->tokenName,"<")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"<",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"<", rightNode, temp,NULL,scope);

		free(temp);
		free(leftNode);
		free(rightNode);
		return leftValue;
	}
	else if(strcmp(node->tokenName,">=")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,">=",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,">=", rightNode, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}
	else if(strcmp(node->tokenName,"<=")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"<=",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"<=", rightNode, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}	
	else if(strcmp(node->tokenName,"==")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"==",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"==", rightNode, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}
	else if(strcmp(node->tokenName,"!=")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		int preLeft=currentNode;
		char* leftValue		=evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		int postLeft=currentNode;
		char* rightValue	=evaluateExpr(node->u.oper.right, expectedType, value,scope);	

		//If we were not given a type, then we can at least check if left matches right
		Print_Error_Arithmetic("int", leftValue,rightValue,"!=",node->lineCreated);

		char* leftNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(leftNode,"t%d",(preLeft+1));

		char* rightNode= malloc(sizeof(char)*20);
		//Current Node is now updated with what the right branch WOULD be
		sprintf(rightNode,"t%d",(postLeft+1));

		Add_IR_Instruction(leftNode,"!=", rightNode, temp,NULL,scope);


		free(temp);
		free(leftNode);
		free(rightNode);

		return leftValue;
	}






	else if(strcmp(node->tokenName,"Return:")==0)
	{
		// printf("RETTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
				char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",(currentNode));

				char* temp2= malloc(sizeof(char)*20);
		sprintf(temp2,"t%d",(currentNode+1));
		//Returning from Function, need to typecheck scope with return argument
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		char* scopeType = getScopeType(scope);

		if(strcmp(leftValue,scopeType)!=0)
		{
			fprintf(stderr,"Type Error: Line[%d] Can't Return type [%s] from function type [%s]\n",node->lineCreated,leftValue, scopeType);
			errorCount++;
			return NULL;
		}


		Add_IR_Instruction(temp2,"return",NULL, temp,NULL,scope);

		free(temp);
		free(temp2);
	}

	else if(strcmp(node->tokenName,"Use:")==0)
	{
		//Go Right first to get params then go Left

		//Modifying Node structure is risky at this point. But we can Kludge
		//Use is only called on Post processes, meaning we can kind of cheat
		currentNode--;
		char* leftValue		= 	evaluateExpr(node->u.oper.left,  expectedType, value,scope);	
		//We want to Return from here...AND go down.
		//We now have X assigned, so we can use it normally. Now we need to Restore current node
		currentNode+=2;

		char* rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value,scope);	



		return leftValue;
		//Return the Left Value, but as you can see we traverse the right side aswell so those instructions do their thing.
				
	}


//For = While
//Operation is Exact Same as if. The difference is the label and Jump position

	else if(strcmp(node->tokenName,"while:")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);


		char* leftNode= malloc(sizeof(char)*20);
		sprintf(leftNode,"t%d",currentNode+1);

		char* labelIf = malloc(sizeof(char)*20);
		sprintf(labelIf,"Label_t%d",currentNode);


		//This is the Logic Check Occurs twice once to know if we skip, 2nd time to reloop
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);	
		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		int index=0;


		char* labelSkipLoop = malloc(sizeof(char)*20);
		sprintf(labelSkipLoop,"SkipLabel_t%d",currentNode);
		//Promote Last IR to IF		
		//Check if There is ==. If yes, it'll handle our Relational Logic
		//Check if First node encountered on Left is, Relational Operator.

		//We need to Change what we Promote on
		index=	Promote_LastIR_IF(labelSkipLoop);	
		

		//Add an Empty instruction with a label
		Add_IR_Instruction(NULL,NULL,NULL,NULL,labelIf,scope);

		//Now we go into the If Branch clause
		char* rightValue=evaluateExpr(node->u.oper.right,  expectedType, value,scope);			


		//This is the Logic Check
		leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);	




		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		index=0;
		//Check if There is ==. If yes, it'll handle our Relational Logic
		//Check if First node encountered on Left is, Relational Operator.
		if((strcmp(node->u.oper.left->tokenName,"==")==0) 	||
				  (strcmp(node->u.oper.left->tokenName,"<")==0)		||
				  (strcmp(node->u.oper.left->tokenName,"<=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,">")==0)		||	
				  (strcmp(node->u.oper.left->tokenName,">=")==0)	||	
				  (strcmp(node->u.oper.left->tokenName,"!=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"&&")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"||")==0)
				  )
		{
			//We need to Change what we Promote on
			index=	Promote_LastIR_IF(labelIf);
			//Double Promote, to inverse the IF Inverse
			index=	Promote_LastIR_IF(labelIf);			
		}
		//We Create our own.
		//Basically we ask if it ==1
		else
		{
			char* labelIf = malloc(sizeof(char)*20);
			sprintf(labelIf,"Label_t%d",currentNode);
			//The Condition is reversed. Therefore if the expression is false
			//we skip the If Logic instructions
			index= Add_IR_Instruction(leftNode,"!=", "0", temp,NULL,scope);
			Promote_LastIR_IF(labelIf);	
		}

		//Add an Empty instruction with a label
		Add_IR_Instruction(NULL,NULL,NULL,NULL,labelSkipLoop,scope);

		//We now have the target Node Label...
		free(labelSkipLoop);
		free(labelIf);
		free(temp);
		return leftValue;
	}
	/*While Snapshot

	else if(strcmp(node->tokenName,"while:")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);


		char* leftNode= malloc(sizeof(char)*20);
		sprintf(leftNode,"t%d",currentNode+1);

		char* labelIf = malloc(sizeof(char)*20);
		sprintf(labelIf,"Label_t%d",currentNode);


		//Add an Empty instruction with a label
		Add_IR_Instruction(NULL,NULL,NULL,NULL,labelIf,scope);

		//Now we go into the If Branch clause
		char* rightValue=evaluateExpr(node->u.oper.right,  expectedType, value,scope);			


		//This is the Logic Check
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);			

		//Promote Last IR to IF		

		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		int index=0;
		//Check if There is ==. If yes, it'll handle our Relational Logic
		//Check if First node encountered on Left is, Relational Operator.
		if((strcmp(node->u.oper.left->tokenName,"==")==0) 	||
				  (strcmp(node->u.oper.left->tokenName,"<")==0)		||
				  (strcmp(node->u.oper.left->tokenName,"<=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,">")==0)		||	
				  (strcmp(node->u.oper.left->tokenName,">=")==0)	||	
				  (strcmp(node->u.oper.left->tokenName,"!=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"&&")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"||")==0)
				  )
		{
			//We need to Change what we Promote on
			index=	Promote_LastIR_IF(labelIf);
			//Double Promote, to inverse the IF Inverse
			index=	Promote_LastIR_IF(labelIf);			
		}
		//We Create our own.
		//Basically we ask if it ==1
		else
		{
			char* labelIf = malloc(sizeof(char)*20);
			sprintf(labelIf,"Label_t%d",currentNode);
			//The Condition is reversed. Therefore if the expression is false
			//we skip the If Logic instructions
			index= Add_IR_Instruction(leftNode,"!=", "0", temp,NULL,scope);
			Promote_LastIR_IF(labelIf);	
		}



		//We now have the target Node Label...

		free(labelIf);
		free(temp);
		return leftValue;
	}
	*/
	else if(strcmp(node->tokenName,"IF:")==0)
	{
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);


		char* leftNode= malloc(sizeof(char)*20);
		sprintf(leftNode,"t%d",currentNode+1);

		char* labelIf = malloc(sizeof(char)*20);
		sprintf(labelIf,"Label_t%d",currentNode);

		//This is the Logic Check
		char* leftValue		= evaluateExpr(node->u.oper.left,  expectedType, value,scope);			

		//Promote Last IR to IF		

		if(strcmp(leftValue,"int")!=0)
		{
			fprintf(stderr, "Type Error: Line[%d] Relation Logic must result as int, instead:%s\n",node->lineCreated, leftValue);
			errorCount++;
			return NULL;
		}

		int index=0;
		//Check if There is ==. If yes, it'll handle our Relational Logic
		//Check if First node encountered on Left is, Relational Operator.
		if((strcmp(node->u.oper.left->tokenName,"==")==0) 	||
				  (strcmp(node->u.oper.left->tokenName,"<")==0)		||
				  (strcmp(node->u.oper.left->tokenName,"<=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,">")==0)		||	
				  (strcmp(node->u.oper.left->tokenName,">=")==0)	||	
				  (strcmp(node->u.oper.left->tokenName,"!=")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"&&")==0)	||
				  (strcmp(node->u.oper.left->tokenName,"||")==0)
				  )
		{
			//We need to Change what we Promote on
			index=	Promote_LastIR_IF(labelIf);
		}
		//We Create our own.
		//Basically we ask if it ==1
		else
		{
			//The Condition is reversed. Therefore if the expression is false
			//we skip the If Logic instructions
			index= Add_IR_Instruction(leftNode,"!=", "0", temp,NULL,scope);
			Promote_LastIR_IF(labelIf);	
		}

		//Now we go into the If Branch clause
		char* rightValue=evaluateExpr(node->u.oper.right,  expectedType, value,scope);			
		
		//Add an Empty instruction with a label
		Add_IR_Instruction(NULL,NULL,NULL,NULL,labelIf,scope);

		//We now have the target Node Label...

		free(labelIf);
		free(temp);
		return leftValue;
	}
	//Here we need to Do a Seperate Type of Scan on the Left Side...this is because of the Params
	else if(strcmp(node->tokenName,"Call:")==0)
	{

		//Go Right first to get params then go Left
		//char* leftValue		= 	evaluateExpr(node->u.oper.left,  expectedType, value,scope);

		if( does_ScopeExist(node->u.oper.left->tokenName)==0)
		{
			fprintf(stderr, "Type Error: Line[%d] No such Function exists:%s\n",node->lineCreated, node->u.oper.left->tokenName);
			errorCount++;
			return NULL;			
		}

		//Toggle Params here
		char* temp= malloc(sizeof(char)*20);
		sprintf(temp,"t%d",currentNode);

		param=TRUE;
		paramCount=0;
		//The Parameters are in the RIGHT Branch
		char* rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value,scope);



		char* params = malloc(sizeof(char)*20);
		sprintf(params,"%d",paramCount);

		//The Function were Calling is here...
		// char* leftValue		=	evaluateExpr(node->u.oper.right, expectedType, value,scope);
		//When call is used var 1 = Label. We know this...
		Add_IR_Instruction(node->u.oper.left->tokenName,"call", params, temp,NULL,scope);

		free(params);
		free(temp);
		param=FALSE;
		paramCount=0;
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


				Add_IR_Instruction(node->tokenName,"=c", NULL, temp,NULL,scope);
				

				free(temp);
				return ("char");
			}
			//Int?
			else if(node->constantType==i)
			{
				char* temp= malloc(sizeof(char)*20);
				sprintf(temp,"t%d",currentNode);

				Add_IR_Instruction(node->tokenName,"=i", NULL, temp,NULL,scope);


				free(temp);
				return ("int");
			}
			//Float?
			else if(node->constantType==f)
			{
				char* temp= malloc(sizeof(char)*20);
				sprintf(temp,"t%d",currentNode);

				Add_IR_Instruction(node->tokenName,"=f", NULL, temp,NULL,scope);


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
				char* sOwner=  Get_Var_Owner(node->tokenName,scope);				
				// printf("Var=%s SOWNER=%s\n",node->tokenName,sOwner);
				if((strcmp(sOwner,"!")!=0) && accessFromStruct==0)
				{
					fprintf(stderr, "Attempting to access var outside of struct.\n",node->tokenName);	
					errorCount++;
					return NULL;	
				}

				// printf("VarType=%s\n",variableType);
				else if( strcmp(variableType,"None")==0)
				{	
					fprintf(stderr, "Variable Error: Variable [%s] was not initialized.\n",node->tokenName);	
					errorCount++;

					//This should be replaced with return null, but i am running out of time.
					exit(1);
				}
				else
				{	

					char* temp= malloc(sizeof(char)*20);
					sprintf(temp,"t%d",currentNode);

					if(param==FALSE && accessFromStruct==0)
						Add_IR_Instruction(node->tokenName,"&", NULL, temp,NULL,scope);

					else if(param==FALSE && accessFromStruct==1)
					{
						//Kludge 1- Force Offset calculation as we go
						Calculate_Offsets();

						//Calc Offset of THIS var
						//This guys offset SHOULD be from the reference of the struct parent
						int varOff= Get_Var_MemoryOffset_FromStruct(node->tokenName,scope);

						char* temp2= malloc(sizeof(char)*20);
						sprintf(temp2,"%d",varOff);

						Add_IR_Instruction(temp2,"=i", NULL, temp,NULL,scope);
						free(temp2);
					}




					else
					{		
						Add_IR_Instruction(node->tokenName,"param", NULL, temp,NULL,scope);	
						paramCount+=1;
						//Check the Parameters of the callee Function here.
						//Basically just check if types match...We support parameter overwriting? cool			

					}
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