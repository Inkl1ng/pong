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

    void freeze();
    bool isFrozen();

    void reset();

private:
    const float radius { 12 };

    Vector2 location { 500, 400 };
    float speed { 10 };
    /// angle in degrees
    float angle { 180 };
    
    /// how long to freeze the ball 
    const double freeze_seconds { 1.5 };
    /// time the ball was first frozen at
    double initial_freeze_seconds {};
};

#endif
