/***********************************************
 * Wrapper class for Modulated Delay that
 * is specifically for the flanging effect
 * depth should never be set more than 10ms
 * for flanging effect.
 * Feedback is set to 99% and cannot be modified
 * Frequency should be between 0.02 and 5
 * Wet is set to 50% and cannot be modified
 ***********************************************/

#ifndef FLANGER_H
#define FLANGER_H

#include "ModulatedDelay.h"
#include "../core/dsp_functions.h"

namespace DSP{
class Flanger{
public:
    Flanger();
    float getNextSample(float input);
    void setWet(float wet);
    
    /*Must be called before processing*/
    void setSpeed(float frequency, float sampleRate);
    /*Must be called before processing*/
    void setDepth(float milliseconds, float sampleRate);
private:
    DSP::ModulatedDelay modDly;
};
}//end namespace DSP
#endif