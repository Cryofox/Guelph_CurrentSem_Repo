

INCLUDES = -F/System/Library/Frameworks -framework OpenGL -framework GLUT -lm

a1: a1.c graphics.c visible.c clouds.c perlin.c perlin2.c graphics.h clouds.h perlin.h
	gcc -w a1.c graphics.c visible.c perlin.c perlin2.c clouds.c -o a1 $(INCLUDES) 

