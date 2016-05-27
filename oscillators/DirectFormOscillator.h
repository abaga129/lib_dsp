#ifndef DIRECT_FORM_OSCILLATOR_H
#define DIRECT_FROM_OSCILLATOR_H

#include <cmath>
#include "../core/core.h"

/*
Simple class to generate oscillators or LFOs.  Good for generating waves that wont change frequency
during playback because it can make audible pops or clicks when changing frequency.  However it is slightly more
efficient than the GordonSmithOscillator.
*/
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

DirectFormOscillator::DirectFormOscillator(){
    init = false;
}

void DirectFormOscillator::setFrequency(float frequency, float sampleRate){
    if(fo != frequency){
        flush();
        fo = frequency;
    }
    fs = sampleRate;
	theta = 2 * PI * fo / fs;
    b1 = -2 * cosf(theta);
    b2 = 1.0f;
    if(!init){
        yn1 = sinf(-1 * theta);
        yn2 = sinf(-2 * theta);
        init = true;
    }
}

float DirectFormOscillator::getNextSample(float input){
    float output = - (b1 * yn1) - (b2 * yn2);
    yn2 = yn1;
    yn1 = output;
    return output;
}

void DirectFormOscillator::flush(){
    yn1 = yn2 = 0;
    init = false;
}

#endif