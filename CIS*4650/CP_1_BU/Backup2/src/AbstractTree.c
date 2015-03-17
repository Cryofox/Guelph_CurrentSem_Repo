#include "AbstractTree.h"


//This Creates a node and assigns the left and right Parents
node *mknode(node *left, node *right, char *token_Name)
{
  /* malloc the node */
  node *newnode = (node *)malloc(sizeof(node));
  char *newstr = (char *)malloc(strlen(token_Name)+1);
  strcpy(newstr, token_Name);
  newnode->left = left;
  newnode->right = right;
  newnode->token_Name = newstr;
  return(newnode);
}

node *Add_FunctionNode(node* rootNode, node* functionNode)
{
  //Increment Size
  if(rootNode->size==0)
    rootNode->FunctionList = (node **) malloc(sizeof(node*));
  else
    realloc(rootNode->FunctionList,  (sizeof(node*)*(rootNode->size+1)) );

  rootNode->FunctionList[rootNode->size]= functionNode;
  rootNode->size+=1;
}

node* Initialize(node* rootNode)
{
  /* malloc the node */
  node *newnode = (node *)malloc(sizeof(node));
  char *newstr = (char *)malloc(strlen("Root")+1);
  strcpy(newstr, "Root");
  newnode->token_Name = newstr;
  
  return(newnode);
}

void printtree(node *tree)
{
  int i;


  if (tree->left || tree->right)
    printf("(");

  printf(" %s ", tree->token_Name);

  if (tree->left)
    printtree(tree->left);
  if (tree->right)
    printtree(tree->right);

  if (tree->left || tree->right)
    printf(")");
}
