
#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.h"
#define TABLE_SIZE 997
#define TRUE 1
#define FALSE 0
/*
Logic: 
During the Creation Process
The Symbol Table will keep track of what scope it is in.

As the ABS tree is created, declerations will simply Call
this Class to add a Parameter.

When a Function is Created, in the ABS tree, it's also created here.

Once the Symbol Table is Created.

We change our Tree Structure? ...Well no, since the Tree has the order in which events occur.

We Traverse the Tree, and for each expression we check if they are done on the
same TYPE of "object", float+ float.


Since Yacc Parses in reverse, when we construct the table, we populate the type with a "Standby"
variable, this then gets converted to the type once we get it

*/








//This will Keep track of what scop we are in.
//Default to [GLOBAL]

//The Scope is Global

char* currentScope;

//Referencing Variables
entry_Node** symbolTable;

//Referencing TypeDefs

//About 997 typedefs...should be sufficient
node_Typdef** referenceTable;

node_Scopes* scopeList;

void Initialize_HashTable()
{
	//Initialize Table
    symbolTable 	= malloc(sizeof(entry_Node)*TABLE_SIZE);
	referenceTable  = malloc(sizeof(node_Typdef)*TABLE_SIZE);	

	//scopeList = malloc(sizeof(node_Scopes));

	for(int i=0;i<TABLE_SIZE;i++)
	{
		symbolTable[i]= malloc(sizeof(entry_Node));
		symbolTable[i]->scopeDefined=FALSE;
	}


	for(int i=0;i<TABLE_SIZE;i++)
	{	//	printf("Creating Ref=%d\n",i);
		referenceTable[i]= malloc(sizeof(node_Typdef));
		referenceTable[i]->type="None";
		referenceTable[i]->size=0; 
	}

	//Adding the Temp Scope, This is so we can have a place to constantly relocate variables to and from

	currentScope=("0Tmp\0");


	//Add the Basic Types
	Add_TYPEDEF("float\0", 		"float");
	Add_TYPEDEF("int\0", 		"int");
	Add_TYPEDEF("char\0", 		"char");	
	Add_TYPEDEF("struct\0", 	"struct");
	Add_TYPEDEF("array\0", 		"array");
	Add_TYPEDEF("void\0",       "void");
	//Use 1, as its illegal to start with a numeral in.cb files
	Add_TYPEDEF("1Standby\0", 	"Standby");


	Add_Scope("0Tmp\0","void"); // Uses Global Variable, so lets set it to True.
	//Add the predefined Functions
	Add_Scope("putc","void");
	Add_Scope("putf","void");	
	Add_Scope("puti","void");	

	//None Value is used as a placeholder untill a type Link exists	
}



void Link_StructVariables(char* structName)
{
	// printf("Linking Structs\n");
	int hashValue = hash("0Tmp");
	//Iterate Untill our illegal Variable
	entry_Node* traveller=symbolTable[hashValue];
	entry_Node* startMarker=traveller;
	//Move Untill we Hist $tart
	// printf("Loosy Gosoy\n");
	while( strcmp(traveller->identifier,structName)!=0)
	{
		if(strcmp(traveller->next->identifier,"$TART")==0)
		{	
				// printf("Setting SM to:%s!\n", traveller->identifier);
				startMarker=traveller;
		}

		// printf("ID:%s\n",traveller->identifier);
		// printf("SN:%s\n",structName);		
		traveller=traveller->next;
	}
		//We now have a nested $tart to End for our struct

	//Now our startMarker is set to 1 Prior to $TART

	//First Cleanup

	// printf("Loosy Gosoy2\n");
		//ReLink Variables
		entry_Node* temp= startMarker->next;
		 // printf("Temp:%s\n", temp->identifier);
	 	//  printf("SM:%s_\n", startMarker->identifier);

		//printf("SM->Next=%s\n", startMarker->next->identifier);
		startMarker->next= temp->next;
		// printf("SM->Next=%s\n", startMarker->next->identifier);
	 	//Free The Illegal Var



	 	free(temp->identifier);
	 	free(temp);


	 	startMarker= startMarker->next;
	// printf("Loosy Gosoy3\n");
	//Now Set the Parents of All Non-Owned Variables to this Struct
	while(strcmp(startMarker->identifier,structName)!=0)
	{
		if(strcmp(startMarker->struct_Owner,"!")==0)
		{
			startMarker->struct_Owner=structName;
		}
		startMarker= startMarker->next;
	}
}

