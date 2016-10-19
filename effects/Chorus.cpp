#include "Chorus.h"

using namespace DSP;

Chorus::Chorus() : modDly(){}

float Chorus::getNextSample(float input){
    return modDly.getNextSample(input);
}

void Chorus::setSpeed(float frequency, float sampleRate){
    modDly.setFrequency(frequency, sampleRate);
}

void Chorus::setDepth(int milliseconds, float sampleRate){
    modDly.initialize(msToSamples(7, sampleRate), msToSamples(milliseconds, sampleRate), 0.99, 0.5);
}
