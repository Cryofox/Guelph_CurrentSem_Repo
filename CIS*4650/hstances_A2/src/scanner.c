#include "scanner.h"
#include "parselist.h"


//State
//For Clarity, The States in the Monolothic Switch are named after the
//state provided in the Diagram. The start state =0, the rest are ordered
//0->N, from the Top Leftmost state in the diagram to the bottom rightmost,
//in left right order. So just read the states from top left L->R, as if it was a 
//book and the number you get should equate to the state in the switch. 
//The case "states" are also labelled to help out.

//Global DFA for Signal to be able to Destroy
DFA* myDFA;

int newLineCount=0;




//Catch Ctrl-C
void sigintHandler(int sig_num)
{
	ExitRoutine();
}

	//Initializes DFA
	void InitializeDFA()
	{
		myDFA = CreateDFA();
		ResetDFA();
		signal(SIGINT, sigintHandler);
	}

	//Increments the Scanner, and returns the token value
	char* Get_NextToken()
	{
		Read_NextWord();
		//printf("Get Next Token=%s\n", myDFA->token_String);
		return myDFA->token_String;
	}


	//Helper function for Get_NextToken, reads an entire word updating the DFA as it progresses
	void Read_NextWord()
	{
	char c=' ';
	ResetDFA();
		c=fgetc(stdin);
		//Read Untill a non-space
		while( (c ==' ' || c=='\t' || c=='\n') && !feof(stdin))
		{
			//Increment if NewLine
			if(c=='\n')
				newLineCount++;

			//printf("White space read\n");
			c=fgetc(stdin);
		}


		// Now that we are aligned on an ascii, keep reading untill whitespace
		while( c !=' ' && c!='\t' && c!='\n' && !feof(stdin))
		{
			//printf("Updating State \n");
			UpdateState(toupper(c));
			c=fgetc(stdin);
		}
		//Increment if NewLine
		if(c=='\n')
			newLineCount++;


		if(feof(stdin))
		{
			//Pass EOF to Parser
			strcpy(myDFA->token_String,"EOF");
			//printf(" EOF \n");		
		}

	}

//Create STruct
DFA* CreateDFA()
{
	DFA* temp = malloc(sizeof(DFA));
	return temp;
}
//DFA Reset to state 0
void ResetDFA()
{
	myDFA->current_State=0;
	memset(myDFA->token_String,0,10);
}

//MEM Clean
void DestroyDFA()
{
	free(myDFA);
}