void Add_Array(char* token_Name, char* type, int size)
{
	// printf("Adding Var:%s\n",token_Name);
	token_Name= strcat(token_Name,"\0");

	int hashValue = hash("0Tmp");
	if( symbolTable[hashValue]->scopeDefined == FALSE)
	{
		fprintf(stderr, "\nError: Variable added before Function Scope Defined:%s\n", token_Name);
		exit(1);
	}
	else
	{

	 	entry_Node* traveller=symbolTable[hashValue];
		while(traveller->next!=NULL)
			traveller=traveller->next;


		//Now we add the Value
		traveller->next= malloc(sizeof(entry_Node));
		traveller->next->size=size;
		traveller=traveller->next;

		//Setup the Variable
		traveller->identifier= strdup(token_Name);
		traveller->struct_Owner="!";
		//Now to Reference it's Type.
		//printf("So far so peachy...\n");
		//printf("Str Peachy:%s\n",type);
		char* nt = Get_VarType(type);

		// printf("NT=%s\n",nt);
		traveller->type=nt;
		traveller->next=NULL;
		traveller->referencedValue=NULL;
		if(nt== nt_NONE)
		{
			fprintf(stderr, "\nError: Unknown Variable:%s\n", token_Name);			
		}
		traveller->scopeDefined=FALSE;
	}
	// printf("Variable Added\n");
}



//This MUST be added to an Existing scope.
//This is called on Variable Decleration
void Add_Variable(char* token_Name, char* type)
{
	// printf("Adding Var:%s\n",token_Name);
	token_Name= strcat(token_Name,"\0");

	int hashValue = hash("0Tmp");
	if( symbolTable[hashValue]->scopeDefined == FALSE)
	{
		fprintf(stderr, "\nError: Variable added before Function Scope Defined:%s\n", token_Name);
		exit(1);
	}
	else
	{

	 	entry_Node* traveller=symbolTable[hashValue];
		while(traveller->next!=NULL)
			traveller=traveller->next;

		//Now we add the Value
		traveller->next= malloc(sizeof(entry_Node));
		traveller=traveller->next;

		//Setup the Variable
		traveller->identifier= strdup(token_Name);
		traveller->struct_Owner="!";
		traveller->size=Get_VarSize(type);
		//Now to Reference it's Type.
		//printf("So far so peachy...\n");
		//printf("Str Peachy:%s\n",type);
		char* nt = Get_VarType(type);


		traveller->type=nt;
		traveller->next=NULL;
		traveller->referencedValue=NULL;

		if(nt== nt_NONE)
		{
			fprintf(stderr, "\nError: Unknown Variable:%s\n", token_Name);			
		}
		traveller->scopeDefined=FALSE;
	}
	// printf("Variable Added\n");
}
//This MUST be added to an Existing scope.
//This is called on Variable Decleration

void Set_TypeDefs(char* type)
{
	// printf("Setting Typedefs...\n");
	//Traverse Array, 
	for(int i=0;i< TABLE_SIZE;i++)
		if(strcmp(referenceTable[i]->type,"None")==0)
			referenceTable[i]->type=type;

}


