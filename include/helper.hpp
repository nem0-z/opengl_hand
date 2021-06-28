#pragma once

#include<GL/glut.h>

extern float angle1, angle2, angle3;
extern bool rotation;

class Helper {
public:
    void closeHand() {
        if (angle1 < 75) 
            angle1 += 1.5;
        if (angle2 < 75)
            angle2 += 1;
        if (angle3 < 75) 
            angle3 += 1;
    }

    void openHand() {
        if (angle1 > 0)
            angle1 -= 1.5;
        if (angle2 > 0)
            angle2 -= 1;
        if (angle3 > 0)
            angle3 -= 1;
    }

    void toggleRotation() {
        rotation = !rotation;
    }
};