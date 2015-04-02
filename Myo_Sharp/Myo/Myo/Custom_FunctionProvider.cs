using System;
using NAudio.Wave;

namespace Myo
{
	public class Custom_FunctionProvider : WaveStream
	{
		int sample;

		public float currentX=0;
		public float currentY=0;

		private double time;
		public float maxTime=2.5f;

		public double frequency;
		public double amplitude;

		public Custom_FunctionProvider(float freq, float amp)
		{
			this.frequency = freq;
			this.amplitude = amp; // let's not hurt our ears            
		}



		//This Read Method is called internally from NAudio
		public override int Read(byte[] buffer, int offset, int count)
		{
			int sampleRate = WaveFormat.SampleRate;
			int samples = count / 2;
			for (int i = 0; i < samples && time < (44100 * maxTime); i++)
			{
				double sine = 0.25*amplitude * Math.Sin(Math.PI * 2 * (frequency*(currentY)) * time);
				//sine = 0.25  * frequency * currentY * time *3;
				time += 1.0 / 44100;
				short truncated = (short)Math.Round(sine * (Math.Pow(2,15) ));
				buffer[i * 2] = (byte)(truncated & 0x00ff);
				buffer[i * 2 + 1] = (byte)((truncated & 0xff00) >> 8);
				//buffer[i+offset] = (byte)(truncated & 0x00ff);
			}
			//return count;
			return (time < (44100 * maxTime)) ? count : 0;

		}
	


		public override long Position
		{
			get;
			set;
		}

		public override long Length
		{
			get { return long.MaxValue;}
		}

		public override WaveFormat WaveFormat
		{
			get { return new WaveFormat(44100, 16, 1); }
		}
	}
}

