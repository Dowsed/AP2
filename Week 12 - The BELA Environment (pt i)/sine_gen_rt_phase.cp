#include <Bela.h>
#include <cmath>

float gFrequency = 440.0;	// Frequency of the sine wave in Hz
float gAmplitude = 0.6;		// Amplitude of the sine wave (1.0 is maximum)
float gPhase = 0;


bool setup(BelaContext *context, void *userData)
{
    return true;
}

void render(BelaContext *context, void *userData)
{
   	// This for() loop goes through all the samples in the block
	for (unsigned int n = 0; n < context->audioFrames; n++) {
	    
	    //PHASE WRAPPING!
		gPhase += (2.0 * M_PI * gFrequency / context->audioSampleRate);
		if(gPhase >= 2*M_PI)
			gPhase -= 2*M_PI;
			
		float out = gAmplitude * sin(gPhase);
		
		for(unsigned int channel = 0; channel < context->audioOutChannels; channel++) {
		    audioWrite(context, n, channel, out);
		}
    }
    gFrequency *= 1.00001; //Increase the frequency gradually
}

// cleanup() runs once at the end of the program
void cleanup(BelaContext *context, void *userData)
{
	// Nothing to do here
}
