using System;

using MyoSharp.Communication;
using MyoSharp.Device;
using MyoSharp.Exceptions;
using MyoSharp.ConsoleSample.Internal;
using MyoSharp.Poses;
namespace Myo
{
	public class Myo_Wrapper
	{
		#region Methods
		static OrientationDataEventArgs cachedEvent;
		static bool startSequence=false;
		static double currentPitch;

		public static double myo_Pitch{
			get{ return  currentPitch;}
		}

		public static bool myo_startSequence{
			get{ return  startSequence;}
		}



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
					e.Myo.OrientationDataAcquired += Myo_OrientationDataAcquired;

					//var pose = HeldPose.Create(e.Myo, Pose.Fist, Pose.FingersSpread);
					var pose = HeldPose.Create(e.Myo, Pose.Fist);
					pose.Interval = TimeSpan.FromSeconds(0.5);



					// for every Myo that connects, listen for special sequences
				var sequence = PoseSequence.Create(e.Myo,Pose.WaveOut,Pose.WaveIn);
					sequence.PoseSequenceCompleted += Sequence_PoseSequenceCompleted;

				};

				// listen for when the Myo disconnects
				hub.MyoDisconnected += (sender, e) =>
				{
					Console.WriteLine("Oh no! It looks like {0} arm Myo has disconnected!", e.Myo.Arm);
					e.Myo.PoseChanged -= Myo_PoseChanged;
					e.Myo.OrientationDataAcquired -= Myo_OrientationDataAcquired;
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
			Console.WriteLine ("Pose =" + e.Myo.Pose);
			if (e.Myo.Pose == Pose.WaveOut)
				startSequence = true;

		}

		private static void Myo_Unlocked(object sender, MyoEventArgs e)
		{
			Console.WriteLine("{0} arm Myo has unlocked!", e.Myo.Arm);
		}

		private static void Myo_Locked(object sender, MyoEventArgs e)
		{
			Console.WriteLine("{0} arm Myo has locked!", e.Myo.Arm);
		}

		private static void Sequence_PoseSequenceCompleted(object sender, PoseSequenceEventArgs e)
		{
			Console.WriteLine("{0} arm Myo has performed a pose sequence!", e.Myo.Arm);
			e.Myo.Vibrate(VibrationType.Medium);
			startSequence = true;
		}

		public static void VibrateMyo()
		{
			cachedEvent.Myo.Vibrate (VibrationType.Short);
		}


		private static void Myo_OrientationDataAcquired(object sender, OrientationDataEventArgs e)
		{
			cachedEvent = e;
			const float PI = (float)System.Math.PI;

			// convert the values to a 0-9 scale (for easier digestion/understanding)
			//var roll = (int)((e.Roll + PI) / (PI * 2.0f) * 10);
			var roll = (int)((e.Roll + PI) / (PI * 2.0f) * 10);
			var pitch = e.Pitch;//(int)((e.Pitch + PI) / (PI * 2.0f) * 10);
			var yaw = (int)((e.Yaw + PI) / (PI * 2.0f) * 10);

			currentPitch = pitch;
			//Console.WriteLine(@"Roll: {0}", roll);
			//Console.WriteLine(@"Pitch: {0}", pitch);
			//Console.WriteLine(@"Yaw: {0}", yaw);
		}
		#endregion

	}
}