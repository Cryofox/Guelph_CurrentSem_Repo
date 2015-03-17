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




//Struct used for Scopes
typedef struct n
{
	char *identifier;
	node_Type type;

	//Only Used for Arrays
	node_Type arrayType;


	//Used for Structs
	//Variables can be called if they belong to the struct.
	char* struct_Owner;

	//Used for Arrays, and Struct
	int size;

	//To Append to Scope
	struct n * next;


	//Only Used if First Node
	int scopeDefined;
}entry_Node;

//Struct used for TypeDef Linking
typedef struct q
{
	node_Type type;
}node_Typdef;

//Scope can be: Function, or Struct
typedef struct s
{
	char* scope_Name;
	struct s* next;
}node_Scopes;




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
	referenceTable[i]->type=nt_NONE; }

	//Adding the Temp Scope, This is so we can have a place to constantly relocate variables to and from

	currentScope=("0Tmp\0");
	Add_Scope("0Tmp\0"); // Uses Global Variable, so lets set it to True.

	//Add the Basic Types
	Add_TYPEDEF("float\0", 	nt_FLOAT);
	Add_TYPEDEF("int\0", 		nt_INT);
	Add_TYPEDEF("char\0", 	nt_CHAR);	
	Add_TYPEDEF("struct\0", 	nt_STRUCT);
	Add_TYPEDEF("array\0", 	nt_ARRAY);
	//Use 1, as its illegal to start with a numeral in.cb files
	Add_TYPEDEF("1Standby\0", 	nt_STANDBY);	
}

void Link_StructVariables(char* structName)
{
	printf("Linking Structs\n");
	int hashValue = hash("0Tmp");
	//Iterate Untill our illegal Variable
	entry_Node* traveller=symbolTable[hashValue]->next;
	entry_Node* startMarker=traveller;
	//Move Untill we Hist $tart
	printf("Loosy Gosoy\n");
	while( strcmp(traveller->identifier,structName)!=0)
	{
		if(strcmp(traveller->next->identifier,"$TART")==0)
		{	
				printf("Setting SM!\n");
				startMarker=traveller;
		}

		printf("ID:%s\n",traveller->identifier);
		printf("SN:%s\n",structName);		
		traveller=traveller->next;
	}
		//We now have a nested $tart to End for our struct

	//Now our startMarker is set to 1 Prior to $TART

	//First Cleanup

	// printf("Loosy Gosoy2\n");
		//ReLink Variables
		entry_Node* temp= startMarker->next;
	
		printf("SM->Next=%s\n", startMarker->next->identifier);
		startMarker->next= temp->next;
		printf("SM->Next=%s\n", startMarker->next->identifier);
	 	//Free The Illegal Var

	 	printf("Temp:%s\n", temp->identifier);
	 	printf("SM:%s\n", startMarker->identifier);

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
	int hashValue = hash("0Tmp");
	if( symbolTable[hashValue]->scopeDefined == FALSE)
	{
		fprintf(stderr, "\nError: Variable added before Function Scope Defined:%s\n", token_Name);
		exit(1);
	}
	else
	{
	 	entry_Node* traveller=symbolTable[hashValue]->next;
		while(traveller!=NULL)
			traveller=traveller->next;
		//Now we add the Value
		traveller->next= malloc(sizeof(entry_Node));
		traveller=traveller->next;

		//Setup the Variable
		traveller->identifier= strdup(token_Name);
		//Now to Reference it's Type.
		traveller->struct_Owner="!";

		node_Type nt = Get_VarType(type);


		traveller->size=size;

		traveller->type=nt_ARRAY;		
		traveller->arrayType=nt;
		traveller->next=NULL;
		if(nt== nt_NONE)
		{
			fprintf(stderr, "\nError: Unknown Variable:%s\n", token_Name);			
		}
		traveller->scopeDefined=FALSE;

	}
	printf("Variable Added\n");	
}