//This Function takes all standby variables in this scope and assigns them the new Variable
//This is done due to yacc doing things in reverse >.>
void Set_Type(char* type)
{
	// printf("Setting Type...%s\n",type);
	int tmpScope= hash("0Tmp\0");
	//printf("Issue?\n");
	entry_Node* traveller=symbolTable[tmpScope]->next;

	char* nt = Get_VarType(type);
	// printf("NewType=%s\n",nt);
	int size = Get_VarSize(type);
	while(traveller!=NULL)
	{
		//if(traveller->type==nt_STANDBY)
		if(strcmp(traveller->type,"Standby")==0)
		{	traveller->type=nt;
			//Here we promote Typedefed only variables 
			//to Arrays if they are supposed to be
			if(traveller->size==0)
				traveller->size=size;
		}
		// printf("Var:[%s]Type:[%s]\n",traveller->identifier, traveller->type);


		traveller=traveller->next;
	}
}

//This MUST be added to an Existing function.
void Add_Scope(char* newScope,char* type)
{
	// printf("Scope=%s\n",newScope);
	//currentScope= newScope;
	//Scope Record Keeping

	if(scopeList==NULL)
	{
		scopeList = malloc(sizeof(node_Scopes));
		scopeList->scope_Name= strdup(newScope);
		// printf("Scope Added!\n");
	}
	else
	{

		node_Scopes* ns = scopeList;
		int i =0;
		while(ns->next!=NULL)
		{
			ns=ns->next;
		}

		ns->next= malloc(sizeof(node_Scopes));
		ns->next->scope_Name= strdup(newScope);
		// printf("Creating new Scope Space\n");
	}



	int tmpScope= hash("0Tmp\0");
	int curScope= hash(newScope);
	//printf("Issue?\n");
	entry_Node* traveller=symbolTable[curScope];


	//This occurs when we want to create a variable inside a scope that was already created
	//Useful for detecting Same Name Functions
	if(traveller->scopeDefined== TRUE)
	{
		fprintf(stderr, "\nError: Conflicting Scope:%s\n", traveller->identifier);
		exit(1);
	}	
	else
	{
		traveller->identifier=newScope;
		char* nt = Get_VarType(type);
		traveller->type=nt;

		// printf("Adding Variables From:%s \tTo:%s\n",  symbolTable[tmpScope]->identifier, symbolTable[curScope]->identifier);

		//Relocate All Temp Scope Values to the Actual Scope
		//This is done by simple changing Pointers
		entry_Node* tempScope =symbolTable[tmpScope];

		//Link Pointers
		traveller->next= tempScope->next;

		//Remove Pointer Link from Temp
		tempScope->next=NULL;

		traveller->scopeDefined=TRUE;

	}
}





//Since all TypeDefs are Global, we can reference these from anywhere.
void Add_TYPEDEF(char* typeDef,  char*type)
{
	// printf("Adding typedef..\n");
//	symbolTable = malloc(sizeof(struct entry_Node)*997);
	int hashValue = hash(typeDef); //Get the Hashed Identifier used for TypeDef


 	node_Typdef* traveller=referenceTable[hashValue];
	// printf("HV=%d\n",hashValue);

	//Setup the Variable
	traveller->structReference=NULL;
	// printf("Type=%s\n",type);
	traveller->type=strdup(type);
	traveller->size=0;
	traveller->memorySize=0;
	traveller->memoryOffset=0;
	// printf("Added TypeDef:%s %i\n",typeDef, hashValue);
}

void Add_TYPEDEF_Array(char* typeDef,  char*type, int size)
{
	// printf("Adding typedef..\n");
//	symbolTable = malloc(sizeof(struct entry_Node)*997);
	int hashValue = hash(typeDef); //Get the Hashed Identifier used for TypeDef


 	node_Typdef* traveller=referenceTable[hashValue];
	// printf("HV=%d\n",hashValue);

	//Setup the Variable
	traveller->structReference=NULL;
	// printf("Type=%s\n",type);
	traveller->type=strdup(type);
	traveller->size=size;
	traveller->memorySize=0;
	traveller->memoryOffset=0;
	// printf("Added TypeDef:%s %i\n",typeDef, hashValue);
}


