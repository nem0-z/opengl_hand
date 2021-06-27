#pragma once

#include <GL/glut.h>

class Model {
    float size;
public:
    Model() = default;
    Model(float size);
    void draw();
};