#ifndef PADDLE_HPP
#define PADDLE_HPP


#include "raylib.h"

class Paddle {
public:
    Paddle(int newXPos, int newPlayerNum);
    
    void move();
    void draw();

private:
    const int WIDTH { 15 };
    const int HEIGHT { 80 };
    const int SPEED { 15 };

    int xPos {};
    int yPos { 400 };
    int playerNum {}; // either 1 or 2, represnets player 1 or 2
};

#endif
