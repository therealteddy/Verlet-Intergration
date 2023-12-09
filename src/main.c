#include <stdio.h> 
#include <raylib.h>

#include "angularmotion.h"
#include "vectors.h"
#include "verlet.h"
#include "circle.h"
#include "aabb.h"

#define WINDOW_W 800 
#define WINDOW_H 600 
#define WINDOW_T "Verlet Intergration"

int main(int argc, char* argv[]) {

    /* Raylib Essentials */ 
    InitWindow(WINDOW_W, WINDOW_H, WINDOW_T); 
    SetTargetFPS(FPS_CAP); 

    while (!WindowShouldClose()) {
        ClearBackground(GRAY); 
    }

    CloseWindow(); 
    return 0;
}   