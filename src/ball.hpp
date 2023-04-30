#ifndef BALL_HPP
#define BALL_HPP

class Ball {
public:
    Ball();

    void move();
    void draw();

private:
    const int RADIUS { 25 };
    const int SPEED { 20 };
};

#endif
