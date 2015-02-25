
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
#include "projectile.h"
#include <sys/time.h>  //Used for Timing Functions




	/* flag which is set to 1 when flying behaviour is desired */
extern int flycontrol;
	/* flag used to indicate that the test world should be used */
extern int testWorld;




//External Reference to Client/Server flags
extern int netClient;      // network client flag, is client when = 1
extern int netServer;      // network server flag, is server when = 1



      //The Projectiles Angle to be Used from the Forward view
   static double projectile_Angle=0.0;
   static double projectile_Velocity=0.0;



   //Functions used, these need to be appended to H

   //Applies Gravity
   void ApplyGravity(double timePassed);
   //Call Destroy on created ptrs (atm it's just skyclouds)
   void ExitCleanUpCode();

   //Updates the Elapsed time from the last time this was Called.
   //This is called every time Update is called from opengl
   double UpdateTime();



   //Structs from Time.h used for Calculating Elapsed Time
   struct timeval time_LastUpdate, time_thisUpdate;


   float gravity_Force = 2;









//Server is handled in backwards Logic Fashion
//Clients Say what they do, and server just sends to everyone

void Initialize_Server()
{



}






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
   currLoc_Y-=.5; //This value is used for Head-Repositioning

   //Apply Bound Checking
   if(( currLoc_X > 100 || currLoc_X < 0) || ( currLoc_Z > 100 || currLoc_Z < 0))
   {
      float oldLoc_X;
      float oldLoc_Y;
      float oldLoc_Z;     

      //There will be a Y difference due to gravity constantly trying to push
      //us through the ground (just like in life :D)

      getOldViewPosition(&oldLoc_X, &oldLoc_Y, &oldLoc_Z);     
      setViewPosition((oldLoc_X), (oldLoc_Y), (oldLoc_Z));
   }


   //Otherwise if we are entering a non Empty && non blue then don't go into it!
   else if(world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=0 && world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=5)
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

   /******* draw2D() *******/
   /* draws 2D shapes on screen */
   /* use the following functions:        */
   /* draw2Dline(int, int, int, int, int);      */
   /* draw2Dbox(int, int, int, int);         */
   /* draw2Dtriangle(int, int, int, int, int, int);   */
   /* set2Dcolour(float []);           */
   /* colour must be set before other functions are called  */
void draw2D() {

   if (testWorld) {
      /* draw some sample 2d shapes */
      GLfloat green[] = {0.0, 0.5, 0.0, 0.5};
      set2Dcolour(green);
      draw2Dline(0, 0, 500, 500, 15);
      draw2Dtriangle(0, 0, 200, 200, 0, 200);

      GLfloat black[] = {0.0, 0.0, 0.0, 0.5};
      set2Dcolour(black);
      draw2Dbox(500, 380, 524, 388);
   } else {

   /* your code goes here */

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

   double timePassed=UpdateTime();
   //Gravity Code
   if(flycontrol==0)
      ApplyGravity(timePassed);
   //Look in clouds.c
   UpdateCloudMovement(timePassed);

   UpdateProjectiles(timePassed);
   }




}
   int firstTime=0;
   //This Function Updates the Time and Returns the elapsed time since the last time it was called
   //Updates the Elapsed time from the last time this was Called.
   //This is called every time Update is called from opengl
   double UpdateTime()
   {
      //This is the first time Calc Elapsed time has been called. Meaning
      //Start the procedure correctly
      if(firstTime==0)
      {
      firstTime=1;
      gettimeofday(&time_thisUpdate, NULL);
      return 0;
      }
      else
      {
      //Store the old_current time
      time_LastUpdate=time_thisUpdate;
      //Calculate the actual current time
      gettimeofday(&time_thisUpdate, NULL);  

      //Calculate the Elapsed time between timeStamps
      double elapsedTime;

      //Calculate in two steps to preserve accuracy
      elapsedTime =  (time_thisUpdate.tv_sec  - time_LastUpdate.tv_sec) * 1000.0;    // sec to ms
      elapsedTime += (time_thisUpdate.tv_usec - time_LastUpdate.tv_usec) / 1000.0;   // us to ms

      //Convert Millisecond back to Seconds
      elapsedTime /= 1000.0;
      //printf("Elapsed Time:%f\n",elapsedTime);
      return elapsedTime;
      }
   }

   


   //This function will decrement the value by .1 if a block is not directly underneath
   void ApplyGravity(double timePassed)
   {
      float gravity = gravity_Force;
      gravity*= timePassed;

      float currLoc_X;
      float currLoc_Y;
      float currLoc_Z;


      //Multiply by a value to recipricate similar gravity as projectile
      gravity*=2;

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

      //Setup ProjectileManager
      CreateProjectileManager();
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
      DestroyProjectileManager(); 
   }


