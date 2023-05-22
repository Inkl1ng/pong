#include "paddle.hpp"
#include "raylib.h"

/**
 * Paddle class constructor
 * 
 * @param[in] new_x_pos Position of the paddle
 * @param[in] new_player_num The player number the paddle is controlled
 *     by
*/
Paddle::Paddle(float new_x_pos, int new_player_num) {
    player_num = new_player_num;
    
    player_num == 1 ? color = BLUE : color = RED;
    rectangle = { new_x_pos - (width/2), 400 - (height/2), width, height };
    score = 0;
}

/// Move the paddle
void Paddle::move() {
    // get and register input from player
    switch (player_num) {
        case 1:
            if (IsKeyDown(KEY_W)) { rectangle.y -= speed; }
            if (IsKeyDown(KEY_S)) { rectangle.y += speed; }
            break;
        case 2:
            if (IsKeyDown(KEY_UP)) { rectangle.y -= speed; }
            if (IsKeyDown(KEY_DOWN)) { rectangle.y += speed; }
            break;
    }

    // prevent player from going out of bounds
    if (rectangle.y < 0) { rectangle.y = 0; }
    if (rectangle.y + height > 800) { rectangle.y = 800 - height; }
}

/// Draw the paddle
void Paddle::draw() {
    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
    DrawRectangleRec(rectangle, color);
}

/// @returns Paddle's Rectangle struct
Rectangle& Paddle::getRectangle() {
    return r_rectangle;
}

/// @returns Score of the player the paddle is associated with
int Paddle::getScore() {
    return score;
}

/// Add 1 point to score
void Paddle::addPoint() {
    ++score;
}

/// Reset score and y-position to initial values
void Paddle::reset() {
    rectangle.y = 400 - (height/2);
    score = 0;
}
