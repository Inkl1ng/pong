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
    
    /// how long to freeze the ball (seconds)
    const float freeze_time { 1.5 };
    /// time the ball was first frozen at (seconds)
    float initial_freeze_time {};
};

#endif
