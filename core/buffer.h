#ifndef BUFFER_H
#define BUFFER_H

namespace dsp
{

class Buffer{
public:
  Buffer(size_t size);
  float getSample(size_t index);
private:
  float *data;
  int writeIndex;
  int readIndex;
};

Buffer::Buffer(size_t size){
  data = new float(size);
  writeIndex = 0;
  readIndex = 1;
}

float Buffer::getSample(size_t index){
  return data[index];
}

}//end namespace dsp
#endif
