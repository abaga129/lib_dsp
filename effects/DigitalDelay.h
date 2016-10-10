#ifndef DIGITAL_DELAY_H
#define DIGITAL_DELAY_H

#include "../core/Buffer.h"
#include <cctype>

namespace DSP{
class DigitalDelay{
  DigitalDelay(size_t delayAmount, float fb, float wet  = 0);
  float getNextSample(float sample);
  void resize(size_t delayAmount);
  void flush();
  
  void setFeedback(float feedback);
  void setWet(float wet_amount);
    
private:
    DSP::Buffer *buffer;
    
    //Controls the ratio of input to out. (dry = 1 - wet)
    float wet;
    
    //Feedback amount in range of 0 to 1
    float fb;
    
    //Sample Rate
    int fs;
    
	//Number of samples to be delayed
    size_t delayAmount;
};
}//end namespace DSP
#endif