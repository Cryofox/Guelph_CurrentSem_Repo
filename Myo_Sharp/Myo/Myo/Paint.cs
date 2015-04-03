using Gtk;
using Cairo;
using System;
namespace Myo
{
	public class Paint : Gtk.Window
	{

		//How much degree freedom to allow user to be within

		//Setup Graphing Parameters
		public int param_Max_x	=  6;
		public int param_Min_x	= -6;

		public int param_Max_y	=  10;
		public int param_Min_y	= -10;

	
		float divisions = 8;

		//The Color Code
		float R=1,  G=1, B=1, A=1;




		Label lbl_MyoPose;
		Label lbl_MyoPosition;


		delegate void DrawShape(Cairo.Context ctx, PointD start, PointD end);

		public ImageSurface surface;

		DrawShape Painter;

		DrawingArea area;


		//Accessor for Paint Start and End

		//Accessor works by creating a value, and inside we choose what is returned
		//and what is set by using the get,set, and value keywords.
		//Heads up Justin, you can also hide the set and get functionality by setting
		//eithor one to private. Useful incase you only want outside functions to GET and not SET
		public PointD paint_Start{
			set{ Start = value; }
			get{ return Start;}
		}

		public PointD paint_End{
			set{ End = value; }
			get{ return End;}
		}


		public DrawingArea paint_Area{
			get{ return area;}
		}



		//These global Variables are What are used for Drawing
		PointD Start, End;

		public bool isDrawing;
		public bool isDrawingPoint;

		Button line;
		Button pen;






		public Paint() : base("The Application")
		{
			SetDefaultSize(500, 500);
			SetPosition(WindowPosition.Center);
			//The WindowSize
			int width = Allocation.Width;
			int height = Allocation.Height;

			surface = new ImageSurface(Format.Argb32, 500, 500);


			area = new DrawingArea();


			area.AddEvents
			(
				//Mouse Related Events
				(int)Gdk.EventMask.PointerMotionMask
				|(int)Gdk.EventMask.ButtonPressMask
				|(int)Gdk.EventMask.ButtonReleaseMask
			);

			//Repaint the Canvas Internally.
			area.ExposeEvent += OnDrawingAreaExposed;
			//Do this on MousePress inside Area
			area.ButtonPressEvent += OnMousePress;
			//Do this on MouseReleased inside Area
			area.ButtonReleaseEvent += OnMouseRelease;

			//Do this if a Motion Occurs inside the Drawing Area
			area.MotionNotifyEvent += OnMouseMotion;
			//Red X of the Window
			DeleteEvent += delegate { Application.Quit(); };



			//The Boundary for the Drawing Application
			Start 	= new PointD(0.0, 0.0);
			End 	= new PointD(width,height);



			isDrawing = false;
			isDrawingPoint = false;

			VBox vbox = new VBox();

			vbox.Add(area);
			HBox hbox = new HBox ();


			lbl_MyoPose = new Label ("ll");//("MyoPose:_______");
			lbl_MyoPosition = new Label ("Myo[x][Y]: { , } ");
			//line = new Button("Line");
			//pen = new Button("Pen");


			//hbox.Add (lbl_MyoPose);
			//hbox.Add(lbl_MyoPosition);


			//hbox.Add(line);
			//hbox.Add(pen);


			Alignment halign = new Alignment  (1, 0, 0.25f, 0);

			//Align buttons on right
			halign.Add(hbox);



			vbox.PackStart(halign, false, false, 5);

			//line.Clicked += LineClicked;
			//pen.Clicked += PenClicked;

			Add(vbox);
			Add(area);

			//Initialize the Painter
			Painter = new DrawShape(DrawLine);


			ShowAll();
		}

		//This Has to be Done before Anything else
		void DrawBackdrop(Cairo.Context ctx, PointD start, PointD end)
		{
			//Draw The Backdrop
			ctx.Rectangle(end, 500, 500);
			ctx.Stroke();
			area.QueueDraw();
		}

