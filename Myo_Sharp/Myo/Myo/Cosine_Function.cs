using System;

namespace Myo
{
	public class Cosine_Function : MathFunction
	{
		//What Percent of the SCREEN (Pixel Accuracy)

		float paramModifier = 0.05f;
		int minX=-1;
		int maxX=1;
		public Cosine_Function ()
		{}
		//Y Values
		public override float Get_MinModif(float x, int screenWidth, int screenHeight)
		{
			//Get the Exact Y value's Pixel Location
			float y = GetY (x, screenWidth, screenHeight);

			//Offset by Paramodif

			float val =y- screenHeight*paramModifier;

			return val;
		}
		public override float Get_MaxModif(float x, int screenWidth, int screenHeight)
		{
			//Get the Exact Y value's Pixel Location
			float y = GetY (x, screenWidth, screenHeight);

			float val =y+ screenHeight*paramModifier;
			return val;}

		//
		public override float Calc_Y(float x)
		{
			//Convert to Radians from degrees
			//x *= (float)(Math.PI / 180);

			float y = (float)(Math.Cos ( (double)(x)));
			return y;
		}
		public override float GetY(float x, int screenWidth, int screenHeight)
		{
			float y = 0;
			x = x / (float)screenWidth;
			x *=( Math.Abs (minX) + Math.Abs (maxX));
			x += minX;
			y = Calc_Y (x);

			//This will generate the Y on the screen
			y = screenHeight-(y * screenHeight);
			//Console.WriteLine ("X=" + ((x / (float)screenWidth)));
			//Console.WriteLine ("Y=" + (y));

			return y;
		}
	}
}

