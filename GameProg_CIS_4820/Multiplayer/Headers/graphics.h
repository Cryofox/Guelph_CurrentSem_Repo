#ifndef GRAPHICS
#define GRAPHICS

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

        /* world size and storage array */
#define WORLDX 100
#define WORLDY 50
#define WORLDZ 100
GLubyte  world[WORLDX][WORLDY][WORLDZ];

#define MAX_DISPLAY_LIST 500000
#define MOB_COUNT 20
#define PLAYER_COUNT 10



   /* create player with identifier "number" at x,y,z with */
   /* heading of rotx, roty, rotz */
void createPlayer(int number, float x, float y, float z, float playerroty);

   /* move player to a new position xyz with rotation rotx,roty,rotz */
void setPlayerPosition(int number, float x, float y, float z, float playerroty);

   /* turn off drawing for player number */
void hidePlayer(int number);


   /* turn on drawing for player number */
void showPlayer(int number);

   /* mob control functions */
   /* set all mob location, rotation, and visibility values to zero */
void initMobArray();

   /* create mob with identifier "number" at x,y,z with */
   /* heading of rotx, roty, rotz */
void createMob(int number, float x, float y, float z, float mobroty);

   /* move mob to a new position xyz with rotation rotx,roty,rotz */
void setMobPosition(int number, float x, float y, float z, float mobroty);

   /* turn off drawing for mob number */
void hideMob(int number);

   /* turn on drawing for mob number */
void showMob(int number);

   /* allows user to set position of the light */
void setLightPosition(GLfloat x, GLfloat y, GLfloat z);

   /* returns current position of the light */
GLfloat* getLightPosition();

   /* functions store and return the current location of the viewpoint */
void getViewPosition(float *x, float *y, float *z);


void setViewPosition(float x, float y, float z);

   /* returns the previous location of the viewpoint */
void getOldViewPosition(float *x, float *y, float *z);

   /* returns the current orientation of the viewpoint */
void getViewOrientation(float *xaxis, float *yaxis, float *zaxis);

        /* add the cube at world[x][y][z] to the display list and */
        /* increment displayCount */
int addDisplayList(int x, int y, int z);

/*  Initialize material property and light source.  */
void init (void);

   /* draw cube in world[i][j][k] */
void drawCube(int i, int j, int k);

   /* called each time the world is redrawn */
void display (void);

   /* sets viewport information */
void reshape(int w, int h);

   /* respond to keyboard events */
void keyboard(unsigned char key, int x, int y);

   /* load a texture from a file */
   /* not currently used */
void loadTexture();

void motion(int x, int y) ;

   /* initilize graphics information and mob data structure */
void graphicsInit(int *argc, char **argv);


  /* functions draw 2D images */
void  draw2Dline(int, int, int, int, int);
void  draw2Dbox(int, int, int, int);
void  draw2Dtriangle(int, int, int, int, int, int);
void  set2Dcolour(float []);

#endif