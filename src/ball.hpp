#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"
#include <array>

class Ball {
public:
    void move();
    void draw();

    std::array<int, 2>& getPos();
    int getRadius();

private:
    const int RADIUS { 12 };

    std::array<int, 2> pos { 500, 400 }; // x and y coordinates
    int& xPos { pos[0] };
    int& yPos { pos[1] };
    double speed { 12 };
    // angle in degrees
    int angle { 180 };
};

#endif
