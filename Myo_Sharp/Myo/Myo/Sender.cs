using System;

namespace Myo
{
	public class Sender
	{
		//
		GUI_Window gui_W;
		public Sender(GUI_Window gw)
		{
			gui_W = gw;
		}

		public void Send_XY(float x, float y)
		{
			gui_W.circleCenter_X= (int)x;
			gui_W.circleCenter_Y= (int)y;	
			gui_W.Refresh ();
		}
	}
}

