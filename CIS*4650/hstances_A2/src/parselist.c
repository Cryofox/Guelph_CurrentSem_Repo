#include "scanner.h"
#include "parselist.h"



//////////
//Grammar Code
static int errorCount=0;
static bool isParseError= false;



extern int newLineCount;
extern DFA* myDFA;




void ERROR_RECOVERY()
{
	//Set isParseError to True
	isParseError= true;
	errorCount++;
	//Read Untill EOF or ; is read, and Then Continue Parsing
	while(HashString(myDFA->token_String, myDFA->token_Length) != HASHED_SEMICOLON && !feof(stdin))
	{
		Get_NextToken();
	}
}







//Program Entry Point

int main (int argc,char * argv[]) 
{

	ParseMyGrammar();


/*This is where I got the Hash Values for the strings used in #DEFINE
	HashString("SET",3);
	HashString("OCT",3);
	HashString("HEX",3);
	HashString("INT",3);
	HashString("STR",3);
	HashString("CDR",3);
	HashString("CAR",3);	
	HashString("EOF",3);

	HashString("CHAR",4);
	HashString("REAL",4);
	HashString("PLUS",4);	

	HashString("LPAREN",6);
	HashString("RPAREN",6);

	HashString("SEMICOLON",9);	
*/

	return 0;
}	

void ParseMyGrammar()
{
	InitializeDFA();

	Parse_PROG_START();

	ExitRoutine();
}


void Parse_PROG_START()
{
	//Gets the NextToken
	Get_NextToken();

	Parse_STMTS();
	//If after Parse STMTS finishes there is leftover Tokens, a problem occured
	if(HashString(myDFA->token_String, myDFA->token_Length) != HASHED_EOF)
	{
		printf("\nPARSE ERROR OCCURED!  Unknown Token Recieved:[%s]\n", myDFA->token_String);
		ExitRoutine();
	}
}

void Parse_STMTS()
{
	//IF STMNT STMNTS
	if (BelongsTo_STMTS())
	{

		//At this point, the Token belongs somewhere, the question is Where?
		if(BelongsTo_ASSIGN())
		{
			//Call Assign 
			Parse_ASSIGN();

			//Now to check if next token (fromLISTEXPR) is a SemiColon
			if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_SEMICOLON)
			{
				Get_NextToken();
				Parse_STMTS(); //Valid Syntax, Parse Next Set of Instructions
			}
			else
			{
				printf("\nParse Error on Line[%d]: Recieved[%s] Expected ';' \n",newLineCount, myDFA->token_String);
				ERROR_RECOVERY();
				Get_NextToken(); 
				Parse_STMTS(); 
			}
		}

		else if(BelongsTo_LISTEXPR())
		{
			//Call Assign 
			Parse_LISTEXPR();
			//Now to check if next token (fromLISTEXPR) is a SemiColon
			if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_SEMICOLON)
			{
				Get_NextToken();
				Parse_STMTS(); //Valid Syntax, Parse Next Set of Instructions
			}
			else
			{
				printf("\nParse Error on Line[%d]: Recieved[%s] Expected ';' \n",newLineCount, myDFA->token_String);
				ERROR_RECOVERY();
				Get_NextToken(); 
				Parse_STMTS(); 
			}
		}
	}
	else if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_EOF)
		return;
	else
	{
		printf("\nParse Error on Line[%d]: Recieved[%s] Expected 'char','cdr','(', or 'set' \n",newLineCount, myDFA->token_String);
		ERROR_RECOVERY();
		Get_NextToken(); 
		Parse_STMTS(); 
	}
}




void Parse_ASSIGN()
{
	//Due to C Switch Statements Being Stubborn.
	//I created a workaround to allow my desire of 
	//using switch statements on strings


	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);
	switch ( hashed_Token )
	{
		case HASHED_SET:
			//LookAhead 1
			Get_NextToken();
			if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_CHAR)
			{
				Get_NextToken();
				Parse_LISTEXPR(); 
			}
			else
			{
				printf("\nParse Error on Line[%d]: Recieved[%s] Expected 'CHAR' \n",newLineCount, myDFA->token_String);
				ERROR_RECOVERY();
				return;
			}
		break;
		default:
			PARSE_ERROR:
				printf("\nParse Error on Line[%d]: Recieved[%s] Expected 'SET' \n",newLineCount, myDFA->token_String);
				ERROR_RECOVERY();
				return;
		break;
	}



}

void Parse_LISTEXPR()
{
	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);
	switch ( hashed_Token )
	{
		case HASHED_CHAR:
			Get_NextToken();
			//if char +
			if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_PLUS)
			{
				Get_NextToken();
				Parse_LISTEXPR();
			}
			return; 

		case HASHED_CDR:
			Get_NextToken();
			if(BelongsTo_LISTEXPR())
				Parse_LISTEXPR();
			else
			{
				printf("\nParse Error on Line[%d]: Token does not belong in LISTEXPR:[%s] \n",newLineCount, myDFA->token_String);
				ERROR_RECOVERY();
				return;			
			}
			break;
		case HASHED_LPAREN:
			Get_NextToken();

			if(BelongsTo_ITEMS())
			{
				Parse_ITEMS();
				//If  ')'
			}

			//At this point whether the the ITEMS block had contents or not, we expect a RPAREN now.
			if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_RPAREN)
			{
				Get_NextToken();
				//Do we have another + ?
				if(HashString(myDFA->token_String, myDFA->token_Length) == HASHED_PLUS)
				{
					Get_NextToken();
					Parse_LISTEXPR();
				} 					
			}
			else
			{
				printf("\nParse Error on Line[%d]: Recieved[%s] Expected ')' \n",newLineCount, myDFA->token_String);					
				ERROR_RECOVERY();
				return;		
			}
			
			break; 
		default:
			printf("\nParse Error on Line[%d]: Recieved[%s] Expected 'char', 'cdr', or '(' \n",newLineCount, myDFA->token_String);	
			ERROR_RECOVERY();
			return;
	}
}



