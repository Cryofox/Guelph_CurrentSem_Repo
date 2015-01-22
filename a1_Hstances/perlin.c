#include "clouds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "perlin.h"
#include "graphics.h"
//1st Implementation- (Not used, only implemented for bonus/fun)

//This is my second implementation of Perlin Noise   

//Once the Perlin Noise is Created use FBM to Make everything more pleasant		
///////////Algorithm Below Requires Help, It's broken from pseudocode alone.		
		
//Algorithm Linked Just Does not Work. The Problem with Pseudocode is that unless its implemented its not even guaranteed to work.		
   //Generates the Perlin Noise at the given Coordinate		
   float PerlinNoise_At(float x, float y)		
   {		
      float gain = 0.65;		
      float height = 0;		
     //This is the persistance value to be used throughout the Perlin program		
      //This determines the lowest or max detail an object can reach. 1=High Detail, 1/4= Low Detail.		
      float persistence = 0.5f; // 1/2		
		
      //How often to loop through the array		
      int num_Octaves = 15; 		
		
		
      float frequency = 1.0f/((float)WORLDX/2);		
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
-*/		
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
		
      float interpolate1   =Cosine_Interpolate(center_Noise,right_Noise,remainder_X);		
      float interpolate2   =Cosine_Interpolate(up_Noise,upRight_Noise,remainder_X);		
		
		
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