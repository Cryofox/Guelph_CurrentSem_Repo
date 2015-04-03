using System;
using System.Threading; // For Threading
using System.Speech.Synthesis;

namespace Myo
{
	//This class is basically the Tester - The Guy/Girl meant to draw on the canvas
	public class Temp_Tester
	{
		bool darkMode=false;
		//Private

		//This function determines our y
		MathFunction lineToDraw;

		private Paint _gui_Paint;
		Audio_Curve audio_Player;

		//private Myo_Wrapper myo;
		public Temp_Tester (Paint paint)
		{
			//Cosine Function
			lineToDraw = new Linear_Function ();



			lineToDraw.minX = paint.param_Min_x;
			lineToDraw.maxX = paint.param_Max_x;
			lineToDraw.minY = paint.param_Min_y;
			lineToDraw.maxY = paint.param_Max_y;

			//_gui_Sender = gui_sender;
			this._gui_Paint = paint;

			//Setup Myo
			Myo_Wrapper.Myo_Start ();
		}


		/*This is what engages the Drawing Logic for Both:
		 * The Initial Drawing of the Function Line &
		 * The User's input line
		*/
		public void Thread_Start()
		{
			float x = 0;
			float y = 100;

			//The File Below Plays a Noise File
			audio_Player = new Audio_Curve(lineToDraw);
			//Here we Draw the Line the User should Trace

			audio_Player.Set_MaxTime (2.5f);

				audio_Player.Play_Dev2();
				while (x<500) 
				{
					float actualY= lineToDraw.GetY (x,500, 500);
					actualY =250 - actualY;
					actualY /= 250;
					Console.WriteLine ("Ay=" + actualY);
					audio_Player.Update_XY (x, actualY);


					//x == Pixel
					//Screen Width
					float scW = x / 500;

					//Return y Pixel
					y = lineToDraw.GetY (x,500, 500);
					if(darkMode==false)
					{
						//This is the pixel perfect Line (white)
						_gui_Paint.DrawPoint (new Cairo.PointD (x, y), new Cairo.PointD (x, y));


						//Draw the Modifier range ( Purple )
						_gui_Paint.DrawLine_Modifier(new Cairo.PointD(x,lineToDraw.Get_MinModif(x,500,500)),new Cairo.PointD(x,lineToDraw.Get_MaxModif(x,500,500)));
					}



					//This is what we use to slowdown the drawing. a 5millisecond sleep
					Thread.Sleep (5);
					x += 1;

				}
				audio_Player.Stop_Dev2 ();
			//After the Line is Drawn Logic
			
			//Reset x to 0

			x=0;
			double myo_Pitch;

			//Wait while we did not get the Fist Pose from the Myo
			while (!Myo_Wrapper.myo_startSequence) 
			{Thread.Sleep (1000);}

			//Now that The Myo was signalled to start, lets check if we are in the starting location

			SpeechSynthesizer reader = new SpeechSynthesizer();
			while (true) 
			{
				float actualY= lineToDraw.GetY (x,500, 500);

				//Static reference, use Class to access var
				myo_Pitch = Myo_Wrapper.myo_Pitch;

				//Range we want is -0.5= Bot, 0.5 = Top

				//Add 0.5 to convert range to 0-1
				myo_Pitch+=0.5;

				//Multiply by screen height
				myo_Pitch*=500;

				float curVal = 250 - (float)myo_Pitch;
				curVal /= -250;

				actualY =250 - actualY;
				actualY /= 250;
				audio_Player.Update_XY (x, curVal);

				y=(float)(500 - myo_Pitch); //The Raw Position
				int areWeReady = lineToDraw.Get_StartPosition(y);
			//	areWeReady = 0;
				Console.WriteLine ("AreWeReady=" + areWeReady);
				if (areWeReady < 0)
				{
					reader.Speak ("Please move your hand upward to begin the tracing.");

				} 
				else if (areWeReady>0 )
				{
					reader.Speak ("Please move your hand downward to begin the tracing.");					
				}
				else
				{
					reader.Speak ("That is perfect, get ready to trace after the vibration.");	
					Myo_Wrapper.VibrateMyo ();
				break;
				}



				Thread.Sleep (2000);
			}


			


			audio_Player.Set_MaxTime (5f);   
			audio_Player.Play_Dev2 ();
			audio_Player.SetVolume_1 ((0));
			audio_Player.Play_Dev1 ();
			while (x<500) 
			{
				float actualY= lineToDraw.GetY (x,500, 500);

				//Static reference, use Class to access var
				myo_Pitch = Myo_Wrapper.myo_Pitch;

				//Range we want is -0.5= Bot, 0.5 = Top

				//Add 0.5 to convert range to 0-1
				myo_Pitch+=0.5;

				//Multiply by screen height
				myo_Pitch*=500;

				float curVal = 250 - (float)myo_Pitch;
				curVal /= -250;


				actualY =250 - actualY;
				actualY /= 250;
				audio_Player.Update_XY (x, curVal);


				Console.WriteLine ("MP:" + curVal);

				//Since 0,0 is Top, and 500,500 is bottom, reverse the direction
				y=(float)(500 - myo_Pitch); //The Raw Position

				//Draw the users location
				_gui_Paint.DrawPoint_User(new Cairo.PointD (x, y), new Cairo.PointD (x, y));
				//float deviation = lineToDraw.Calculate_Deviation (x, y);

				//If Deviation is GREATER than ParamModif
				if (!lineToDraw.isWithinModif (x, y)) {
					float deviation = lineToDraw.Calculate_Deviation (x, y);
					audio_Player.SetVolume_1 ((deviation));
				} else 
				{
					audio_Player.SetVolume_1 ((0));
				}
				//audio_Player.SetVolume_2((1-deviation));
				audio_Player.Update_XY (x, curVal);


				//if(deviation> lineToDraw.modifier)
				//	Myo_Wrapper.VibrateMyo ();


				//_gui_Sender.Send_XY ((x = x + 1), 0);
				Thread.Sleep (10);
				x += 1;

				//audio_Player.Play_Dev1 ();
			}
			audio_Player.Stop_Dev2 ();
			audio_Player.Stop_Dev1 ();


			audio_Player.Set_MaxTime (2.5f);
			if(darkMode==true)
			{
				x = 0;
				while (x<500) 
				{
					float actualY= lineToDraw.GetY (x,500, 500);
					actualY =250 - actualY;
					actualY /= 250;
					Console.WriteLine ("Ay=" + actualY);
					audio_Player.Update_XY (x, actualY);


					//x == Pixel
					//Screen Width
					float scW = x / 500;

					//Return y Pixel
					y = lineToDraw.GetY (x,500, 500);

					//This is the pixel perfect Line (white)
					_gui_Paint.DrawPoint (new Cairo.PointD (x, y), new Cairo.PointD (x, y));


					//Draw the Modifier range ( Purple )
					_gui_Paint.DrawLine_Modifier(new Cairo.PointD(x,lineToDraw.Get_MinModif(x,500,500)),new Cairo.PointD(x,lineToDraw.Get_MaxModif(x,500,500)));




					//This is what we use to slowdown the drawing. a 5millisecond sleep
					Thread.Sleep (5);
					x += 1;

				}
			}
			audio_Player.Close ();
		}

	}
}

