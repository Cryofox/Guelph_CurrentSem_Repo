using Gtk;
using Cairo;
using System;
namespace Myo
{
	public class Paint : Gtk.Window
	{

		Label lbl_MyoPose;
		Label lbl_MyoPosition;


		delegate void DrawShape(Cairo.Context ctx, PointD start, PointD end);

		ImageSurface surface;
		DrawingArea area;
		DrawShape Painter;

		//These global Variables are What are used for Drawing
		PointD Start, End;

		bool isDrawing;
		bool isDrawingPoint;

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
			Start = new PointD(0.0, 0.0);
			End = new PointD(width,height);



			isDrawing = false;
			isDrawingPoint = false;

			VBox vbox = new VBox();

			vbox.Add(area);
			HBox hbox = new HBox ();




			lbl_MyoPose = new Label ("ll");//("MyoPose:_______");
			lbl_MyoPosition = new Label ("Myo[x][Y]: { , } ");
			line = new Button("Line");
			pen = new Button("Pen");


			hbox.Add (lbl_MyoPose);
			hbox.Add(lbl_MyoPosition);


			hbox.Add(line);
			hbox.Add(pen);


			Alignment halign = new Alignment  (1, 0, 0.25f, 0);

			//Align buttons on right
			halign.Add(hbox);



			vbox.PackStart(halign, false, false, 5);

			line.Clicked += LineClicked;
			pen.Clicked += PenClicked;

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
				DrawLine (ctx, new PointD (0.0, 0.0), new PointD (500, 500));

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
			ctx.SetSourceRGB(1, 1,1);
			ctx.MoveTo(start);
			ctx.LineTo(end);
			ctx.Stroke();
		}

		void DrawPoint(Cairo.Context ctx, PointD start, PointD end)
		{
			ctx.SetSourceRGB(1, 1,1);
			ctx.Rectangle(end, 1, 1);
			ctx.Stroke();
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