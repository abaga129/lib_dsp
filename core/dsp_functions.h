#ifndef DSP_FUNCTIONS_H
#define DSP_FUNCTIONS_H

#include <cmath>

extern float floatToDecibel(float value);

extern float decibelToFloat(float value);

extern float msToSamples(float ms, float sampleRate);

extern float samplesToMs(float samples, float sampleRate);
#endif
/*
extern float floatToDecibel(float value){
  return 20 * logf(value);
}

extern float decibelToFloat(float value){
  return pow(10, (value/20));
}

extern float msToSamples(float ms, float sampleRate){
  return ms * (sampleRate / 1000);
}

extern float samplesToMs(float samples, float sampleRate){
  return samples/(sampleRate/1000);
}
*/