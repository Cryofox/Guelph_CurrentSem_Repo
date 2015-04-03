using System;

namespace Myo
{
	public class Linear_Function : MathFunction
	{
		//What Percent of the SCREEN (Pixel Accuracy)


		public Linear_Function ()
		{}


		public override float Calc_Y(float x)
		{
			//Convert to Radians from degrees
			//x *= (float)(Math.PI / 180);

			float y = x;
			return y;
		}

	}
}

