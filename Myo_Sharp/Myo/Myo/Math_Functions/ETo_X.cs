using System;

namespace Myo
{
	public class ETo_X : MathFunction
	{
		//What Percent of the SCREEN (Pixel Accuracy)


		public ETo_X ()
		{}


		public override float Calc_Y(float x)
		{
			//Convert to Radians from degrees
			//x *= (float)(Math.PI / 180);

			float y = (float)( Math.Pow(Math.E, x)  );
			return y;
		}

	}
}

