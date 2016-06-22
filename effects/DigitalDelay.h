#ifndef DIGITAL_DELAY_H
#define DIGITAL_DELAY_H

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
    int iRead, iWrite;
    
    //Feedback amount in range of 0 to 1
    float fb;
    
    //Sample Rate
    int fs;
    
	//Number of samples to be delayed
    size_t delayAmount;
};

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

#endif