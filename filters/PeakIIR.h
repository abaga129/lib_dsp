/*
  ==============================================================================

    PeakIIR.h
    Created: 19 Apr 2016 1:04:20pm
    Author:  CTRecordings

  ==============================================================================
*/

#ifndef PEAKIIR_H_INCLUDED
#define PEAKIIR_H_INCLUDED

#include "BiQuadFilter.h"

namespace DSP
{

class PeakIIR : public BiQuadFilter {
public:
	PeakIIR(int numChannels, float G, float fc, float Q, float fs);

	void update(float fc, float fs, float G);

private:
	float thetac;
	float mu;
	float sigma;
	float beta;
	float gamma;
	float Q; //Quality factor A.K.A bandwidth
	int G;
};


}//end namespace dsp
#endif  // PEAKIIR_H_INCLUDED
