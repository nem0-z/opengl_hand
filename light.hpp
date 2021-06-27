#pragma once

#include <GL/glut.h>

class Light {
    float *position;
    float *diffuseColor;
    float *specularColor;
    int light;

public:
    Light(int light);
    void draw();
    void setPosition(float *position);
    void setColor(float *dcolor, float *scolor);
};