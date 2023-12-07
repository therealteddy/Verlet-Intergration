#ifndef VERLET_H
#define VERLET_H

#include "vectors.h"
#include "constants.h"
#include "aabb.h"

typedef struct {
    Vector Position; // Current position 
    Vector PreviousPosition; // Previous position
    Vector NextPosition; // Next Position
    Vector Velocity; // Initial velocity
    Vector Acceleration; // Acceleration
} VerletObject; 

// Verlet Velocity - Calculate Velocity from just the current position and acceleration.Then Write to a memory address 
void VerletGravity(VerletObject* Object, bool IsColliding); 

// Verlet Velocity V2 - Calculate position from Velocity and Acceleration. Then return an object
VerletObject VerletGravityObject (void); 

/* More Standard Verlet intergration */
void VerletMotion(VerletObject* Object, bool Colliding);

#endif // VERLET_H