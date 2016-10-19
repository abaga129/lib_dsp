
#include <iostream>
#include <string>
#include "../../include/lib_dsp.h"

using std::cout;
using namespace DSP;

void BezierCurveTest();
void BufferTest();
void EnvelopeDetectorTest();

void GordonSmithOscillatorTest();
void DirectFormOscillatorTest();

void DigitalDelayTest();
void ModulatedDelayTest();
void FlangerTest();
void ChorusTest();
void VibratoTest();

void BiQuadFilterTest();
void HighPassIIRTest();
void LowPassIIRTest();
void BandPassIIRTest();
void PeakIIRTest();

int main(int argv, char** argc){
	cout << "*************************\n"
		 << "*   Testing lib_dsp     *\n"
		 << "*************************\n"
	     << "\nThis file is designed to test the library"
		 << "\nin a raw state before using it with other libraries"
		 << "\nto ensure that everything is working correctly..\n\n";
    int choice = 1;
    while(choice > 0){
        cout << "Select Category - 0 to quit.\n"
             << "1 - Core\n"
             << "2 - Effects\n"
             << "3 - Filters\n"
             << "4 - Oscillators\n"
             << ">";
             
        std::cin >> choice;
        switch(choice){
            case 4:{
            	int choice2 = 1;
                while(choice2 > 0){
                    cout << "\n\nOscillators\nSelect module to test - 0 to quit.\n"
                         << "1 - GordonSmithOscillator\n"
                         << "2 - DirectFormOscillator\n"
                         << ">";
                    std::cin >> choice2;
                    switch(choice2){
                    	case 2:
                    		DirectFormOscillatorTest();
                    		break;
                    	case 1:
                    		GordonSmithOscillatorTest();
                    		break;
                    	default:
                    		cout << "No Selection..\n";
                    		break;
                    }
                    
                }
                break;
            }
            case 3:{
            	int choice2 = 1;
                while(choice2 > 0){
                    cout << "\n\nFilters\nSelect module to test - 0 to quit.\n"
                         << "1 - BiQuadFilter\n"
                         << "2 - HighPassIIR\n"
                         << "3 - LowPassIIR\n"
                         << "4 - BandPassIIR\n"
                         << "5 - PeakIIR\n"
                         << ">";
                    std::cin >> choice2;
                    switch(choice2){
                    	case 5:
                    		PeakIIRTest();
                    		break;
                    	case 4:
                    		BandPassIIRTest();
                    		break;
                    	case 3:
                    		LowPassIIRTest();
                    		break;
                    	case 2:
                    		HighPassIIRTest();
                    		break;
                    	case 1:
                    		BiQuadFilterTest();
                    		break;
                    	default:
                    		cout << "No Selection..\n";
                    		break;
                    }
                    
                }
                break;
            }
            case 2:{
            	int choice2 = 1;
                while(choice2 > 0){
                    cout << "\n\nEffects\nSelect module to test - 0 to quit.\n"
                         << "1 - DigitalDelay\n"
                         << "2 - ModulatedDelay\n"
                         << "3 - Flanger\n"
                         << "4 - Chorus\n"
                         << "5 - Vibrato\n"
                         << ">";
                    std::cin >> choice2;
                    switch(choice2){
                    	case 5:
                    		VibratoTest();
                    		break;
                    	case 4:
                    		ChorusTest();
                    		break;
                    	case 3:
                    		FlangerTest();
                    		break;
                    	case 2:
                    		ModulatedDelayTest();
                    		break;
                    	case 1:
                    		DigitalDelayTest();
                    		break;
                    	default:
                    		cout << "No Selection..\n";
                    		break;
                    }
                }
                break;
            }
            case 1:{
            	int choice2 = 1;
                while(choice2 > 0){
                    cout << "\n\nCore\nSelect module to test - 0 to quit.\n"
                         << "1 - Buffer\n"
                         << "2 - BezierCurve\n"
                         << "3 - EnvelopeDetector\n"
                         << ">";
                    std::cin >> choice2;
                    switch(choice2){
                    	case 3:
                    		EnvelopeDetectorTest();
                    		break;
                    	case 2:
                    		BezierCurveTest();
                    		break;
                    	case 1:
                    		BufferTest();
                    		break;
                    	default:
                    		cout << "No Selection..\n";
                    		break;
                    }
                    
                }
                break;
            }
         }
             
    }

	cout << "\n\nRan with no errors..\n"
		 << "Current build is stable..\n";


	return 0;
}

