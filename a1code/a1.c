
/* Derived from scene.c in the The OpenGL Programming Guide */
/* Keyboard and mouse rotation taken from Swiftless Tutorials #23 Part 2 */
/* http://www.swiftless.com/tutorials/opengl/camera2.html */

/* Frames per second code taken from : */
/* http://www.lighthouse3d.com/opengl/glut/index.php?fps */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "graphics.h"

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
   float PerlinNoise_At(float x, float y);
   float Cosine_Interpolate(float val1, float val2, float percentage);
   float InterpolateNoise(float x, float y);


   const int SIZE=256;

   typedef struct{
      int* permutationReference;

      float* gradientX;
      float* gradientY;
   } Gradient_Table;
   Gradient_Table CreateGradientTable();

   float ComputePerlin_Value(Gradient_Table gTable, float x, float y);
      void DestroyGradientTable(Gradient_Table gT);
         float lerp(float a0, float a1, float w);

	/*** collisionResponse() ***/
	/* -performs collision detection and response */
	/*  sets new xyz  to position of the viewpoint after collision */
	/* -can also be used to implement gravity by updating y position of vp*/
	/* note that the world coordinates returned from getViewPosition()
	   will be the negative value of the array indices */
void collisionResponse() {
	/* your collision code goes here */

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

   }
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

