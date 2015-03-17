CC = gcc

# define any compile-time flags
#c99 used so I can use inline forloop declarations. pav1
CFLAGS = -w -std=c99 

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
SRCS = src/scanner.c src/lex.yy.c

LEX = src/Translater.l
# define the C object files 
OBJS = src/scanner.o src/lex.yy.o

# define the executable file 
MAIN = parselist
HEADERS = 
#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean




#This is what allows Make scanner to work.
all:    $(MAIN)		

run: $(MAIN)	
	@echo Program Launched:
	./$(MAIN)


$(MAIN):
#Create Lex.yy.c
		echo Stuff
		$(CC) $(CFLAGS) $(INCLUDES)  -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
		@echo  Relocating Obj Files

		mv ./src/scanner.o ./obj/
		mv ./src/parselist.o ./obj/
		
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
		echo Stuff
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@





#Delete the OBJ folder, the executable and then remake the obj folder
clean:
		#
		rm -rf *obj *~ $(MAIN)
		mkdir obj

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it