﻿using System;

namespace Myo
{
	public class Cosine_Function : MathFunction
	{
		//What Percent of the SCREEN (Pixel Accuracy)


		public Cosine_Function ()
		{}
		//Y Values


		//
		public override float Calc_Y(float x)
		{
			//Convert to Radians from degrees
			//x *= (float)(Math.PI / 180);

			float y = (float)(Math.Cos ( (double)(x)));
			return y;
		}

	}
}

