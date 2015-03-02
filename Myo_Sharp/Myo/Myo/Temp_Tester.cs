using System;
using System.Threading; // For Threading
namespace Myo
{
	public class Temp_Tester
	{
		//Private
		private Sender _gui_Sender;
		public Temp_Tester (Sender gui_sender)
		{
			_gui_Sender = gui_sender;
		}


		public void EntryPoint()
		{
			float x = 0;
			float y = 0;
			while (true) 
			{
				//Infinite Loop
				Console.WriteLine ("I'm spamming your console :)");
				_gui_Sender.Send_XY ((x = x + 1), 0);
				Thread.Sleep (5);
			}

		}

	}
}

