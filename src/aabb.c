#include "aabb.h"

Rect_CollisionData Rect_GetCollisionData(Vector position, double w, double h) {
    return (Rect_CollisionData) {
        {position.x, position.y}, 
        {position.x + w, position.y + h}
    }; 
}

bool Rect_PrimitiveCheckCollision(Rect_CollisionData R, Rect_CollisionData r) {
    if ((R.Br.x > r.Tl.x && r.Br.x > R.Tl.x) && (R.Br.y > r.Tl.y && r.Br.y > R.Tl.y)) {
        return true; 
    } else return false; 
}

bool Rect_CheckCollision(Rect_CollisionData R, Rect_CollisionData r) {
    return (((R.Br.x > r.Tl.x) && (r.Br.x > R.Tl.x)) && ((R.Br.y > r.Tl.y) && (r.Br.y > R.Tl.y)));
}