#pragma once

#include <GL/glut.h>

#include "model.hpp"
#include "finger.hpp"
#include "material.hpp"

class Hand {
    Model palm;
    Finger *digits;
    Material material;
    float *angles;
    void drawPalm();
    void drawThumb();
    void drawDigits();

public:
    Hand();
    void draw();
    void setDigits(Finger *digits);
    void setPalm(float size);
    void setAngles(float *angles);
};