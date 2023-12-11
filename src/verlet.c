#include "verlet.h"
#include "vectors.h"

void VerletGravity(VerletObject* Object, bool Colliding) {
   if (!Colliding) {
      Object->Position.y = Object->Position.y + (Object->Velocity.y * dt()) + (EARTH_GRAVITY_CONST * dt() * dt() * 0.5); 
      Object->Velocity.y = Object->Velocity.y + EARTH_GRAVITY_CONST * dt();
   } else Object->Velocity.y = 0.0f; 
}

void VerletMotion(VerletObject* Object, bool Colliding)
{
   if (!Colliding) {
      /* Update X Position */ 
      Object->NextPosition.x = (2 * Object->Position.x) - (Object->PreviousPosition.x) + (0.5 * dt() * dt() * Object->Acceleration.x); 

      /* Update Y Position */
      Object->NextPosition.y = (2 * Object->Position.y) - (Object->PreviousPosition.y) + (0.5 * dt() * dt() * Object->Acceleration.y); 

      /*Upate Everything else :)*/ 
      Object->PreviousPosition = Object->Position; 
      Object->Position = Object->NextPosition;
   } else Object->Velocity.y = 0.0f; 
} 