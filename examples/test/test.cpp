
#include <iostream>
#include "../../include/lib_dsp.h"

using std::cout;

int main(int argv, char** argc){
	cout << "*************************\n"
		 << "*   Testing lib_dsp     *\n"
		 << "*************************\n"
	     << "\nThis file is designed to test the library"
		 << "\nin a raw state before using it with other libraries"
		 << "\nto ensure that everything is working correctly..\n\n";
	
	cout << "Bezier Curve Test..\n";
	BezierCurve curve;
	curve.set(-96, -96, -48, -48, 0, -24);
	for (float i = -96; i < 0; i = i + 5){
		cout << "\nX: " << i << "Y: " << curve.getValueAt(i);
	}
	
	cout << "\n\nRan with no errors..\n"
		 << "Current build is stable..\n";
		 
}