		//This is where the Pre-set drawing code is.
		void OnDrawingAreaExposed(object source, ExposeEventArgs args)
		{
			Cairo.Context ctx;
			//cr.SetSourceRGB(0.7, 0.2, 0.0);
			using (ctx = Gdk.CairoHelper.Create(area.GdkWindow))
			{
				//Set Background Color

				ctx.SetSourceRGB(0, 0, 0);
				ctx.Rectangle (0, 0, 500, 500);
				ctx.Fill();


				//This is how the Axis will be Drawn. The Next Step is positioning all the lines
				//Draw a Line, 

				//DrawLine (ctx, new PointD (0.0, 0.0), new PointD (500, 500));

				//Set DrawLines 
				//DrawLine (ctx, new PointD (100,0),new PointD (500, 500));

				//Draw Axis Lines
				for (int i = 0; i < (int)(divisions); i++) 
				{
					float curX = Math.Abs(param_Min_x) + Math.Abs(param_Max_x);
					//curX /= (i+1);
					//curX += param_Min_x;

					float divCount = (500) / divisions;
					divCount *= i;
					//curX /= divisions-( (i));
					//curX *= 500;
					//curX += 500;
					curX = divCount;
					//Console.WriteLine ("CurX="+curX+",I="+i);

					//Draw Vertical Lines

					//If Middle Color Green
					if( i == ((int)divisions/2)) 
					{
						R = 0;
						G = 1;
						B = 0;
					} else 
					{
						R = 0.5F;
						G = 0.5F;
						B = 0.5F;
					}
					//Draw Vertical Lines
					DrawLine (ctx, new PointD ((int)(curX), 0), new PointD ((int)(curX), 500));

					//Draw Horizontal Lines
					DrawLine (ctx, new PointD (0, (int)(curX)), new PointD (500, (int)(curX)));
					/*
					//Draw the Modifier
					R = 1;
					G = 0;
					B = 0.5f;
					A = 0.25f;

					//This will be Replaced with the Function
					DrawLine (ctx, new PointD ((int)(curX), (500*0.75)), new PointD ((int)(curX), (500*0.25)) ) ;  

					A = 1;*/

				}
				ctx.SetSource(new SurfacePattern(surface));
				ctx.Paint();












				((IDisposable) ctx.GetTarget()).Dispose ();
				((IDisposable)ctx).Dispose ();
			}

			if (isDrawing)
			{
				//This Is responsible for Drawing the Line Stroke, from Point A->B
				using (ctx = Gdk.CairoHelper.Create(area.GdkWindow))
				{
					Painter(ctx, Start, End);

					((IDisposable) ctx.GetTarget()).Dispose ();
					((IDisposable)ctx).Dispose ();
				}
			}
		}



		void OnMousePress(object source, ButtonPressEventArgs args)
		{
			Start.X = args.Event.X;
			Start.Y = args.Event.Y;

			End.X = args.Event.X;
			End.Y = args.Event.Y;

			isDrawing = true;
			area.QueueDraw();
		}

		void OnMouseRelease(object source, ButtonReleaseEventArgs args)
		{
			End.X = args.Event.X;
			End.Y = args.Event.Y;

			isDrawing = false;

			using (Context ctx = new Context(surface))
			{
				Painter(ctx, Start, End);
			}

			area.QueueDraw();
		}

		void OnMouseMotion(object source, MotionNotifyEventArgs args)
		{
			if (isDrawing)
			{
				End.X = args.Event.X;
				End.Y = args.Event.Y;

				if(isDrawingPoint)
				{
					using (Context ctx = new Context(surface))
					{
						Painter(ctx, Start, End);
					}
				}
				area.QueueDraw();
			}
		}






		void DrawLine(Cairo.Context ctx, PointD start, PointD end)
		{
			ctx.SetSourceRGBA(R,G,B,A);
			ctx.MoveTo(start);
			ctx.LineTo(end);
			ctx.Stroke();

		}

		void DrawPoint(Cairo.Context ctx, PointD start, PointD end)
		{
			ctx.SetSourceRGBA(R, G,B,A);
			ctx.Rectangle(end, 1, 1);
			ctx.Stroke();
		}




		public void DrawPoint(PointD start, PointD end)
		{
			R = 1;
			G = 1;
			B = 1;
			A = 1;
			Cairo.Context ctx = new Context (surface);
			DrawPoint (ctx, start, end);
			area.QueueDraw();
		}




		public void DrawPoint_User(PointD start, PointD end)
		{
			R = 0;
			G = 0;
			B = 1;
			Cairo.Context ctx = new Context (surface);
			DrawPoint (ctx, start, end);
			area.QueueDraw();
		}

		public void DrawPoint_User_DontSave(PointD start, PointD end)
		{
			R = 0;
			G = 0;
			B = 1;
			Cairo.Context ctx = new Context (surface);
			Cairo.Context ctx2 = new Context (surface);

			//Cache Surface
			DrawPoint (ctx, start, end);


		}

		public void DrawLine(PointD start, PointD end)
		{
			Cairo.Context ctx = new Context (surface);
			DrawLine (ctx, start, end);
			area.QueueDraw();
		}

		public void DrawLine_Modifier(PointD start, PointD end)
		{
			//Draw the Modifier
			R = 1;
			G = 0;
			B = 0.5f;
			A = 0.25f;
			Cairo.Context ctx = new Context (surface);
			DrawLine (ctx, start, end);
			area.QueueDraw();
			A = 1;
		}

		//Button Functions
		//----------------------
		void LineClicked(object sender, EventArgs args)
		{
			isDrawingPoint = false;
			Painter = new DrawShape(DrawLine);
		}

		void PenClicked(object sender, EventArgs args)
		{
			isDrawingPoint = true;
			Painter = new DrawShape(DrawPoint);
		}
		//=====================


	}
}