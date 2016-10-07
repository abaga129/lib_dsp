#include "BandPassIIR.h"

using namespace DSP;

BandPassIIR::BandPassIIR(int numChannels, float fc, float fs) : BiQuadFilter(numChannels, fc, fs){
    lowpass = new LowPassIIR(numChannels, fc, fs);
    highpass = new HighPassIIR(numChannels, fc, fs);
}
float BandPassIIR::nextSample(float sample, int channel){
    return highpass->nextSample(lowpass->nextSample(sample, channel), channel);
}
void BandPassIIR::update(float fc, float fs){
    lowpass->update(fc, fs, 1);
    highpass->update(fc, fs, 1);
}

void BandPassIIR::setSampleRate(double sampleRate) {
    lowpass->setSampleRate(sampleRate);
    highpass->setSampleRate(sampleRate);
}

double BandPassIIR::getSampleRate(){
    return lowpass->getSampleRate();
}