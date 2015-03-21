using System;
using System.Threading; // For Threading

namespace Myo
{
	public class Temp_Tester
	{
		//Private

		MathFunction lineToDraw;
		private Paint _gui_Paint;

		private Myo_Wrapper myo;
		public Temp_Tester (Paint paint)
		{
			//Cosine Function
			lineToDraw = new Cosine_Function ();

			//_gui_Sender = gui_sender;
			this._gui_Paint = paint;

			Myo_Wrapper.Myo_Start ();
		}



		public void Thread_Start()
		{
			float x = 0;
			float y = 100;

			//Here we Draw the Line the Use should Trace
			while (x<500) 
			{
				//x == Pixel
				//Screen Width
				float scW = x / 500;

				//Return y Pixel
				y = lineToDraw.GetY (x,500, 500);

				//This is the Line that Draws
				_gui_Paint.DrawPoint (new Cairo.PointD (x, y), new Cairo.PointD (x, y));


				//Draw the Modifier
				_gui_Paint.DrawLine_Modifier(new Cairo.PointD(x,lineToDraw.Get_MinModif(x,500,500)),new Cairo.PointD(x,lineToDraw.Get_MaxModif(x,500,500)));


				//_gui_Sender.Send_XY ((x = x + 1), 0);
				Thread.Sleep (5);

				x += 1;
			}
			//After the Line is Drawn, lets end the program.

		}

	}
}

