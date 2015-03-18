#ifndef SYMBTABLE
#define SYMBTABLE

typedef enum { nt_STRUCT, nt_FLOAT, nt_INT, nt_CHAR, nt_ARRAY, nt_FUNCTION, nt_NONE, nt_STANDBY} node_Type;

//Struct used for Scopes
typedef struct n
{
	char *identifier;
	char* type;

	//Only Used for Arrays
	char* arrayType;


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
	//Types are Strings because structs >.>
	char* structReference;
	char* type;
	int size; //Used for Arrays
}node_Typdef;

//Scope can be: Function, or Struct
typedef struct s
{
	char* scope_Name;
	struct s* next;
}node_Scopes;

void Set_Type(char* type);
unsigned int hash();
void Initialize_HashTable();
void Add_Variable(char* token_Name, char* type);
void Link_StructVariables(char* structName);
void Add_TYPEDEF_Array(char* typeDef,  char*type, int size);
void Add_Array(char* token_Name, char* type, int size);
void Add_Scope(char* newScope,char* type);
void Add_TYPEDEF(char* typeDef,  char*type);
char* Get_VarType(char* tokenType);
void Free_HashTable();
void Add_TYPEDEF_Struct(char* typeDef,char* structLink, char* type);
void Set_TypeDefs(char* type);



int isInScope(char* variable, char* currentscope);
#endif