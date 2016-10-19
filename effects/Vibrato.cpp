#include "Vibrato.h"

using namespace DSP;

Vibrato::Vibrato() : modDly(){}

float Vibrato::getNextSample(float input){
    return modDly.getNextSample(input);
}

void Vibrato::setSpeed(float frequency, float sampleRate){
    modDly.setFrequency(frequency, sampleRate);
}

void Vibrato::setDepth(int milliseconds, float sampleRate){
    modDly.initialize(0, msToSamples(milliseconds, sampleRate), 0, 1);
}