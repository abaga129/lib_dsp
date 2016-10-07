**********************
LIB_DSP
Author: Ethan Reker
Purpose: To create a simple to use C++ Library for digital audio applications.
**********************

This library is free to use in any application.  To use this in your project, simply
include the lib_dsp.h file located in the include directory, or if you only need a certain
component, include the necessary file (filters.h, delays.h, etc).

Current Components

>Filters
	* Generic BiQuadFilter
	* Lowpass IIR 
	* Highpass IIR
	* Peak IIR
	* BandPass IIR

>Effects
	* Compressor (only hard-knee currently. Will be implementing soft-knee soon)
	* Digital Delay
	+ Plans to implement various modulated effects such as tremolo, chorus, and flanger
	
>Oscillators
	* Direct Form Oscillator
	* Gordon-Smith Oscillator (For an oscillator that will change frequency while playing)
	
>Core
	* Functions for common conversions such as dB to float
	* Linear Interpolator for graphics and for soft-knee compression
	* Buffer class for storing large amounts of data

**********************
Contact
**********************
email: ctrecordingslive@gmail.com
website: http://www.modernmetalproduction.com