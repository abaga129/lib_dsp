/*******************************************************************************
 * 
 * DelayBuffer.cpp
 * Created By Ethan Reker
 * on 04/20/2016
 * 
 * Purpose: This class is for implementing a circular buffer
 *          for use in digital delays.
 * ****************************************************************************/
 
 #ifndef DELAY_BUFFER_H
 #define DELAY_BUFFER_H

 class DelayBuffer{
     public:
    
        /* Contructor: creates an array of floats equal in size to delayAmount*/
        DelayBuffer(size_t delayAmount, float feedback, float wet_amount = 0);
        
        /* Method where the guts of the processing happen.
        Typical use:  *samplePointer = getNextSample(*samplePointer); */
        float getNextSample(float sample);
        
        /* Should be called when the amount of delay is changed */
        void resize(size_t size);
        
        /*Set all values in the buffer to 0. Should be called before play-back 
        starts*/
        void flush();
        
        void setFeedback(float feedback){ fb = feedback; }
        void setWet(float wet_amount){ wet = wet_amount; }
		int getBufferSize() { return bufferSize; }
     private:

        //Points to an array of floats equal in size to the delay amount.
        double *bufferPtr;
        
        //Controls the ratio of input to out. (dry = 1 - wet)
        float wet;
        
        //Used to know when to wrap around to the front of the buffer
        size_t bufferSize;
        
        //Indexes to control movement through the buffer
        int iRead, iWrite;
        
        //Feedback
        float fb;
        
        //Sample Rate
        int fs;

 };
 
 DelayBuffer::DelayBuffer(size_t delayAmount, float feedback, float wet_amount){
	 bufferPtr = new double[delayAmount];
     	 fb = feedback;
	 wet = wet_amount;
	 bufferSize = delayAmount;

     	 iWrite = delayAmount -1;
     	 iRead = 0;
 }
 
 float DelayBuffer::getNextSample(float sample){
	 vector<float>& buffer = *bufferPtr;

     float yn;
	 if (iWrite + 1 == bufferSize)
		 iWrite = 0;
	 else
		 iWrite++;
         
     if(iRead + 1 == bufferSize){
         iRead = 0;
         yn = buffer[bufferSize - 1];
     }
     else{
         iRead++;
         yn = buffer[iRead - 1];
     }
     
     buffer[iWrite] = sample + fb * yn;
     return wet * yn + sample * (1-wet);
 }
 
 void DelayBuffer::resize(size_t size){
	 //delete bufferPtr;

	 /*
	 Still need to implement carrying over data from old vector.
	 */
	 vector<float>& bufRef = *bufferPtr;
	 vector<float> newBuffer;
	 for (int i = 0; i < size; i++) {
		 if (i < bufferSize) {
			 newBuffer.push_back(bufRef[i]);
		 }
		 else
			 newBuffer.push_back(0);
	 }

	 bufferSize = size;
	 iWrite = bufferSize - 1;
	 iRead = 0;
	 //delete bufferPtr;
	 *bufferPtr = newBuffer;
 }
 
 void DelayBuffer::flush(){
	 vector<float>& buffer = *bufferPtr;

     for(int i = 0; i < bufferSize; i++){
         buffer[i] = 0;
     }
 }
 
 #endif
