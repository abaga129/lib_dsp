#ifndef GORDON_SMITH_OSCILLATOR_H
#define GORDON_SMITH_OSCILLATOR_H

#include<cmath>
#include "../core/core.h"

/*
Class for creating pure sine wave oscillators or LFOs based on the Gordon Smith design.
The frequency can change smoothly with no audible pops or clicks.
*/
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

GordonSmithOscillator::GordonSmithOscillator() {
	init = false;
}

void GordonSmithOscillator::setFrequency(float frequency, float sampleRate) {
	fo = frequency;
	fs = sampleRate;

	theta = 2 * PI * fo / fs;
	epsilon = 2 * sinf(theta / 2);

	if (!init) {
		yn1 = sinf(-1 * theta);
		yq1 = cosf(-1 * theta);
		init = true;
	}

}

float GordonSmithOscillator::getNextSample(float input) {
	yq = yq1 - epsilon * yn1;
	yn = epsilon * yq + yn1;

	yq1 = yq;
	yn1 = yn;
	return yn;
}

void GordonSmithOscillator::flush() {

}

#endif // !GORDON_SMITH_OSCILLATOR_H