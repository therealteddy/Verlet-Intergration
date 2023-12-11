#include <math.h> 

#include "springs.h"
#include "constants.h"

void DrawSpring(Spring Coil) {
    DrawLine(Coil.AnchorPoint.x, Coil.AnchorPoint.y, Coil.ParticlePoint.x, Coil.ParticlePoint.y, WHITE);
}

void SpringMotion(Spring* Coil, Particle* Load) {
    double Weight, SpringForce, NetForce, Acceleration, Velocity;
    Weight = Load->Mass * EARTH_GRAVITY_CONST; 
    SpringForce = -Coil->SpringConst * (Coil->ParticlePoint.y - Coil->AnchorPoint.y); 
    NetForce = SpringForce + Weight; 
    Acceleration = NetForce/Load->Mass; 
    Velocity = Velocity + (Acceleration * dt()); 
    Load->Position.y += (Velocity * dt()) + (Acceleration * dt() * dt() * 0.5); 
    Coil->ParticlePoint.y = Load->Position.y;
}

void SpringHarmonicMotion(Spring* Coil, Particle* Load, double Ax, double Bx, double Ay, double By) {
    Load->Position.y += (Ay * sin(dt() * sqrt(Coil->SpringConst/Load->Mass))) + (By * cos(dt() * sqrt(Coil->SpringConst/Load->Mass)));
    Coil->ParticlePoint.y = Load->Position.y;
    Load->Position.x += (Ax * sin(dt() * sqrt(Coil->SpringConst/Load->Mass))) + (Bx * cos(dt() * sqrt(Coil->SpringConst/Load->Mass)));
    Coil->ParticlePoint.x = Load->Position.x;
}

void SpringMotion2D(Spring* Coil, Particle* Load, double Damping) {
    double Weight, SpringForceX, DampingForceX, NetForceX, VelocityX, AccelerationX = 0.0f;
    double SpringForceY, DampingForceY, NetForceY, VelocityY, AccelerationY = 0.0f;

    /* Calculate the X component */ 
    SpringForceX = -1 * (Coil->SpringConst) * (Coil->ParticlePoint.x - Coil->AnchorPoint.x); 
    DampingForceX = Damping * VelocityX; 
    NetForceX = SpringForceX - DampingForceX; 
    AccelerationX = NetForceX/Load->Mass; 
    VelocityX += AccelerationX * dt(); 
    Coil->ParticlePoint.x += (VelocityX * dt()) + (AccelerationX * dt() * dt() * 0.5f);
    Load->Position.x = Coil->ParticlePoint.x; 

    /* Calculate the Y component */
    Weight = Load->Mass * EARTH_GRAVITY_CONST;
    SpringForceY = -1 * (Coil->SpringConst) * (Coil->ParticlePoint.y - Coil->AnchorPoint.y); 
    DampingForceY = Damping * VelocityY; 
    NetForceY = SpringForceY + Weight - DampingForceY; 
    AccelerationY = NetForceY/Load->Mass; 
    VelocityY += AccelerationY * dt(); 
    Coil->ParticlePoint.y += (VelocityY * dt()) + (AccelerationY * dt() * dt() * 0.5f);
    Load->Position.y = Coil->ParticlePoint.y; 

}