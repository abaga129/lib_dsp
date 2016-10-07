#include "HighPassIIR.h"

using namespace DSP;

HighPassIIR::HighPassIIR(int numChannels, float fc, float fs) : BiQuadFilter(numChannels, fc, fs) {
		update(fc, fs, 0);
}

void HighPassIIR::update(float fc, float fs, float G) {
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