/***********************************************
 * Wrapper class for Modulated Delay that
 * is specifically for the flanging effect
 * depth should never be set more than 10ms
 * for flanging effect.
 * Feedback is set to 0% and cannot be modified
 * Frequency should be between 0.02 and 5
 * Wet is set to 100% and cannot be modified
 ***********************************************/

#ifndef VIBRATO_H
#define VIBRATO_H

#include "ModulatedDelay.h"
#include "../core/dsp_functions.h"

namespace DSP{
    class Vibrato{
public:
    Vibrato();
    float getNextSample(float input);
    void setWet(float wet);
    
    /*Must be called before processing*/
    void setSpeed(float frequency, float sampleRate);
    /*Must be called before processing*/
    void setDepth(int milliseconds, float sampleRate);
private:
    ModulatedDelay modDly;  
};
}//end namespace DSP

#endif