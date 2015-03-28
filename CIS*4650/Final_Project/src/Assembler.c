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
	struct temp* prev;
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
	// printf("Could not Find:%s  Value=%d\n", var);
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

	if(exists==1)
		memory=currentNode->memory;

	char lC='_';
	int li=-1;
	float lf=-1.0f;

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
		lC=curNode->leftValue[1];
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}
	else if(strcmp(curNode->op,"=i")==0)
	{		

		//Were assigning an address, look it up in SymbolTable
		memory = LITERAL_USED+1; //Secret number
		li= atoi(curNode->leftValue);
		printf("Loading Address: %s Val=%d\n", curNode->result,li);
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
		// printf("%sMemory=%d\n",curNode->result,memory);
		// printf("%sMemory1=%d\n",curNode->leftValue,memory1);
		// printf("%sMemory2=%d\n",curNode->rightValue,memory2);
	}
	else if(strcmp(curNode->op,"param")==0)
	{		
		printf("PARAM Found\n");
		memory = Get_Var_MemoryOffset(curNode->leftValue, curNode->scope);
	}



	if(exists==1)
	{	
		currentNode->memory=memory;	
	}
	else
	{
		currentNode->next=malloc(sizeof(temp_Val));

		currentNode->next->memory=memory;

		//Only used if LITERAL is given for Memory
		currentNode->next->literal_c=lC;
		currentNode->next->literal_f=lf;		
		currentNode->next->literal_i=li;				
		
		currentNode->next->prev = currentNode;

		currentNode->next->tag=curNode->result;
		currentNode->next->next=NULL;
		currentNode= currentNode->next;
	}
	printf("Added: %s %d \n", currentNode->tag, currentNode->literal_i);
	//printf("Added: %s-------------\n",currentNode->tag);
}









void CreateAssembly()
{
	root_Temp= malloc(sizeof(temp_Val)); //Just to have a start
	root_Temp->tag="$";
	root_Temp->memory=-1;
	root_Temp->next=NULL;
	root_Temp->prev=NULL;
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
			
			if((currentNode->result!=NULL) /*&& (strcmp(currentNode->op,"*=")!=0)*/)
				Add_Temp(currentNode);

			//Now we'll have memory for all these guys
			//Whenever * is encountered as the first char, we need to lookup somememory

			if(strcmp(currentNode->op,"*=")==0)
			{
				//This is the memory location of this value
				int memLeft   = LookupMemory(currentNode->leftValue);
				int memResult = LookupMemory(currentNode->result);

				//-999 is a number I used for Not Found in lookup memory
				if(memLeft==-999)
					memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 


				if(memLeft>0)
				{
					fprintf(f,"#  *=  //\n");
					fprintf(f,"\tlw $t0,%d($sp)  #%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\tsw $t0,%d($sp)  #%s\n",memResult,currentNode->result);
					fprintf(f,"\t\t#=====//\n");
				}
				else
				{	//A Literal was assigned to the 1st argument
					if(memLeft==LITERAL_USED) 
					{
						temp_Val* tmp=GetNode(currentNode->leftValue);

						fprintf(f,"#  = Literal C #\n");
						fprintf(f,"\tli $t0,'%c' #--%s\n",tmp->literal_c  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);				
						//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
						fprintf(f,"#=====//\n");						
					}
					if(memLeft==LITERAL_USED+1)
					{
						temp_Val* tmp=GetNode(currentNode->leftValue);

						fprintf(f,"#  = Literal I #\n");
						fprintf(f,"\tli $t0,%d #--%s\n",tmp->literal_i  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);				
						//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
						fprintf(f,"#=====//\n");						
					}
					if(memLeft==LITERAL_USED+2)
					{
						temp_Val* tmp=GetNode(currentNode->leftValue);

						fprintf(f,"#  = Literal F #\n");
						fprintf(f,"\tli.s $f0,%f #--%s\n",tmp->literal_f  ,currentNode->leftValue);
						fprintf(f,"\ts.s $f0,%d($sp) #%s\n",memResult,currentNode->result);				
						//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
						fprintf(f,"#=====//\n");						
					}					

				}

				//}
			}
			//Load Address into Var at offset
			if(strcmp(currentNode->op,"&")==0)
			{
				//This is the memory location of this value
				int memLeft   = LookupMemory(currentNode->leftValue);
				int memResult = LookupMemory(currentNode->result);

				if(memLeft==-999)
					memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 

				fprintf(f,"#  &  //\n");
				fprintf(f,"\tla $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
				fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
				fprintf(f,"#=====//\n");
			}


			if(strcmp(currentNode->op,"call")==0)
			{
				if(strcmp(currentNode->leftValue,"puti")==0)
				{
					//we only need 1 param back. So lets grab it
					temp_Val* tmp=GetNode(currentNode->result);

					tmp= tmp->prev;
					fprintf(f,"#  SysCall Put_I //\n");
					fprintf(f,"\tli $v0,1 #\n");
					fprintf(f,"\tlw $a0,%d($sp) #%s\n",tmp->memory,tmp->tag);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}
				if(strcmp(currentNode->leftValue,"putf")==0)
				{
					//we only need 1 param back. So lets grab it
					temp_Val* tmp=GetNode(currentNode->result);

					tmp= tmp->prev;
					fprintf(f,"#  SysCall Put_F //\n");
					fprintf(f,"\tli $v0,2 #\n");
					fprintf(f,"\tl.s $f12,%d($sp) #%s\n",tmp->memory,tmp->tag);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}	
				if(strcmp(currentNode->leftValue,"putc")==0)
				{
					//we only need 1 param back. So lets grab it
					temp_Val* tmp=GetNode(currentNode->result);

					tmp= tmp->prev;
					fprintf(f,"#  SysCall Put_C //\n");
					fprintf(f,"\tli $v0,4 #\n");
					fprintf(f,"\tla $a0,%d($sp) #%s\n",tmp->memory,tmp->tag);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
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