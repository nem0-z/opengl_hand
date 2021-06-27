#pragma once

#include <GL/glut.h>

#include "finger.hpp"
#include "model.hpp"
#include "material.hpp"

class Finger {
    float *position;
    float *angle;
    float modelSize;
    Model box;
    Material material;
    void drawJoint(float zscale, float tx, float ty, float tz);

public:
    Finger() = default;
    Finger(float size, float *pos);
    void draw();
    void setFlexAngles(float *f);
    void drawThumb();
};