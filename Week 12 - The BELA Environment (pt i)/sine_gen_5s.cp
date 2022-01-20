#include <Bela.h>
#include <cmath>
#include <vector>
#include <libraries/AudioFile/AudioFile.h>	

//This code does not generate audio in real-time. It produces a 5 second sine wave which is then play in a loop
//the 5 seconnds sine wave is also recorded on a .wav file

float gFrequency = 440.0;	// Frequency of the sine wave in Hz
float gAmplitude = 0.6;		// Amplitude of the sine wave (1.0 is maximum)
float gDuration = 5.0;		// Length of file to generate, in seconds

std::string gFilename = "output.wav"; //Names the file on which the sine will be saved
std::vector<float> gSampleData; //Creates a vector ro store the sine wave data
int gNumSamples = 0;
int gReadPointer = 0;

// This function calculates a sine wave, storing it in a buffer of length numSamples.
void calculate_sine(float *buffer, int numSamples, float sampleRate)
{
	// Generate the sine wave sample-by-sample for the whole duration
	for (int n = 0; n < numSamples; n++) {
	    // Calculate one sample of the sine wave
		float out = gAmplitude * sin(2.0 * M_PI * n * gFrequency / sampleRate);
		// Store the sample in the buffer
		buffer[n] = out;
	}
}

bool setup(BelaContext *context, void *userData)
{
	float sampleRate = context->audioSampleRate;	//Sample Rate is taken from the BelaContext structure
	gNumSamples = gDuration * sampleRate;	//Duration*sampleRate = number of total samples

	gSampleData.resize(gNumSamples);					
	
	calculate_sine(gSampleData.data(), gNumSamples, sampleRate);

	AudioFileUtilities::write(gFilename, gSampleData.data(), 1, gNumSamples, sampleRate);	//Writes the buffer

	return true;
}

void render(BelaContext *context, void *userData) //Callback funtion
{
    for(unsigned int n = 0; n < context->audioFrames; n++) {
        // Increment read pointer and reset to 0 when end of file is reached
        if(++gReadPointer >= gNumSamples)
            gReadPointer = 0;

    	for(unsigned int channel = 0; channel < context->audioOutChannels; channel++) {
    	    float out = gSampleData[gReadPointer];
    		audioWrite(context, n, channel, out); // Write the sample to every audio output channel (1=left, 2=right)
    	}
    }
}

void cleanup(BelaContext *context, void *userData)
{
}
