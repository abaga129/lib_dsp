/****************************************
* Author: Ethan Reker
* Date Created: June 22, 2016
* Purpose: Create a class to implement a quadratic bezier curve.
*   This implementation is mostly tailored to generating points for
*   the soft-knee on a compressor. Usually a bezier curve is treated
*   as a function of t (parametric curve), but for the soft-knee we
*   need to calculate the curve as a function of x, so t is aproximated
*   from x which works fine for this purpose.  The only draw back is
*   this curve has very limited uses.
*/

#ifndef BEZIER_CURVE_H
#define BEZIER_CURVE_H

#include <cmath>

namespace DSP {
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
}//end namespace DSP

#endif
