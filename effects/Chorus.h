/***********************************************
 * Wrapper class for Modulated Delay that
 * is specifically for the chorus effect
 * depth should never be set more than 40ms
 * for flanging effect.
 * Feedback is set to 0% by default
 * Frequency should be between 0.02 and 5
 * Wet is set to 50% and cannot be modified;
 ***********************************************/

#ifndef CHORUS_H
#define CHORUS_H

#include "ModulatedDelay.h"
#include "../core/dsp_functions.h"

namespace DSP{
class Chorus{
public:
    Chorus();
    float getNextSample(float input);
    void setWet(float wet);
    
    /*Must be called before processing*/
    void setSpeed(float frequency, float sampleRate);
    /*Must be called before processing*/
    void setDepth(int milliseconds, float sampleRate);
private:
    DSP::ModulatedDelay modDly;
};
}//end namespace DSP

#endif