#include "AbstractTree.h"
#include <stdio.h>
#include <stdlib.h>


extern int lineNum;
//Container Name is used for Functions
//Code for creating the trees was mostly frankensteined from a modern compiler text
//ie:http://www.cs.usfca.edu/~galles/compilerdesign/cimplementation.pdf
//So similarities from there. He made a simple calc, I made a simple program parser :P



//Tree Node - Container for expressions and functions. This was
//implemented to keep a binary tree representation while allowing for expression/function lists.
expressionTree ContainerExpression(char* containerName,expressionTree left, expressionTree right,containerType ct)
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = Containerexp;
  retval->u.oper.op = None;
  retval->u.oper.left = left;
  retval->u.oper.right = right;

  if(ct==Expression)
  retval->tokenName = strdup("Exp:");
  else if(ct==Function)  
  {
    char buffer[200];
    memset(buffer,0,200);
    strcat(buffer,"FC:");
    strcat(buffer,containerName);
    strcat(buffer,"\0");
    retval->tokenName = strdup(buffer);
  }
  else if(ct==Arguments)  
  {
  retval->tokenName = strdup("Arg:");
  printf("arg\n");
  }  

  return retval; 
}
//Tree Node - Any Operation Values
expressionTree operatorExpression(optype op, expressionTree left,expressionTree right) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = operatorExp;
  retval->u.oper.op = op;
  retval->u.oper.left = left;
  retval->u.oper.right = right;

//Arithmetic
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

//Assignment  
     else if(op== AssignOp)
      retval->tokenName = strdup("="); 
//Sizeof      
     else if(op== SIZE_OP)
      retval->tokenName = strdup("SIZEOF");     

//Relational
     else if(op== AND_OP)
      retval->tokenName = strdup("&&"); 

     else if(op== OR_OP)
      retval->tokenName = strdup("||"); 

     else if(op== EQ_OP)
      retval->tokenName = strdup("=="); 
     else if(op== NE_OP)
      retval->tokenName = strdup("!=");
     else if(op== GT_OP)
      retval->tokenName = strdup(">");
     else if(op== LT_OP)
      retval->tokenName = strdup("<");


     else if(op== GTE_OP)
      retval->tokenName = strdup(">=");
     else if(op== LTE_OP)
      retval->tokenName = strdup("<=");
     else if(op== NOT_OP)
      retval->tokenName = strdup("!");

     else if(op== ACCESS_OP)
      retval->tokenName = strdup(".");

      else if(op== ARRAYACCESS_OP)
      retval->tokenName = strdup("Arr[ ]");   

      else if(op== RETURN_OP)
      retval->tokenName = strdup("Return"); 
      else if(op== USE_OP)
      retval->tokenName = strdup("Use"); 

      else if(op== IF_OP)
      retval->tokenName = strdup("IF");     

      else if(op== ELSE_OP)
      retval->tokenName = strdup("ELSE");  

      else if(op== Call_OP)
      retval->tokenName = strdup("Call:"); 

      else if(op== WHILE_OP)
      retval->tokenName = strdup("While"); 

      else
      retval->tokenName = strdup("Error"); 

//Pre-Post, are converted to Arithmetic during parse +1, -1
  return retval;
}








//Tree Node - Identifier Values
expressionTree IdentifierExpression(char *variable) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = variableExp;
  retval->u.variable = variable;

  retval->tokenName =  strdup(variable);
  return retval;
}

//Tree Node - Constant Values
expressionTree ConstantExpression(void* tokenVal,vartype var) 
{
  expressionTree retval = (expressionTree) malloc(sizeof(struct node_Expression));
  retval->kind = constantExp;
  if(var== _Int)
  {
    retval->u.constantval_i = *((int*)tokenVal);
    
    //printf("Token=%d\n", retval->u.constantval_i );
    if(retval->u.constantval_i<0)
      retval->tokenName =  malloc(sizeof(int)*( -1*retval->u.constantval_i));    
    else
      retval->tokenName =  malloc(sizeof(int)*(retval->u.constantval_i)); 

    snprintf( retval->tokenName, sizeof(retval->tokenName), "%d", retval->u.constantval_i);
    //snprintf( retval->tokenName, sizeof(retval->tokenName), "%d", retval->u.constantval_i);
  }
  else if(var== _Float)
  {
    float f = *((float *)tokenVal);
    retval->u.constantval_f = f;
    retval->tokenName =  malloc(sizeof(float)*(retval->u.constantval_f));
    snprintf( retval->tokenName, sizeof(retval->tokenName), "%f", retval->u.constantval_f);
  }
  else if(var== _Char)
  {
    retval->u.constantval_c =  *((char*)tokenVal);
    retval->tokenName =  malloc(sizeof(char)*(retval->u.constantval_c));
    snprintf( retval->tokenName, sizeof(retval->tokenName), "'%c'", retval->u.constantval_c);
  } 


  return retval;
}

int nodesCount=0;




void padding ( char ch, int n, FILE* fptr )
{
  int i;
  for ( i = 0; i < (n+1); i++ )
    fputc (ch,fptr );
}


void PrintTree_Recursive(expressionTree node, int depth, int* totalNodes, FILE* fptr)
{

  int currentLocation;
  if (  node == NULL ) 
  {
    //These just made the tree look busy
    //in a not so groovy way.

   // padding ( '\t', depth, fptr );
   //fprintf (fptr, "[D:%d] ~NULL~\n",depth);
  }
  else 
  {
    if(node->u.oper.left!=NULL)
    {
      *totalNodes+=1;
      fprintf(fptr, "\"%s[%d]\" -> \"%s[%d]\";\n",node->tokenName,(depth),node->u.oper.left->tokenName,(*totalNodes)  );
      int val=  *totalNodes;
      PrintTree_Recursive( (node->u.oper.left), (val),totalNodes, fptr   );
    }
    if(node->u.oper.right!=NULL)
    {
      *totalNodes+=1;
      fprintf(fptr, "\"%s[%d]\" -> \"%s[%d]\";\n",node->tokenName,(depth),node->u.oper.right->tokenName,(*totalNodes)  );  
      int val=  *totalNodes;
      PrintTree_Recursive( (node->u.oper.right),(val),totalNodes, fptr   );
    }

  nodesCount++; 
  }
}

void PrintTree(expressionTree node, int depth, FILE* fptr)
{
  int i=0;
    fprintf(fptr, "digraph G{\n" );
    PrintTree_Recursive(node,depth, &i,fptr);
    fprintf(fptr, "}\n" );   
}
void FreeTree (expressionTree node)
{
  if(node==NULL)
    return;
  
  nodesCount--;
  if(node->kind!=constantExp && node->kind!=variableExp)
  {
    if(node->u.oper.left!=NULL)
      FreeTree(node->u.oper.left);
    if(node->u.oper.right!=NULL)
      FreeTree(node->u.oper.right);   
  }


  if(node!=NULL)
  {
      if(strlen(node->tokenName)>0)
      {
        printf("Node:[%s]\n", node->tokenName);
        free(node->tokenName);
      }
    node->tokenName=NULL;
    free(node);
    node=NULL;
  }
}


