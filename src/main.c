#include <stdio.h> 
#include <raylib.h>

#include "angularmotion.h"
#include "vectors.h"
#include "springs.h"
#include "verlet.h"
#include "circle.h"
#include "aabb.h"

#define WINDOW_W 1280
#define WINDOW_H 720
#define WINDOW_T "Verlet Intergration"

int main(int argc, char* argv[]) {
    InitWindow(WINDOW_W, WINDOW_H, WINDOW_T); 
    SetTargetFPS(FPS_CAP);

    /* Define a load */
    Particle Load; 
    Load.Mass = 1; 
    Load.Position = (Vector) {WINDOW_W/2 + 100, WINDOW_H/2 + 100}; 
    
    /* Define a Spring */
    Spring Coil; 
    Coil.AnchorPoint = (Vector) {WINDOW_W/2, WINDOW_H/2};
    Coil.ParticlePoint = Load.Position; 
    Coil.SpringConst = 7;

    while (!WindowShouldClose()) {
        BeginDrawing();
          if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Load.Position.x = (Coil.ParticlePoint.x = GetMousePosition().x);
            Load.Position.y = (Coil.ParticlePoint.y = GetMousePosition().y);
          }
          ClearBackground(BLACK);
          SpringMotion2D(&Coil, &Load, 1); 
          DrawSpring(Coil);
          DrawCircle(Coil.ParticlePoint.x, Coil.ParticlePoint.y, 10, WHITE);
          DrawText(TextFormat("Y: %f\n", Coil.ParticlePoint.y), 0, 0, 25, WHITE);
          DrawText(TextFormat("X: %f\n", Coil.ParticlePoint.x), 0, 25, 25, WHITE);
        EndDrawing(); 
   }

   CloseWindow(); 
   return 0; 
}