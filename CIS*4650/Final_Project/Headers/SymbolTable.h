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

	int memoryOffset;
	int memorySize;
	//Only Used if First Node
	int scopeDefined;

	//This only used by temps during Instructions so we can re-assign values where they belong
	char* referencedValue;
}entry_Node;

//Struct used for TypeDef Linking
typedef struct q
{
	//Types are Strings because structs >.>
	char* structReference;
	char* type;

	int memoryOffset;
	int memorySize;	
	
	int size; //Used for Arrays
}node_Typdef;

//Scope can be: Function, or Struct
typedef struct s
{
	char* scope_Name;
	struct s* next;
}node_Scopes;
void Print_SymbolTable(FILE* fptr);

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
int Get_Var_MemorySize(char* variable, char* currentscope);
int Get_Var_MemoryOffset(char* variable, char* currentscope);
char* Get_Var_AssignedType(char* variable, char* currentscope);

int doesVar_Belongto_Struct(char* variable, char* structType, char* currentscope);
char* getScopeType(char* scope);
int isInScope(char* variable, char* currentscope);
void CalculateOffsets();
int Get_Scope_Offset(char* scope);
int Get_Scope_Size(char* scope);
void Add_TempSym(char * tag,char* type, char*scope);
char* Get_ReferencedValue(char* temp,char* currentscope );
#endif