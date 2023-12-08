#ifndef ANGULAR_MOTION_H
#define ANGULAR_MOTION_H

#include "vectors.h"
#include "verlet.h"
#include <math.h>

enum Shapes {PLATE, DISK, RING}; 

typedef struct {
    double AngularVelocity; 
    double AngularAcceleration; 
    double AngularDisplacement;
    double Rotation;  
    double Inertia;   
    double Mass; 
} AngularObject; 

/* Convert Degrees to radians */
double ToDegrees(double Radians); 

/* Convert Radians to degrees */
double ToRadians(double Degrees); 

/* Calculate rotation from gravity as torque */ 
void AngularDisplacementFromLinearVelocity(AngularObject* Object, Vector LinearVelocity, double radius, bool colliding, unsigned int Shape); 

/* Calculate moment of inertia of a plate */
double Plate_GetMomentOfInertia(double mass, double a, double b);

/* Calculate moment of inertia of a disk */
double Disk_GetMomentOfInertia(double mass, double radius); 

/* Calculate moment of inertia of a ring */
double Ring_GetMomentOfInertia(double mass, double radius);

/* Calculate angular momentum */ 
double GetAngularMomentum(AngularObject* Object); 

/* Get torque of a plate assuming rotational axis is at the center */  
double Plate_GetTorque(double force, double height, double width); 

/* Get angular acceleration from torque and inertia */
void GetAngularAcceleration(AngularObject* Object, double torque); 

/* Get Angular Displacement from angular velocity */
void GetAngularDisplacement(AngularObject* Object); 

#endif /* ANGULAR_MOTION_H */