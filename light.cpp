#include "light.hpp"

Light::Light(int light) {
    this->light = light;
}

void Light::draw() {
    glLightfv(light, GL_POSITION, position);
    glLightfv(light, GL_SPECULAR, specularColor);
    glLightfv(light, GL_DIFFUSE, diffuseColor);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(light);
}

void Light::setPosition(float *position) {
    this->position = position;
}

void Light::setColor(float *dcolor, float *scolor) {
    this->diffuseColor = dcolor;
    this->specularColor = scolor;
}