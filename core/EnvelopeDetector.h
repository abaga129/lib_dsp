#ifndef ENVELOPE_DETECTOR_H
#define ENVELOPE_DETECTOR_H

#ifndef e
#define e 2.718281828459
#endif

#include<cmath>
#include "dsp_functions.h"

class EnvelopeDetector{
public:
    
    EnvelopeDetector(bool isDigital = true);
    float getNextValue(float input);
    void setParams(float releaseTimeMs, float attackTimeMs, float sampleRate);
    
private:
    float ta; //Attack Time
    float tr; //Release Time
    float tc; //Time Constant;
    
    bool digital;
    
    float fs;
    
    float yn1; //Previous output value
};

EnvelopeDetector::EnvelopeDetector(bool isDigital){
    digital = isDigital;
    if(isDigital){
        tc = logf(0.01);
    }
    else{
        tc = logf(0.368);
    }
}

void EnvelopeDetector::setParams(float attackTimeMs, float releaseTimeMs, float sampleRate){
    fs = sampleRate;
    //ta = powf(e, (tc/(attackTimeMs * fs * 0.001)));
    //tr = powf(e, (tc/(releaseTimeMs * fs * 0.001)));
	ta = exp(-1 / ((fs / 1000) * attackTimeMs));
	tr = exp(-1 / ((fs / 1000) * releaseTimeMs));
}

float EnvelopeDetector::getNextValue(float input){
	input = abs(input);
    if(input > yn1){
        //yn1 = ta * (yn1 - input) + input;
		yn1 *= ta;
		yn1 += (1 - ta) * input;
    }
    else{
        //yn1 = tr * (yn1 - input) + input;
		yn1 *= tr;
		yn1 += (1 - tr) * input;
    }
    return yn1;
}

#endif //!ENVELOPE_DETECTOR_H