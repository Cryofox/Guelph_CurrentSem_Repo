#ifndef ABSTREE
#define ABSTREE

#include <stdio.h>
typedef struct node_Expression *expressionTree;
typedef enum {Call_OP,PlusOp, MinusOp, TimesOp, DivideOp, ModOp, AssignOp, SIZE_OP, EQ_OP, NE_OP, GT_OP, LT_OP, GTE_OP, LTE_OP, AND_OP,OR_OP,NOT_OP, ACCESS_OP, ARRAYACCESS_OP, RETURN_OP, IF_OP, ELSE_OP, WHILE_OP, FOR_OP, None} optype;

typedef enum {_Float,_Int,_Char} vartype;

typedef enum { Expression, Function, Arguments} containerType;



//A Tree can have Several Expressions
struct node_Expression
{
	char *tokenName;
	enum {Containerexp,operatorExp, constantExp, variableExp} kind;
	union 
	{
		struct 
		{
			optype op;
			expressionTree left;
			expressionTree right;
		} oper;

		int constantval_i;
		char constantval_c;
		float constantval_f;
		char *variable;
	} u;
};

typedef struct stmnts * StatementList;

struct stmnts
{
	//A Series of Expressions
	expressionTree* myTrees;
};
void padding ( char ch, int n, FILE* fptr );
void PrintTree(expressionTree node, int depth, FILE* fileptr);

expressionTree operatorExpression(optype op, expressionTree left, expressionTree right);

expressionTree IdentifierExpression(char *variable);


//expressionTree ConstantExpression(int constantval);
expressionTree ConstantExpression(void* tokenVal,vartype var) ;

expressionTree ContainerExpression(char* containerName,expressionTree left, expressionTree right, containerType ct);

void FreeTree (expressionTree node);






#endif
