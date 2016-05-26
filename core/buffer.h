#ifndef BUFFER_H
#define BUFFER_H

namespace dsp
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

Buffer::Buffer(size_t size){
  data = new float[size];
  writeIndex = 0;
  readIndex = 1;
  numSamples = size;
}

void Buffer::write(float sample){
  data[writeIndex] = sample;
  writeIndex++;
}

float Buffer::read(){
  return data[++readIndex];
}

float* Buffer::getWritePointer(){
  float *ptr = data;
  return ptr;
}

float Buffer::getSample(size_t index){
  return data[index];
}

void Buffer::setSample(float sample, size_t index){
  data[index] = sample;
}

}//end namespace dsp
#endif
