#ifndef CIRCLE_H
#define CIRCLE_H

#include "vectors.h"

#include <math.h>
#include <stdbool.h>

typedef struct {
    Vector center;
    double radius;
} Circle; 

/* Get the distance between the centers of 2 circle */ 
double GetDistanceBetween(Circle a, Circle b); 

/* See if the circles are colliding */ 
bool Circle_CheckCollision(Circle a, Circle b); 

#endif //CIRCLE_H