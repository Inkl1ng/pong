#include "paddle.hpp"
#include <raylib.h>


Paddle::Paddle(float new_x_pos, int new_player_num) {
    player_num = new_player_num;
    
    player_num == 1 ? color = BLUE : color = RED;
    rectangle = { new_x_pos - (width/2), 400 - (height/2), height, height };
    score = 0;
}

void Paddle::Move() {
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

void Paddle::Draw() {
    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
    DrawRectangleRec(rectangle, color);
}

Rectangle& Paddle::GetRectangle() {
    return r_rectangle;
}

int Paddle::GetScore() {
    return score;
}

void Paddle::AddPoint() {
    ++score;
}

void Paddle::Reset() {
    rectangle.y = 400 - (height/2);
    score = 0;
}
