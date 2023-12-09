#include "circle.h"

double GetDistanceBetween(Circle a, Circle b) {
    double xd, yd; 
    xd = abs(a.center.x - b.center.x); 
    yd = abs(a.center.y - b.center.y); 
    return sqrt((xd*xd) + (yd*yd)); 
}

bool Circle_CheckCollision(Circle a, Circle b) {
    return ((GetDistanceBetween(a,b) <= (b.radius + a.radius))); 
}