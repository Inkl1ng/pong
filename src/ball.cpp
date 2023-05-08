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

int Ball::outOfBounds() {
    bool outOfBounds { location.x < 0 || location.x > 1000 };
    int playerSide {}; // which side the ball was on when it was scored

    if (outOfBounds) {
        // playerSide will be 1 or 2 depending on which half of the
        // playerfield it was on before it was scored
        location.x < 500 ? playerSide = 1 : playerSide = 2;
        // reset location to center of screen
        location.x = 500;
        location.y = 400;
        // reset speed
        speed = 10;

        // if player 1 scored then send the ball to player 2 and if 
        // player 2 scored then send the ball to player 1
        playerSide == 1 ? angle = 180 : angle = 0;
        return playerSide;
    } else {
        return 0;
    }
}

Vector2& Ball::getPos() {
    return location;
}

int Ball::getRadius() {
    return RADIUS;
}

void Ball::freeze() {
    initialFreezeTime = GetTime();
}

bool Ball::isFrozen() {
    return GetTime() - initialFreezeTime < FREEZE_TIME;
}
