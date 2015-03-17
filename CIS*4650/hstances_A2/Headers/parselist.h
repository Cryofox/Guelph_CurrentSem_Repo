#ifndef PARSELIST
#define PARSELIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>




//Grammar

//This is just a Wrapper Function to engage the Parseing
//This just call Parse_Prog_Start
void ParseMyGrammar();

//The parse logic to start the entire process
// S -> SMTS EOF
void Parse_PROG_START();

//This will parse the statement as eithor Assign or ListExpr
// followed by awaiting further STMTS, it does so by using the Belongs
//to functions.
// STMTS -> STMT STMTS
// STMT  -> ASSIGN | LISTEXPR
void Parse_STMTS();

//This Continues the Parsing Logic above, but specific to ASSIGN
//ASSIGN -> set char LISTEXPR
void Parse_ASSIGN();


//This Continues the Parsing Logic above, but specific to LISTEXPR
//LISTEXPR   -> LISTEXPR_T LISTEXPR
//LISTEXPR_T -> char | cdr LISTEXPR | ( ITEMS )
void Parse_LISTEXPR();

//This Continues the Parsing Logic above, but specific to ITEMS
//ITEMS -> ITEM ITEMS | e 
//ITEM  -> str | int | real | oct | hex | LISTEXPR | car LISTEXPR
void Parse_LISTEXPR();


//These functions compute the follow sets for each STMTS
//and returns TRUE if the Current_Token matches a token the function is expecting
bool BelongsTo_STMTS();
bool BelongsTo_ASSIGN();
bool BelongsTo_ITEMS();
bool BelongsTo_LISTEXPR();


//This function eats untill semicolons and increments the error count
void ERROR_RECOVERY();


//This will create a Numeric Interpretation of the String, useful when using
//switch on strings, as technically that is "forbidden"

//Unfortunatly as C does not have a .count, .length, len(), or anyway to get the size of a string
//it must be stored and passed in this function to prevent out of bounds
int HashString(char* string, int length);


//Macros For Switch Case String Comparisons, these were manually calculated via calling HASHString
//ahead of time.
#define HASHED_SET 236
#define HASHED_OCT 230
#define HASHED_HEX 229
#define HASHED_INT 235
#define HASHED_STR 249
#define HASHED_CDR 217
#define HASHED_EOF 218
#define HASHED_CAR 214
#define HASHED_CHAR 286
#define HASHED_REAL 292
#define HASHED_PLUS 324

#define HASHED_LPAREN 450
#define HASHED_RPAREN 456

#define HASHED_SEMICOLON 681





#endif