/*
      //CHOOSE a seed to replicate Results:
      
      //Step 1: Create Array of Perlin Noise.
      int maxWorldHeight=50;

      //Since Interpolation requires constant referencing of Values, instead of creating
      //points on Demand utilizing prime numbers, simply fill ahead of time using Random
      //this allows for new worlds simply by changing the Seed above.

      //This Array must be slightly larger than the world, this is to 
      //accomodate for the edges when they are being interpolated


      //Values are Stored surrounding the border of the array, but only the worldsize array is going to be used.
      //Due to this a +1 offset will be used, ie 0,0 == 1,1.
   
      //Create the HeightMap. 
      //This new array is used as the Array holding the random value must not be altered for
      //perlin noise to be accurate
      float heightMap[WORLDX][WORLDZ];  

      //Debug Print Array Contents
      for(int x=0;x<WORLDX;x++)
      {        
         printf("\n"); 
         for(int z=0;z<WORLDZ;z++)    
         {
            //To do, offset Values with the Seed
            heightMap[x][z]= (PerlinNoise_At(x,z))*WORLDY;

            printf("HM[%d][%d]=%f\t",x,z, heightMap[x][z]);

            //Set WorldHeight at XZ to Value
            for(int i=0;i<heightMap[x][z];i++)
               world[x][i][z]=1;
         }
      }
      //////////////////////
*/

      //Second Implementations
      int seed = 140;
      Gradient_Table gradientTable = CreateGradientTable(seed);

      //Nice Seed Values Range between ~20-60. 70 Becomes very Flat
      //If you wish to See Clouds passing through High Mountains set this very low for example 2-9
      float detailModifier =2;

      //For now Ensure that WORLDX == WORLDZ and that SIZE == WORLDX * WORLDZ
      for(int x=0;x<WORLDX;x++)
         {
            printf("\n");
            for(int z=0;z<WORLDZ;z++)
            {
               //printf("GT REF[%d][%d]=%d",x,z, gradientTable.permutationReference[x*16+z]);
               //0.5F offset must be used for Gradient Point calculation
               float val=ComputePerlin_Value(gradientTable, (float)(x)/detailModifier +seed, (float)(z)/detailModifier +seed)  *25 +25;

               printf("FVal=%f \t",val);

               //Set Cubes to Land!
               for(int i=0;i<val;i++)
                  world[x][i][z]=1;

            }
         }
      DestroyGradientTable(gradientTable);
      
   }



	/* starts the graphics processing loop */
	/* code after this will not run until the program exits */
   glutMainLoop();
   return 0; 
}
//Perlin Noise Utilizes Gradient Vectors to Create Relational Data.


   void DestroyGradientTable(Gradient_Table gT)
   {
      free(gT.permutationReference);
      free(gT.gradientX);
      free(gT.gradientY);
   }

   //Create Permutation Table
   Gradient_Table CreateGradientTable(int seed)
   {
      srand(seed);
      Gradient_Table gT;
      gT.permutationReference = malloc(sizeof(int)*SIZE);
      gT.gradientX=malloc(sizeof(float)*SIZE);
      gT.gradientY=malloc(sizeof(float)*SIZE);

      //Create the Pointer Array
    //  float ptr_Array[256];

      //Initialize Array
      for(int i=0; i< SIZE;i++)
      {
      gT.permutationReference[i]=i;
      }

      //Jumble the Order of which the values occur in
      for(int i=0;i<SIZE;i++)
      {
         //Wrap the Random value around the max size
         int j= rand() % SIZE;

         //Swap Values, 
         float tmp_Swap = gT.permutationReference[i];

         gT.permutationReference[i] = gT.permutationReference[j];
         gT.permutationReference[j] = gT.permutationReference[i];
      }


      for(int i=0;i<SIZE;i++)
      {
         //V This is where the Seed Can change the Shape
         gT.gradientX[i]= (float)(rand())/(RAND_MAX/2) -1.0f;
         gT.gradientY[i]= (float)(rand())/(RAND_MAX/2) -1.0f;
      }
      return gT;
   }
 
   float ComputePerlin_Value(Gradient_Table gTable, float x, float y)
   {
      //Step 1: Find the Integer position of the 4 Surrounding Points
 
      //X Values
      int qx0 = (int) floorf(x);
      int qx1 = qx0 + 1;
      //Y Values
      int qy0 = (int) floorf(y);
      int qy1 = qy0 + 1;

      //Step 2: Permutate (Re-Order) value to find the index of lookup table
      int q00 = gTable.permutationReference[(qy0 + gTable.permutationReference[qx0 % SIZE]) % SIZE];
      int q01 = gTable.permutationReference[(qy0 + gTable.permutationReference[qx1 % SIZE]) % SIZE];

      int q10 = gTable.permutationReference[(qy1 + gTable.permutationReference[qx0 % SIZE]) % SIZE];
      int q11 = gTable.permutationReference[(qy1 + gTable.permutationReference[qx1 % SIZE]) % SIZE];


      //Step 3: Computing vectors from the four points to the input point
      float tx0 = (float)(x - floorf(x));
      float tx1 = tx0 - 1;

      float ty0 = (float)(y - floorf(y));
      float ty1 = ty0 - 1;

      //THIS IS WHAT MAKES A PERLIN ALGORITHM!
      //Step 4: Compute the dot-product between the vectors and the gradients
      float v00 = gTable.gradientX[q00]*tx0 + gTable.gradientY[q00]*ty0;
      float v01 = gTable.gradientX[q01]*tx1 + gTable.gradientY[q01]*ty0;

      float v10 = gTable.gradientX[q10]*tx0 + gTable.gradientY[q10]*ty1;
      float v11 = gTable.gradientX[q11]*tx1 + gTable.gradientY[q11]*ty1;

      //printf("V00=%f ",v00);
      //printf("V01=%f ",v01);
      //printf("V10=%f ",v10);
      //printf("V11=%f \n",v11);

      // Do the bi-cubic interpolation to get the final value
      float wx = (3.0 - 2.0*tx0)*tx0*tx0;
      //printf("wx=%f \t",wx);   
      float v0 = v00 - wx*(v00 - v01);
      float v1 = v10 - wx*(v10 - v11);
      //printf("v1=%f \t",v1);

      float wy = (3.0 - 2.0*ty0)*ty0*ty0;
      //printf("wy=%f \t",wy);
      //Final Value
      float v = v0 - wy*(v0 - v1);

      //printf("fV=%f",v);
      return v;
   }









   //Once the Perlin Noise is Created use FBM to Make everything more pleasant