int oldX;
int oldY;
void mouse(int button, int state, int x, int y) {
/* capture mouse button events - not currently used */
   if ((state == GLUT_DOWN) && (button == GLUT_LEFT_BUTTON))
   { 
      //All that is needed is to take our current XZ orientation
      //and determine the upward Y force which we will decay over time in ApplyGravity

      //Note Gravity plays no effect on X or Z force, instead wind would naturally have a
      //friction coefficient to reduce these values, but we will assume those are negligible

      //M_PI is pi defined in math.h
      //printf("Pi = %f\n", M_PI);
      long double radianAngle = (long double)projectile_Angle * M_PI/180.0; 

   //Soh Cah Toa
      //Calculate Y and Horizontal Force
      double xzForce= (double)(cos(radianAngle)) * projectile_Velocity;
      double yForce= (double)(sin(radianAngle)) * projectile_Velocity;


     //Now to apply our xz force in the direction we are facing
      float orientationX;
      float orientationY;
      float orientationZ;

      getViewOrientation(&orientationX,&orientationY,&orientationZ);

      //X Controls Up/Down Pitch
      //Y Controls Yaw , which is whats needed for XZ force

      //Orientation produces weird results therefore constrain to 360%
      orientationY = (int) orientationY%360;

      //Since Triangls have a MAX of 90 Degrees Each, the Quadrant this Orientation is in will be needed

      /*
      Q1 = 0-90
      Q2 = 90-180
      Q3 = 180-270
      Q4 = 270-360 (Which is not possible due to Mod, so its technically 270-359)

      Overlaps do not matter.
      */

      //Mod 90 to get the Quadrant Angle
      radianAngle = ((int)orientationY)%90;


     //This Value also determines the amount of XZ force needed to apply the XZ Force
     //Calculate XForce and ZForce
     radianAngle = (long double)radianAngle * M_PI/180.0; 

     double xForce= (double)(cos(radianAngle)) * xzForce;
     double zForce= (double)(sin(radianAngle)) * xzForce;

     //Now that the angle is set, apply a quick Swap based on what quadrant we are in.

     //Q1 Inverse XZ
     if( (orientationY) <=90)
     {
      float temp = zForce;
      zForce= -xForce;
      xForce= temp;
     }
     //Q2 this is the default orientation quadrant, do nothing.
     else if( (orientationY) <=180)
     {}
     //Q3 X becomes Negative and Z becomes Negative
     else if( (orientationY) <=270)
     {
      ///printf("Quadrant:3\n");
      float temp = xForce;
      xForce= -zForce;
      zForce= temp;
     }   
     //Q4 Z becomes Negative 
     else
     {
      float temp = xForce;
      xForce= -temp;
      zForce= -zForce;     
     }


     //Now we have all the variables to Spawn our projectile
     SpawnProjectile(xForce,yForce,zForce);
   }

   if ((state == GLUT_UP) && (button == GLUT_RIGHT_BUTTON))
   {  
         //Calculate The Difference in X
         // ->  = Increase Velocity
      int   xDifference = x-oldX;
      float yDifference = y-oldY;

      //Compact the y Difference so smaller angles are achievable
      yDifference /= 10.0;
      xDifference /= 10.0;
      //Display Currently Set Velocity and Angle

      //Height is Inverted
      projectile_Angle    -= (double)(yDifference);

      projectile_Velocity += (double)(xDifference);

      //Max Angle = 180;
      if(projectile_Angle>90)
         projectile_Angle=90;
      if(projectile_Angle<0)
         projectile_Angle=0;

      if(projectile_Velocity<0)
         projectile_Velocity=0;
      if(projectile_Velocity>100)
         projectile_Velocity=100;

      //Max Velocity = 100
      //Warp the Mouse position to old position to make it easier to modify values 
      //and navigate
      glutWarpPointer( oldX, oldY);
           //Scale down the Projectile Force Between a Range

     //Find the Sweet Spot for Arcs ie if Mass = 5 *2 = Gravity will push down with a Force of 10
     //XZ should equate to a force of 20 in this instance min
     printf("----------\n");
     printf("Angle=%f\n", projectile_Angle);
     printf("Velocity=%f\n", projectile_Velocity);
     printf("===========\n");
   }
   else if ((state == GLUT_DOWN) && (button == GLUT_RIGHT_BUTTON))
   {
      oldX=x;
      oldY=y;
      //printf("down - %d,%d \n",x,y);
   }
}
























