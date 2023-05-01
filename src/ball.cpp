#include "ball.hpp"
#include "raylib.h"
#include <cmath>
#include <array>

void Ball::move() {
    xPos += xSpeed;
    yPos += ySpeed;
}

void Ball::draw() {
    DrawCircle(xPos, yPos, RADIUS, WHITE);
}

std::array<int, 2>& Ball::getPos() {
    return pos;
}

int Ball::getRadius() {
    return RADIUS;
}
