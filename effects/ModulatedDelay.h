#ifndef MODULATED_DELAY_H
#define MODULATED_DELAY_H

#include "../core/Buffer.h"
#include "../oscillators/GordonSmithOscillator.h"

namespace DSP{
class ModulatedDelay{
public:
    ModulatedDelay();
    ModulatedDelay(size_t minDelay, size_t maxDelay, float fb, float wet);
    void initialize(size_t minDelay, size_t maxDelay, float fb, float wet);
    float getNextSample(float sample);
    void resize(size_t delayAmount);
    void flush();
    void setFeedback(float feedback);
    void setWet(float wet_amount);
    void setDepth(float depth);
    
    /*Must be set before processing begins*/
    void setFrequency(float frequency, float sampleRate);
    
    /*Must be set before processing begins*/
    void setDelayRange(int min, int max);

    int getWriteIndex();

    int getReadIndex();
    

private:
    DSP::Buffer buffer;
    DSP::GordonSmithOscillator osc;
    
    //Controls the ratio of input to out. (dry = 1 - wet)
    float wet;
    
    //Feedback amount in range of 0 to 1
    float fb;
    
    //Sample Rate
    int fs;
    
    float depth;
    
	int centerDelay;
	
	int prevDelay;
	
	int scalar;
    
    //Speed of oscillation
    float oscFreq;
    
    //Number of samples that the read index can vary by.
    int delayRange;
};   
}//end namespace DSP
#endif