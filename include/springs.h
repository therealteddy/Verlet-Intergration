#ifndef SPRINGS_H
#define SPRINGS_H

#include "vectors.h"
#include <raylib.h>

typedef struct {
    Vector AnchorPoint; 
    Vector ParticlePoint; 
    double SpringConst; 
} Spring; 

typedef struct {
    Vector Position; 
    double Mass; 
} Particle; 

/* Draw Spring from anchor to particle */ 
void DrawSpring(Spring Coil); 

/* Update Springs Position in 1 Dimension */ 
void SpringMotion(Spring* Coil, Particle* Load);

/* position of the spring using harmonic motion */
void SpringHarmonicMotion(Spring* Coil, Particle* Load, double Ax, double Bx, double Ay, double By); 

/* Calculate the 2D motion of a sprin using newtonian mechanics and hook's law */
void SpringMotion2D(Spring* Coil, Particle* Load, double Damping);

#endif // SPRINGS_H