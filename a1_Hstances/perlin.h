#ifndef PERLIN
#define PERLIN

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
   void DestroyGradientTable(Gradient_Table gT);









#endif