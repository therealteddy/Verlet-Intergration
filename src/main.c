#include <stdio.h> 
#include <raylib.h>

#include "angularmotion.h"
#include "vectors.h"
#include "verlet.h"
#include "aabb.h"

#define WINDOW_W 800 
#define WINDOW_H 600 
#define WINDOW_T "Verlet Intergration"

int main(int argc, char* argv[]) {
    InitWindow(WINDOW_W, WINDOW_H, WINDOW_T); 
    SetTargetFPS(FPS_CAP);

    /* Set a maximum of 100 objects */ 
    VerletObject Squares[100]; 
    Rect_CollisionData SquaresCollisionData[100]; 
    unsigned int ObjectIndex = 0; 

    /* Something to collide against! */
    Rect_CollisionData GroundCollisioData = Rect_GetCollisionData((Vector) {0, WINDOW_H-50}, WINDOW_W, 50);

    /* VerletMotion Test Object */
    VerletObject MotionObject; 
    MotionObject.Acceleration = (Vector) {0, EARTH_GRAVITY_CONST}; 
    MotionObject.PreviousPosition = (Vector) {100, 100}; 
    MotionObject.Position = (Vector) {100, 100}; 
    MotionObject.Velocity = (Vector) {0, 0}; 

    /*Another test object */ 
    VerletObject ComparisonObject; 
    ComparisonObject.Position = (Vector) {300, 100}; 

    while(!WindowShouldClose()) {
        BeginDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) Squares[ObjectIndex++].Position = (Vector) {GetMousePosition().x, GetMousePosition().y};  
        ClearBackground(BLACK);  
        for (int i = 0; i < ObjectIndex; i++) { 
            DrawRectangle(Squares[i].Position.x, Squares[i].Position.y, 100, 100, GRAY); 
            SquaresCollisionData[i] = Rect_GetCollisionData((Vector) {Squares[i].Position.x, Squares[i].Position.y}, 100, 100);  
            VerletGravity(&Squares[i], Rect_CheckCollision(SquaresCollisionData[i], GroundCollisioData)); 
        }
        DrawRectangle(MotionObject.Position.x, MotionObject.Position.y, 100, 100, WHITE);
        DrawRectangle(ComparisonObject.Position.x, ComparisonObject.Position.y, 100, 100, WHITE);
        Rect_CollisionData MotionObjectCollisionData = Rect_GetCollisionData((Vector) {MotionObject.Position.x, MotionObject.Position.y}, 100, 100);
        Rect_CollisionData ComparisonObjectCollisionData = Rect_GetCollisionData((Vector) {ComparisonObject.Position.x, ComparisonObject.Position.y}, 100, 100); 
        VerletMotion(&MotionObject, Rect_CheckCollision(GroundCollisioData, MotionObjectCollisionData)); 
        VerletGravity(&ComparisonObject, Rect_CheckCollision(GroundCollisioData, ComparisonObjectCollisionData)); 
        DrawRectangle(0, WINDOW_H-50, WINDOW_W, 50, WHITE);
        DrawText(TextFormat("Object Count: %d/100 \n", ObjectIndex), 0, 0, 25, WHITE); 
        DrawText(TextFormat("Dt: %f\n", GetFrameTime()), 650, 0, 25, WHITE);
        DrawText(TextFormat("FPS: %d\n", GetFPS()), 700, 25, 25, WHITE);
        DrawText(TextFormat("M(x,y): %f %f", MotionObject.Position.x, MotionObject.Position.y), 0, 25, 25, WHITE);
        DrawText(TextFormat("C(x,y): %f %f", ComparisonObject.Position.x, ComparisonObject.Position.y), 0, 50, 25, WHITE); 
        EndDrawing();
    }

    CloseWindow(); 
    return 0;
}
