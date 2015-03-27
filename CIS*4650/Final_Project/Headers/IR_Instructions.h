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
	int isLoop;
	char* gotoLabel; //IF and For      
	struct irn* next;
}ir_Node;

void InitializeIR_Node();

//Add a new instruction to our current list of instructions
int Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label);
int Promote_LastIR_IF(char* label);
void Print_IR_Instructions();
void Add_GoToLabel(int index, char* gotoLabel);
void Add_Last_Label(char* Label);


void Free_IR_Instructions();


#endif