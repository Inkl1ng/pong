#ifndef BALL_HPP
#define BALL_HPP

#include "paddle.hpp"
#include "raylib.h"
#include <array>

class Ball {
public:
    void Move();
    void Draw();

    void Collision(Paddle& target);
    int OutOfBounds();

    Vector2& GetPos();
    int GetRadius();

    void Freeze();
    bool IsFrozen();

    void Reset();

private:
    const float radius { 12 };

    Vector2 location { 500, 400 };
    float speed { 10 };
    float angle { 180 };
    
    const float freezeTime { 1.5 };
    float initialFreezeTime {};
};

#endif
