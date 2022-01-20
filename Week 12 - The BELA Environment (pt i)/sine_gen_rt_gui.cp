#include <Bela.h>
#include <cmath>

#include <libraries/Gui/Gui.h>
#include <libraries/GuiController/GuiController.h>

Gui gui;
GuiController controller;

float gPhase = 0;


bool setup(BelaContext *context, void *userData)
{
	//Setup GUI
	gui.setup(context->projectName);
	controller.setup(&gui, "Sine");
	controller.addSlider("Hz", 440, 150, 800, 0);
	controller.addSlider("Vol", 0.5, 0, 1, 0);
	
    return true;
}

void render(BelaContext *context, void *userData)
{
	float freq = controller.getSliderValue(0); //Assign GUI vaue to variable
	float amp = controller.getSliderValue(1); //Assign GUI vaue to variable
	
	for (unsigned int n = 0; n < context->audioFrames; n++) {
	    
		gPhase += (2.0 * M_PI * freq / context->audioSampleRate); //The argument of the sine function in stored in a variable
		if(gPhase >= 2*M_PI)
			gPhase -= 2*M_PI;
			
		float out = amp * sin(gPhase); //Sine wave is calculated using the variable created in line 31
		
		for(unsigned int channel = 0; channel < context->audioOutChannels; channel++) {
		    audioWrite(context, n, channel, out);
		}
    }
}

void cleanup(BelaContext *context, void *userData)
{
	// Nothing to do here
}
