#include "paddle.hpp"
#include <raylib.h>


Paddle::Paddle(int newXPos, int newPlayerNum) {
    xPos = newXPos;
    playerNum = newPlayerNum;
    rectangle.width = WIDTH;
    rectangle.height = HEIGHT;
    
    playerNum == 1 ? color = BLUE : color = RED;
}

void Paddle::move() {
    // get and register input from player
    switch (playerNum) {
        case 1:
            if (IsKeyDown(KEY_W)) { yPos -= SPEED; }
            if (IsKeyDown(KEY_S)) {yPos += SPEED; }
            break;
        case 2:
            if (IsKeyDown(KEY_UP)) { yPos -= SPEED; }
            if (IsKeyDown(KEY_DOWN)) { yPos += SPEED; }
            break;
    }

    // prevent player from going out of bounds
    if (yPos - (HEIGHT/2) < 0) { yPos = (HEIGHT/2); }
    if (yPos + (HEIGHT/2) > 800) { yPos = 800 - (HEIGHT/2); }
}

void Paddle::draw() {
    // update rectangle
    r_rectangle.x = xPos - (WIDTH/2.0);
    r_rectangle.y = yPos - (HEIGHT/2.0);

    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
    DrawRectangleRec(rectangle, color);
}

Rectangle& Paddle::getRect() {
    return r_rectangle;
}
