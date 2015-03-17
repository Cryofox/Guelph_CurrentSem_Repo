#ifndef SCANNER
#define SCANNER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//DFA struct
typedef struct 
{
	char token_String[10];
	int token_Length;
	int current_State;
}DFA;


typedef enum { false, true } bool;



//The function that constantly reads till EOL
void Scanner();

//Updates the DFA state based on read char
//Do not pass in space.
void UpdateState(char readToken);

//Destroys Struct
void DestroyDFA();

//Resets the TokenString to null and state to 0
void ResetDFA();
//Creates the Struct
DFA* CreateDFA();

//Used to Call Destroy DFA on ctrl-c quit
void sigintHandler(int sig_num);

	//Initializes DFA
	void InitializeDFA();
	//Increments the Scanner, and returns the token value
	char* Get_NextToken();

	//Helper function for Get_NextToken, reads an entire word updating the DFA as it progresses
	void Read_NextWord();

void ExitRoutine();



#endif