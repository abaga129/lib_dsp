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
#include <vector>

namespace DSP{
class Compressor{
public:
    Compressor(int numChannels, bool isDigital = true);
    void setRatio(float ratio){r = ratio;}
    void setThreshold(float threshold){th = threshold;}
    void setParams(float timeAttack, float timeRelease, float threshold, float ratio, float sampleRate);
    float getNextSample(float input, int channel);
private:
    std::vector<DSP::EnvelopeDetector*> detector;
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
}//end namespace DSP
#endif