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

		//Here we alter the memory offset of our var.
		//We state the size of the frame + the temp number

	}
	printf("Added: %s %d \n", currentNode->tag, currentNode->literal_i);
	//printf("Added: %s-------------\n",currentNode->tag);
}






void CreateArithRel_Statement(FILE* f, ir_Node* currentNode)
{
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

	if(type!=NULL)
		if(strcmp(type,"float")==0)
			isFloat=1;

	if(currentNode->rightValue!=NULL)
	{		
		type= Get_Var_AssignedType(currentNode->rightValue,currentNode->scope);
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
			fprintf(f,"\tadd.s $f1,$f1,$f2 #\n");

		else if(strcmp(currentNode->op,"-")==0)
			fprintf(f,"\tsub.s $f1,$f1,$f2 #\n");

		else if(strcmp(currentNode->op,"*")==0)
			fprintf(f,"\tmul.s $f1,$f1,$f2 #\n");

		else if(strcmp(currentNode->op,"/")==0)
			fprintf(f,"\tdiv.s $f1,$f1,$f2 #\n");

		fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memResult,currentNode->result);
		fprintf(f,"#=====//\n");	
	}
	//Int maths
	else
	{
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
			fprintf(f,"\tadd $t0,$t0,$t1 #\n");

		else if(strcmp(currentNode->op,"-")==0)
			fprintf(f,"\tsub $t0,$t0,$t1 #\n");

		else if(strcmp(currentNode->op,"*")==0)
			fprintf(f,"\tmul $t0,$t0,$t1 #\n");

		else if(strcmp(currentNode->op,"/")==0)
			fprintf(f,"\tdiv $t0,$t0,$t1 #\n");



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
	printf("Starting the Assembly...\n");
	printf("Calculating Offsets\n");
	Calculate_Offsets();
	//Traverse IR instructions
	printf("Converting to ASM\n");
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

				if(isFloat==1)
				{
					fprintf(f,"#  &  //\n");
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless
					fprintf(f,"\tl.s $f1,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memResult,currentNode->result);
					fprintf(f,"#=====//\n");
					//We load the value the address holds but WE make note of what variable that was
				}
				else
				{				
					fprintf(f,"#  &  //\n");
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless
					fprintf(f,"\tlw $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
					fprintf(f,"#=====//\n");
					//We load the value the address holds but WE make note of what variable that was
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

				int memRef= Get_Var_MemoryOffset(referenceVar, currentNode->scope);
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
						fprintf(f,"\ts.s $f1,%d($sp) #%s\n",memRef,referenceVar);					


					fprintf(f,"#=====//\n");	
				}
				else
				{
					//These can for the most part be ignored. This instruction would just overwrite the value
					//inside a var with its own address...completely pointless

					//Now we store to both the Temp on the left, AND the reference link
					fprintf(f,"\tlw $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
					fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
					if(referenceVar!=NULL)
						fprintf(f,"\tsw $t0,%d($sp) #%s\n",memRef,referenceVar);					


					fprintf(f,"#=====//\n");	
				}

			}	

			//Chars and Ints use Same register
			if(strcmp(currentNode->op,"=i")==0 || strcmp(currentNode->op,"=c")==0 )
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
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);
					fprintf(f,"#  SysCall Put_I //\n");
					fprintf(f,"\tli $v0,1 #\n");
					fprintf(f,"\tlw $a0,%d($sp) #%s\n",memparam,tmp->leftValue);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}
				//Special Case Put_i
				if(strcmp(currentNode->leftValue,"putc")==0)
				{
					ir_Node* tmp =currentNode;
					tmp= tmp->prev;
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);
					fprintf(f,"#  SysCall Put_I //\n");
					fprintf(f,"\tli $v0,4 #\n");
					fprintf(f,"\tlw $a0,%d($sp) #%s\n",memparam,tmp->leftValue);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}				
				if(strcmp(currentNode->leftValue,"putf")==0)
				{
					ir_Node* tmp =currentNode;
					tmp= tmp->prev;
					// printf("%s %s %s \n", tmp->leftValue, tmp->rightValue, tmp->op);
					int memparam = Get_Var_MemoryOffset(tmp->leftValue,tmp->scope);
					fprintf(f,"#  SysCall Put_I //\n");
					fprintf(f,"\tli $v0,2 #\n");
					fprintf(f,"\tl.s $f12,%d($sp) #%s\n",memparam,tmp->leftValue);
					fprintf(f,"\tsyscall\n");
					fprintf(f,"#=====//\n");
				}			
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



			// if(strcmp(currentNode->leftValue,"putf")==0)
			// {
			// 	//we only need 1 param back. So lets grab it
			// 	temp_Val* tmp=GetNode(currentNode->result);

			// 	tmp= tmp->prev;
			// 	fprintf(f,"#  SysCall Put_F //\n");
			// 	fprintf(f,"\tli $v0,2 #\n");
			// 	fprintf(f,"\tl.s $f12,%d($sp) #%s\n",tmp->memory,tmp->tag);
			// 	fprintf(f,"\tsyscall\n");
			// 	fprintf(f,"#=====//\n");
			// }	
			// if(strcmp(currentNode->leftValue,"putc")==0)
			// {
			// 	//we only need 1 param back. So lets grab it
			// 	temp_Val* tmp=GetNode(currentNode->result);

			// 	tmp= tmp->prev;
			// 	fprintf(f,"#  SysCall Put_C //\n");
			// 	fprintf(f,"\tli $v0,4 #\n");
			// 	fprintf(f,"\tla $a0,%d($sp) #%s\n",tmp->memory,tmp->tag);
			// 	fprintf(f,"\tsyscall\n");
			// 	fprintf(f,"#=====//\n");
			// }



			// //Regardless the OP, we need to perform the calculations ourselves
			// //incase an array is called or any other nonsense everything must be up to date
			
			// if((currentNode->result!=NULL) /*&& (strcmp(currentNode->op,"*=")!=0)*/)
			// 	Add_Temp(currentNode);

			// //Now we'll have memory for all these guys
			// //Whenever * is encountered as the first char, we need to lookup somememory

			// if(strcmp(currentNode->op,"*=")==0)
			// {
			// 	//This is the memory location of this value
			// 	int memLeft   = LookupMemory(currentNode->leftValue);
			// 	int memResult = LookupMemory(currentNode->result);

			// 	//-999 is a number I used for Not Found in lookup memory
			// 	if(memLeft==-999)
			// 		memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 


			// 	if(memLeft>0)
			// 	{
			// 		fprintf(f,"#  *=  //\n");
			// 		fprintf(f,"\tlw $t0,%d($sp)  #%s\n",memLeft  ,currentNode->leftValue);
			// 		fprintf(f,"\tsw $t0,%d($sp)  #%s\n",memResult,currentNode->result);
			// 		fprintf(f,"\t\t#=====//\n");
			// 	}
			// 	else
			// 	{	//A Literal was assigned to the 1st argument
			// 		if(memLeft==LITERAL_USED) 
			// 		{
			// 			temp_Val* tmp=GetNode(currentNode->leftValue);

			// 			fprintf(f,"#  = Literal C #\n");
			// 			fprintf(f,"\tli $t0,'%c' #--%s\n",tmp->literal_c  ,currentNode->leftValue);
			// 			fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);				
			// 			//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
			// 			fprintf(f,"#=====//\n");						
			// 		}
			// 		else if(memLeft==LITERAL_USED+1)
			// 		{
			// 			temp_Val* tmp=GetNode(currentNode->leftValue);

			// 			fprintf(f,"#  = Literal I #\n");
			// 			fprintf(f,"\tli $t0,%d #--%s\n",tmp->literal_i  ,currentNode->leftValue);
			// 			fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);				
			// 			//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
			// 			fprintf(f,"#=====//\n");						
			// 		}
			// 		else if(memLeft==LITERAL_USED+2)
			// 		{
			// 			temp_Val* tmp=GetNode(currentNode->leftValue);

			// 			fprintf(f,"#  = Literal F #\n");
			// 			fprintf(f,"\tli.s $f0,%f #--%s\n",tmp->literal_f  ,currentNode->leftValue);
			// 			fprintf(f,"\ts.s $f0,%d($sp) #%s\n",memResult,currentNode->result);				
			// 			//fprintf(f,"\tsw %s,%d($sp)   #%s\n",currentNode->leftValue,memResult,currentNode->result);
			// 			fprintf(f,"#=====//\n");						
			// 		}	
			// 		//Otherwise we just pretend T0 is rigged with what we want.
			// 		else
			// 		{					

			// 			fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);					
			// 			fprintf(f,"#=====//\n");
			// 		}	
												
			// 	}

			// 	//}
			// }
			// //Load Address into Var at offset
			// if(strcmp(currentNode->op,"&")==0)
			// {
			// 	//This is the memory location of this value
			// 	int memLeft   = LookupMemory(currentNode->leftValue);
			// 	int memResult = LookupMemory(currentNode->result);

			// 	if(memLeft==-999)
			// 		memLeft= Get_Var_MemoryOffset(currentNode->leftValue, currentNode->scope); 

			// 	fprintf(f,"#  &  //\n");
			// 	//These can for the most part be ignored. This instruction would just overwrite the value
			// 	//inside a var with its own address...completely pointless
			// 	// fprintf(f,"\tla $t0,%d($sp) #%s\n",memLeft  ,currentNode->leftValue);
			// 	// fprintf(f,"\tsw $t0,%d($sp) #%s\n",memResult,currentNode->result);
			// 	fprintf(f,"#=====//\n");
			// }

			// //Arithmetics
			// if((strcmp(currentNode->op,"+")==0) ||
			//   (strcmp(currentNode->op,"*")==0) ||
			//   (strcmp(currentNode->op,"/")==0) ||
			//   (strcmp(currentNode->op,"-")==0) ||
			//   (strcmp(currentNode->op,"||")==0) ||  
			//   (strcmp(currentNode->op,"&&")==0) )
			// {
			// 	CreateArithRel_Statement(f,currentNode);
			// }



			// if(strcmp(currentNode->op,"call")==0)
			// {
			// 	if(strcmp(currentNode->leftValue,"puti")==0)
			// 	{
			// 		//we only need 1 param back. So lets grab it
			// 		temp_Val* tmp=GetNode(currentNode->result);

			// 		tmp= tmp->prev;
			// 		fprintf(f,"#  SysCall Put_I //\n");
			// 		fprintf(f,"\tli $v0,1 #\n");
			// 		fprintf(f,"\tlw $a0,%d($sp) #%s\n",tmp->memory,tmp->tag);
			// 		fprintf(f,"\tsyscall\n");
			// 		fprintf(f,"#=====//\n");
			// 	}
			// 	if(strcmp(currentNode->leftValue,"putf")==0)
			// 	{
			// 		//we only need 1 param back. So lets grab it
			// 		temp_Val* tmp=GetNode(currentNode->result);

			// 		tmp= tmp->prev;
			// 		fprintf(f,"#  SysCall Put_F //\n");
			// 		fprintf(f,"\tli $v0,2 #\n");
			// 		fprintf(f,"\tl.s $f12,%d($sp) #%s\n",tmp->memory,tmp->tag);
			// 		fprintf(f,"\tsyscall\n");
			// 		fprintf(f,"#=====//\n");
			// 	}	
			// 	if(strcmp(currentNode->leftValue,"putc")==0)
			// 	{
			// 		//we only need 1 param back. So lets grab it
			// 		temp_Val* tmp=GetNode(currentNode->result);

			// 		tmp= tmp->prev;
			// 		fprintf(f,"#  SysCall Put_C //\n");
			// 		fprintf(f,"\tli $v0,4 #\n");
			// 		fprintf(f,"\tla $a0,%d($sp) #%s\n",tmp->memory,tmp->tag);
			// 		fprintf(f,"\tsyscall\n");
			// 		fprintf(f,"#=====//\n");
			// 	}
			// 	//Otherwise it's a real function call...golly	


			// }		


		}
	}
	//Since Main should be the last instruction
	//Should be safe to print the finaly syscall here
	fprintf(f,"\tli $v0,10\n");
	fprintf(f,"\tsyscall\n");

	fclose(f);
}