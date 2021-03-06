#ifndef PERLIN
#define PERLIN




//The Code for Pelin1  //1st Implementation- (Not used, only implemented for bonus/fun)

   //Grabs the calculated perlin value at the provided location
   float PerlinNoise_At(float x, float y);	
		
   //The Raw Noise at this location, without any perlin/smoothing value applied
   float RawNoise(int x, int y);	
		
   //Returns a smoothed perlin location
   float SmoothedNoise(float x, float y);	
		
		
   //Creates an Interpolation of the Point utilizing Neighbouring Cells		
   float InterpolateNoise(float x, float y);
   //Interpolates between val1 and val2 based on percentage. 0 = Val1 Dominance, 1 = Val2 Dominance, 1/2 = Average.		
   float Cosine_Interpolate(float val1, float val2, float percentage);
//





//The Code for Pelin2 
   	//Gradient struct
	typedef struct
	{
		int* permutationReference;
		//The Gradient for the Array at X values
		float* gradientX;
		//The Gradient for the Array at Y values	
		float* gradientY;
	} Gradient_Table;


   
   //A Function which returns a Gradient Table struct
   //filled with all the data, this allows the ability to comput perlin noise at values chosen
   Gradient_Table CreateGradientTable();

	//Computes Perlin Value at X & Y location, given a gradient Table
	//Feeding an integer results in 0, this is just how perlin works.
   float ComputePerlin_Value(Gradient_Table gTable, float x, float y);

   //Destory the GradientTable provided
   void DestroyGradientTable(Gradient_Table gT);









#endif