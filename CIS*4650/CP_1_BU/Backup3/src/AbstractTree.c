#include "AbstractTree.h"
#include <stdio.h>



expressionTree operatorExpression(optype op, expressionTree left,expressionTree right) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = operatorExp;
  retval->u.oper.op = op;
  retval->u.oper.left = left;
  retval->u.oper.right = right;
  return retval;
}

expressionTree IdentifierExpression(char *variable) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = variableExp;
  retval->u.variable = variable;
  return retval;
}

expressionTree ConstantExpression(int constantval) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = constantExp;
  retval->u.constantval = constantval;
  return retval;
}