///////////Algorithm Below Requires Help, It's broken from pseudocode alone.

//Algorithm Linked Just Does not Work. The Problem with Pseudocode is that unless its implemented its not even guaranteed to work.
   //Generates the Perlin Noise at the given Coordinate
   float PerlinNoise_At(float x, float y)
   {
      float gain = 0.65f;


      float height = 0;
      //This is the persistance value to be used throughout the Perlin program
      //This determines the lowest or max detail an object can reach. 1=High Detail, 1/4= Low Detail.
      float persistence = 0.5f; // 1/2

      //How often to loop through the array
      int num_Octaves = 10; 


      float frequency = 1.0f/(float)WORLDX;
      float amplitude = gain;   


      for(int i=0;i<num_Octaves;i++)
      {
         height += InterpolateNoise( (x * frequency), (y* frequency) ) * amplitude;
         frequency *=2;
         amplitude *=gain;

      }

    //  if(height>0.5f)
    //     printf("Height=%f",height);




      return height;
   }

   //In order to match the Algorithm Posted here:http://freespace.virgin.net/hugo.elias/models/m_perlin.htm
   //This must return a value between -1, and 1. This isn't hard when the max height is 50;
   float RawNoise(int x, int y)
   {
 
/*
      int n = x + y * 57;
      n = (n << 13) ^ n;
      float f = (1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
*/
      int useMine=0;
      if(useMine==0)
      {
         int n = x + y * 57;
         n = (n << 13) ^ n;
         float f = (1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
         return f;
      }
      else 
      {      
         srand(x);
         float valueX= rand()%100;

         srand(y);
         rand();
         float valueY= rand()%100;
         return (valueX+valueY)/200;
      }

   }

   float SmoothedNoise(float x, float y)
   {
      int int_x= (int)x;
      int int_y= (int)y;

     float corners  = (RawNoise((int_x-1),(int_y-1)) + RawNoise((int_x+1),(int_y-1)) + RawNoise((int_x-1),(int_y+1)) + RawNoise((int_x+1),(int_y+1)) )/16;
     float sides    = (RawNoise((int_x-1),(int_y)) + RawNoise((int_x+1),(int_y)) + RawNoise((int_x),(int_y+1)) + RawNoise((int_x),(int_y-1)) )/8;
     float center   = RawNoise((int_x),(int_y))/4;

      return (corners+sides+center);

   }


   //Creates an Interpolation of the Point utilizing Neighbouring Cells
   float InterpolateNoise(float x, float y)
   {
      int int_x = (int)x;
      float remainder_X = x- int_x;

      int   int_y = (int)y;
      float remainder_Y = y- int_y;

      float center_Noise   = SmoothedNoise(  int_x, int_y);
      float right_Noise    = SmoothedNoise( (int_x+1), int_y);
      float left_Noise     = SmoothedNoise( (int_x-1), int_y);
      float down_Noise     = SmoothedNoise( (int_x), int_y-1);
      float up_Noise       = SmoothedNoise(  int_x, (int_y +1));
 
      float upRight_Noise  = SmoothedNoise( (int_x+1), (int_y+1));

      float interpolate1   =Cosine_Interpolate(left_Noise,right_Noise,remainder_X);
      float interpolate2   =Cosine_Interpolate(up_Noise,down_Noise,remainder_X);


      return Cosine_Interpolate(interpolate1,interpolate2, remainder_Y);
   }

   //Interpolates between val1 and val2 based on percentage. 0 = Val1 Dominance, 1 = Val2 Dominance, 1/2 = Average.
   float Cosine_Interpolate(float val1, float val2, float percentage)
   {
      //Multiply by PI
      float converted_Percent = percentage * 3.1415927;
      converted_Percent = (1 - cosf(converted_Percent) * .5);

      return  val1*(1-converted_Percent) + val2*converted_Percent;
   }















