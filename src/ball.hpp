#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"


class Ball {
public:
    void move();
    void draw();

private:
    const int RADIUS { 25 };

    int xPos { 500 };
    int yPos { 400 };
    double speed { 25 };
    // angle in degrees
    int angle { 180 };
};

#endif
