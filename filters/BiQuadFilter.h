#ifndef BIQUADFILTER_H_INCLUDED
#define BIQUADFILTER_H_INCLUDED

#ifndef PI
#define PI 3.14159265359
#endif

#include <vector>
#include <cmath>
#include "../core/buffer.h"

using std::vector;

namespace DSP
{

class BiQuadFilter {
public: 
	/*
	Constructor. Initializes the sample rate and center frequency.
	Creates a series of Buffers and pushes them into the vectors for each channel.
	*/
	BiQuadFilter(int numChannels, int centerFrequency, double sampleRate);
	
	/*
	Calculates and returns the next output sample based on the sample that is input.
	Channel specifies which channel is being processed.
	*/
	float nextSample(float sample, int channel);
	
	void setSampleRate(double sampleRate);
	double getSampleRate();
	
	/*
	Call any time the center frequency is changed. All coefficients are recalculated.
	*/
	virtual void update(float fc, float fs, float G = 0);
	
	int numChannels;
	double fs; //Sample Rate
	int fc; //Center Frequency

	float a0, a1, a2; //Input coefficients
	float b1, b2; //Output coefficients
	float c0, d0; //Dry/Wet coefficients
	
private:
	//Holds a number of buffers equal to the number of channels.
	//Each buffer only has two samples and represents the input buffer.
	vector<Buffer> inputBuffer;
	
	//Holds a number of buffers equal to the number of channels.
	//Each buffer only has two samples and represents the output buffer.
	vector<Buffer> outputBuffer;
};

}//end namespace dsp
#endif
