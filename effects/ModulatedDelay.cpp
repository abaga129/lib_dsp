#include "ModulatedDelay.h"

using namespace DSP;

ModulatedDelay::ModulatedDelay(): buffer(), osc(){}
ModulatedDelay::ModulatedDelay(size_t minDelay, size_t maxDelay, float fb, float wet) : buffer(maxDelay), osc(){
    this->fb = fb;
    this->wet = wet;
    depth = 1;
    
    this->scalar = (maxDelay - minDelay) / 2;
    
    this->centerDelay = minDelay + scalar;

    buffer.initialize(maxDelay);
    buffer.setReadIndex(minDelay);
    buffer.setWriteIndex(maxDelay);
}
void ModulatedDelay::initialize(size_t minDelay, size_t maxDelay, float fb, float wet){
    this->fb = fb;
    this->wet = wet;
    depth = 1;
    
    this->scalar = (maxDelay - minDelay) / 2;
    
    this->centerDelay = minDelay + scalar;

    buffer.initialize(maxDelay);
    buffer.setReadIndex(minDelay);
    buffer.setWriteIndex(maxDelay);
}

float ModulatedDelay::getNextSample(float sample){
    float oscVal = osc.getNextSample(0);
    int currentDelay = centerDelay + (oscVal * scalar);
    float yn = buffer.read();
    buffer.shiftReadIndex(prevDelay - currentDelay);
    prevDelay = currentDelay;
    buffer.write(sample + fb * yn);
    return wet * yn + sample * (1 - wet);
    return 0;
}

void ModulatedDelay::resize(size_t delayAmount){
    buffer.resize(delayAmount);
}

void ModulatedDelay::flush(){}

void ModulatedDelay::setDepth(float depth){
    this->depth = depth;
}

void ModulatedDelay::setFeedback(float feedback){
    fb = feedback;
}

void ModulatedDelay::setWet(float wet_amount){
    wet = wet_amount;
}

void ModulatedDelay::setFrequency(float frequency, float sampleRate){
    osc.setFrequency(frequency, sampleRate);
    oscFreq = frequency;
}

int ModulatedDelay::getWriteIndex(){
    return buffer.getWriteIndex();
}

int ModulatedDelay::getReadIndex(){
    return buffer.getReadIndex();
}