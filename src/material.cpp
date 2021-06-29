#include "../include/material.hpp"
#include "../include/wood.c"

void Material::setPrimary() {
    GLfloat mat_ambient[] = {1, 1, 1, 1.0};
    GLfloat mat_diffuse[] = {1, 1, 1, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {100.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void Material::setSecondary() {
    GLfloat mat_diffuse[] = {0.7, 0.8, 0.4, 1.0};
    GLfloat mat_specular[] = {0.8, 0.8, 0.8, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
}

void Material::handTexture() {
    GLuint texturePot = 0;

    glGenTextures(1, &texturePot);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturePot);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image_wood.width, gimp_image_wood.height,0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image_wood.pixel_data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}