//TypeDefs occur before
void Add_TYPEDEF_Struct(char* typeDef,char* structLink, char* type)
{
	// printf("Adding typedef..\n");
//	symbolTable = malloc(sizeof(struct entry_Node)*997);
	int hashValue = hash(typeDef); //Get the Hashed Identifier used for TypeDef


 	node_Typdef* traveller=referenceTable[hashValue];
 	traveller->structReference=strdup(structLink);
	//Setup the Variable
	traveller->type=strdup(type);
	traveller->size=0;
	traveller->memorySize=0;
	traveller->memoryOffset=0;
	// printf("Added TypeDef:%s %i\n",typeDef, hashValue);
}



//Needed to know if it's an Array
int Get_VarSize(char* tokenType)
{
	// printf("poop?\n");
	int hashValue = hash( tokenType); //Get the Hashed Identifier used for TypeDef
	// printf("We good?\n");
	return referenceTable[hashValue]->size;
}



unsigned int hash(char* string)
{

	unsigned int h=0;
	// printf("Str=%s_\n",string);
	char *word= strdup(string); 

	unsigned long hash = 5381;
    int c;
	int hashAddress = 0;
	for (int counter = 0; word[counter]!='\0'; counter++){
	    hashAddress = word[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
	}
	if(hashAddress<TABLE_SIZE)
		hashAddress*=-1;

	//Mod h by array size
	h=hashAddress%TABLE_SIZE;

	//printf("H=%d S=%s\n",h,string);
	free(word);
	// printf("HA=%d\n", h);
	return(h); 
}
void Add_TempSym(char * tag,char* type, char*scope)
{
	if(scope==NULL || tag==NULL)
		return;
	printf("Tag=%sScope=%s\n",tag,scope);
	printf("Type=%s\n",type);
	int hashValue = hash(scope);
	//Check if variable is in current scope

	entry_Node* traveller = symbolTable[hashValue];
	while(traveller->next!=NULL)
	{
		if(strcmp(traveller->identifier,tag)==0)
			return;
		traveller=traveller->next;
	}		
	traveller->next=malloc(sizeof(entry_Node));
	traveller=traveller->next;

	traveller->identifier=strdup(tag);
	if(type!=NULL)
		traveller->type=strdup(type); //just a byte of data in size
	else
		traveller->type=strdup("int"); //just a byte of data in size

	traveller->struct_Owner=strdup("!"); //just a byte of data in size
	traveller->arrayType=NULL;
	traveller->size=0;
	traveller->next=NULL;
	traveller->referencedValue=NULL;
	traveller->memorySize=4;
}

int isInScope(char* variable, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return TRUE;
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return TRUE;
		traveller=traveller->next;
	}

	return FALSE;
}
//Not sufficent
//This returns the TRUE type of a variable based on a symLink
// Float = float
//typedef float x;
// x = Float. Etc.

char* Get_VarType(char* tokenType)
{
	// printf("poop?\n");
	int hashValue = hash(tokenType); //Get the Hashed Identifier used for TypeDef
	// printf("We good?%d\n",hashValue);
	return referenceTable[hashValue]->type;
}



//Call this to get a Variable assigned Type
char* Get_Var_AssignedType(char* variable, char* currentscope)
{
	int hashValue = hash(currentscope);

	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return Get_VarType(traveller->type);
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return Get_VarType(traveller->type);
		traveller=traveller->next;
	}

	return NULL;
}

//Call this to get a Variable assigned Type
char* Get_Var_Owner(char* variable, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->struct_Owner;
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->struct_Owner;
		traveller=traveller->next;
	}

	return NULL;
}

