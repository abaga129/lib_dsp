#ifndef BUFFER_H
#define BUFFER_H

namespace dsp
{

class Buffer{
public:
  Buffer(size_t size);
  float getSample(size_t index);
  float* getWritePointer();
private:
  float *data;
  int writeIndex;
  int readIndex;
  size_t numSamples;
};

Buffer::Buffer(size_t size){
  data = new float(size);
  writeIndex = 0;
  readIndex = 1;
  numSamples = size;
}

float* Buffer::getWritePointer(){
  float *ptr = data;
  return ptr;
}

float Buffer::getSample(size_t index){
  return data[index];
}

}//end namespace dsp
#endif
