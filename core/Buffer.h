#ifndef BUFFER_H
#define BUFFER_H

/*READ FIRST WRITE LAST BUFFER*/

#include<stdlib.h>

namespace DSP
{
class Buffer{
public:
  Buffer(size_t size);
  //Writes one sample to buffer then increments writeIndex
  void write(float sample);
  
  //Increments readIndex and returns sample at that index
  float read();
  
  float getSample(const size_t index);
  
  void setSample(float sample, size_t index);
  
  float* getWritePointer();
  
  void resize(size_t size);
private:
  void increment(size_t index);
  float *data;
  size_t writeIndex;
  size_t readIndex;
  size_t numSamples;
};
}//end namespace DSP
#endif