#include "ball.hpp"
#include "paddle.hpp"
#include "raylib.h"
#include <cmath>
#include <array>

void Ball::move() {
    float radians = angle * PI / 180;
    location.x += speed * std::cos(radians);
    location.y += speed * std::sin(radians);

    // bounce off the top and bottom boarders of the playfield
    if (location.y - radius < 0) {
        location.y = radius;
        angle = 360 - angle;
    }
    if (location.y + radius > 800) {
        location.y = 800 - radius;
        angle = 360 - angle;
    }
}

void Ball::draw() {
    DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), radius, WHITE);
}

void Ball::collision(Paddle& target_paddle) {
    Rectangle& r_target_rect { target_paddle.getRectangle() };
    bool collided = CheckCollisionCircleRec(location, radius,
            r_target_rect);

    if (collided) {
        // the farther from the cneter the ball hits the paddle the
        // greater the bounce angle
        float distance_from_center { r_target_rect.y
                + (r_target_rect.height/2) - location.y };
        float new_angle { (distance_from_center/r_target_rect.height)
                * 80};

        // make sure new angle will send ball in correct direction
        (angle < 90 || angle > 270) ? angle = 180 + new_angle
                : angle = 360 - new_angle;

        speed *= 1.05f;
    } else {
        return;
    }
}

int Ball::outOfBounds() {
    // chcek if the ball is out of bounds
    bool out_of_bounds { location.x < 0 || location.x > 1000 };
    int player_side {};

    if (out_of_bounds) {
        // playerSide will be 1 or 2 depending on which half of the
        // playerfield it was on before it was scored
        location.x < 500 ? player_side = 1 : player_side = 2;

        location.x = 500;
        location.y = 400;
        speed = 10;

        // if player 1 scored then send the ball to player 2 and if 
        // player 2 scored then send the ball to player 1
        player_side == 1 ? angle = 180 : angle = 0;
        return player_side;
    } else {
        return 0;
    }
}

void Ball::freeze() {
    initial_freeze_seconds = GetTime();
}

bool Ball::isFrozen() {
    return GetTime() - initial_freeze_seconds < freeze_seconds;
}

void Ball::reset() {
    location.x = 500;
    location.y = 400;
    speed = 10;
    angle = 180;
}