void Calculate_Offsets()
{
	//For each Table Entry

	//Calculate the sum of the children (each dec = 4)
	//store it in the parent and make sure its a multiple of 8
	node_Scopes* scopeTraveler = scopeList;

	while(scopeTraveler!=NULL)
	{
		//Grab Scope Index
		int scope_Index;
		scope_Index=hash(scopeTraveler->scope_Name);

		int scopeSize=0;
			printf("Scope==%s\n\n", symbolTable[scope_Index]->identifier);
			//Create the Traveller	
			entry_Node* traveller = symbolTable[scope_Index]->next;

			//For each variable check it's size
			int varSize=0;
			while(traveller!=NULL)
			{
				varSize=0;
				//Grab the variables size and the pass the scope.
				//varSize= Get_Var_MemorySize(traveller->identifier,symbolTable[scope_Index]->identifier);
				varSize=referenceTable[hash(traveller->type)]->memorySize;

				//If the variable was already created, varSize >0, otherwise we give it a value
				if(varSize==0)
				{
					if((strcmp(traveller->type,"int")!=0)  &&
					  (strcmp(traveller->type,"char")!=0) &&
 					  (strcmp(traveller->type,"float")!=0)) 
					{
					//For Structs, check all children up to struct
						entry_Node* struct_traveller = symbolTable[scope_Index]->next;
						while(struct_traveller!= traveller)
						{
							//no need for nesting since we cant declare/create structs inside structs
							if((strcmp(traveller->type,"struct")==0)&&
							 (strcmp(struct_traveller->struct_Owner,traveller->identifier)==0)
							)
							{

								int temp=0;
								//temp= Get_Var_MemorySize(struct_traveller->identifier,symbolTable[scope_Index]->identifier);
					
								// printf("%s --VS=%d\n",struct_traveller->identifier,temp);
								
								if(strcmp(struct_traveller->type,"struct")==0)
									temp=referenceTable[hash(struct_traveller->identifier)]->memorySize;
								else
									temp=referenceTable[hash(struct_traveller->type)]->memorySize;
								if(temp==0)
									temp+=4+ struct_traveller->size*4;
	
								varSize+=temp;
								
							}
							struct_traveller=struct_traveller->next;	
						}

					}
					else
					{
						varSize=4+ traveller->size*4;
					}
				//This only works for basic types
				}
				if(strcmp(traveller->type,"struct")==0)
				{
					referenceTable[hash(traveller->identifier)]->memorySize=varSize;	
					referenceTable[hash(traveller->identifier)]->memoryOffset=scopeSize+varSize;	
				}

				scopeSize+=varSize;
				traveller->memoryOffset=scopeSize;
				traveller->memorySize=varSize;
				printf("%s[%s]=%d\n", traveller->identifier,traveller->type, varSize);

				traveller=traveller->next;
			}
			symbolTable[scope_Index]->memorySize=scopeSize;

			//Must be multiple of 8
			if(scopeSize<24)
				scopeSize=24;
			else
			{
				int rem = scopeSize % 8;
				if(rem!=0)
					scopeSize+= 8-rem;
			}
			//Offset is 24 and 8 aligned.
			symbolTable[scope_Index]->memoryOffset=scopeSize;

		scopeTraveler=scopeTraveler->next;
	}

}
int Get_Scope_Offset(char* scope)
{
	int hashValue = hash(scope);
	return symbolTable[hashValue]->memoryOffset;	
}
int Get_Scope_Size(char* scope)
{
	int hashValue = hash(scope);
	return symbolTable[hashValue]->memorySize;
}

//Call this to get a Variable assigned Type
void Create_ReferenceLink(char* temp, char* addressed, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,temp)==0)
		{
			traveller->referencedValue=strdup(addressed);
			return;
		}
		traveller=traveller->next;
	}	
}

char* Get_ReferencedValue(char* temp,char* currentscope )
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,temp)==0)
		{
			return traveller->referencedValue;
		}
		traveller=traveller->next;
	}	
	return NULL;
}
//Call this to get a Variable assigned Type
int Get_Var_MemoryOffset(char* variable, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	// 
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->memoryOffset;
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->memoryOffset;
		traveller=traveller->next;
	}

	//If not found
	// printf("COULDNT FIND Var=%s Scope =%s\n",variable,currentscope);
	return -666;
}




