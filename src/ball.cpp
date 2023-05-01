#include "ball.hpp"
#include "raylib.h"
#include <cmath>
#include <array>

void Ball::move() {
    double radians { angle * 3.14159 * 180 };

    xPos += speed * std::cos(radians);
    yPos += speed * std::sin(radians);
}

void Ball::draw() {
    DrawCircle(xPos, yPos, RADIUS, WHITE);
}

std::array<int, 2>& Ball::getPos() {
    return pos;
}
