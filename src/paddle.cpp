#include "paddle.hpp"
#include <raylib.h>


Paddle::Paddle(int newXPos, int newPlayerNum) {
    xPos = newXPos;
    playerNum = newPlayerNum;
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
    DrawRectangle(xPos - (WIDTH/2), yPos - (HEIGHT/2), WIDTH, HEIGHT, 
        playerNum == 1 ? BLUE : RED);
    // line above sets the color to either be BLUE or RED based on the 
    // player number, 1 for BLUE and 2 for RED
}
