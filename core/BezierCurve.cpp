#include "BezierCurve.h"

using namespace DSP;

BezierCurve::BezierCurve(){
    
}

void BezierCurve::set(float x0, float y0, float x1, float y1, float x2, float y2){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    y[0] = y0;
    y[1] = y1;
    y[2] = y2;
}

float BezierCurve::getValueAt(float input){
    float t = fabs(input - x[0])/fabs(x[2] - x[0]);//approximate t from x
    float output = pow(1 - t, 2) * y[0] + 2 * (1 - t) * t * y[1] + t * t * y[2];
    return output;
}