// Monolothic State handler for DFA
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
			myDFA->token_Length=4;
		}
		else if(readToken=='-')
		{
			myDFA->current_State=10;
			strcpy(myDFA->token_String,"CHAR");
			myDFA->token_Length=4;
		}
		else if(readToken=='S')
		{
			myDFA->current_State=19;
			strcpy(myDFA->token_String,"CHAR");
			myDFA->token_Length=4;
		}
		else if(readToken=='.')
		{
			myDFA->current_State=14;
			strcpy(myDFA->token_String,"CHAR");
			myDFA->token_Length=4;
		}	
		//Catch the 0 before digits
		else if(readToken=='0')
		{
			myDFA->current_State=16;
			strcpy(myDFA->token_String,"INT");
			myDFA->token_Length=3;
		}

		else if(isdigit(readToken))
		{
			myDFA->current_State=11;
			strcpy(myDFA->token_String,"INT");
			myDFA->token_Length=3;
		}	

		else if(readToken=='(')
		{
			myDFA->current_State=7;
			strcpy(myDFA->token_String,"LPAREN");
			myDFA->token_Length=6;
		}
		else if(readToken==')')
		{
			myDFA->current_State=8;
			strcpy(myDFA->token_String,"RPAREN");
			myDFA->token_Length=6;
		}	
		else if(readToken==';')
		{
			myDFA->current_State=22;
			strcpy(myDFA->token_String,"SEMICOLON");
			myDFA->token_Length=9;
		}		

		else if(readToken=='+')
		{
			//Go to same space as - char
			myDFA->current_State=43;
			strcpy(myDFA->token_String,"PLUS");
			myDFA->token_Length=4;
		}			
		//Otherwise Default Char
		else 
		{
			myDFA->current_State=9;
			strcpy(myDFA->token_String,"CHAR");
			myDFA->token_Length=4;
		}
	break;

	//+, just a  +
	case 43:
		//Catch the 0 before digits
		if(readToken=='0')
		{
			myDFA->current_State=16;
			strcpy(myDFA->token_String,"INT");
			myDFA->token_Length=3;
		}
		else if(isdigit(readToken))
		{
			myDFA->current_State=11;
			strcpy(myDFA->token_String,"INT");
			myDFA->token_Length=3;
		}
		//Otherwise Dump String
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}

	break;


	//State:STR (CD)
	case 1:
		if(readToken=='R')
		{
			myDFA->current_State=2;
			strcpy(myDFA->token_String,"CDR");
			myDFA->token_Length=3;
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}
	break;

	//State:CDR 
	case 2:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
	break;

	//State:Char (C)
	case 3:
		if(readToken=='D'){
			myDFA->current_State=1;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;
		}
		else if(readToken=='A')
		{
			myDFA->current_State=4;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
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
			myDFA->token_Length=3;			
		}
	break;

	//State:CAR 
	case 5:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
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
		myDFA->token_Length=3;
	break;

	//State: )
	case 8:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
	break;

	//State: default char
	case 9:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
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
			myDFA->token_Length=3;			
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
			myDFA->token_Length=3;			
		}	
		else if(readToken=='.')
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");
			myDFA->token_Length=4;			
		}			
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}
	break;	

	//State: STR (Real potential:e)
	case 12:
		if(isdigit(readToken))
		{
			myDFA->current_State=13;
			strcpy(myDFA->token_String,"REAL");	
			myDFA->token_Length=4;			
		}
		else if(readToken=='+' || readToken=='-')
		{
			myDFA->current_State=42;
			strcpy(myDFA->token_String,"STR");	
			myDFA->token_Length=3;	
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}	
	break;

	//STR +-  for numE +- Num
	case 42:
		if(isdigit(readToken))
		{
			myDFA->current_State=13;
			strcpy(myDFA->token_String,"REAL");	
			myDFA->token_Length=4;			
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
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
			myDFA->token_Length=3;			
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
			myDFA->token_Length=4;
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
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
			myDFA->token_Length=3;			
		}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}		
	break;	

	//State: INT (initial, only 0 read)
	case 16:
		if(isdigit(readToken))
		{
			//0-7 Range ==Oct
			if(readToken >= '0' && readToken <='7')
			{
				myDFA->current_State=17;
				strcpy(myDFA->token_String,"OCT");
				myDFA->token_Length=3;					
			}
			else
			{
				myDFA->current_State=11;
				strcpy(myDFA->token_String,"INT");
				myDFA->token_Length=3;					
			}

		}
		else if(readToken=='.')
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");
			myDFA->token_Length=4;			
		}		
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");	
			myDFA->token_Length=3;		
		}	

		else if(readToken=='X')
		{
			myDFA->current_State=41;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}			
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}		
	break;	

	//STR Pre-Hex
	case 41:
		if(isdigit(readToken) || (readToken>='A' && readToken<='F'))
		{
			myDFA->current_State=18;
			strcpy(myDFA->token_String,"HEX");
			myDFA->token_Length=3;		
		}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;				
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
				myDFA->token_Length=3;					
			}
		}
		else if(readToken=='E')
		{
			myDFA->current_State=12;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}	
		else if(readToken=='.')
		{
			myDFA->current_State=15;
			strcpy(myDFA->token_String,"REAL");
			myDFA->token_Length=4;			
		}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}
	break;	

	//State: HEX 0x Numbers

	case 18:
		if(isdigit(readToken))
		{}
		else if(readToken>='A' && readToken<='F')
		{}	
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");	
			myDFA->token_Length=3;		
		}
	break;		


	//State:Char (S)
	case 19:
		if(readToken=='E')
		{
			myDFA->current_State=20;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}
	break;

	//State:Char (SE)
	case 20:
		if(readToken=='T')
		{
			myDFA->current_State=21;
			strcpy(myDFA->token_String,"SET");
			myDFA->token_Length=3;
		}
		else
		{
			myDFA->current_State=6;
			strcpy(myDFA->token_String,"STR");
			myDFA->token_Length=3;			
		}
	break;

	//State:SET
	case 21:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
	break;

	//State: ;
	case 22:
		myDFA->current_State=6;
		strcpy(myDFA->token_String,"STR");
		myDFA->token_Length=3;
	break;
	

	}	

}


