#ifndef DSP_FUNCTIONS_H
#define DSP_FUNCTIONS_H

#include <cmath>

namespace DSP
{
float floatToDecibel(float value);

float decibelToFloat(float value);

float msToSamples(float ms, float sampleRate);

float samplesToMs(float samples, float sampleRate);

}//end namespace
#endif
