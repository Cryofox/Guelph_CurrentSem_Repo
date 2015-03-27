using System;
using Gtk;
using Cairo;			// For Drawing on the Canvas
using System.Threading; // For Threading
namespace Myo
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Application.Init();
			//Create the Gui which handles all drawing
			Paint theGui = new Paint();

			//Create the Polling Thread for Calling Draw Events outside the program.
			Temp_Tester t_Tester = new Temp_Tester (theGui);

			//Setup the Second Thread by assigning the Target to Enter on.
			Thread secondaryThread = new Thread(t_Tester.Thread_Start);
			//Run the Thread by using the predefined Start() function.
			secondaryThread.Start ();

			//Run the Gui Application
			Application.Run();
		}



	}

/*
	public class GUI_Window: Window
	{

		public int circleCenter_X=0;
		public int circleCenter_Y=0;	


		private DrawingArea canvas;
		public GUI_Window() : base("Window Title.")
		{
			SetDefaultSize(390, 240);
			SetPosition(WindowPosition.Center);
			DeleteEvent += delegate { Application.Quit(); }; //Associate the red X with quit. :)

			canvas= new DrawingArea();
			canvas.SetSizeRequest (200, 200);

			//This is called everytime the Canvas requires to be re-drawn.
			canvas.ExposeEvent += OnExpose;
			//Add the Canvas to the Window
			//Add(canvas);



			Button btn_start = new Button ("Start");
			btn_start.SetSizeRequest(70, 30);
			//Add the Start Button
			//Add (btn_start);



			Add (canvas);
			ShowAll();
		}

		public void DrawCircl()
		{
			canvas.ExposeEvent += OnExpose;
			//ShowAll();
		}


		public void Refresh()
		{
			canvas.ExposeEvent += OnExpose;
			//ShowAll();
		}












		//This occurs when the canvas gets exposed.
		void OnExpose(object sender, ExposeEventArgs args)
		{
			DrawingArea area = (DrawingArea) sender;
			//The Gui application used for drawing vectors
			Cairo.Context cr =  Gdk.CairoHelper.Create(area.GdkWindow);

			cr.LineWidth = 9;
			cr.SetSourceRGB(0.7, 0.2, 0.0);

			int width, height;
			width = Allocation.Width;
			height = Allocation.Height;

			cr.Translate(width/2, height/2);
				//Creates an ARC, or circle. If width < height, return width, otherwise height.
			//cr.Arc(0, 0, (width < height ? width : height) / 2 - 10, 0, 2*Math.PI);
			cr.Arc (circleCenter_X, circleCenter_Y, 5, 0,2*Math.PI);
			//cr.ar
			cr.StrokePreserve();

			cr.SetSourceRGB(0.3, 0.4, 0.6);
			cr.Fill();

			((IDisposable) cr.GetTarget() ).Dispose();                                      
			((IDisposable) cr).Dispose();
		}

		//Draw XAxis Over time




	}
*/
}
