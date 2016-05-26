#ifndef BUFFER_H
#define BUFFER_H

namespace dsp
{

class Buffer{
public:
  Buffer(size_t size);
private:
  float *data;
  int writeIndex;
  int readIndex;
};

Buffer(size_t size){
  data = new float(size);
  writeIndex = 0;
  readIndex = 1;
}

}//end namespace dsp
#endif
