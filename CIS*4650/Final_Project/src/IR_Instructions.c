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
	root_Node->next=NULL;
	root_Node->label = NULL;
	root_Node->scope = NULL;
	root_Node->next= NULL;
	root_Node->rightValue=NULL;
	root_Node->leftValue=NULL;	
	root_Node->op=NULL;
}




//Add a new instruction to our current list of instructions
//Returns index of added IR instruction, for IF's and GoTo's
int Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label,char* scope)
{
	//printf("Adding:%s %s %s %s %s %s\n", leftVal, op, rightVal,result,label, scope);
	int index=0;
	if(root_Node==NULL)
		return;
	//Get the Last Node
	//This can be optimized by always having the last node, but w.e for now.
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL)
	{
		currentNode->next->prev= currentNode;
		currentNode= currentNode->next;
		index++;
	}

	currentNode->next= malloc(sizeof(ir_Node));

	currentNode=currentNode->next;

	currentNode->label = NULL;
	currentNode->scope = NULL;
	currentNode->next= NULL;
	currentNode->rightValue=NULL;
	currentNode->leftValue=NULL;
	currentNode->result=NULL;	
	currentNode->op=NULL;

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
	if(scope!=NULL)
		currentNode->scope=strdup(scope);

	currentNode->gotoLabel=NULL;

	currentNode->isIF=0;

	//If Scope is not null, add this "result" to symbole table at scope

	Add_TempSym(currentNode->result, currentNode->scope);
	return index;
}

void IR_Add_Scope(char* scope)
{
	if(scope==NULL)
		return;
	int i=0;
	if(root_Node==NULL)
		return;
	//Get the Last Node
	//This can be optimized by always having the last node, but w.e for now.
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL )
	{
		if(currentNode->scope==NULL)
			currentNode->scope=strdup(scope);

		currentNode= currentNode->next;
	}

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



void Print_IR_Instructions(FILE * fptr)
{
	ir_Node* currentNode = root_Node->next;

	while(currentNode!=NULL)
	{

		if(currentNode->op!=NULL && strcmp(currentNode->op,"call")==0)
		{
			fprintf(fptr,"\t[%s]%s %s %s\n",currentNode->result, currentNode->op, currentNode->leftValue, currentNode->rightValue);
		}
		else if(currentNode->op!=NULL && strcmp(currentNode->op,"param")==0)
		{
			fprintf(fptr,"\t%s %s \n", currentNode->op, currentNode->leftValue);
		}		

		else if(currentNode->isIF==1)
		{
			fprintf(fptr,"\tif %s %s %s goto %s\n",currentNode->leftValue, currentNode->op,currentNode->rightValue, currentNode->gotoLabel );
		}

		//Pretty Print
		else if(currentNode->label!=NULL)
		{			
		//Here we print just Function Labels
			if(currentNode->rightValue==NULL && currentNode->leftValue==NULL && currentNode->op==NULL && currentNode->result==NULL)
				fprintf(fptr,"[%s]:\n",currentNode->label);
			else
			{
				if(currentNode->rightValue==NULL)
					fprintf(fptr,"%s %s = %s %s\n",currentNode->label,currentNode->result, currentNode->op, currentNode->leftValue);
				else
					fprintf(fptr,"%s %s = %s %s %s\n",currentNode->label,currentNode->result,currentNode->leftValue, currentNode->op,currentNode->rightValue );
			}
		}
		else if(currentNode->result==NULL)
		{}
		else
		{
			if(currentNode->rightValue==NULL)
				fprintf(fptr,"\t%s = %s %s\n",currentNode->result, currentNode->op, currentNode->leftValue);
			else if(currentNode->rightValue!=NULL && currentNode->leftValue!=NULL)
				fprintf(fptr,"\t%s = %s %s %s\n",currentNode->result,currentNode->leftValue, currentNode->op,currentNode->rightValue );
		
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