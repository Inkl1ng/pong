#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"


class Ball {
public:
    void move();
    void draw();

private:
    const int RADIUS { 12 };

    int xPos { 500 };
    int yPos { 400 };
    double speed { 12 };
    // angle in degrees
    int angle { 180 };
};

#endif
