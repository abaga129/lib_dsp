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

using namespace dsp;

namespace dsp
{

class HighPassIIR : public BiQuadFilter {
public:
	HighPassIIR(int numChannels, float fc, float fs) : BiQuadFilter(numChannels, fc, fs) {
		update(fc, fs, 0);
}

	void update(float fc, float fs, float G) {
		HighPassIIR::fc = fc;
		HighPassIIR::fs = fs;

		thetac = PI * fc / fs;
		omegac = PI * fc;
		K = omegac / tanf(thetac);
		sigma = K * K + omegac * omegac + 2 * K * omegac;

		a0 = K * K / sigma;
		a1 = -2 * a0;
		a2 = a0;
		b1 = (-2 * K * K + 2 * omegac * omegac) / sigma;
		b2 = (-2 * K * omegac + K * K + omegac * omegac) / sigma;
		c0 = 1;
		d0 = 0;
}

private:
	float thetac;
	float omegac;
	float K;
	float sigma;
};


}//end namespace dsp
#endif  // HIGHPASSIIR_H_INCLUDED