void Parse_ITEMS()
{
	//Due to C Switch Statements Being Stubborn.
	//I created a workaround to allow my desire of 
	//using switch statements on strings

	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);
	switch ( hashed_Token )
	{
		case HASHED_STR:
		case HASHED_INT:
		case HASHED_REAL:
		case HASHED_OCT:
		case HASHED_HEX:
			//LookAhead One
			Get_NextToken();
			if(BelongsTo_ITEMS())
			{
				Parse_ITEMS();
			}
			else //Possible Empty String
				{
					//printf("Else Return\n");
					return;
				}

		break;

		case HASHED_CAR:
		{
			//LookAhead One
			Get_NextToken();		
			if(BelongsTo_LISTEXPR())
			{
				Parse_LISTEXPR();

				// Look Ahead one for New Item?
				if(BelongsTo_ITEMS())
					Parse_ITEMS();			
			}
			else
			{
					printf("Parse Error on Line[%d]: Recieved[%s] Expected 'char', 'cdr', or '(' \n",newLineCount, myDFA->token_String);	
					ERROR_RECOVERY();
					return;					
			}
		}
		break;
		default:
			//Items has the possibility of having the Empty String, meaning it can't parse error
			//On the Initial Read

			//For CHAR cdr etc
			if(BelongsTo_LISTEXPR())
			{
				Parse_LISTEXPR();

				// Look Ahead one for New Item?
				if(BelongsTo_ITEMS())
					Parse_ITEMS();
			}
			else
			{
					printf("Parse Error on Line[%d]: Recieved[%s] Expected 'char', 'cdr', or '(' \n",newLineCount, myDFA->token_String);	
					ERROR_RECOVERY();
					return;						
			}

			//If its not ITEMS -> LISTEXPR, its possible its just ITEMS -> emptyString
		break;
	}

}



//All Belongs To function utilize the CURRENT token, they do not look ahead one
// on their own.

//Therefore pay close attention to the calling functions to see when 
//Get_NextToken(); and UnGet_NextToken(); are called as those are what are used
//in conjunction with BelongsTo, to look into the future 1.
bool BelongsTo_STMTS()
{
	if(BelongsTo_ASSIGN())
		goto ReturnTrue;
	if(BelongsTo_LISTEXPR())
		goto ReturnTrue;

	ReturnFalse:
	    //printf("[%s] Does Not Belong in STMTS\n", myDFA->token_String);
		return false;

	ReturnTrue:
	    //printf("[%s] Belongs in STMTS\n", myDFA->token_String);
		return true;
}



bool BelongsTo_ASSIGN()
{
	//Check all Item Terminals
	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);

	switch ( hashed_Token )
	{
	//ASSIGN Terminals
		case HASHED_SET:	
			goto ReturnTrue;
	}


	ReturnFalse:
	    //printf("[%s] Does Not Belong in ITEMS\n", myDFA->token_String);
		return false;

	ReturnTrue:
	    //printf("[%s] Belongs in ITEMS\n", myDFA->token_String);
		return true;
}


bool BelongsTo_LISTEXPR()
{
	//Check all Item Terminals
	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);

	switch ( hashed_Token )
	{
	//LISTEXPR Terminals
		case HASHED_LPAREN:	
		case HASHED_CHAR:
		case HASHED_CDR:
			goto ReturnTrue;
	}


	ReturnFalse:
	    //printf("[%s] Does Not Belong in ITEMS\n", myDFA->token_String);
		return false;

	ReturnTrue:
	    //printf("[%s] Belongs in ITEMS\n", myDFA->token_String);
		return true;
}

bool BelongsTo_ITEMS()
{
	//Check all Item Terminals
	int hashed_Token=HashString(myDFA->token_String, myDFA->token_Length);

	switch ( hashed_Token )
	{
	//LISTEXPR Terminals
		case HASHED_LPAREN:	
		case HASHED_CHAR:
		case HASHED_CDR:
	//Item Terminals
		case HASHED_STR:
		case HASHED_INT:
		case HASHED_REAL:
		case HASHED_OCT:
		case HASHED_HEX:
		case HASHED_CAR:
			goto ReturnTrue;
	}


	ReturnFalse:
	    //printf("[%s] Does Not Belong in ITEMS\n", myDFA->token_String);
		return false;

	ReturnTrue:
	    //printf("[%s] Belongs in ITEMS\n", myDFA->token_String);
		return true;
}




//This will create a Numeric Interpretation of the String, useful when using
//switch on strings, as technically that is "forbidden"

//Unfortunatly as C does not have a .count, .length, len(), or anyway to get the size of a string
//it must be stored and passed in this function to prevent out of bounds
int HashString(char* string, int length)
{
//Simply Add the Ascii values to get a strings int value
	int hash=0;
	for(int i=0;i<length;i++)
	{
		hash+= (int) string[i];
	}

	//printf("Hashed[%s]=%d\n",string,hash);
	return hash;
}



//This is Called from Parser BUT it Affects the DFA
void ExitRoutine()
{
	//Clearing Memory Before Program Termination :)
	DestroyDFA();
	printf("\n Parsing Complete, number of Parse Errors [%d] \n",errorCount);
	if(isParseError)
		printf(" Program failed to Compile.\n");
	else
		printf(" Program successfully Compiled.\n");
	exit(0);
}