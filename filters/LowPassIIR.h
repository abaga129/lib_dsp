/*
  ==============================================================================

    LowPassIIR.h
    Created: 19 Apr 2016 1:19:25pm
    Author:  CTRecordings

  ==============================================================================
*/

#ifndef LOWPASSIIR_H_INCLUDED
#define LOWPASSIIR_H_INCLUDED

#include "BiQuadFilter.h"

namespace DSP
{

class LowPassIIR : public BiQuadFilter {
public:
	LowPassIIR(int numChannels, float fc, float fs);

	void update(float fc, float fs, float G);

private:
	float thetac;
	float omegac;
	float K;
	float sigma;
};


}//end namespace dsp
#endif  // LOWPASSIIR_H_INCLUDED