//This MUST be added to an Existing scope.
//This is called on Variable Decleration
void Add_Variable(char* token_Name, char* type)
{
	printf("Adding Var:%s\n",token_Name);
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
		//Now to Reference it's Type.
		//printf("So far so peachy...\n");
		//printf("Str Peachy:%s\n",type);
		node_Type nt = Get_VarType(type);


		traveller->type=nt;
		traveller->size=1;
		traveller->next=NULL;
		if(nt== nt_NONE)
		{
			fprintf(stderr, "\nError: Unknown Variable:%s\n", token_Name);			
		}
		traveller->scopeDefined=FALSE;
	}
	printf("Variable Added\n");
}
//This MUST be added to an Existing scope.
//This is called on Variable Decleration




//This Function takes all standby variables in this scope and assigns them the new Variable
//This is done due to yacc doing things in reverse >.>
void Set_Type(char* type)
{
	int tmpScope= hash("0Tmp\0");
	//printf("Issue?\n");
	entry_Node* traveller=symbolTable[tmpScope]->next;

	node_Type nt = Get_VarType(type);

	while(traveller!=NULL)
	{
		if(traveller->type==nt_STANDBY)
			traveller->type=nt;
		traveller=traveller->next;
	}
}


//This MUST be added to an Existing function.
void Add_Scope(char* newScope)
{
	printf("Scope=%s\n",newScope);
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
		printf("Adding Variables From:%s \tTo:%s\n",  symbolTable[tmpScope]->identifier, symbolTable[curScope]->identifier);

		//Relocate All Temp Scope Values to the Actual Scope
		//This is done by simple changing Pointers
		entry_Node* tempScope =symbolTable[tmpScope];

		//Link Pointers
		traveller->next= tempScope->next;

		//Remove Pointer Link from Temp
		tempScope->next=NULL;

		traveller->scopeDefined=TRUE;

	}
	printf("Lol\n");
}



//Since all TypeDefs are Global, we can reference these from anywhere.
void Add_TYPEDEF(char* typeDef, node_Type type)
{
//	symbolTable = malloc(sizeof(struct entry_Node)*997);
	int hashValue = hash(typeDef); //Get the Hashed Identifier used for TypeDef


 	node_Typdef* traveller=referenceTable[hashValue];

	//Setup the Variable
	traveller->type= type;
	printf("Added TypeDef:%s %i\n",typeDef, hashValue);
}

node_Type Get_VarType(char* tokenType)
{
	// printf("poop?\n");
	int hashValue = hash( tokenType); //Get the Hashed Identifier used for TypeDef
	// printf("We good?\n");

	return referenceTable[hashValue]->type;
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


	free(word);
	// printf("HA=%d\n", h);
	return(h); 
}



void Print_SymbolTable()
{
	//Print the Variables
	//Grab the Scope, List all Variables in scope
	node_Scopes* scopeTraveler = scopeList;

	while(scopeTraveler!=NULL)
	{
		//Print the Scope
		printf("\nScope:[%s]\n",scopeTraveler->scope_Name);
		printf("Variable\tType\tStructOwner\n");
		printf("--------------------------------\n");
		//Grab Scope Index
		int scope_Index;

		scope_Index=hash(scopeTraveler->scope_Name);

		//Now we can iterate through all declared variables inside this function
		entry_Node* node = symbolTable[scope_Index]->next;

		while(node!=NULL)
		{
			//Print the Variable
			printf("%s\t",node->identifier);

			if(node->type==nt_FLOAT)
				printf("Float\t");
			else if(node->type==nt_INT)
				printf("Int\t");
			else if(node->type==nt_CHAR)
				printf("Char\t");		
			else if(node->type==nt_STRUCT)
				printf("Struct\t");
			else if(node->type==nt_ARRAY)
				printf("Array\t");
			else if(node->type==nt_STANDBY)
				printf("Standby\t");			
			else if(node->type==nt_NONE)
				printf("ERROR:Undefined\t");

			if( strcmp(node->struct_Owner,"!")==0)
				{printf("None\n");}
			else
				{
					printf(node->struct_Owner);
					printf("\n");
				}

			node=node->next;
		}

		printf("================================\n");
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
				if(varTraveler->type!= nt_NONE)
					printf("i=%d val=%d\n",i, referenceTable[i]->type);

				temp2= varTraveler;
				varTraveler= varTraveler->next;
				free(temp2);
			}
			free(symbolTable[i]);
		}

	}


}










