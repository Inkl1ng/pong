#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "raylib.h"

class Paddle {
public:
    Paddle(float new_x_pos, int new_player_num);
    
    void move();
    void draw();
    Rectangle &getRectangle();

    int getScore();
    void addPoint();

    void reset();

private:
    const float width { 15.0 };
    const float height { 80.0 };
    const int speed { 15 };

    int player_num {}; // either 1 or 2, represnets player 1 or 2
    Color color {};
    int score {};

    Rectangle rectangle;
    // reference to rectangle to reduce memory usage from copying entire
    // struct
    Rectangle &r_rectangle { rectangle };
};

#endif
