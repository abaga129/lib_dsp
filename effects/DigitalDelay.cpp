#include "DigitalDelay.h"

using namespace DSP;

DigitalDelay::DigitalDelay(size_t delayAmount, float fb, float wet){
	this->delayAmount = delayAmount;
	this->fb = fb;
	this->wet = wet;
    buffer = new Buffer(delayAmount);
}

float DigitalDelay::getNextSample(float sample){
    float yn = buffer->read();
    buffer->write(sample + fb * yn);
    return wet * yn + sample * (1 - wet);
}

void DigitalDelay::resize(size_t delayAmount){
    buffer->resize(delayAmount);
}

void DigitalDelay::setFeedback(float feedback){ fb = feedback; }

void DigitalDelay::setWet(float wet_amount){ wet = wet_amount; }

void DigitalDelay::flush(){
    
}