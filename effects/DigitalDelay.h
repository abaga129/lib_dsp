#ifndef DIGITAL_DELAY_H
#define DIGITAL_DELAY_H

#include <cstdlib>
using std::size_t;

namespace DSP{
class DigitalDelay{
  DigitalDelay(size_t delayAmount, float feedback, float wet_amount  = 0);
  float getNextSample(float sample);
  void resize(size_t size);
  void flush();
  
  void setFeedback(float feedback){ fb = feedback; }
  void setWet(float wet_amount){ wet = wet_amount; }
    
private:
    //Points to an array of floats equal in size to the delay amount.
    float *bufferPtr;
    
    //Controls the ratio of input to out. (dry = 1 - wet)
    float wet;
    
    //Indexes to control movement through the buffer
    unsigned int iRead, iWrite;
    
    //Feedback amount in range of 0 to 1
    float fb;
    
    //Sample Rate
    int fs;
    
	//Number of samples to be delayed
    size_t delayAmount;
};
}//end namespace DSP
#endif