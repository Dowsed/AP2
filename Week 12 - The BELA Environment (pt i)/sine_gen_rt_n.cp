#include <Bela.h>
#include <cmath>

float gFrequency = 440.0;	// Frequency of the sine wave in Hz
float gAmplitude = 0.6;		// Amplitude of the sine wave (1.0 is maximum)
unsigned int gTotalSample = 0;

bool setup(BelaContext *context, void *userData)
{
    return true;
}

void render(BelaContext *context, void *userData)
{
   	// This for() loop goes through all the samples in the block
	for (unsigned int n = 0; n < context->audioFrames; n++) {
	    
	   
		float out = gAmplitude * sin(2.0 * M_PI * n * gFrequency / context->audioSampleRate);
		
		for(unsigned int channel = 0; channel < context->audioOutChannels; channel++) {
		    audioWrite(context, n, channel, out);
		}
    }
    //gFrequency *= 1.00001; //Increase the frequency gradually
}

void cleanup(BelaContext *context, void *userData)
{
	// Nothing to do here
}
