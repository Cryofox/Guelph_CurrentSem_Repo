
/* Derived from scene.c in the The OpenGL Programming Guide */
/* Keyboard and mouse rotation taken from Swiftless Tutorials #23 Part 2 */
/* http://www.swiftless.com/tutorials/opengl/camera2.html */

/* Frames per second code taken from : */
/* http://www.lighthouse3d.com/opengl/glut/index.php?fps */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "clouds.h"
#include "graphics.h"
#include "perlin.h"

	/* initialize graphics library */
extern void graphicsInit(int *, char **);

	/* lighting control */
extern void setLightPosition(GLfloat, GLfloat, GLfloat);
extern GLfloat* getLightPosition();

	/* viewpoint control */
extern void setViewPosition(float, float, float);
extern void getViewPosition(float *, float *, float *);
extern void getOldViewPosition(float *, float *, float *);
extern void getViewOrientation(float *, float *, float *);

	/* add cube to display list so it will be drawn */
extern int addDisplayList(int, int, int);

	/* mob controls */
extern void createMob(int, float, float, float, float);
extern void setMobPosition(int, float, float, float, float);
extern void hideMob(int);
extern void showMob(int);

	/* player controls */
extern void createPlayer(int, float, float, float, float);
extern void setPlayerPosition(int, float, float, float, float);
extern void hidePlayer(int);
extern void showPlayer(int);

	/* flag which is set to 1 when flying behaviour is desired */
extern int flycontrol;
	/* flag used to indicate that the test world should be used */
extern int testWorld;
	/* list and count of polygons to be displayed, set during culling */
extern int displayList[MAX_DISPLAY_LIST][3];
extern int displayCount;
	/* flag to print out frames per second */
extern int fps;
	/* flag to indicate removal of cube the viewer is facing */
extern int dig;
	/* flag indicates the program is a client when set = 1 */
extern int netClient;
	/* flag indicates the program is a server when set = 1 */
extern int netServer; 

	/* frustum corner coordinates, used for visibility determination  */
extern float corners[4][3];

	/* determine which cubes are visible e.g. in view frustum */
extern void ExtractFrustum();
extern void tree(float, float, float, float, float, float, int);

/********* end of extern variable declarations **************/



   //Functions used, these need to be appended to H

   //Applies Gravity
   void ApplyGravity();
   //Call Destroy on created ptrs (atm it's just skyclouds)
   void ExitCleanUpCode();




	/*** collisionResponse() ***/
	/* -performs collision detection and response */
	/*  sets new xyz  to position of the viewpoint after collision */
	/* -can also be used to implement gravity by updating y position of vp*/
	/* note that the world coordinates returned from getViewPosition()
	   will be the negative value of the array indices */

//This function only gets called on Keyboard Press, not exactly Ideal for Gravity
//Setting a Flag here to determine what's calling it can provide an easy fix as to the Hopping Glitch
void collisionResponse() 
{
	/* your collision code goes here */
   float currLoc_X;
   float currLoc_Y;
   float currLoc_Z;

   getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

   currLoc_X*=-1;
   currLoc_Y*=-1;
   currLoc_Z*=-1;
   currLoc_Y-=.5;
   //If it's a green block, don't move?

   //IF we are entering a non Empty && non blue then don't go into it!
   if(world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=0 && world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=2)
   {
      //Silly Statement the computer says. Wouldn't you scream if you walked through walls?
      //printf("IM ENTERING A BLOCK AHAHHHHHHH=\n");

      //Reuse xyz variables, as condition has been checked
      //This is useless if keyboard was not pressed
      float oldLoc_X;
      float oldLoc_Y;
      float oldLoc_Z;     

      //There will be a Y difference due to gravity constantly trying to push
      //us through the ground (just like in life :D)

      getOldViewPosition(&oldLoc_X, &oldLoc_Y, &oldLoc_Z);

      oldLoc_X*=-1;
      oldLoc_Y*=-1;
      oldLoc_Z*=-1;

      oldLoc_Y=  ((int)oldLoc_Y)+.5;

      //Only do this if we are not moving
      //Check if a block exists here, but not at the elevation above

      //Only Perform this "HOP" mechanic if the following criteria is met:
      //1. A difference occured in the X and/or Z
      //2. We are not attempting to move down, otherwise a jostle will occur due to gravity + hop
      //3. There is a block at the location we are attempting to move onto, AND nothing ontop.
      //4. This move is not called by Gravity, this is important because gravity will always force down
         if(world[(int)currLoc_X][ (int)(oldLoc_Y)][(int)currLoc_Z]!=0) 
         {      
            if(world[(int)currLoc_X][ (int)(oldLoc_Y+1)][(int)currLoc_Z]==0)
            {
            oldLoc_X=currLoc_X;
            oldLoc_Z=currLoc_Z; 
            oldLoc_Y+=1;
            }
         }
         else
         {
          oldLoc_X=currLoc_X;
          oldLoc_Z=currLoc_Z;  
         }

      setViewPosition((oldLoc_X*-1), (oldLoc_Y*-1), (oldLoc_Z*-1));
   }
}


	/*** update() ***/
	/* background process, it is called when there are no other events */
	/* -used to control animations and perform calculations while the  */
	/*  system is running */
	/* -gravity must also implemented here, duplicate collisionResponse */
