#include <GL/glut.h>
#include <stdlib.h>

#include "include/camera.hpp"
#include "include/finger.hpp"
#include "include/hand.hpp"
#include "include/helper.hpp"
#include "include/light.hpp"
#include "include/model.hpp"

GLfloat angle1 = 0.;
GLfloat angle2 = 0.;
GLfloat angle3 = 0.;
GLfloat rotatingAngle = 0;

Helper helper;

void init() {
    glClearColor(0, 0, 0, 0);

    Camera camera;
    float position[] = {0, 0, 11};
    float target[] = {0, 0, 0};
    camera.setClips(-5, 5, -5, 5, 5, 20);
    camera.setPosition(position);
    camera.setTarget(target);
    camera.draw();


    Light light = Light(GL_LIGHT0);
    float lightPosition[] = {-10.0, -2.0, 3.0, 0.0};
    float diffuseColor[] = {1, 1, 1, 1};
    float specularColor[] = {0.5, 0.5, 0.5, 1};
    light.setPosition(lightPosition);
    light.setColor(diffuseColor, specularColor);
    light.draw();

    light = Light(GL_LIGHT1);
    float lightPosition1[] = {10.0, 2.0, 3.0, 0.0};
    light.setPosition(lightPosition1);
    light.setColor(diffuseColor, specularColor);
    light.draw();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glRotatef(rotatingAngle, 0, 1, 0);

    Hand hand;
    float angles[] = {angle1, angle2, angle3};

    float pos1[] = {-2.5, 2.2, 0};
    Finger firstFinger = Finger(1, pos1);

    float pos2[] = {-0.8, 2.2, 0};
    Finger secondFinger = Finger(1, pos2);

    float pos3[] = {0.8, 2.2, 0};
    Finger thirdFinger = Finger(1, pos3);

    float pos4[] = {2.5, 2.2, 0};
    Finger fourthFinger = Finger(1, pos4);

    float pos5[] = {3.8, -1.2, 0};
    Finger thumb = Finger(1.1, pos5);

    Finger fingers[] = {firstFinger, secondFinger, thirdFinger, fourthFinger, thumb};

    hand.setDigits(fingers);
    hand.setPalm(4.9);
    hand.setAngles(angles);
    hand.draw();

    glFlush();
}

void keyboardCallback(unsigned char key, int x, int y) {
    switch(key) {
        case 'o':
            helper.openHand();
            break;
        case 'c':
            helper.closeHand();
            break;
    }
    glutPostRedisplay();
}

void idleCallback() {
    rotatingAngle = (rotatingAngle > 360) ? 0 : rotatingAngle + 0.01;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardCallback);
    glutIdleFunc(idleCallback);
    glutMainLoop();
    return 0;
}