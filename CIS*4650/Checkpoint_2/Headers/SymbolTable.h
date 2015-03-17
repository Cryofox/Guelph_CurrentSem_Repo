#ifndef SYMBTABLE
#define SYMBTABLE
typedef enum { nt_STRUCT, nt_FLOAT, nt_INT, nt_CHAR, nt_ARRAY, nt_FUNCTION, nt_NONE, nt_STANDBY} node_Type;
void Set_Type(char* type);
unsigned int hash();
void Initialize_HashTable();
void Add_Variable(char* token_Name, char* type);
void Link_StructVariables(char* structName);

void Add_Array(char* token_Name, char* type, int size);
void Add_Scope(char* newScope);
void Add_TYPEDEF(char* typeDef, node_Type type);
node_Type Get_VarType(char* tokenType);
void Free_HashTable();
#endif