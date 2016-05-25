#ifndef DIRECT_FORM_OSCILLATOR2_CPP
#define DIRECT_FROM_OSCILLATOR2_CPP

#define PI 3.14159265

#include <cmath>

class DirectFormOscillator {
public:
    DirectFormOscillator();
    
    /*Must be called at the beginning of processBlock() in the Audio Processor
     *This method initializes all the values neccesary to begin oscillation.*/
    void setFrequency(float frequency, float sampleRate);
    
    /*Returns the next sample and increments the delaySamples*/
    float getNextSample(float input);
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