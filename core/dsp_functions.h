#ifndef DSP_FUNCTIONS_H
#define DSP_FUNCTIONS_H

#include <cmath>

namespace dsp
{
float floatToDecibel(float value){
  return 20 * logf(value);
}

float decibelToFloat(float value){
  return pow(10, (value/20));
}

float msToSamples(float ms, float sampleRate){
  return ms * (sampleRate / 1000);
}

float samplesToMs(float samples, float sampleRate){
  return samples/(sampleRate/1000);
}

}//end namespace
#endif
