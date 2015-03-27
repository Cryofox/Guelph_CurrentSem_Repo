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
//Returns index of added IR instruction, for IF's and GoTo's
int Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label)
{
	int index=0;
	if(root_Node==NULL)
		return;
	//Get the Last Node
	//This can be optimized by always having the last node, but w.e for now.
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL)
	{
		currentNode= currentNode->next;
		index++;
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

	currentNode->gotoLabel=NULL;

	currentNode->isIF=0;
	currentNode->isLoop=0;

	return index;
}

void Add_GoToLabel(int index, char* gotoLabel)
{
	int i=0;
	if(root_Node==NULL)
		return;
	//Get the Last Node
	//This can be optimized by always having the last node, but w.e for now.
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL && i!=index)
	{
		currentNode= currentNode->next;
		i++;
	}

	if(currentNode->gotoLabel!=NULL)
		free(currentNode->gotoLabel);

	currentNode->gotoLabel= strdup(gotoLabel);
}


int Promote_LastIR_IF(char* label)
{
	int index=0;
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL)
	{
		currentNode= currentNode->next;
		index++;
	}
	//On Last Node
	currentNode->isIF=1;
	if(label!=NULL)
	{
		if(currentNode->gotoLabel!=NULL)
			free(currentNode->gotoLabel);
		currentNode->gotoLabel=strdup(label);
	}


	//Since this is a promotion, it means we must inverse the sign
	if( strcmp(currentNode->op,"==")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup("!=");
	}
	else if( strcmp(currentNode->op,"!=")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup("==");
	}
	else if( strcmp(currentNode->op,">=")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup("<");
	}
	else if( strcmp(currentNode->op,"<=")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup(">");
	}
	else if( strcmp(currentNode->op,">")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup("<=");
	}
	else if( strcmp(currentNode->op,"<")==0)
	{
		free(currentNode->op);
		currentNode->op=strdup(">=");
	}

//&& || ?



	return index;
}



void Print_IR_Instructions()
{
	ir_Node* currentNode = root_Node->next;

	while(currentNode!=NULL)
	{

		if(currentNode->op!=NULL && strcmp(currentNode->op,"call")==0)
		{
			printf("\t%s %s %s\n", currentNode->op, currentNode->leftValue, currentNode->rightValue);
		}
		else if(currentNode->op!=NULL && strcmp(currentNode->op,"param")==0)
		{
			printf("\t%s %s \n", currentNode->op, currentNode->leftValue);
		}		

		else if(currentNode->isIF==1)
		{
			printf("\tif %s %s %s goto %s\n",currentNode->leftValue, currentNode->op,currentNode->rightValue, currentNode->gotoLabel );
		}

		//Pretty Print
		else if(currentNode->label!=NULL)
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