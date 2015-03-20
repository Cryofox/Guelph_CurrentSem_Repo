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
	int gotoLabel;      //If it's an if node we jump to the label we need
	struct irn* next;
}ir_Node;

void InitializeIR_Node();

//Add a new instruction to our current list of instructions
void Add_IR_Instruction(char* leftVal, char* op, char* rightVal, char* result,char* label);

void Print_IR_Instructions();

void Free_IR_Instructions();


#endif