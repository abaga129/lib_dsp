#ifndef GORDON_SMITH_OSCILLATOR_H
#define GORDON_SMITH_OSCILLATOR_H

#include<cmath>
#include "../include/core.h"

/*
Class for creating pure sine wave oscillators or LFOs based on the Gordon Smith design.
The frequency can change smoothly with no audible pops or clicks.
*/
namespace DSP{
class GordonSmithOscillator{
public:
	GordonSmithOscillator();
	/*Must be called at the beginning of processBlock() in the Audio Processor
	*This method initializes all the values neccesary to begin oscillation.*/
	void setFrequency(float frequency, float sampleRate);

	/*Returns the next sample and increments the delaySamples*/
	float getNextSample(float input);
	void flush();

private:

	float yq;
	float yq1;
	float yn;
	float yn1;
	float epsilon;

	float theta;
	float fo;
	float fs;

	bool init;

};
}
#endif // !GORDON_SMITH_OSCILLATOR_H