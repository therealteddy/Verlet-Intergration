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
    /* Declare Position of an object */ 
    Rectangle Square; 
    Square.height = 100; 
    Square.width = 100; 
    Square.x = 100; 
    Square.y = 100; 

    /* Update Object Position based on Linear Kinematics */ 
    VerletObject VerletSquare = {0}; 
    VerletSquare.Position = (Vector) {Square.x, Square.y}; 

    /* Update Objects Rotation */ 
    AngularObject AngularSquare; 
    AngularSquare.Mass = 10; 
    AngularSquare.Inertia = Plate_GetMomentOfInertia(AngularSquare.Mass, Square.width, Square.height); 

    InitWindow(WINDOW_W, WINDOW_H, WINDOW_T); 
    SetTargetFPS(FPS_CAP); 

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK); 
            
            /* Update Angular Stuff! */
            GetAngularAcceleration(&AngularSquare, Plate_GetTorque(EARTH_GRAVITY_CONST, Square.height, Square.width)); 
            GetAngularVelocity(&AngularSquare); 
            GetAngularDisplacement(&AngularSquare); 

            /* Update Linear Stuff */ 
            VerletGravity(&VerletSquare, false); 
            Square.x = VerletSquare.Position.x; 
            Square.y = VerletSquare.Position.y; 

            /* Render a quad! */
            DrawRectanglePro(Square, 
                (Vector2) {
                    Square.width/2, 
                    Square.height/2
                }, 
                AngularSquare.AngularDisplacement, 
                RAYWHITE
            ); 

        EndDrawing(); 
    }

    CloseWindow(); 
    return 0; 
}
