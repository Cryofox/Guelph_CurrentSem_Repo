#ifndef TYPECHECK
#define TYPECHECK
#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.h"
#include "AbstractTree.h"

void PerformTypeCheck(int depth, expressionTree node, char* scope);
char* functionScope(expressionTree node, char* curScope);
//These are typedefed as pointers
expressionTree TraverseLeft(expressionTree node);
expressionTree TraverseRight(expressionTree node);
int isExpression_Container(expressionTree node);

void TraverseTree(int depth, expressionTree node);
int evaluateExpr(expressionTree node, char* expectedType, int value, char*scope);
#endif