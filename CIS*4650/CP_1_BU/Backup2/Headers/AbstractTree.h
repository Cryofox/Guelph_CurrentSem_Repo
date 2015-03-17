#ifndef ABSTREE
#define ABSTREE

typedef struct node
  {
    struct node *left;
    struct node *right;

    struct node **FunctionList;
    int  size;
    char *token_Name;
  } node;


node* Initialize(node* rootNode);


//Given a Root Node it will create a slot for an Extra Function
node *Add_FunctionNode(node* rootNode, node* functionNode);





node *mknode(node *left, node *right, char *token_Name);









void printtree(node *tree);

//Prototypes















#endif
