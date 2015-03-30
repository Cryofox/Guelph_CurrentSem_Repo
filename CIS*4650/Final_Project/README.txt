To Compile: make, make all, make cflatc
To Comp & run: make run
To Clean: make clean

To Draw Graph:
1)./cflatc -a <1.cb
2)dot -Tps ./Tree.abs -o Test.ps 
Doing only step 1 results in code for Graphviz to parse, 
pretty much useless to a human.







The program consists of:
	-a .y file for Yacc, the main file is located inside this .y file.
	-a .l file for flex
	-a .c/h file for the abstract tree data struct itself. 
	-a .c/h file for the Symbol Table.
	-a .c/h file for the TypeChecking.
	-a .c/h file for the IR code generation.   
	-a .c/h file for converting IR code Assembly

1.cb=
	Error Free Beautiful tree
./cflatc -a < 1.cb
	A Lovely Symbol Table with variables in Scopes
	Note: Since IR generation works at same time, all temp values are also
	present in symbol table.
./cflatc -s < 1.cb
	The IR Instruction code
./cflatc -i < 1.cb

	The Assembly, the one to rule them all
	and in the darkness Guide Them
./cflatc -c < 1.cb

	Create ALL the files!
./cflatc -q < 1.cb

2-4 = About 3 Errors










