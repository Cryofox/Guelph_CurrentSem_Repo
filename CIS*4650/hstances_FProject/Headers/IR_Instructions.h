#ifndef IR_I
#define IR_I

//An IR Node has 3 Properties
typedef struct irn
{
	char* label; //Every Instruction has a Label Number


	char* op;
	char* leftValue;
	char* rightValue;
	char* result;

	int isIF;
	char* gotoLabel; //IF and For 

	char* scope;

	struct irn* next;
	struct irn* prev;
	int state_Addressed;
}ir_Node;

void InitializeIR_Node();
void IR_Add_Scope(char* scope);
//Add a new instruction to our current list of instructions
int Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label,char*scope);
int Promote_LastIR_IF(char* label);
void Print_IR_Instructions(FILE * fptr);
void Add_GoToLabel(int index, char* gotoLabel);
void Add_Last_Label(char* Label);


void Free_IR_Instructions();


#endif