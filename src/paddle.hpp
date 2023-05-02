#ifndef PADDLE_HPP
#define PADDLE_HPP


#include "raylib.h"

class Paddle {
public:
    Paddle(float newXPos, int newPlayerNum);
    
    void move();
    void draw();
    Rectangle& getRectangle();

private:
    const float WIDTH { 15.0 };
    const float HEIGHT { 80.0 };
    const int SPEED { 15 };

    int playerNum {}; // either 1 or 2, represnets player 1 or 2
    Color color {};
    int score {};

    Rectangle rectangle;
    Rectangle& r_rectangle { rectangle };
};

#endif
