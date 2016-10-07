/*
  ==============================================================================

    HighPassIIR.h
    Created: 19 Apr 2016 1:19:04pm
    Author:  CTRecordings

  ==============================================================================
*/

#ifndef HIGHPASSIIR_H_INCLUDED
#define HIGHPASSIIR_H_INCLUDED

#include "BiQuadFilter.h"

namespace DSP
{

class HighPassIIR : public DSP::BiQuadFilter {
public:
	HighPassIIR(int numChannels, float fc, float fs);

	void update(float fc, float fs, float G);

private:
	float thetac;
	float omegac;
	float K;
	float sigma;
};


}//end namespace dsp
#endif  // HIGHPASSIIR_H_INCLUDED
