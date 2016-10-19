#include "Buffer.h"

using namespace DSP;

Buffer::Buffer(){
}

Buffer::Buffer(size_t size){
  initialize(size);
}

void Buffer::initialize(size_t size){
  data = new float[size * 2];
  writeIndex = size - 1;
  readIndex = 0;
  numSamples = size;
}

void Buffer::write(float sample){
  data[writeIndex] = sample;
  increment(writeIndex);
}

float Buffer::read(){
  if(data == NULL)
    return 0;
  float val = data[readIndex];
  increment(readIndex);
  return val;
}

float Buffer::getSample(const size_t index){
  return data[index];
}

void Buffer::setSample(float sample, size_t index){
  data[index] = sample;
}

void Buffer::setReadIndex(int index){
  readIndex = index;
}
  
void Buffer::setWriteIndex(int index){
  writeIndex = index;
}

void Buffer::increment(size_t &index){
  index++;
  if(index == numSamples)
    index = 0;
}

void Buffer::decrement(size_t &index){
  index--;
  if(index < 0)
    index = numSamples - 1;
}

void Buffer::resize(size_t size){
  int difference = numSamples - size;
  shiftReadIndex(difference);
}

void Buffer::shiftReadIndex(int amount){
  if(amount < 0)
    for(int i = 0; i > amount; i--)
      decrement(readIndex);
  if(amount > 0)
    for(int i = 0; i < amount; i++)
      increment(readIndex);
}

int Buffer::getWriteIndex(){return writeIndex;}

int Buffer::getReadIndex(){return readIndex;}