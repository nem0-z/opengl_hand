#include "camera.hpp"

void Camera::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(leftClip, rightClip, bottomClip, topClip, nearClip, farClip);
    gluLookAt(position[0], position[1], position[2], 
            target[0], target[1], target[2], 
            0, 1, 0);
}

void Camera::setPosition(float *position) {
    this->position = position;
}

void Camera::setTarget(float *target) {
    this->target = target;
}

void Camera::setClips(float left, float right, float bottom, float top, float near, float far) {
    this->leftClip = left;
    this->rightClip = right;
    this->bottomClip = bottom;
    this->topClip = top;
    this->nearClip = near;
    this->farClip = far;
}