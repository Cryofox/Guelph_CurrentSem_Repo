#include "clouds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "perlin.h"
#include "graphics.h"
//This is my second implementation of Perlin Noise




//Perlin Noise Utilizes Gradient Vectors to Create Relational Data. THAT is TRUE perlin noise.
//The way it works is by generating Vector "Gradients" at integer locations, then provided a 
//a float, find out how far it is from its nearest surrounding 4 vectors, and then 
//interpolate. The below code uses Bi-Cubic interpolation (a bit math heavy), and vectors


   //The Size of the Lookup/Permutation, do not alter this.
   //However if you wish to experiment with different sizes note level of detail + seed must use
   //different values to provide correct results. Also ensure Size is constructed via a value^2.
   //IE if SquareRoot(SIZE) is not a whole number, do not use it.
   const int SIZE=256;




   //Free Malloced Memory
   void DestroyGradientTable(Gradient_Table gT)
   {
      free(gT.permutationReference);
      free(gT.gradientX);
      free(gT.gradientY);
   }

   //http://www.angelcode.com/dev/perlin/perlin.html
   //The code in this function is referenced from here, I simply chose to store it in a struct
   //Create Permutation Table
   Gradient_Table CreateGradientTable(int seed)
   {
      srand(seed);
      Gradient_Table gT;
      gT.permutationReference = malloc(sizeof(int)*SIZE);
      gT.gradientX=malloc(sizeof(float)*SIZE);
      gT.gradientY=malloc(sizeof(float)*SIZE);

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
 

   //http://www.angelcode.com/dev/perlin/perlin.html
   //The code in this function is referenced from here. It helped me solve the math behind 
   //the math involved with perlin noise such as gradient dot product
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

      // Do the bi-cubic interpolation to get the final value
      float wx = (3.0 - 2.0*tx0)*tx0*tx0; 
      float v0 = v00 - wx*(v00 - v01);
      float v1 = v10 - wx*(v10 - v11);
      float wy = (3.0 - 2.0*ty0)*ty0*ty0;

      //Final Value
      float v = v0 - wy*(v0 - v1);

      return v;
   }

//Old PerlinCode




