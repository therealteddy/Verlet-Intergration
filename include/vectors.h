#ifndef VECTORS_H 
#define VECTORS_H 

typedef struct {
    double x; 
    double y; 
} Vector;

/* Vector Magnitude - Get the magnitude of a vector using the pythagoras theorum */
double VectorMagnitude(Vector Vec); 

/* Dot Product - Get the sum of the products of the components */ 
double VectorDot(Vector a, Vector b); 

/* Get the angle between the vectors */ 
double GetTheta(Vector a, Vector b); 

/* Add two vectors */ 
Vector AddVector(Vector a, Vector b); 

/* Multiply a scalar and a Vector */
Vector ScalarMultiply(double s, Vector v); 
#endif // VECTORS_H