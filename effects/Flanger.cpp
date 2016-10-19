#include "Flanger.h"

using namespace DSP;

Flanger::Flanger() : modDly(){}

void Flanger::setDepth(float milliseconds, float sampleRate){
    modDly.initialize(0, msToSamples(milliseconds, sampleRate), 0.99, 0.5);
}

float Flanger::getNextSample(float input){
    return modDly.getNextSample(input);
}

void Flanger::setSpeed(float frequency, float sampleRate){
    modDly.setFrequency(frequency, sampleRate);
}