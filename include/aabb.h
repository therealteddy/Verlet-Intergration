#ifndef AABB_H
#define AABB_H

#include "vectors.h"
#include <stdbool.h>

typedef struct {
    Vector Tl;
    Vector Br;
} Rect_CollisionData; 

/* Get the min and max points for a aabb rect */ 
Rect_CollisionData Rect_GetCollisionData(Vector position, double w, double h);

/*Check for collision between two aabb rects */ 
bool Rect_CheckCollision(Rect_CollisionData R, Rect_CollisionData r); 
#endif //AABB_H