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

/// @brief Get Torque of a plate from a force that acts perpendicularly
/// @param force Force that acts perpendicularly on the plate
/// @param width Width of the plate
/// @param height Height of the plate
/// @param origin Axis along which the object is supposed to rotate; Relative to the origin - topleft of plate
/// @return Return the resultant torque according to the principle of moments

double Plate_GetTorque(double force, double width, double height, Vector origin) {
    
    /* Horribly Named Important variables */
    
    double tl, tr; /* Torque to the left and right of origin */
    double rl, rr; /* Radii from the origin  */
    double dw, dh; /* The individual components of a radii */
    double ndw, ndh; /* The individual components of another radii */
    
    dw = width - origin.x; 
    dh = height - origin.y;
    ndw = width - dw; 
    ndh = height - dh; 

    /* Assuming force is perpendicular to the plate as only gravity acts as of now */
    rr = VectorMagnitude((Vector) {dw, dh}); 
    rl = VectorMagnitude((Vector) {ndw, ndh}); 
    tr = rr * force; 
    tl = rl * force; 

    return (tr-tl); /* Resultant torque - According to the principle of moments */
}

void GetAngularAcceleration(AngularObject* Object) {
    Object->AngularAcceleration = Object->Torque/Object->Inertia; 
}

void GetAngularVelocity(AngularObject* Object) {
    Object->AngularVelocity += Object->AngularAcceleration * dt(); 
}

void GetAngularDisplacement(AngularObject* Object) {
    Object->AngularDisplacement += Object->AngularVelocity * dt();  
}

void Plate_AngularUpdate(AngularObject* Plate, bool Colliding) {
    if (!Colliding) {
        GetAngularAcceleration(Plate);
        GetAngularVelocity(Plate); 
        GetAngularDisplacement(Plate); 
    } else Plate->AngularDisplacement = 0.0f;
}