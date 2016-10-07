#include "BiQuadFilter.h"

using namespace DSP;
/*
Calculates and returns the next output sample based on the sample that is input.
Channel specifies which channel is being processed.
*/
void BiQuadFilter::setSampleRate(double sampleRate) { fs = sampleRate; }
double BiQuadFilter::getSampleRate() { return fs; }
BiQuadFilter::BiQuadFilter(int numChannels, int centerFrequency, double sampleRate){
	fc = centerFrequency;
	BiQuadFilter::numChannels = numChannels;
	fs = sampleRate;
	for (int i = 0; i < numChannels; i++){
		Buffer *b = new Buffer(2);
		inputBuffer.push_back(*b);
		b = new Buffer(2);
		outputBuffer.push_back(*b);
	}
}

float BiQuadFilter::nextSample(float sample, int channel){
	float output = a0 * sample + a1 * inputBuffer[channel].getSample(0) + a2 * inputBuffer[channel].getSample(1)
				 - b1 * outputBuffer[channel].getSample(0) - b2 * outputBuffer[channel].getSample(1);
				 
	outputBuffer[channel].setSample( outputBuffer[channel].getSample(0),1);
	outputBuffer[channel].setSample(output, 0);
	inputBuffer[channel].setSample(inputBuffer[channel].getSample(0), 1);
	inputBuffer[channel].setSample(sample, 0);
	
	output = 0.5 * c0 * output + 0.5 * d0 * sample;	
	return output;
}

void BiQuadFilter::update(float fc, float fs, float G){}