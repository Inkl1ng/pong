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

    Vector2& getPos();
    int getRadius();

private:
    const float RADIUS { 12 };

    Vector2 location { 500, 400 };
    float speed { 10 };
    float xSpeed {};
    float ySpeed {};
    float angle { 180 };
};

#endif
