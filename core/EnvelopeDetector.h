#ifndef ENVELOPE_DETECTOR_H
#define ENVELOPE_DETECTOR_H

#ifndef e
#define e 2.718281828459
#endif

namespace DSP
{
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
}
#endif //!ENVELOPE_DETECTOR_H