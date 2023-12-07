#include <math.h>
#include "vectors.h"
#include "constants.h"

double VectorMagnitude(Vector Vec) {
    return sqrt((Vec.x*Vec.x) + (Vec.y*Vec.y));
}

double VectorDot(Vector a, Vector b) {
    return (a.x * b.x) + (a.y * b.y);
}

double GetTheta(Vector a, Vector b) {
    const double A = VectorMagnitude(a); 
    const double B = VectorMagnitude(b); 
    const double Theta = acos(
        (A*B)/VectorDot(a,b)
    ); 
    const double Degrees = (Theta) * (180/Pi); 
    return Degrees;    
}

Vector AddVector(Vector a, Vector b) {
    return (Vector) {
        (a.x + b.x), (a.y + b.y)
    }; 
}

Vector ScalarMultiply(double s, Vector v) {
    return (Vector) {
        (s * v.x), 
        (s * v.y)
    }; 
}