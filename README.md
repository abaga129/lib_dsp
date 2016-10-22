**********************
#LIB_DSP
##Author: Ethan Reker
####Purpose: To create a simple to use C++ Library for digital audio applications.
**********************

This library is free to use in any application.  To use this in your project, simply
include the lib_dsp.h file located in the include directory, or if you only need a certain
component, include the necessary file (filters.h, delays.h, etc).

##Installation and Use
	-Open command prompt
	-run "make all"
	-In the file that will need the library include "lib_dsp_location/include/lib_dsp.h".
	- #include "lib_dsp_location/include/lib_dsp.h"
	-Link lib_dsp.o when compiling
	- g++ lib_dsp_location/include/lib_dsp.o main.cpp -o main.exe

##Current Components

####Filters
	- Generic BiQuadFilter
	- Lowpass IIR 
	- Highpass IIR
	- Peak IIR
	- BandPass IIR

####Effects
	- Compressor (only hard-knee currently. Will be implementing soft-knee soon)
	- Digital Delay
	- Modulated Delay
	- Flanger			
	- Chorus
	- Vibrato
	
####Oscillators
	- Direct Form Oscillator
	- Gordon-Smith Oscillator (For an oscillator that will change frequency while playing)
	
####Core
	- Functions for common conversions such as dB to float
	- Linear Interpolator for graphics and for soft-knee compression
	- Buffer class for storing large amounts of data
	
	
#####Not Currently Implemented
	- Reverb
	- Wave Table Oscillator
	
###Contact
####email: ctrecordingslive@gmail.com
####website: http://www.modernmetalproduction.com
