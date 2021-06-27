#pragma once

#include <GL/glut.h>

class Camera {
    float *position;
    float *target;
    float leftClip, rightClip, bottomClip, topClip, nearClip, farClip;

public:
    void draw();
    void setPosition(float *position);
    void setTarget(float *target);
    void setClips(float left, float right, float bottom, float top, float near, float far);
};