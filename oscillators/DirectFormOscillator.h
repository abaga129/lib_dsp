#ifndef DIRECT_FORM_OSCILLATOR_H
#define DIRECT_FROM_OSCILLATOR_H

#include <cmath>
#include "../include/core.h"

/*
Simple class to generate oscillators or LFOs.  Good for generating waves that wont change frequency
during playback because it can make audible pops or clicks when changing frequency.  However it is slightly more
efficient than the GordonSmithOscillator.
*/
namespace DSP{
class DirectFormOscillator {
public:
    DirectFormOscillator();
    
    /*Must be called at the beginning of processBlock() in the Audio Processor
     *This method initializes all the values neccesary to begin oscillation.*/
    void setFrequency(float frequency, float sampleRate);
    
    /*Returns the next sample and increments the delaySamples*/
    float getNextSample(float input);
	
	/*Called to reset the output buffer*/
    void flush();
private:
    float theta;
    float fo; 
    float fs;
    
    float b1, b2;
    float yn1, yn2;
    
    bool init;
};
}
#endif