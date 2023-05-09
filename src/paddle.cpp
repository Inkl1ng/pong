#include "paddle.hpp"
#include <raylib.h>


Paddle::Paddle(float newXPos, int newPlayerNum) {
    playerNum = newPlayerNum;
    
    playerNum == 1 ? color = BLUE : color = RED;
    rectangle = { newXPos - (WIDTH/2), 400 - (HEIGHT/2), WIDTH, HEIGHT };
    initialYPos = newXPos - (WIDTH/2);
    score = 0;
}

void Paddle::move() {
    // get and register input from player
    switch (playerNum) {
        case 1:
            if (IsKeyDown(KEY_W)) { rectangle.y -= SPEED; }
            if (IsKeyDown(KEY_S)) { rectangle.y += SPEED; }
            break;
        case 2:
            if (IsKeyDown(KEY_UP)) { rectangle.y -= SPEED; }
            if (IsKeyDown(KEY_DOWN)) { rectangle.y += SPEED; }
            break;
    }

    // prevent player from going out of bounds
    if (rectangle.y < 0) { rectangle.y = 0; }
    if (rectangle.y + HEIGHT > 800) { rectangle.y = 800 - HEIGHT; }
}

void Paddle::draw() {
    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
    DrawRectangleRec(rectangle, color);
}

Rectangle& Paddle::getRectangle() {
    return r_rectangle;
}

int Paddle::getScore() {
    return score;
}

void Paddle::addPoint() {
    ++score;
}

void Paddle::reset() {
    rectangle.y = initialYPos;
}
