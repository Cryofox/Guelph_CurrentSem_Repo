using System;

namespace Myo
{
	public class MathFunction
	{
		public float paramModifier = 0.05f;
		public int minX=-1;
		public int maxX= 1;
		public int minY=-1;
		public int maxY=1;

		public float modifier {
			get{ return paramModifier; }
		}

		//The Math Function BaseClass
		public MathFunction ()
		{
		
		}
		//Y Values
		public float Get_MinModif(float x, int screenWidth, int screenHeight)
		{
			//Get the Exact Y value's Pixel Location
			float y = GetY (x, screenWidth, screenHeight);

			//Offset by Paramodif

			float val =y- screenHeight*paramModifier;


			return val;
		}
		public float Get_MaxModif(float x, int screenWidth, int screenHeight)
		{
			//Get the Exact Y value's Pixel Location
			float y = GetY (x, screenWidth, screenHeight);

			float val =y+ screenHeight*paramModifier;
			return val;
		}


		//Check if Y is within Modif Range at 0
		public int Get_StartPosition(float y)
		{
			float min = Get_MinModif (0f, 500, 500);
			float max = Get_MaxModif (0f, 500, 500);


			Console.WriteLine ("Value Y="+y);
			Console.WriteLine ("Min = " + min);
			Console.WriteLine ("Max = " + max);
			if (y < min) {
				return 1;
			} else if (y > max)
				return -1;
			else
				return 0;
		}

		public bool isWithinModif(float x, float y)
		{
			float min = Get_MinModif (0f, 500, 500);
			float max = Get_MaxModif (0f, 500, 500);


			//Console.WriteLine ("Value Y="+y);
			//Console.WriteLine ("Min = " + min);
			//Console.WriteLine ("Max = " + max);
			float deviation= Calculate_Deviation(x,y);
			if (deviation <= paramModifier) {
				return true;
			} 
			else
				return false;		
		}

		public float Calculate_Deviation(float x, float y)
		{
			float min = Get_MinModif (x, 500, 500);
			float max = Get_MaxModif (x, 500, 500);

			float exactLocation = GetY (x, 500, 500);

			//Here we check how we do

			float deviation = y - exactLocation;

			//Absolute
			deviation= Math.Abs(deviation);

			//Rescale to get exact percentage
			deviation /= 500;

		Console.WriteLine ("Deviation:" + deviation);

			return deviation;
		}

		public virtual float Calc_Y(float x)
		{
			return 0;
				
		}
		//Given an X we return a Y based on the formula this class represents

		//Given the ScreenHeight, and screenWidth
		//we will take the pixel we are at and convert to where in the function we are
		//Then return the Y value PIXEL is.
		public float GetY(float x, int screenWidth, int screenHeight)
		{
			float y = 0;
			x = x / (float)screenWidth;
			x *=( Math.Abs (minX) + Math.Abs (maxX)); //Range
			x += minX;
			y = Calc_Y (x);

			//This will generate the Y on the screen

			int newMinY = Math.Abs (minY);

			//y *=( Math.Abs (minY) + Math.Abs (maxY)); //Range
			y += newMinY; //Shift

			float percentage = y / (Math.Abs (minY) + Math.Abs (maxY));

			//Console.WriteLine ("X=" + (x));
			//Console.WriteLine ("Y=" + (y));
			//Console.WriteLine ("%=" + percentage);
			y = (screenHeight)-((percentage * (screenHeight)));


			return y;
		}

	}
}

