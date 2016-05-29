/***********************************
* Created By Ethan Reker
* On May 29, 2016
* Purpose: A class for implementing a simple bandpass filter.
***********************************/

#ifndef BANDPASSIIR_H
#define BANDPASSIIR_H

#include "LowpassIIR.h"
#include "HighpassIIR.h"

namespace dsp
{

class BandpassIIR{
  BandpassIIR();
  float getNextSample();
  
}
  
}//end namespace dsp
#endif
