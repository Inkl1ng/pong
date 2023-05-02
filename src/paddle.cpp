#include "paddle.hpp"
#include <raylib.h>


Paddle::Paddle(int newXPos, int newPlayerNum) {
    location.x = newXPos;
    playerNum = newPlayerNum;
    
    playerNum == 1 ? color = BLUE : color = RED;
}

void Paddle::move() {
    // get and register input from player
    switch (playerNum) {
        case 1:
            if (IsKeyDown(KEY_W)) { location.y -= SPEED; }
            if (IsKeyDown(KEY_S)) { location.y += SPEED; }
            break;
        case 2:
            if (IsKeyDown(KEY_UP)) { location.y -= SPEED; }
            if (IsKeyDown(KEY_DOWN)) { location.y += SPEED; }
            break;
    }

    // prevent player from going out of bounds
    if (location.y - (HEIGHT/2) < 0) { location.y = (HEIGHT/2); }
    if (location.y + (HEIGHT/2) > 800) { location.y = 800 - (HEIGHT/2); }
}

void Paddle::draw() {
    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
    DrawRectangle(location.x, location.y, WIDTH, HEIGHT, color);
}

Vector2& Paddle::getLocation() {
    return location;
}
