#ifndef ABSTREE
#define ABSTREE

typedef struct node_Expression *expressionTree;
typedef enum {PlusOp, MinusOp, TimesOp, DivideOp, ModOp} optype;


//A Tree can have Several Expressions
struct node_Expression
{
	char *tokenName;
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


typedef struct stmnts * StatementList;

struct stmnts
{
	expressionTree* myTrees;
};

expressionTree operatorExpression(optype op, expressionTree left, expressionTree right);

expressionTree IdentifierExpression(char *variable);

expressionTree ConstantExpression(int constantval);











#endif
