/**********************************************
* Created By Ethan Reker
* On May 29, 2016
* Purpose: An adapter class for implementing a 
*          bandpass filter using a highpass and
*          lowpass in series.
**********************************************/

#ifndef BANDPASSIIR_H
#define BANDPASSIIR_H

#include "LowpassIIR.h"
#include "HighpassIIR.h"

namespace dsp
{

class BandpassIIR : public BiQuadFilter {
public:
  BandpassIIR(int numChannels, float fc, float fs){
    lowpass = new LowpassIIR(numChannels, fc, fs);
    highpass = new HighpassIIR(numChannels, fc, fs);
  }
  float nextSample(float sample, int channel){
    return highpass->nextSample(lowpass->nextSample(sample, channel), channel);
  }
  void update(float fc, float fs){
    lowpass->update(fc, fs);
    highpass->update(fc, fs);
  }
  
  void setSampleRate(double sampleRate) {
    lowpass->setSampleRate(sampleRate);
    highpass->getSampleRate(sampleRate);
  }
  double getSampleRate() { return fs; }{
    return lowpass->getSampleRate();
  } 

private:
  LowpassIIR *lowpass;
  HighpassIIR *highpass;
};
  
}//end namespace dsp
#endif
