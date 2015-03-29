#include "Assembler.h"
#include "SymbolTable.h"
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
			// printf("Found:%s\n",currentNode->tag);
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
		// printf("Loading Address: %s Val=%d\n", curNode->result,li);
	}	
	else if(strcmp(curNode->op,"=f")==0)
	{		
		//Were assigning an address, look it up in SymbolTable
		memory = LITERAL_USED+2; //Secret number
		lf= atof(curNode->leftValue);
		// printf("Loading Address: %s Val=%d\n", curNode->result,memory);
	}	



	else if(strcmp(curNode->op,"param")==0)
	{		
		// printf("PARAM Found\n");
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

		//Here we alter the memory offset of our var.
		//We state the size of the frame + the temp number

	}
	// printf("Added: %s %d \n", currentNode->tag, currentNode->literal_i);
	//printf("Added: %s-------------\n",currentNode->tag);
}






void CreateArithRel_Statement(FILE* f, ir_Node* currentNode)
{
	// printf("ATTEMPTING ARITHMETIC:\n");
	// printf(" %s = %s %s %s\n", currentNode->result, currentNode->leftValue, currentNode->op, currentNode->rightValue);
	//This is the memory location of this value
	int memLeft   	= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 
	int memRight   	= Get_Var_MemoryOffset(currentNode->rightValue, currentNode->scope); 
	int memResult 	= Get_Var_MemoryOffset(currentNode->result, currentNode->scope); 

	fprintf(f,"#  Arithmet / Relation  //\n");


	//Need to check if we're operating on Float or Int Registers
	//Since Temp values are given int just for spacing issues, we only need to
	//check if 1 of the 2 vars are Floats, if so we op on float registers.
	//This is due to us assuming typechecking would have caught float on non float operations
	int isFloat=0;
	char * type= Get_Var_AssignedType(currentNode->leftValue,currentNode->scope);
	// printf("Type1=%s\n",type);
	if(type!=NULL)
		if(strcmp(type,"float")==0)
			isFloat=1;

	if(currentNode->rightValue!=NULL)
	{		
		type= Get_Var_AssignedType(currentNode->rightValue,currentNode->scope);
		// printf("Type2=%s\n",type);		
		if(type!=NULL)
			if(strcmp(type,"float")==0)
				isFloat=1;
	}


	if(isFloat==1)
	{
		if(memLeft==-666) //if -666, means no var exists, meaning it must be a number or something...
			fprintf(f,"\tl.s $f1,%s #%s\n",currentNode->leftValue ,currentNode->leftValue);
		else
			fprintf(f,"\tl.s $f1,%d($sp) #%s\n",memLeft ,currentNode->leftValue);
		if(currentNode->rightValue!=NULL)
		{
			if(memRight==-666) //if -666, means no var exists, meaning it must be a number or something...
				fprintf(f,"\tl.s $f2,%s #%s\n",currentNode->rightValue ,currentNode->leftValue);
			else
				fprintf(f,"\tl.s $f2,%d($sp) #%s\n",memRight ,currentNode->leftValue);
		}

		//Possible its an int

		//Use the following commands for 
		if(strcmp(currentNode->op,"+")==0)
		{
			fprintf(f,"\tadd.s $f1,$f1,$f2 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);
		}

		else if(strcmp(currentNode->op,"-")==0)
		{	fprintf(f,"\tsub.s $f1,$f1,$f2 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);
		}
		else if(strcmp(currentNode->op,"*")==0)
		{	fprintf(f,"\tmul.s $f1,$f1,$f2 #\n");
			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);
		}

		else if(strcmp(currentNode->op,"/")==0)
		{	fprintf(f,"\tdiv.s $f1,$f1,$f2 #\n");
			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);
		}

		fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memResult,currentNode->result);
		fprintf(f,"#=====//\n");	
	}
	//Int maths
	else
	{
		//printf("ML:%d \t MR:%d \t MRES:%d\n",memLeft,memRight,memResult);
		if(memLeft==-666) //if -666, means no var exists, meaning it must be a number or something...
			fprintf(f,"\tli $t0,%s #%s\n",currentNode->leftValue ,currentNode->leftValue);
		else
			fprintf(f,"\tlw $t0,%d($sp) #%s\n",memLeft ,currentNode->leftValue);

		if(memRight==-666) //if -666, means no var exists, meaning it must be a number or something...
			fprintf(f,"\tli $t1,%s #%s\n",currentNode->rightValue ,currentNode->leftValue);
		else
			fprintf(f,"\tlw $t1,%d($sp) #%s\n",memRight ,currentNode->leftValue);

		//Possible its an int

			
		
		//Use the following commands for 
		if(strcmp(currentNode->op,"+")==0)
		{
			fprintf(f,"\tadd $t0,$t0,$t1 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);


		}

		else if(strcmp(currentNode->op,"-")==0)
		{
			fprintf(f,"\tsub $t0,$t0,$t1 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);


		}

		else if(strcmp(currentNode->op,"*")==0)
		{
			fprintf(f,"\tmul $t0,$t0,$t1 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);


		}

		else if(strcmp(currentNode->op,"/")==0)
		{
			fprintf(f,"\tdiv $t0,$t0,$t1 #\n");

			//Here we check if our new temp is also addressed
			if( GetAddressedFlag(currentNode->leftValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);

			if( GetAddressedFlag(currentNode->rightValue, currentNode->scope)==1)
				SetAddressed(currentNode->result, currentNode->scope);


		}


		//Dont care after here, because the values are 0-1 ....
		else if(strcmp(currentNode->op,"&&")==0)
			fprintf(f,"\tand $t0,$t0,$t1 #\n");

		else if(strcmp(currentNode->op,"||")==0)
			fprintf(f,"\tor $t0,$t0,$t1 #\n");
		//Lets Add More Relational Logic


		//Here we check the Ifs
		else if(strcmp(currentNode->op,">=")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tbge $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, whic fkin sucks...but w.e
				// Perform Set Less than, then Not it
				fprintf(f,"\tslt $t0, $t0, $t1#\n");
				fprintf(f,"\tnot $t0, $t0\n"); 
				//We Just performed >=
			}
		}
		else if(strcmp(currentNode->op,">")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tbgt $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, whic fkin sucks...but w.e
				// Perform Set Less than, then Not it
				fprintf(f,"\tsgt $t0, $t0, $t1\n");
				//Check if t1<t0  ..IE if t0>t1 :)
			}
		}
		else if(strcmp(currentNode->op,"<=")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tble $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, which fkin sucks...but w.e
				// Perform Set Less than in reverse (greater than), then Not it
				fprintf(f,"\tsgt $t0, $t0, $t1\n");
				fprintf(f,"\tnot $t0, $t0\n"); 
			}
		}
		else if(strcmp(currentNode->op,"<")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tblt $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, which fkin sucks...but w.e
				fprintf(f,"\tslt $t0, $t0, $t1\n");
			}
		}

		else if(strcmp(currentNode->op,"==")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tbeq $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, which fkin sucks...but w.e
				fprintf(f,"\tseq $t0, $t0, $t1\n"); 
				// fprintf(f,"\tslt $t3, $t1, $t0");
				// //Not both Registers
				// fprintf(f,"\tnot $t2, $t2");
				// fprintf(f,"\tnot $t3, $t3");
				// //AND in t0, for == check
				// fprintf(f,"\t")
			}
		}		
		else if(strcmp(currentNode->op,"!=")==0)
		{
			if(currentNode->isIF==1)
			{
				fprintf(f,"\tbne $t0, $t1, %s\n",currentNode->gotoLabel);
			}
			else
			{
				//We only have SetLess than, which fkin sucks...but w.e
				fprintf(f,"\tsne $t0, $t0, $t1\n"); 
				// fprintf(f,"\tslt $t3, $t1, $t0");
				// //Not both Registers
				// fprintf(f,"\tnot $t2, $t2");
				// fprintf(f,"\tnot $t3, $t3");
				// //AND in t0, for == check
				// fprintf(f,"\t")
			}
		}
		else if(strcmp(currentNode->op,"!")==0)
		{
			//We only have SetLess than, which fkin sucks...but w.e
			fprintf(f,"\tnot $t0, $t0\n");				
		}
		fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
		fprintf(f,"#=====//\n");	
	}


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
	// printf("Starting the Assembly...\n");
	// printf("Calculating Offsets\n");
	Calculate_Offsets();
	//Traverse IR instructions
	// printf("Converting to ASM\n");
	ir_Node* currentNode = root_Node;

	//Before Processing the Functions, we have to layout the global memory
	fprintf(f,".data\n");

	entry_Node* varList = Get_Scope_Variables("Global");

	while(varList!=NULL)
	{
		if(strcmp(varList->struct_Owner,"!")==0)
			fprintf(f,"%s: .space %d\n", varList->identifier, (varList->memorySize));
		varList=varList->next;
	}



	fprintf(f,".text\n");



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

			// printf(" %s = %s %s %s\n", currentNode->result, currentNode->leftValue, currentNode->op, currentNode->rightValue);
			//Since all  Temp Variables are stored, we don't need to do any dancing..just use the variables

			//We don't actually want the address, we just want
			if(strcmp(currentNode->op,"&")==0)
			{
				//This is the memory location of this value
				int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);

				//Create the Reference for bookkeeping
				Create_ReferenceLink(currentNode->result, currentNode->leftValue, currentNode->scope);

				// if(memLeft==-999)
				// 	memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 

				//Use Left value because result could be Temp which we arbitrarily named an int
				int isFloat=0;
				char * type= Get_Var_AssignedType(currentNode->leftValue,currentNode->scope);

				if(type!=NULL)
					if(strcmp(type,"float")==0)
						isFloat=1;

				//The Below Code only works on Localized Variables...Lets Add Globals
				int isGlobal = isVar_Global(currentNode->leftValue,currentNode->scope);

				if(isGlobal==0)
				{
					if(isFloat==1)
					{
						fprintf(f,"#  &  //\n");
						//These can for the most part be ignored. This instruction would just overwrite the value
						//inside a var with its own address...completely pointless
						fprintf(f,"\tla  $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
						fprintf(f,"#=====//\n");
						//We load the value the address holds but WE make note of what variable that was


						//Set Left side Flag to True
						 SetAddressed(currentNode->result, currentNode->scope);
					}
					else
					{				
						fprintf(f,"#  &  //\n");
						//These can for the most part be ignored. This instruction would just overwrite the value
						//inside a var with its own address...completely pointless
						//Whenever we're loading an address zero out the value at it
						fprintf(f,"\tla $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
						fprintf(f,"#=====//\n");
						//We load the value the address holds but WE make note of what variable that was

						//Set Left side Flag to True
						 SetAddressed(currentNode->result, currentNode->scope);

					}
				}
				else
				{
					if(isFloat==1)
					{
						fprintf(f,"#  &  //\n");
						//These can for the most part be ignored. This instruction would just overwrite the value
						//inside a var with its own address...completely pointless
						//Whenever we're loading an address zero out the value at it
						fprintf(f,"\tla $t0,%s #%s\n",currentNode->leftValue  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);//These are local Temp Registers
						fprintf(f,"#=====//\n");
						//We load the value the address holds but WE make note of what variable that was


						//Set Left side Flag to True
						 SetAddressed(currentNode->result, currentNode->scope);
					}
					else
					{				
						fprintf(f,"#  &  //\n");
						//These can for the most part be ignored. This instruction would just overwrite the value
						//inside a var with its own address...completely pointless
						//Whenever we're loading an address zero out the value at it
						fprintf(f,"\tla $t0,%s #%s\n",currentNode->leftValue  ,currentNode->leftValue);
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);//These are local Temp Registers
						fprintf(f,"#=====//\n");
						//We load the value the address holds but WE make note of what variable that was

						//Set Left side Flag to True
						 SetAddressed(currentNode->result, currentNode->scope);

					}
				}

			}
			//Chars and Ints use Same register
			if(strcmp(currentNode->op,"*=")==0)
			{
				//This is the memory location of this value
				// int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);
				int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);

				fprintf(f,"#  Assignment //\n");

				//First push the Address we are holding to t0
				char* referenceVar =Get_ReferencedValue(currentNode->result,currentNode->scope);

				int isFloat=0;
				char * type= Get_Var_AssignedType(currentNode->leftValue,currentNode->scope);

				if(type!=NULL)
					if(strcmp(type,"float")==0)
						isFloat=1;

								if(type!=NULL)
					if(strcmp(type,"float")==0)
						isFloat=1;


				//The Below Code only works on Localized Variables...Lets Add Globals
				int isGlobal = isVar_Global(currentNode->leftValue,currentNode->scope);

				if(isFloat==1)
				{
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless

					//Now we store to both the Temp on the left, AND the reference link
					fprintf(f,"\tl.s $f1, %d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					//fprintf(f,"\tlw $t0, ($t0) #Grab Word from Address\n");

					fprintf(f,"\tlw $t1, %d($sp) #%s\n",memResult  ,currentNode->result);


					if(GetAddressedFlag(currentNode->leftValue,currentNode->scope)==1)
					{
						fprintf(f,"\tl.s $f1, ($f1) #\n");
					}
					fprintf(f,"\ts.s $f1, ($t1) #%s\n",currentNode->result);
					fprintf(f,"#=====//\n");
				}
				else
				{
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless

					//Now we store to both the Temp on the left, AND the reference link
					fprintf(f,"\tlw $t0, %d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					//fprintf(f,"\tlw $t0, ($t0) #Grab Word from Address\n");

					fprintf(f,"\tlw $t1, %d($sp) #%s\n",memResult  ,currentNode->result);


					if(GetAddressedFlag(currentNode->leftValue,currentNode->scope)==1)
					{
						fprintf(f,"\tlw $t0, ($t0) #\n");
					}
					fprintf(f,"\tsw $t0, ($t1) #%s\n",currentNode->result);
					fprintf(f,"#=====//\n");	
				}


			}	
			//Used for Re-assigning values...printing array values instead of addresses
			if(strcmp(currentNode->op,"=")==0)
			{
				//This is the memory location of this value
				// int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);
				int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);

				fprintf(f,"#  Assignment //\n");

				//First push the Address we are holding to t0
				char* referenceVar =Get_ReferencedValue(currentNode->result,currentNode->scope);

				int isFloat=0;
				char * type= Get_Var_AssignedType(currentNode->leftValue,currentNode->scope);

				if(type!=NULL)
					if(strcmp(type,"float")==0)
						isFloat=1;

								if(type!=NULL)
					if(strcmp(type,"float")==0)
						isFloat=1;

				if(isFloat==1)
				{
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless

					//Now we store to both the Temp on the left, AND the reference link
					fprintf(f,"\tl.s $f1,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memResult,currentNode->result);
					if(referenceVar!=NULL)
					{
						int memRef= Get_Var_MemoryOffset(referenceVar, currentNode->scope);
						fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memRef,referenceVar);					
					}
					fprintf(f,"#=====//\n");	
				}
				else
				{
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless

					//Now we store to both the Temp on the left, AND the reference link
					fprintf(f,"\tlw $t0, %d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					//fprintf(f,"\tlw $t0, ($t0) #Grab Word from Address\n");

					fprintf(f,"\tlw $t1, %d($sp) #%s\n",memResult  ,currentNode->result);


					if(GetAddressedFlag(currentNode->leftValue,currentNode->scope)==1)
					{
						fprintf(f,"\tlw $t0, ($t0) #\n");
					}
					//Re-Assignment
					fprintf(f,"\tsw $t0, %d($sp) #%s\n",memResult  ,currentNode->result);
					//fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
					// if(referenceVar!=NULL)
					// {
					// 	int memRef= Get_Var_MemoryOffset(referenceVar, currentNode->scope);
					// 	fprintf(f,"\tsw $t0,%d($sp) #%s\n",memRef,referenceVar);
					// }


					fprintf(f,"#=====//\n");	
				}

			}	

			//Chars and Ints use Same register
			if(strcmp(currentNode->op,"=i")==0)
			{
				//This is the memory location of this value
				// int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);

				fprintf(f,"#  Literal Int/Char  //\n");
				//These can for the most part be ignored. This instruction would just overwrite the value
				//inside a var with its own address...completely pointless

				fprintf(f,"\tli $t0,%s #%s\n",currentNode->leftValue  ,currentNode->leftValue);

				fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
				fprintf(f,"#=====//\n");
			}		


			if(strcmp(currentNode->op,"=c")==0 )
			{
				//This is the memory location of this value
				// int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);

				fprintf(f,"#  Literal Int/Char  //\n");
				//These can for the most part be ignored. This instruction would just overwrite the value
				//inside a var with its own address...completely pointless


				if(strcmp(currentNode->leftValue,"'\n'")==0)
				{
				fprintf(f,"\tli $t0,%s #'\\n'\n",currentNode->leftValue  ,currentNode->leftValue);
				}
				else
				fprintf(f,"\tli $t0,%s #%s\n",currentNode->leftValue  ,currentNode->leftValue);

				fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
				fprintf(f,"#=====//\n");
			}		

			if(strcmp(currentNode->op,"=f")==0)
			{
				//This is the memory location of this value
				// int memLeft   = Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); //LookupMemory(currentNode->leftValue);
				int memResult = Get_Var_MemoryOffset(currentNode->result, currentNode->scope); //LookupMemory(currentNode->result);

				fprintf(f,"#  Literal Float  //\n");
				//These can for the most part be ignored. This instruction would just overwrite the value
				//inside a var with its own address...completely pointless
				fprintf(f,"\tli.s $f1,%s #%s\n",currentNode->leftValue  ,currentNode->leftValue);
				fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memResult,currentNode->result);
				fprintf(f,"#=====//\n");
			}



			if(strcmp(currentNode->op,"call")==0)
			{
				//Special Case Put_i
				if(strcmp(currentNode->leftValue,"puti")==0)
				{


					ir_Node* tmp =currentNode;
					tmp= tmp->prev;

					//The Below Code only works on Localized Variables...Lets Add Globals
					int isGlobal = isVar_Global(tmp->leftValue,tmp->scope);
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);


					fprintf(f,"#  SysCall Put_I //\n");
					fprintf(f,"\tli $v0,1 #\n");
					if(isGlobal==1)
						fprintf(f,"\tlw $a0,%s #%s\n",tmp->leftValue,tmp->leftValue);
					else
						fprintf(f,"\tlw $a0,%d($sp) #%s\n",memparam,tmp->leftValue);

					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}
				//Special Case Put_i
				else if(strcmp(currentNode->leftValue,"putc")==0)
				{
					ir_Node* tmp =currentNode;
					tmp= tmp->prev;
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);
					fprintf(f,"#  SysCall Put_C //\n");
					fprintf(f,"\tli $v0,4 #\n");
					fprintf(f,"\tla $a0,%d($sp) #%s\n",memparam,tmp->leftValue);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}				
				else if(strcmp(currentNode->leftValue,"putf")==0)
				{
					ir_Node* tmp =currentNode;
					tmp= tmp->prev;
					int isGlobal = isVar_Global(tmp->leftValue,tmp->scope);
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);
					fprintf(f,"#  SysCall Put_F //\n");
					fprintf(f,"\tli $v0,2 #\n");
					if(isGlobal==1)
						fprintf(f,"\tl.s $f12,%s #%s\n",tmp->leftValue,tmp->leftValue);
					else
						fprintf(f,"\tl.s $f12,%d($sp) #%s\n",memparam,tmp->leftValue);

					
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}
				
				else
				{
				//We Copy the Argument Parameters onto the Modified Stack

				//To Setup for a Function call we need to modify the Stack Pointer
					int funcMem = Get_Scope_Memory(currentNode->leftValue);
					int myFuncMem=Get_Scope_Memory(currentNode->scope);
					fprintf(f,"#  Function Call:%s //\n", currentNode->leftValue);





					//Save Return Address and Frame Pointer

					//Copy our Address to the RA

					//Store the current Ret Address here for us.
					fprintf(f,"\tsw $ra, %d($sp)\n",(myFuncMem+8));				
					

					//Offset SP
					fprintf(f,"\tsub $sp, $sp, %d\n",(funcMem+16) );
					//Store FP, for restoring
					fprintf(f,"\tsw $fp, %d($sp)\n",(funcMem+4));

					//Offset FP
					fprintf(f,"\tadd $fp,$sp, %d\n",(funcMem+16));

					//Jump to Address
					fprintf(f,"\tjal %s\n",currentNode->leftValue);

					//Restore the RA
					fprintf(f,"\tlw $ra, %d($sp)\n",(myFuncMem+8));


				 	

					fprintf(f,"#=====//\n");
				}






			}
			if(strcmp(currentNode->op,"return")==0)
			{
				int funcMem = Get_Scope_Memory(currentNode->scope);	
				//Before We Jump back.
				//
					fprintf(f,"# Return Called\n");
					// fprintf(f,"\tlw $ra, %d($sp)\n",(funcMem+8));
					fprintf(f,"\tlw $fp, %d($sp)\n",(funcMem+4));	
					fprintf(f,"\tadd $sp, $sp, %d\n",(funcMem+16));

					fprintf(f,"\tjr $ra\n");

					fprintf(f,"#=====//\n");
			}


			//Arithmetics
			if(
			  (strcmp(currentNode->op,"+")==0)	||
			  (strcmp(currentNode->op,"*")==0) 	||
			  (strcmp(currentNode->op,"/")==0) 	||
			  (strcmp(currentNode->op,"-")==0) 	||
			  (strcmp(currentNode->op,"||")==0) ||  
			  (strcmp(currentNode->op,"&&")==0) || 
			  (strcmp(currentNode->op,">=")==0) || 
			  (strcmp(currentNode->op,"<=")==0) || 
			  (strcmp(currentNode->op,">")==0)	|| 
			  (strcmp(currentNode->op,"<")==0)	|| 
			  (strcmp(currentNode->op,"==")==0) || 
			  (strcmp(currentNode->op,"!=")==0)	||
			  (strcmp(currentNode->op,"!")==0)	
			  )
			{
				CreateArithRel_Statement(f,currentNode);
			}
		


		}
	}
	//Since Main should be the last instruction
	//Should be safe to print the finaly syscall here
	fprintf(f,"\tli $v0,10\n");
	fprintf(f,"\tsyscall\n");

	fclose(f);
}