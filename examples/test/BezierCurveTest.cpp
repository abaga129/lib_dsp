
#include <iostream>
#include "../../include/lib_dsp.h"

using std::cout;

int main(int argv, char** argc){
	cout << "*************************\n"
		 << "Testing Bezier Curve\n"
		 << "*************************\n";
	
	BezierCurve curve;
	curve.set(-96, -96, -48, -48, 0, -24);
	for (float i = -96; i < 0; i = i + 5){
		cout << "\nX: " << i << "Y: " << curve.getValueAt(i);
	}
	cout << "\n\n";
}