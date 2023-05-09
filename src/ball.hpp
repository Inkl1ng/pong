#ifndef BALL_HPP
#define BALL_HPP

#include "paddle.hpp"
#include "raylib.h"
#include <array>

class Ball {
public:
    void move();
    void draw();

    void collision(Paddle& target);
    int outOfBounds();

    Vector2& getPos();
    int getRadius();

    void freeze();
    bool isFrozen();

    void reset();

private:
    const float RADIUS { 12 };

    Vector2 location { 500, 400 };
    float speed { 10 };
    float angle { 180 };
    
    const float FREEZE_TIME { 1.5 };
    float initialFreezeTime {};
};

#endif
