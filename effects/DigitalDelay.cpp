#include "DigitalDelay.h"

using namespace DSP;

DigitalDelay::DigitalDelay(size_t delayAmount, float feedback, float wet_amount){
    bufferPtr = new float[delayAmount + 1];
    DigitalDelay::delayAmount = delayAmount;
	wet = wet_amount;
    iWrite = 0;
    iRead = delayAmount;
}

float DigitalDelay::getNextSample(float sample){
    iWrite++;
    iRead++;
    if(iWrite > delayAmount + 1)
        iWrite = 0;
    if(iRead > delayAmount + 1)
        iRead = 0;
        
    float yn = bufferPtr[iRead];
    bufferPtr[iWrite] = sample + fb * yn;
    return wet * yn + sample * (1 - wet);
}

void DigitalDelay::resize(size_t size){
    /*bufferPtr = new float[delayAmount + 1];
    DigtalDelay::delayAmount = delayAmount;
    
    int index = delayAmount + 1;
    float *newBuffer = new float[size + 1];
    for(int i = 0; i < size + 1; i ++){
      newBuffer[i] = delayBuffer[iWrite];
      newBuffer[index] = delayBuffer[iRead];
      index++;
      iWrite++;
      iRead++;
    }*/
    delete[] bufferPtr;
    bufferPtr = new float[size + 1];
    iWrite = 0;
    iRead = size;
}

void DigitalDelay::flush(){
    
}