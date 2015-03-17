#include "AbstractTree.h"
#include <stdio.h>



expressionTree operatorExpression(optype op, expressionTree left,expressionTree right) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = operatorExp;
  retval->u.oper.op = op;
  retval->u.oper.left = left;
  retval->u.oper.right = right;

    if(op== PlusOp)
      retval->tokenName = strdup("+");
    else if(op== MinusOp)
      retval->tokenName = strdup("-");
    else if(op== TimesOp)
      retval->tokenName = strdup("*");
    else if(op== DivideOp)
      retval->tokenName = strdup("/");
     else if(op== ModOp)
      retval->tokenName = strdup("%");   


  return retval;
}

expressionTree IdentifierExpression(char *variable) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = variableExp;
  retval->u.variable = variable;

  retval->tokenName = strdup(variable);

  return retval;
}

expressionTree ConstantExpression(int constantval) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = constantExp;
  retval->u.constantval = constantval;

  retval->tokenName =  malloc(sizeof(int)*(constantval));
  snprintf( retval->tokenName, sizeof(retval->tokenName), "%d", constantval);



  return retval;
}


void Print()