int Get_Var_MemorySize(char* variable, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	// 
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->memorySize;
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			return traveller->memorySize;
		traveller=traveller->next;
	}

	//If not found
	// printf("COULDNT FIND Var=%s Scope =%s\n",variable,currentscope);
	return -666;
}


int doesVar_Belongto_Struct(char* variable, char* structType, char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	traveller=traveller->next;
	//Check Current Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			if (strcmp(traveller->struct_Owner,structType)==0 )
				return TRUE;
		traveller=traveller->next;
	}	
	hashValue = hash("Global");
	traveller = symbolTable[hashValue];
	traveller=traveller->next;
	//Check Global Scope
	while(traveller!=NULL)
	{
		if( strcmp(traveller->identifier,variable)==0)
			if (strcmp(traveller->struct_Owner,structType)==0 )
				return TRUE;
		traveller=traveller->next;
	}

	return FALSE;	
}

char* getScopeType(char* currentscope)
{
	int hashValue = hash(currentscope);
	//Check if variable is in current scope
	entry_Node* traveller = symbolTable[hashValue];

	return traveller->type;
}


void Print_SymbolTable(FILE* fptr)
{
	//Print the Variables
	//Grab the Scope, List all Variables in scope
	node_Scopes* scopeTraveler = scopeList;

	while(scopeTraveler!=NULL)
	{
		//Print the Scope
		fprintf(fptr,"\nScope:[%s]\n",scopeTraveler->scope_Name);
		fprintf(fptr,"Variable\tType\t\tStructOwner\n");
		fprintf(fptr,"--------------------------------\n");
		//Grab Scope Index
		int scope_Index;

		scope_Index=hash(scopeTraveler->scope_Name);

		//Now we can iterate through all declared variables inside this function
		entry_Node* node = symbolTable[scope_Index]->next;

		while(node!=NULL)
		{
			//Print the Variable
			fprintf(fptr,"%s",node->identifier);
			if(strlen(node->identifier)<=7)
				fprintf(fptr,"\t\t");
			else
				fprintf(fptr,"\t" );


			fprintf(fptr,"%s",node->type);
			if(node->size>0)
			{
				fprintf(fptr,"_Ar[%d]",node->size);
				fprintf(fptr,"\t" );
			}
			else
			{
				if(strlen(node->type)<=7)
				fprintf(fptr,"\t\t");
				else
				fprintf(fptr,"\t" );
			}

			
			if( strcmp(node->struct_Owner,"!")==0)
				{
					fprintf(fptr,"None\n");
				}
			else
				{
					fprintf(fptr,"%s",node->struct_Owner);
					fprintf(fptr,"\n");
				}

			node=node->next;
		}

		fprintf(fptr,"================================\n");
		scopeTraveler= scopeTraveler->next;
	}

}


void Free_HashTable()
{
	node_Scopes* scopeTraveler = scopeList;
	node_Scopes* temp;
	//Free ScopeList

	while(scopeTraveler!=NULL)
	{
		temp= scopeTraveler;
		scopeTraveler= scopeTraveler->next;
		free(temp);
	}
	//Free Reference Table
	for(int i=0;i<TABLE_SIZE;i++)
	{
		//printf("i=%d val=%d\n",i, referenceTable[i]->type);
		free(referenceTable[i]);
	}
	// //Free Symbol Table
	for(int i=0;i< TABLE_SIZE;i++)
	{
		//Check if a List exists at this scope.
		if(symbolTable[i]->scopeDefined==TRUE)
		{

			entry_Node* varTraveler = symbolTable[i]->next;
			entry_Node* temp2;
			while(varTraveler!=NULL)
			{
				// if(varTraveler->type!= nt_NONE)
				// 	printf("i=%d val=%d\n",i, referenceTable[i]->type);

				temp2= varTraveler;
				varTraveler= varTraveler->next;
				free(temp2);
			}
			free(symbolTable[i]);
		}

	}


}










