#include "GordonSmithOscillator.h"

using namespace DSP;

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