void BufferTest(){
	cout << "\n\nBuffer Test..\n";
	Buffer buffer(20);
	for(int i = 0; i < 200; i++){
		float sample = float(i)/200;
		float output = buffer.read();
		buffer.write(sample);
		cout << "Input: " << sample << " Output: "<< output << " - ";
	}
}

void BezierCurveTest(){
	cout << "\n\nBezierCurve Test..\n";
	BezierCurve curve;
	curve.set(-96, -96, -48, -48, 0, -24);
	for (float i = -96; i < 0; i = i + 5){
		cout << "\nX: " << i << "Y: " << curve.getValueAt(i);
	}
}

void EnvelopeDetectorTest(){
	cout << "\n\nEnvelopeDetector Test..\n";
}

void GordonSmithOscillatorTest(){
	cout << "\n\nGordonSmithOscillator Test..\n";
	GordonSmithOscillator osc;
	osc.setFrequency(1000, 44100);
	for(int i = 0; i < 200; i++)
		cout << "Output: " << osc.getNextSample(0) << " - ";
}

void DirectFormOscillatorTest(){
	cout << "\n\nDirectFormOscillator Test..\n";
	DirectFormOscillator osc;
	osc.setFrequency(1000, 44100);
	for(int i = 0; i < 200; i++)
		cout << "Output: " << osc.getNextSample(0) << " - ";
}

void DigitalDelayTest(){
	cout << "\n\nDigitalDelay Test..\n";
	DigitalDelay dly(20, 0.5, 0.5);
	for(int i = 0; i < 200; i++){
		float sample = float(i)/200;
		float output = dly.getNextSample(sample);
		cout << "Input: " << sample<< " Output: " << output << " - ";
	}
}

void ModulatedDelayTest(){
	cout << "\n\nModulatedDelay Test..\n";
	ModulatedDelay mdly(0, 10, 0.99, 1);
	mdly.setFrequency(1, 44100);
	for(int i = 0; i < 100; i++){
		float sample = float(i)/100;
		cout << "Write Index: " << mdly.getWriteIndex() << " Read Index: " << mdly.getReadIndex() << '\n';
		float output = mdly.getNextSample(sample);
		cout << "Input: " << sample << " Output: " << output << "\n";
	}
}

void FlangerTest(){
	cout << "\n\nFlanger Test..\n";
	Flanger *flanger = new Flanger;
	flanger->setDepth(10, 100);
	flanger->setSpeed(2, 100);
	for(int i = 0; i < 200; i++){
		float sample = float(i)/200;
		float output = flanger->getNextSample(sample);
		cout << "Input: " << sample << " Output: " << output << " - ";
	}
	delete flanger;
}

void ChorusTest(){
	cout << "\n\nChorus Test..\n";
	Chorus *chorus = new Chorus;
	chorus->setDepth(10, 100);
	chorus->setSpeed(2, 100);
	for(int i = 0; i < 200; i++){
		float sample = float(i)/200;
		float output = chorus->getNextSample(sample);
		cout << "Input: " << sample << " Output: " << output << " - ";
	}
	delete chorus;
}

void VibratoTest(){
	cout << "\n\nVibrato Test..\n";
}

void BiQuadFilterTest(){
	cout << "\n\nBiQuadFilter Test..\n";
}

void HighPassIIRTest(){
	cout << "\n\nHighPassIIR Test..\n";
}

void LowPassIIRTest(){
	cout << "\n\nLowPassIIR Test..\n";
}

void BandPassIIRTest(){
	cout << "\n\nBandPassIIR Test..\n";
}

void PeakIIRTest(){
	cout << "\n\nPeakIIR Test..\n";
}