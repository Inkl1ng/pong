#include "ball.hpp"
#include "paddle.hpp"
#include "raylib.h"
#include <cmath>
#include <array>

/// Move the ball
void Ball::move() {
    // break velocity vector into x and y components and update location
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


/// Draw the ball onto the screen
void Ball::draw() {
    DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), radius, WHITE);
}

/**
 * Check if the ball has collided with the target paddle. If it has,
 * then update angle and slightly increase speed
 * 
 * @param[in] target_paddle paddle to check collision against
*/
void Ball::collision(Paddle& target_paddle) {
    // use rectangle from paddle to check for collision
    Rectangle& r_target_rect { target_paddle.getRectangle() };
    bool collided = CheckCollisionCircleRec(location, radius,
            r_target_rect);

    if (collided) {
        // get the distance from the center of the paddle
        float distance_from_center { r_target_rect.y
                + (r_target_rect.height/2) - location.y };
        // use distance from center of paddle to calculate new angle,
        // bounce angles scale with distance from center of paddle up to
        // max of -+ 40 and min of 0
        float new_angle { (distance_from_center/r_target_rect.height)
                * 80};

        // update angle
        // if the ball is moving to the left, then the angle will be
        // adjusted to move it to the right + new_angle from bounce and
        // vice versa        
        (angle < 90 || angle > 270) ? angle = 180 + new_angle
                : angle = 360 - new_angle;

        // slightly increase speed
        speed *= 1.05f;
    } else {
        return;
    }
}

/**
 * Check if the ball is out of bounds. If the ball is then the reset the
 * location, angle, and speed to inital values
 * 
 * @returns Which side the ball was scored on (1 or 2)
*/
int Ball::outOfBounds() {
    // chcek if the ball is out of bounds
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

/// Freezes the ball, starts a timer for freezing the ball
void Ball::freeze() {
    initial_freeze_time = GetTime();
}

/**
 * Check if the ball has been frozen for enough more than or less than
 * initial_freeze_time.
 * 
 * @returns If should be frozen or not
*/
bool Ball::isFrozen() {
    return GetTime() - initial_freeze_time < freeze_time;
}

/// Reset location, speed, and angle to initial values
void Ball::reset() {
    location.x = 500;
    location.y = 400;
    speed = 10;
    angle = 180;
}
