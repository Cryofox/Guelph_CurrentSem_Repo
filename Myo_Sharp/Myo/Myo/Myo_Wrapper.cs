using System;

using MyoSharp.Communication;
using MyoSharp.Device;
using MyoSharp.Exceptions;
using MyoSharp.ConsoleSample.Internal;

namespace Myo
{
	public class Myo_Wrapper
	{
		#region Methods
		public static void Myo_Start()
		{
			Console.WriteLine ("Entered MW");
			// create a hub that will manage Myo devices for us

			var channel = Channel.Create (
				              ChannelDriver.Create (ChannelBridge.Create (),
					              MyoErrorHandlerDriver.Create (MyoErrorHandlerBridge.Create ())));

			IHub hub = Hub.Create (channel);
				// listen for when the Myo connects
				hub.MyoConnected += (sender, e) =>
				{
					Console.WriteLine("Myo {0} has connected!", e.Myo.Handle);
					Console.WriteLine("YAY1");
					e.Myo.Vibrate(VibrationType.Short);
					e.Myo.PoseChanged += Myo_PoseChanged;
					//e.Myo.Locked += Myo_Locked;
					//e.Myo.Unlocked += Myo_Unlocked;
				};

				// listen for when the Myo disconnects
				hub.MyoDisconnected += (sender, e) =>
				{
					Console.WriteLine("Oh no! It looks like {0} arm Myo has disconnected!", e.Myo.Arm);
					e.Myo.PoseChanged -= Myo_PoseChanged;
					//e.Myo.Locked -= Myo_Locked;
					//e.Myo.Unlocked -= Myo_Unlocked;
				};

				// start listening for Myo data
				channel.StartListening();
				Console.WriteLine ("Listening to channel...");
				// wait on user input
				ConsoleHelper.UserInputLoop(hub);


			Console.WriteLine ("Exit MW");
		}
		#endregion

		#region Event Handlers
		private static void Myo_PoseChanged(object sender, PoseEventArgs e)
		{
			Console.WriteLine("{0} arm Myo detected {1} pose!", e.Myo.Arm, e.Myo.Pose);
		}

		private static void Myo_Unlocked(object sender, MyoEventArgs e)
		{
			Console.WriteLine("{0} arm Myo has unlocked!", e.Myo.Arm);
		}

		private static void Myo_Locked(object sender, MyoEventArgs e)
		{
			Console.WriteLine("{0} arm Myo has locked!", e.Myo.Arm);
		}
		#endregion
	}
}