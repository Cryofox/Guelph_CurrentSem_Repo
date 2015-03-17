To Compile: make, make all, make cflatc
To Comp & run: make run
To Clean: make clean


Note: \n and \0 Are working and implemented, however due to their
characteristics they do affect the tree in a funny way.
Chars in the tree are represented as 'char' where char is the ascii char.
However with \0 we get '  due to the string being terminated early.
and with \n we get '
'  because of the newline. 


Only thing not implemented are If's, loops, and function CALLS. Function blocks
are parseable and required if statements/expressions are to be evaluated.
For the sake of the program I used the term expression to refer to a statement in
the grammar.



The program consists of:
	-a .y file for Yacc, the main file is located inside this .y file.
	-a .l file for flex
	-a .c/h file for the abstract tree data struct itself. 




1 = Error Free Beautiful tree
./cflatc -a < 1.cb
./cflatc -c < 1.cb

2-4 = About 3 Errors










