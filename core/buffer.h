#ifndef BUFFER_H
#define BUFFER_H

#include<stdlib.h>

namespace DSP
{

class Buffer{
public:
  Buffer(size_t size);
  void write(float sample);
  float read();
  float getSample(size_t index);
  void setSample(float sample, size_t index);
  float* getWritePointer();
private:
  float *data;
  size_t writeIndex;
  size_t readIndex;
  size_t numSamples;
};
}//end namespace DSP
#endif