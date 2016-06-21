/************************************
* Author: Ethan Reker
* Date Created: June 06, 2016
* 
* Purpose: Provide a simple class
*   for audio compression.
*
************************************/

#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "../core/EnvelopeDetector.h"

class Compressor{
public:
    Compressor(int numChannels, bool isDigital = true);
    void setRatio(float ratio){r = ratio;}
    void setThreshold(float threshold){th = threshold;}
    void setParams(float timeAttack, float timeRelease, float threshold, float ratio, float sampleRate);
    float getNextSample(float input, int channel);
private:
    vector<EnvelopeDetector*> detector;
    //attack time
    float attack;
    //release time
    float release;
    //compression ratio
    float r;
    //threshold
    float th;
	
	int numChannels;
};

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

#endif