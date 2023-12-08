#include "angularmotion.h"
#include "constants.h"

double ToDegrees(double Radians) {
    return (double) (Radians/(2*Pi)) * 360.0f;
}

double ToRadians(double Degrees) {
    return (double) (Degrees/360.0f) * (2*Pi);
}

double Plate_GetMomentOfInertia(double mass, double a, double b) {
    return (mass/12) * ((a*a) + (b*b)); 
}

double Disk_GetMomentOfInertia(double mass, double radius) {
    return (mass/2) * (radius*radius); 
}

double Ring_GetMomentOfInertia(double mass, double radius) {
    return (mass) * (radius*radius);
}

double GetAngularMomentum(AngularObject* Object) {
    return (Object->AngularVelocity * Object->Inertia); 
}

double Plate_GetTorque(double force, double width, double height) {
    double hw = height/2; 
    double ww = width/2; 
    double r = sqrt((hw)*(hw) + (ww)*(ww)); 
    return (r * force); /* Assuming origin is center (width/2, height/2)*/
}

void GetAngularAcceleration(AngularObject* Object, double torque) {
    Object->AngularAcceleration = torque/Object->Inertia; 
}

void GetAngularVelocity(AngularObject* Object) {
    Object->AngularVelocity += Object->AngularAcceleration * dt(); 
}

void GetAngularDisplacement(AngularObject* Object) {
    Object->AngularDisplacement += Object->AngularVelocity * dt();  
}

void AngularDisplacementFromLinearVelocity(AngularObject* Object, Vector LinearVelocity, double radius, bool colliding, unsigned int Shape) {
    /* Get Resultant Vector of Linear Velocity */ 
    double LinearResulatant = VectorMagnitude(LinearVelocity); 

    /* Get Moment of inertia assuming uniform mass */ 
    switch (Shape)
    {
    case DISK:
        Object->Inertia = Disk_GetMomentOfInertia(Object->Mass, radius); 
        break;
    
    case RING: 
        Object->Inertia = Ring_GetMomentOfInertia(Object->Mass, radius);
        break; 

    case PLATE: 
        //Implement later; 
        break; 

    default:
        break;
    }

    if (!colliding) {
        Object->AngularVelocity += (LinearResulatant/radius) * dt(); 
        Object->AngularDisplacement += Object->AngularVelocity; 
    } else Object->AngularVelocity = 0.0f; 
}