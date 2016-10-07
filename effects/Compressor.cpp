#include "Compressor.h"

using namespace DSP;

Compressor::Compressor(int numChannels, bool isDigital){
    for(int i = 0; i < numChannels; i++){
		detector.push_back(new EnvelopeDetector(isDigital));
	}
	Compressor::numChannels = numChannels;
}

void Compressor::setParams(float timeAttack, float timeRelease, float threshold, float ratio, float sampleRate){
    for(int i = 0; i < numChannels; i++)
		detector[i]->setParams(timeAttack, timeRelease, sampleRate);
    setRatio(ratio);
    setThreshold(threshold);
}

float Compressor::getNextSample(float input, int channel){
	float level = detector[channel]->getNextValue(input);
    float compLevel;
    if(level <= th){
        return input;
    }
    else{
        //Calculate new level after compression then apply to input
        compLevel = (1/r) * (level - th) + th;
		
        return input * compLevel / level;
    }
}