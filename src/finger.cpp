#include "../include/model.hpp"
#include "../include/finger.hpp"
#include "../include/material.hpp"

Finger::Finger(float size, float *pos) {
    this->position = pos;
    this->modelSize = size;
    this->box = Model(modelSize);
    this->material = Material();
}

void Finger::drawJoint(float zscale, float tx, float ty, float tz) {
    material.setSecondary();
    glPushMatrix();
    glScalef(3.5, 1, zscale);
    glTranslatef(tx, ty, tz);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();
    material.setPrimary();
}

void Finger::drawThumb() {
    glPushMatrix();

    glScalef(0.8, 1.5, 0.6);

    glTranslatef(3.8, -1.1, 0);
    glRotatef(-angle[1], 0, 1, 0);
    glTranslatef(0, 0, angle[1] * 0.01);
    box.draw();

    drawJoint(1, 0.1, 0.0, 0);

    glTranslatef(modelSize + 0.2, 0, 0);
    glRotatef(-angle[1], 0, 1, 0);
    glTranslatef(0, 0, angle[1] * 0.007);
    box.draw();

    glPopMatrix();
}

void Finger::draw() {
    if (modelSize != 1) {
        drawThumb();
        return;
    }

    glPushMatrix();

    glScalef(0.8, 1.5, 0.6);

    glTranslatef(position[0], position[1], position[2]);
    glRotatef(angle[0], 1, 0, 0);
    glTranslatef(0, angle[0] * 0.01, angle[0] * 0.01);
    box.draw();

    drawJoint(2, 0, 0.6, 0);

    glTranslatef(0, modelSize + 0.1, 0);
    glRotatef(angle[1], 1, 0, 0);
    glTranslatef(0, angle[1] * 0.005, angle[1] * 0.007);
    box.draw();

    drawJoint(2, 0, 0.6, 0);

    glTranslatef(0, modelSize + 0.1, 0);
    glRotatef(angle[2], 1, 0, 0);
    glTranslatef(0, angle[2] * 0.005, angle[2] * 0.007);
    box.draw();

    glPopMatrix();
}

void Finger::setFlexAngles(float *f) {
    this->angle = f;
}