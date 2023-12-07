#include "angularmotion.h"
#include "constants.h"

double ToDegrees(double Radians) {
    return (double) (Radians/(2*Pi)) * 360.0f;
}

double ToRadians(double Degrees) {
    return (double) (Degrees/360.0f) * (2*Pi);
}

void GetAngularRotation(AngularObject* Object, Vector LinearVelocity, double radius, bool colliding) {
    double LinearVelocityMagnitude = VectorMagnitude(LinearVelocity); 
    if (!(colliding)){ 
        Object->AngularVelocity += LinearVelocityMagnitude * dt() * radius; 
        Object->Rotation = ToRadians(Object->AngularVelocity);
    }  else Object->Rotation = Object->AngularVelocity = 0.0f;
}