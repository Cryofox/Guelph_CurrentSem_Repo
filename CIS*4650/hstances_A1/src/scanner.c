#include "scanner.h"



//State
//For Clarity, The States in the Monolothic Switch are named after the
//state provided in the Diagram. The start state =0, the rest are ordered
//0->N, from the Top Leftmost state in the diagram to the bottom rightmost,
//in left right order. So just read the states from top left L->R, as if it was a 
//book and the number you get should equate to the state in the switch. 
//The case "states" are also labelled to help out.




//Global DFA for Signal to be able to Destroy
DFA* myDFA;

//Catch Ctrl-C
void sigintHandler(int sig_num)
{
	//Clearing Memory Before Program Termination :)
	DestroyDFA();

	exit(0);
}








//Program Entry Point
int main (int argc,char * argv[]) 
{
	float test= 1.e4;

	Scanner();
	return 0;
}	


	void Scanner()
	{

		char lineReader[BUFFER_SIZE];
		int wordSize = 0;
		myDFA = CreateDFA();
		ResetDFA();
		signal(SIGINT, sigintHandler);
		while(fgets(lineReader, BUFFER_SIZE, stdin)!=NULL)
		{

			//printf("Text=%s \n", lineReader);
			//Pass Chars into the DFA 1 by 1
			printf("Tokens= ");
			for(int i=0;i< BUFFER_SIZE;i++)
			{
				//"Read Untill a zero is read"
				if(lineReader[i]==0)
				{
					//printf("LR[%d]==%c\n",wordSize,lineReader[i]);
					//printf("Zero is read at:%d\n",i);	
					break;
				}
				//If not at the end
				// /n should not be read due to fgets nature. However just for safety:)
				else if(lineReader[i]==' ' || lineReader[i]=='\t' || lineReader[i]=='\n')
				{
					//printf("Word Done, Reset DFA.");
					//Print DFA State
					printf("%s ", myDFA->token_String);
					ResetDFA();
				}
				else
				{
					//Process our DFA. Feed it CAPS for alphanumeric
					//printf("Char=%c ",toupper(lineReader[i]));
					UpdateState(toupper(lineReader[i]));
				}
			}
			printf("\n");

			//Reset LineReader
			memset(lineReader,0,BUFFER_SIZE);
		}
		DestroyDFA(myDFA);


	}

DFA* CreateDFA()
{
	DFA* temp = malloc(sizeof(DFA));
	return temp;
}
void ResetDFA()
{
	myDFA->current_State=0;
	memset(myDFA->token_String,0,10);
}

void DestroyDFA()
{
	free(myDFA);
}

void UpdateState(char readToken)
{
	//Check State we are in
	int state= myDFA->current_State;

	//Monolothic Switch
	switch(state){

	//State:Start
	case 0:
		if(readToken=='C')
		{
			myDFA->current_State=3;
			strcpy(myDFA->token_String,"CHAR");
		}
		else if(readToken=='-')
		{
			myDFA->current_State=10;
			strcpy(myDFA->token_String,"CHAR");
		}
		else if(readToken=='.')
		{
			myDFA->current_State=14;
			strcpy(myDFA->token_String,"CHAR");
		}	
		//Catch the 0 before digits
		else if(readToken=='0')
		{
			myDFA->current_State=16;
			strcpy(myDFA->token_String,"OCT");
		}

		else if(isdigit(readToken))
		{
			myDFA->current_State=11;
			strcpy(myDFA->token_String,"INT");
		}	

		else if(readToken=='(')
		{
			myDFA->current_State=7;
			strcpy(myDFA->token_String,"LPAREN");
		}
		else if(readToken==')')
		{
			myDFA->current_State=8;
			strcpy(myDFA->token_String,"RPAREN");
		}	
		//Otherwise Default Char
		else 
		{
			myDFA->current_State=9;
			strcpy(myDFA->token_String,"CHAR");
		}
	break;


	//State:STR (CD)
	case 1:
		if(readToken=='R')
		{
			myDFA->current_State=2;
			strcpy(myDFA->token_String,"CDR");
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;

	//State:CDR 
	case 2:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
	break;

	//State:Char (C)
	case 3:
		if(readToken=='D'){
			myDFA->current_State=1;
			strcpy(myDFA->token_String,"STR");
		}
		else if(readToken=='A')
		{
			myDFA->current_State=4;
			strcpy(myDFA->token_String,"STR");
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;

	//State:STR (CA)
	case 4:
		if(readToken=='R')
		{
			myDFA->current_State=5;
			strcpy(myDFA->token_String,"CAR");
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;

	//State:CAR 
	case 5:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
	break;

	//State:STR dump state 
	case 6:
		//Already set to this state, already set to STR
		//basically do nothing here. :)
	break;	

	//State: (
	case 7:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
	break;

	//State: )
	case 8:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
	break;

	//State: default char
	case 9:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
	break;

	//State: Char (-)
	case 10:
		if(isdigit(readToken))
		{
			myDFA->current_State=11;
			strcpy(myDFA->token_String,"INT");
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;	

	//State: Int
	case 11:
		if(isdigit(readToken))
		{}
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");			
		}	
		else if(readToken=='.')
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");			
		}			
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;	

	//State: STR (Real potential:e)
	case 12:
		if(isdigit(readToken))
		{
			myDFA->current_State=13;
			strcpy(myDFA->token_String,"REAL");				
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}	
	break;	

	//State: Real [post e]
	case 13:
		if(isdigit(readToken))
		{}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}		
	break;	

	//State: Char (.)
	//This is incase a string such as . is entered.
	//  .e43 is not a valid float.
	case 14:
		if(isdigit(readToken))
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}	
	break;

	//State: Real [post period. no e]
	case 15:
		if(isdigit(readToken))
		{}
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");			
		}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}		
	break;	

	//State: OCT (initial, only 0 read)
	case 16:
		if(isdigit(readToken))
		{
			//0-7 Range ==Oct
			if(readToken >= '0' && readToken <='7')
			{
				myDFA->current_State=17;
				strcpy(myDFA->token_String,"OCT");					
			}
			else
			{
				myDFA->current_State=11;
				strcpy(myDFA->token_String,"INT");					
			}

		}
		else if(readToken=='.')
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");			
		}		
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");			
		}	

		else if(readToken=='X')
		{
			myDFA->current_State=18;
			strcpy(myDFA->token_String,"HEX");			
		}			
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}		
	break;	

	//State: OCT (Not Initial)
	case 17:
		if(isdigit(readToken))
		{
			if(readToken == '8' || readToken =='9')
			{
				myDFA->current_State=11;
				strcpy(myDFA->token_String,"INT");					
			}
		}
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");			
		}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;	

	//State: HEX
	case 18:
		if(isdigit(readToken))
		{}
		else if(readToken>='A' && readToken<='F')
		{}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");			
		}
	break;		
	}







}



