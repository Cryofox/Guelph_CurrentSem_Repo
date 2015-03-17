Horia "Ryder" Stancescu
hstances - 0721385

To Compile: make, make all, make scanner
To Comp & run: make run
To Clean: make clean

How it works:
	It just converts the DFA to a monolothic sized switch case. When a space is read the dfa prints it's current token if in a "final" state
and resets. States count with start=0, and then Top Left -> Bottom Right in chronological order. Worked on the test cases I provided + the one on the website. Reads till end of input, uses a signal handler to catch ctrl-c and
clear struct so no mem leaks. Typical stuff.


REGEX:
-----------
INT: positive and negative natural numbers, including zero 
REGEX: (-?[0-9]*)

HEX: a hexidecimal integer value (valid numerals are 0-F) with a 0x prefix (e.g. 0x012F) 
REGEX: 0x([0-9][A-F])([0-9][A-F])([0-9][A-F])([0-9][A-F])

OCT: an octal integer value (valid numerals are 0-7) with a 0 prefix (e.g. 0177) 
REGEX:0[0-9][0-9][0-9]

REAL: floating point decimal and exponential notation 
"^" = XOR in C. Do we include this?
Valid Syntax in C: 5.65345e12;
		   5.e12
		   5.
REGEX: (-?[0-9]*)([\.](0-9)*)?([e](0-9)*)?


LPAREN: left parenthesis '(' 
REGEX:(

RPAREN: right parenthesis ')' 
REGEX:)

CAR: the string "car" 
REGEX:car

CDR: the string "cdr" 
REGEX:cdr

CHAR: any other single ASCII character 
#Far too many types of ASCII characters, simpler to say non-whitespace
REGEX:[^ \n\t]

STR: any other sequence of (more than 1) ASCII characters 
REGEX:[^ \n\t][^ \n\t]+
================


