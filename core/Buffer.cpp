#include "Buffer.h"

using namespace DSP;

Buffer::Buffer(size_t size){
  data = new float[size];
  writeIndex = 0;
  readIndex = 1;
  numSamples = size;
}

void Buffer::write(float sample){
  data[writeIndex] = sample;
  increment(writeIndex);
}

float Buffer::read(){
  increment(readIndex);
  return data[readIndex];
}

float* Buffer::getWritePointer(){
  float *ptr = data;
  return ptr;
}

float Buffer::getSample(const size_t index){
  return data[index];
}

void Buffer::setSample(float sample, size_t index){
  data[index] = sample;
}

void Buffer::increment(size_t index){
  index++;
  if(index == numSamples)
    index = 0;
}

void Buffer::resize(size_t size){
  
}