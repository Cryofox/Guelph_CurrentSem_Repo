#ifndef ABSTREE
#define ABSTREE

typedef struct node_Expression *expressionTree;
typedef enum {PlusOp, MinusOp, TimesOp, DivideOp} optype;

struct node_Expression
{
	enum {operatorExp, constantExp, variableExp} kind;
	union 
	{
		struct 
		{
			optype op;
			expressionTree left;
			expressionTree right;
		} oper;

		int constantval;
		char *variable;
	} u;
};




expressionTree operatorExpression(optype op, expressionTree left, expressionTree right);

expressionTree IdentifierExpression(char *variable);

expressionTree ConstantExpression(int constantval);











#endif
