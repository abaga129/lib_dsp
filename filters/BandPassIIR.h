/**********************************************
* Created By Ethan Reker
* On May 29, 2016
* Purpose: An adapter class for implementing a 
*          bandpass filter using a highpass and
*          lowpass in series.
**********************************************/

#ifndef BANDPASSIIR_H
#define BANDPASSIIR_H

#include "LowPassIIR.h"
#include "HighPassIIR.h"

namespace DSP
{

class BandPassIIR : public BiQuadFilter {
public:
  BandPassIIR(int numChannels, float fc, float fs);
  float nextSample(float sample, int channel);
  void update(float fc, float fs);
  
  void setSampleRate(double sampleRate);
  double getSampleRate();

private:
  DSP::LowPassIIR *lowpass;
  DSP::HighPassIIR *highpass;
};
  
}//end namespace dsp
#endif
