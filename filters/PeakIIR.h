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

using namespace dsp;

namespace dsp
{

class PeakIIR : public BiQuadFilter {
public:
	PeakIIR(int numChannels, float G, float fc, float Q, float fs) : BiQuadFilter(numChannels, fc, fs){
		PeakIIR::Q = Q;
		update(fc, fs, G);
}

	void update(float fc, float fs, float G) {
		PeakIIR::fc = fc;
		PeakIIR::fs = fs;
		PeakIIR::G = G;
		thetac = 2 * PI * fc / fs;
		mu = powf(10, G / 20);
		sigma = 4 / (1 + mu);
		beta = 0.5 * ((1 - sigma * tanf(thetac / (2 * Q))) / (1 + sigma * tanf(thetac / (2 * Q))));
		gamma = (0.5 + beta) * cosf(thetac);
		a0 = 0.5 - beta;
		a1 = 0.0f;
		a2 = -a0;
		b1 = -2 * gamma;
		b2 = 2 * beta;
		c0 = mu - 1.0;
		d0 = 1.0;
}

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
