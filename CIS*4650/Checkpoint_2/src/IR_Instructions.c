//This class is just a giant queue/list used for creating instructions in the order
//they need to be executed in.

#include <stdio.h>
#include <stdlib.h>
#include "IR_Instructions.h"

int currentLabel=0;
int currentNode=0;
ir_Node* root_Node;
void InitializeIR_Node()
{
	root_Node = malloc(sizeof(ir_Node));
}




//Add a new instruction to our current list of instructions
void Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label)
{
	if(root_Node==NULL)
		return;
	//Get the Last Node
	//This can be optimized by always having the last node, but w.e for now.
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL)
	{
		currentNode= currentNode->next;
	}
	currentNode->next= malloc(sizeof(ir_Node));
	currentNode=currentNode->next;
	currentNode->label = NULL;

	if(leftVal!=NULL)
		currentNode->leftValue=strdup(leftVal);
	if(rightVal!=NULL)
		currentNode->rightValue=strdup(rightVal);
	if(op!=NULL)
		currentNode->op=strdup(op);
	if(result!=NULL)
		currentNode-> result=strdup(result);
	if(label!=NULL)
		currentNode->label=strdup(label);
}


void Print_IR_Instructions()
{
	ir_Node* currentNode = root_Node->next;

	while(currentNode!=NULL)
	{
		//Pretty Print
		if(currentNode->label!=NULL)
		{			
		//Here we print just Function Labels
			if(currentNode->rightValue==NULL && currentNode->leftValue==NULL && currentNode->op==NULL && currentNode->result==NULL)
				printf("[%s]:\n",currentNode->label);
			else
			{
				if(currentNode->rightValue==NULL)
					printf("%s %s = %s %s\n",currentNode->label,currentNode->result, currentNode->op, currentNode->leftValue);
				else
					printf("%s %s = %s %s %s\n",currentNode->label,currentNode->result,currentNode->leftValue, currentNode->op,currentNode->rightValue );
			}
		}
		else
		{
			if(currentNode->rightValue==NULL && currentNode->leftValue==NULL && currentNode->op==NULL && currentNode->result==NULL)		
			{}
			else
			{
				if(currentNode->rightValue==NULL)
					printf("\t%s = %s %s\n",currentNode->result, currentNode->op, currentNode->leftValue);
				else
					printf("\t%s = %s %s %s\n",currentNode->result,currentNode->leftValue, currentNode->op,currentNode->rightValue );
			}
		}
		currentNode=currentNode->next;
	}
}

void Free_IR_Instructions()
{
	ir_Node* currentNode = root_Node;
	while(currentNode!=NULL)
	{
		ir_Node* temp = currentNode;
		currentNode=currentNode->next;
		free(temp);
	}
}