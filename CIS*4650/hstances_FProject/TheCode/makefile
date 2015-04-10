CC = gcc

# define any compile-time flags
#c99 used so I can use inline forloop declarations. pav1
CFLAGS = -g -w -std=c99 

# define any directories containing header files other than /usr/include
#
INCLUDES = -IHeaders

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = 


# define the C source files
SRCS = src/lex.yy.c src/y.tab.c src/AbstractTree.c src/SymbolTable.c src/TypeCheck.c src/IR_Instructions.c src/Assembler.c

LEX = src/Translater.l
YACC= src/Parser.y
# define the C object files 
OBJS = src/scanner.o 

# define the executable file 
MAIN = cflatc
HEADERS = 
#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#





#This is what allows Make "name" to work.
all:    $(MAIN)		

run: $(MAIN)	
	@echo Program Launched:
	./$(MAIN)


$(MAIN): clean
#Create Lex.yy.c
		flex $(LEX)
#Create y.tab.h and y.tab.c
		yacc -d $(YACC)

		mv lex.yy.c ./src/
		mv y.tab.c ./src/
		mv y.tab.h ./Headers

		$(CC) $(CFLAGS)	$(SRCS) $(INCLUDES) -o $(MAIN)	



		#$(CC) $(CFLAGS) $(INCLUDES)  -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
		@echo  Relocating Obj Files


		#mv ./src/scanner.o ./obj/
		#mv ./src/parselist.o ./obj/
		







#Delete the OBJ folder, the executable and then remake the obj folder
clean:
		#
		rm -rf *obj *~ $(MAIN)
		mkdir obj



# DO NOT DELETE THIS LINE -- make depend needs it