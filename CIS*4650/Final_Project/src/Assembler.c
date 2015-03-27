#include "Assembler.h"
#include <stdio.h>
extern ir_Node* root_Node;
#define LITERAL_USED -9435331
typedef struct temp
{
	char* 	tag; //Every Instruction has a Label Number
	int 	memory;
	int 	literal_i;
	float 	literal_f;
	char 	literal_c;
	struct temp* next;
}temp_Val;

temp_Val* root_Temp;

//As Instructions get Parsed, a Lookup function will be needed to replace
//temps with actual addresses....
//List is inefficient, but im losing the will to live, so forget
//optimizations right now.

temp_Val* GetNode(char* var)
{
	temp_Val* currentNode = root_Temp;
	while(currentNode!=NULL)
	{
		if(strcmp(currentNode->tag, var)==0)
		{
			// printf("\n\nLookingUpMemory:%s  Value=%d\n", currentNode->tag, currentNode->memory);
			return currentNode;
		}
		//printf("Checking [%s] with [%s]\n", currentNode->tag, var);
		currentNode= currentNode->next;
	}
	return NULL;	
}

int LookupMemory(char* var)
{
	temp_Val* currentNode = root_Temp;
	while(currentNode!=NULL)
	{
		if(strcmp(currentNode->tag, var)==0)
		{
			// printf("\n\nLookingUpMemory:%s  Value=%d\n", currentNode->tag, currentNode->memory);
			return currentNode->memory;
		}
		//printf("Checking [%s] with [%s]\n", currentNode->tag, var);
		currentNode= currentNode->next;
	}
	printf("Could not Find:%s  Value=%d\n", var);
	return -999;
}



//Add the Temporary values, and associate them with a memory/value
void Add_Temp(ir_Node* curNode)
{
	int exists=0;
	//Check if the variable exists
	temp_Val* currentNode = root_Temp;
	while(currentNode!=NULL)
	{
		if(strcmp(currentNode->tag, curNode->result)==0)
		{
			printf("Found:%s\n",currentNode->tag);
			exists=1;
			break;
		}
		if(currentNode->next==NULL)
			break;

		currentNode= currentNode->next;
	}
	//We are now at the index of target node.
	//What sucks? Well, we have to basically do the operation here...AND in spim =_=;...
	int memory=-101; //Default memory value, must get replaced
	char lC='_';
	int li=0;
	int lf=0.0f;

	if(strcmp(curNode->op,"&")==0)
	{		
		//Were assigning an address, look it up in SymbolTable
		memory = Get_Var_MemoryOffset(curNode->leftValue, curNode->scope);
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}
	else if(strcmp(curNode->op,"=c")==0)
	{		

		//Were assigning an address, look it up in SymbolTable
		memory = LITERAL_USED; //Secret number
		lC=curNode->leftValue[0];
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}
	else if(strcmp(curNode->op,"=i")==0)
	{		

		//Were assigning an address, look it up in SymbolTable
		memory = LITERAL_USED+1; //Secret number
		li= atoi(curNode->leftValue);
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}	
	else if(strcmp(curNode->op,"=f")==0)
	{		

		//Were assigning an address, look it up in SymbolTable
		memory = LITERAL_USED+2; //Secret number
		lf= atof(curNode->leftValue);
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}	


	else if(strcmp(curNode->op,"+")==0)
	{
		//Were assigning an address, look it up in SymbolTable
		int memory1 = Get_Var_MemoryOffset(curNode->leftValue, curNode->scope);
		int memory2 = Get_Var_MemoryOffset(curNode->rightValue, curNode->scope);

		if(memory1==-666)
			memory1=LookupMemory(curNode->leftValue); //Not a variable, could be a temp
		if(memory2==-666)
			memory2=LookupMemory(curNode->rightValue);//Not a variable, could be a temp		

		memory= memory1+memory2;
		printf("Memory=%d\n",memory);
		printf("Memory1=%d\n",memory1);
		printf("Memory2=%d\n",memory2);
	}


	if(exists==1)
		currentNode->memory=memory;
	else
	{
		currentNode->next=malloc(sizeof(temp_Val));

		currentNode->next->memory=memory;

		//Only used if LITERAL is given for Memory
		currentNode->literal_c=lC;
		currentNode->literal_f=lf;		
		currentNode->literal_i=li;				

		currentNode->next->tag=curNode->result;
		currentNode->next->next=NULL;
		currentNode= currentNode->next;
	}
	//printf("Added: %s-------------\n",currentNode->tag);
}









void CreateAssembly()
{
	root_Temp= malloc(sizeof(temp_Val)); //Just to have a start
	root_Temp->tag="$";
	root_Temp->memory=-1;
	root_Temp->next=NULL;
 	FILE *f = fopen("Code.asm", "w");
	//Well we'll need the start of the IR list

	//Lets calculate the Stack Frames...a little late, but better late then never.
	printf("Starting the Assembly...\n");
	Calculate_Offsets();
	//Traverse IR instructions
	ir_Node* currentNode = root_Node;
	while(currentNode->next!=NULL)
	{
		currentNode= currentNode->next;

		//Print all Labels
		if(currentNode->op == NULL)
			if(currentNode->label!=NULL)
				fprintf(f,"%s:\n", currentNode->label);

		//If its the load address

		//Doesn't work....
		if(currentNode->op!=NULL)
		{
			//Regardless the OP, we need to perform the calculations ourselves
			//incase an array is called or any other nonsense everything must be up to date
			
			if((currentNode->result!=NULL) && (strcmp(currentNode->op,"*=")!=0))
				Add_Temp(currentNode);

			//Now we'll have memory for all these guys
			//Whenever * is encountered as the first char, we need to lookup somememory

			if(strcmp(currentNode->op,"*=")==0)
			{
				//This is the memory location of this value
				int memLeft   = LookupMemory(currentNode->leftValue);
				int memResult = LookupMemory(currentNode->result);

				if(memLeft==-999)
					memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 

				if(memLeft<-999)
				{
					temp_Val* tmp=GetNode(currentNode->leftValue);
					if(tmp->memory== LITERAL_USED)
					{
						//Now we can print the correct value
						fprintf(f,"\t\t//  *=  //\n");
						fprintf(f,"\tsw %c,%d($sp) //%s\n",tmp->literal_c,memResult,currentNode->result);
					}
					else if(tmp->memory== LITERAL_USED+1)
					{
						//Now we can print the correct value
						fprintf(f,"\t\t//  *=  //\n");
						fprintf(f,"\tsw %d,%d($sp) //%s\n",tmp->literal_i,memResult,currentNode->result);
					}
					else if(tmp->memory== LITERAL_USED+2)
					{
						//Now we can print the correct value
						fprintf(f,"\t\t//  *=  //\n");
						fprintf(f,"\tsw %f,%d($sp) //%s\n",tmp->literal_f,memResult,currentNode->result);
					}						
				}
				else	
				{//If the left value is not a literal
					//Load the variable 1
					fprintf(f,"\t\t//  *=  //\n");
					fprintf(f,"\tlw $t0,%d($sp) //%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\tsw $t0,%d($sp) //%s\n",memResult,currentNode->result);
				}
			}
		}
	}
	//Since Main should be the last instruction
	//Should be safe to print the finaly syscall here
	fprintf(f,"\tli $v0,10\n");
	fprintf(f,"\tsyscall\n");

	fclose(f);
}