#include "../include/finger.hpp"
#include "../include/hand.hpp"
#include "../include/model.hpp"

Hand::Hand() {
    this->material = Material();
}

void Hand::setAngles(float *angles) {
    this->angles = angles;
}

void Hand::setDigits(Finger digits[5]) {
    this->digits = digits;
}

void Hand::setPalm(float size) {
    this->palm = Model(size);
}

void Hand::drawPalm() {
    glPushMatrix();

    glScalef(1, 1, 0.15);
    palm.draw();

    glPopMatrix();
}

void Hand::drawDigits() {
    for (int i = 0; i < 5; i++) { 
        digits[i].setFlexAngles(angles);
        digits[i].draw();
    }
}

void Hand::draw() {
    material.setPrimary();
    material.handTexture();
    drawPalm();
    drawDigits();
}