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
    DrawCircle(location.x, location.y, radius, WHITE);
}

void Ball::collision(Paddle& target) {
    Rectangle& r_target_rect { target.GetRectangle() };
    bool collided = CheckCollisionCircleRec(location, radius,
            r_target_rect);

    if (collided) {
        // get the distance from the center of the paddle
        float distance_from_center { r_target_rect.y
                + (r_target_rect.height/2) - location.y };
        float new_angle { (distance_from_center/r_target_rect.height)
                * 75};
        
        bool moving_right { angle < 90 || angle > 270 }; 
        if (moving_right) {
            angle = 180 + new_angle;
        } else {
            angle = 360 - new_angle;
        }

        speed *= 1.05;
    } else {
        return;
    }
}

int Ball::outOfBounds() {
    bool out_of_bounds { location.x < 0 || location.x > 1000 };
    int player_side {}; // which side the ball was on when it was scored

    if (out_of_bounds) {
        // playerSide will be 1 or 2 depending on which half of the
        // playerfield it was on before it was scored
        location.x < 500 ? player_side = 1 : player_side = 2;
        // reset location to center of screen
        location.x = 500;
        location.y = 400;
        // reset speed
        speed = 10;

        // if player 1 scored then send the ball to player 2 and if 
        // player 2 scored then send the ball to player 1
        player_side == 1 ? angle = 180 : angle = 0;
        return player_side;
    } else {
        return 0;
    }
}

Vector2& Ball::getPos() {
    return location;
}

int Ball::getRadius() {
    return radius;
}

void Ball::freeze() {
    initial_freeze_time = GetTime();
}

bool Ball::isFrozen() {
    return GetTime() - initial_freeze_time < freeze_time;
}

void Ball::reset() {
    location.x = 500;
    location.y = 400;
    speed = 10;
    angle = 180;
}
