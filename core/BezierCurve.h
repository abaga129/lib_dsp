/****************************************
* Author: Ethan Reker
* Date Created: June 22, 2016
* Purpose: Create a class to implement a
*   quadratic bezier curve.
*
*/

#ifndef BEZIER_CURVE_H
#define BEZIER_CURVE_H

#include <cmath>

class BezierCurve{
public:

    /***************************************
     * Default contructor
     ***************************************/
    BezierCurve();
    
    /***************************************
     * Set the X and Y values for the points
     * used in the curve.  P0 is the start
     * point, P1 is the control point,
     * and P2 is the end point.
     ***************************************/
    void set(float x0, float y0, float x1, float y1, float x2, float y2);
    
    /***************************************
     * Approximates t value based on x and 
     * returns Y
     ***************************************/
    float getValueAt(float input);
    
private:
    float x[3];
    float y[3];
};

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
#endif
