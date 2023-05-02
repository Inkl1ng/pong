#include "ball.hpp"
#include "paddle.hpp"
#include "raylib.h"
#include <cmath>
#include <array>

void Ball::move() {
    float radians = angle * 3.14159 / 180;
    location.x += speed * std::cos(radians);
    location.y += speed * std::sin(radians);

    // bounce off the top and bottom boarders of the playfield
    if (location.y - RADIUS < 0) {
        location.y = RADIUS;
        angle = 360 - angle;
    }
    if (location.y + RADIUS > 800) {
        location.y = 800 - RADIUS;
        angle = 360 - angle;
    }
}

void Ball::draw() {
    DrawCircle(location.x, location.y, RADIUS, WHITE);
}

void Ball::collision(Paddle& target) {
    Rectangle& r_targetRect { target.getRectangle() };
    bool collided = CheckCollisionCircleRec(location, RADIUS,
            r_targetRect);

    if (collided) {
        float distanceFromPaddleCenter { r_targetRect.y
                + (r_targetRect.height/2) - location.y };
        float newAngel { (distanceFromPaddleCenter/r_targetRect.height)
                * 75};
        
        bool movingRight { angle < 90 || angle > 270 }; 
        if (movingRight) {
            angle = 180 + newAngel;
        } else {
            angle = 360 - newAngel;
        }

        speed *= 1.05;
    } else {
        return;
    }
}

Vector2& Ball::getPos() {
    return location;
}

int Ball::getRadius() {
    return RADIUS;
}
