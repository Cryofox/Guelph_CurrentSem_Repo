using System;
using NAudio;
using NAudio.Wave;
using NAudio.Wave.SampleProviders;
using System.IO;
namespace Myo
{


	//Use Naudio for 
	public class Audio_Curve
	{
		//Apprantly in order to create a simple sound based on Frequency Amplitude
		//Along with other factors is a lot harder to do at runtime as it requires to create
		//a synthesizer, compute the sound, store it as a file, then play the file on the sound card.
		//Because of this it CAN also be slow.

		//Hack_1: pre-compute the soundfile for a "perfect" run.
		//Hack_2: Load some form of Noise file to play throughout the run
		//Hack_3; Toggle the Volume sliders on both the perfect run clip, and noise clip based on
		// where the user is.

		//This is what we use to Play the Noise File
		VolumeSampleProvider vwp_Noise;
		Custom_FunctionProvider vwp_Curve;
		WaveOut waveOutDevice_1;
		WaveOut waveOutDevice_2;
		public Audio_Curve (MathFunction mf)
		{
			string dir = Directory.GetCurrentDirectory ();
			//System.Media.SystemSounds.Asterisk.Play();
			waveOutDevice_1= new WaveOut();
			waveOutDevice_2= new WaveOut();

			Console.WriteLine ("File Location:"+dir);
			AudioFileReader aReader = new AudioFileReader("Audio_Files/audiocheck.net_greynoise.wav");
			vwp_Noise = new VolumeSampleProvider(aReader.ToSampleProvider());
			vwp_Curve = new Custom_FunctionProvider (2000, 0.25f);

			//SetVolume_1(1f);  
			waveOutDevice_1.Volume=0.5f;
//			SetVolume_2(0.5f);

//			vwp_Noise.Amplitude = 1;
			waveOutDevice_2.Init(vwp_Curve);
			waveOutDevice_1.Init(vwp_Noise);

			//	PlayAudio ();
			//waveOutDevice.Volume     //Range: 0 -> 1
		}


		public void Set_MaxTime(float newTime)
		{
			vwp_Curve.maxTime = newTime;
			waveOutDevice_2.Init(vwp_Curve);
		}
		public void Play_Dev2()
		{waveOutDevice_2.Play();			
		}
		public void Stop_Dev2()
		{
			waveOutDevice_2.Stop();		
		}

		public void Play_Dev1()
		{waveOutDevice_1.Play();			
		}
		public void Stop_Dev1()
		{waveOutDevice_1.Stop();			

		}

		public void Update_XY(float x, float y)
		{
			vwp_Curve.currentX = x;
			vwp_Curve.currentY = y;
		}


		public void SetVolume_1(float volume)
		{
			if (volume > 1)
				volume = 1;


			if(volume<0)
				volume=0;
			vwp_Curve.amplitude = (1-volume)*0.25f ; 
			volume *= 4;
			if (volume > 1)
				volume = 1;

			vwp_Noise.Amplitude=  (volume);
		}

		public void Close()
		{
			waveOutDevice_1.Dispose ();
			waveOutDevice_2.Dispose ();

		}





	}
}

