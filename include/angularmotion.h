#ifndef ANGULAR_MOTION_H
#define ANGULAR_MOTION_H

#include "vectors.h"
#include "verlet.h"
#include <math.h>

typedef struct {
    double AngularVelocity; 
    double Rotation;     
} AngularObject; 

/* Convert Degrees to radians */
double ToDegrees(double Radians); 

/* Convert Radians to degrees */
double ToRadians(double Degrees); 

/* Calculate rotation from gravity as torque */ 
void GetAngularRotation(AngularObject* Object, Vector LinearVelocity, double radius, bool colliding); 

#endif /* ANGULAR_MOTION_H */