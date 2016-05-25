/*
  ==============================================================================

    BiQuadFilter.h
    Created: 15 Apr 2016 10:27:57pm
    Author:  CTRecordings

	This is an abstract class to be inherited to create different types of IIR
	Filters.

  ==============================================================================
*/

#ifndef BIQUADFILTER_H_INCLUDED
#define BIQUADFILTER_H_INCLUDED
#define PI 3.14159265359

#include<stack>
#include<vector>

using std::stack;
using std::vector;

class BiQuadFilter {
protected:
	
public:
	BiQuadFilter(int numChannels, int centerFrequency, double sampleRate) {
		for (int i = 0; i < numChannels; i++) {
			vector<float> *v = new vector<float>;
			v->push_back(0);
			v->push_back(0);
			inputBuffer.push_back(*v);

			v = new vector<float>;
			v->push_back(0);
			v->push_back(0);
			outputBuffer.push_back(*v);
		}
		BiQuadFilter::fc = centerFrequency;
		BiQuadFilter::numChannels = numChannels;
		BiQuadFilter::fs = sampleRate;
	}
	
	float nextSample(float sample, int channel) {
		float output = a0 * sample + a1 * inputBuffer[channel][0] + a2 * inputBuffer[channel][1]
			   - b1 * outputBuffer[channel][0] - b2 * outputBuffer[channel][1];

		outputBuffer[channel][1] = outputBuffer[channel][0];
		outputBuffer[channel][0] = output;
		inputBuffer[channel][1] = inputBuffer[channel][0];
		inputBuffer[channel][0] = sample;

		output = 0.5 * c0 * output + 0.5 * d0 * sample;
		return output;
	}
	
	void setSampleRate(double sampleRate) { fs = sampleRate; }
	double getSampleRate() { return fs; };
	virtual void update(float fc, float fs, float G) {

	}

	int numChannels;

	double fs; //Sample Rate
	int fc; //Center Frequency

	float a0, a1, a2; //Input coefficients
	float b1, b2; //Output coefficients
	float c0, d0; //Dry/Wet coefficients

	vector<vector<float>> inputBuffer;
	vector<vector<float>> outputBuffer;

};


#endif  // BIQUADFILTER_H_INCLUDED