void update() {
int i, j, k;
float *la;
	/* sample animation for the test world, don't remove this code */
	/* -demo of animating mobs */
   if (testWorld) {
	/* sample of rotation and positioning of mob */
	/* coordinates for mob 0 */
      static float mob0x = 50.0, mob0y = 25.0, mob0z = 52.0;
      static float mob0ry = 0.0;
      static int increasingmob0 = 1;
	/* coordinates for mob 1 */
      static float mob1x = 50.0, mob1y = 25.0, mob1z = 52.0;
      static float mob1ry = 0.0;
      static int increasingmob1 = 1;

	/* move mob 0 and rotate */
	/* set mob 0 position */
      setMobPosition(0, mob0x, mob0y, mob0z, mob0ry);

	/* move mob 0 in the x axis */
      if (increasingmob0 == 1)
         mob0x += 0.2;
      else 
         mob0x -= 0.2;
      if (mob0x > 50) increasingmob0 = 0;
      if (mob0x < 30) increasingmob0 = 1;

	/* rotate mob 0 around the y axis */
      mob0ry += 1.0;
      if (mob0ry > 360.0) mob0ry -= 360.0;

	/* move mob 1 and rotate */
      setMobPosition(1, mob1x, mob1y, mob1z, mob1ry);

	/* move mob 1 in the z axis */
	/* when mob is moving away it is visible, when moving back it */
	/* is hidden */
      if (increasingmob1 == 1) {
         mob1z += 0.2;
         showMob(1);
      } else {
         mob1z -= 0.2;
         hideMob(1);
      }
      if (mob1z > 72) increasingmob1 = 0;
      if (mob1z < 52) increasingmob1 = 1;

	/* rotate mob 1 around the y axis */
      mob1ry += 1.0;
      if (mob1ry > 360.0) mob1ry -= 360.0;
    /* end testworld animation */
   } else {

	/* your code goes here */
   //Gravity Code
   ApplyGravity();
   //Look in clouds.c
   UpdateCloudMovement();
   }

}

   
   


   //This function will decrement the value by .1 if a block is not directly underneath
   void ApplyGravity()
   {
      float gravity = .1;

      float currLoc_X;
      float currLoc_Y;
      float currLoc_Z;

      getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);
      currLoc_Y+=gravity; //Works because values are inherently Negative


      setViewPosition(currLoc_X, currLoc_Y, currLoc_Z);
      currLoc_X*=-1;
      currLoc_Y*=-1;
      currLoc_Z*=-1;  

 

      //Call Collision Responds Manually, as it does not get Called
      //unless provided keyboard input. Therefore fix via manual invoction
      //Collision Code:
      collisionResponse();
   }



int main(int argc, char** argv)
{
int i, j, k;
	/* initialize the graphics system */
   graphicsInit(&argc, argv);

	/* the first part of this if statement builds a sample */
	/* world which will be used for testing */
	/* DO NOT remove this code. */
	/* Put your code in the else statment below */
	/* The testworld is only guaranteed to work with a world of
		with dimensions of 100,50,100. */
   if (testWorld == 1) {
	/* initialize world to empty */
      for(i=0; i<WORLDX; i++)
         for(j=0; j<WORLDY; j++)
            for(k=0; k<WORLDZ; k++)
               world[i][j][k] = 0;
	
	/* some sample objects */
	/* build a red platform */
      for(i=0; i<WORLDX; i++) {
         for(j=0; j<WORLDZ; j++) {
            world[i][24][j] = 3;
         }
      }
	/* create some green and blue cubes */
      world[50][25][50] = 1;
      world[49][25][50] = 1;
      world[49][26][50] = 1;
      world[52][25][52] = 2;
      world[52][26][52] = 2;

	/* blue box shows xy bounds of the world */
      for(i=0; i<WORLDX-1; i++) {
         world[i][25][0] = 2;
         world[i][25][WORLDZ-1] = 2;
      }
      for(i=0; i<WORLDZ-1; i++) {
         world[0][25][i] = 2;
         world[WORLDX-1][25][i] = 2;
      }

	/* create two sample mobs */
	/* these are animated in the update() function */
      createMob(0, 50.0, 25.0, 52.0, 0.0);
      createMob(1, 50.0, 25.0, 52.0, 0.0);

	/* create sample player */
      createPlayer(0, 52.0, 27.0, 52.0, 0.0);

   } else {
   	/* your code to build the world goes here */

      //Second Implementations
      int seed = 10;

      //Method 2
      Gradient_Table gradientTable = CreateGradientTable(seed);

      //Nice Seed Values Range between ~20-60. 70 Becomes very Flat
      //Use 10 if you wish to check the collision for the No hopping on Tiles with Height difference of 2.
      //Use 2 For REALLY Jagged Array
      //Use 25 for Nice Valley type.
      float detailModifier =15;

      //For now Ensure that WORLDX == WORLDZ and that SIZE == WORLDX * WORLDZ
      for(int x=0;x<WORLDX;x++)
         {
            printf("\n");
            for(int z=0;z<WORLDZ;z++)
            {

               //Method 1
               //float val=PerlinNoise_At((float)(x+seed),(float)z+seed) *30 +25;
               
               //Method 2. The * modifier = Amplitude. DetailModifier= Frequency. Seed = Slight repositioning
               //Octaves are implied.
               float val=ComputePerlin_Value(gradientTable, (float)(x)/detailModifier +seed, (float)(z)/detailModifier +seed)  *25+25;


               //Set Cubes to Land!
               for(int i=0;i<val;i++)
                  world[x][i][z]=1;
            }
         }

      //Method 2
      //Gradient Table no longer needed so lets scrap it.
      DestroyGradientTable(gradientTable);

      //Lets Create some Clouds
      CreateSkyClouds();

   }



	/* starts the graphics processing loop */
	/* code after this will not run until the program exits */
   glutMainLoop();
   return 0; 
}

   //Code where Destroy Code should be placed on proper Exits.
   //Graphics.c Enters this function via Keyboard Q
   void ExitCleanUpCode()
   {
      //Lets Avoid MemoryLeaks :) 
      //Cleanup after self. 
      DestroySkyClouds(); 
   }



























