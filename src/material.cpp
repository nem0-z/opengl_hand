#include "../include/material.hpp"

void Material::setPrimary() {
    GLfloat mat_diffuse[] = {1, 0.8, 0, 1.0};
    GLfloat mat_specular[] = {0.9, 0.5, 0.3, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
}

void Material::setSecondary() {
    GLfloat mat_diffuse[] = {0.7, 0.8, 0.4, 1.0};
    GLfloat mat_specular[] = {0.8, 0.8, 0.8, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
}