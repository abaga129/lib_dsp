#include "DirectFormOscillator.h"

using namespace DSP;

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