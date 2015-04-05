CC = gcc

# define any compile-time flags
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
LIBS = -F/System/Library/Frameworks -framework OpenGL -framework GLUT -lm

# define the C source files
SRCS = src/projectile.c src/a1.c src/graphics.c src/visible.c src/clouds.c src/perlin.c src/perlin2.c src/enemy.c

# define the C object files 
OBJS = src/projectile.o src/a1.o src/graphics.o src/visible.o src/clouds.o src/perlin.o src/perlin2.o src/enemy.o

# define the executable file 
MAIN = a1
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

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES)  -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
		@echo  Relocating Obj Files

		mv ./src/a1.o ./obj/
		mv ./src/graphics.o ./obj/
		mv ./src/visible.o ./obj/
		mv ./src/clouds.o ./obj/
		mv ./src/perlin.o ./obj/
		mv ./src/perlin2.o ./obj/
		mv ./src/projectile.o ./obj/
		mv ./src/enemy.o ./obj/
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@





#Delete the OBJ folder, the executable and then remake the obj folder
clean:
		#
		rm -rf *obj *~ $(MAIN)
		mkdir obj
depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it