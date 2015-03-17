Horia "Ryder" Stancescu
hstances - 0721385

To Compile: make, make all, make parselist
To Compile & run: make run
To Clean: make clean

 It reads tokens from stdin, and reports errors and upon completion whether or not the grammar will compile. If an error is discovered, it will continue eating tokens untill a semicolon is matched but it will report the problem as soon as it occurs. Thereby if you are entering sequences of tokens manually and see a parse error, unless you also ended the line where the error was reported with a semicolon it is silently eating tokens waiting for a semicolon or EOF, so it can continue analyzing the next set of instructions.

( hello ) 

hey   
 	##Parse Error Message, str outside of ( ) 
cdr a         ## It is ignoring this prompt as a semicolon wasn't read
; hey 		## It read the semicolon and is parsing this line,
		## str can't exist outside ( ) therefore
  	##Parse Error Message, eating tokens till semicolon is read again.

EOF
 # Print Parse Results



How it works:
	Belongs_To is used to check if a token belongs to an expression, if it does
 	the expression's associated Parse function is called, this is done untill EOF is read printing parse
	errors as they occur with a final message on completion with a total number of errors and whether or
	not the program will compile, a single error will result in a failed compilation. 

	The code is documented, and in areas where they aren't the Function calls should be intuitive as they are named
	based on what they accomplish. PARSE_ASSIGN, parses the assign expression, BELONGSTO_ITEM, checks if the current token
 	would transition to the ITEM expression ie if it belongs to it.

 	The Current token is stored in the dfa that was used in A1, a quick mod was implemented to allow for the
	new 'set', '+', and ';' tokens. 


	Since I wanted to use switch statements on strings but C for obvious reasons was not letting me I created a 
	hash function which returns a numerical expression of a string passed into it, ran this algorithm ahead of time
	stored the results as macros, and used these macros against the hashed(token) within every switch.

	The Go To statements were only used to provide a neat and tidy place to store extra return True/ False 
	instructions without copy pasting, for the sake of this assignment all gotos could be replaced with an actual
	return true/false and the program would function the same...but it would look ugly, and it's less fun 
	(it's not every place you can put a go-to without looking like a novice).

	



//Bellow a more detailed breakdown of How I converted the grammar for Q1 of the
assignment. It's listed in my report but below was me doing it step by step for the first
time and my thought process along the way. Basically everything below
this line 'v' is thought process and yammering and is not needed in anyway.
--------------------------------------------------------------------------------------

Terminal symbols in this grammar are: char int real str car cdr ( ) set + ;

Grammer Provided:

#STMTS Sequence
	STMTS -> STMTS STMT | STMT
	STMT -> ASSIGN ;
	STMT -> LISTEXPR ;
#ASSIGN Sequence
	ASSIGN -> set VAR LISTEXPR
	VAR -> char
#LISTEXPR Sequence
	LISTEXPR -> VAR
	LISTEXPR -> cdr LISTEXPR
	LISTEXPR -> ( ITEMS )
	LISTEXPR -> CONCAT
	CONCAT -> LISTEXPR + LISTEXPR
#ITEMS Sequence
	ITEMS -> ITEMS ITEM | ITEM
	ITEM -> LISTEXPR
	ITEM -> str | int | real
	ITEM -> car LISTEXPR
	ITEM ->

===========================

The problem is it relies on the wrong type of recursion (Left), need to modify to use
Right Recursion to produce correct Results.

Start from the sequence which has the least amount of reliance, and work from there
to produce a Grammar in an efficient manner.

Therefore Assign Sequence:

#ASSIGN Sequence Rewrite
	ASSIGN -> set char LISTEXPR

Assign already uses left recursion, however VAL terminates to char, therefore it is unneeded
to have the non-terminal rule, it is removed.

Items Sequence is next:

#ITEMS Sequence rewrite

	ITEMS -> ITEM ITEMS
	ITEMS -> 

	ITEM -> str | int | real 
	ITEM -> LISTEXPR
	ITEM -> car LISTEXPR


To Fix this grammar simply relocate the Empty string so a terminal is followed by a nonterminal
and that nonterminal can equate to nothing. This forces the predict 1 to determine whether or not
the next iteration is eithor a non-null terminal thereby appened nonterminal, or null, in which case we are done.

Next is LIST EXPR:



#LISTEXPR Sequence
	LISTEXPR -> LISTEXPR_T + LISTEXPR
	LISTEXPR -> LISTEXPR_T

	LISTEXPR_T -> char | cdr LISTEXPR
	LISTEXPR_T -> ( ITEMS )




To Fix this similar to before, append a null character to the "root" of this sequence LISTEXPR,
then modify so it eithor calls null, or terminals followed by itself.
CONCAT is a pointless rule so it was removed as :
	LEXPR -> CONCAT  
	CONCAT -> LEXPR + LEXPR 
is the same as:
	LEXPR -> LEXPR +LEXPR


Finally STMNTS

#STMTS Sequence
	STMTS -> STMT STMTS
	STMTS -> 
	STMT -> ASSIGN ;
	STMT -> LISTEXPR ;	 




The Final Grammar is:
Modified with OCT and HEX from A1

	#PROG_START, where EOF is end of file
		S -> STMTS EOF

	#STMTS Sequence
		STMTS -> STMT STMTS
		STMTS -> STMT

		STMT -> ASSIGN ;   //This does not Need to be altered because ASSIGN is not Left Recursed
		STMT -> LISTEXPR ; //This does not Need to be altered because LISTEXPR it not left recursed
	#ASSIGN 
		ASSIGN -> set char LISTEXPR

	#LISTEXPR Sequence
		LISTEXPR -> LISTEXPR_T + LISTEXPR
		LISTEXPR -> LISTEXPR_T

		LISTEXPR_T -> char 
		LISTEXPR_T -> cdr LISTEXPR
		LISTEXPR_T -> ( ITEMS )

	#ITEMS
		ITEMS -> ITEM ITEMS
		ITEMS -> 

		ITEM -> str | int | real | oct | hex
		ITEM -> LISTEXPR
		ITEM -> car LISTEXPR



