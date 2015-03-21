using System;

namespace Myo
{
	public class MathFunction
	{
		//The Math Function BaseClass
		public MathFunction ()
		{
		
		}
		//Y Values
		public virtual float Get_MinModif(float x, int screenWidth, int screenHeight)
		{return 0;}
		public virtual float Get_MaxModif(float x, int screenWidth, int screenHeight)
		{return 0;}

		public virtual float Calc_Y(float x)
		{
			return 0;
				
		}
		//Given an X we return a Y based on the formula this class represents

		//Given the ScreenHeight, and screenWidth
		//we will take the pixel we are at and convert to where in the function we are
		//Then return the Y value PIXEL is.
		public virtual float GetY(float x, int screenWidth, int screenHeight)
		{
			float y = 0;
			return y;
		}

	}
}

