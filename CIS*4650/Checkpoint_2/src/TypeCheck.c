#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.h"
#include "AbstractTree.h"
#include "TypeCheck.h"
#define TRUE 1
#define FALSE 0

extern expressionTree root;
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
void PerformTypeCheck(int depth, expressionTree node, char* scope)
{


	if(node==NULL)
		return;



	//Call this on Every node, abit in-efficient, but it'll gaurantee scope.
	//Update the Current Scope we are in, based on the Function we just passed.
	scope=functionScope(node, scope);


	if(!isExpression_Container(node) && !isFunction_Container(node))
	{
		//If it is, then this violates the Assignment Operator.
		// printf("Semantic Error: Can't Assign an expression to an expression.\n");
		// int evaluateExpr(expressionTree node, char* expectedType, int value)
	}


}

//Here we recursively traverse the expression, updating the Value, and returning the Type of the evaluated token
int evaluateExpr(expressionTree node, char* expectedType, int value)
{
	//Traverse all Branches
	if(node==NULL)
		return 0;

	//Check if we're +
	if(strcmp(node->tokenName,"+")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  expectedType, value);
		int rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value);	

		return (leftValue+rightValue);
	}
	else if(strcmp(node->tokenName,"=")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  expectedType, value);
		int rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value);	

		return (leftValue);
	}
	else if(strcmp(node->tokenName,"-")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  expectedType, value);
		int rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value);	

		return (leftValue-rightValue);		
	}
	else if(strcmp(node->tokenName,"/")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  expectedType, value);
		int rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value);	

		return (leftValue/rightValue);		
	}
	else if(strcmp(node->tokenName,"*")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  expectedType, value);
		int rightValue	=	evaluateExpr(node->u.oper.right, expectedType, value);	

		return (leftValue*rightValue);		
	}
	//Relational operators require INTS as a type
	else if(strcmp(node->tokenName,">")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  "int", value);
		int rightValue	=	evaluateExpr(node->u.oper.right, "int", value);	
		if(leftValue>rightValue)
			return (TRUE);	
		else
			return(FALSE);	
	}
	else if(strcmp(node->tokenName,"<")==0)
	{
		int leftValue	=	evaluateExpr(node->u.oper.left,  "int", value);
		int rightValue	=	evaluateExpr(node->u.oper.right, "int", value);	
		if(leftValue<rightValue)
			return (TRUE);	
		else
			return(FALSE);	
	}




	return 0;

	// evaluateChar(node->u.oper.left);
	// evaluateChar(node->u.oper.right);

	// return NULL;
}






int isExpression_Container(expressionTree node)
{
	if(node==NULL)
		return FALSE;

	if(node->tokenName[0]=='E')
	if(node->tokenName[0]=='x')
	if(node->tokenName[0]=='p')
	if(node->tokenName[0]==':')
		return TRUE;

	return FALSE;		
}

int isFunction_Container(expressionTree node)
{
	if(node==NULL)
		return FALSE;

	if(node->tokenName[0]=='F')
	if(node->tokenName[0]=='C')
	if(node->tokenName[0]==':')
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