#include "paddle.hpp"
#include "ball.hpp"
#include "raylib.h"
#include <iostream>

int main() {
    const int WIDTH { 1000 };
    const int HEIGHT { 800 };
    const int FPS { 30 };
    const int PADDLE_OFFSET { 25 };

    const int player1XPos { PADDLE_OFFSET };
    const int player2XPos { WIDTH - PADDLE_OFFSET };

    InitWindow(WIDTH, HEIGHT, "Raylib pong!");
    SetTargetFPS(FPS);

    Paddle player1(player1XPos, 1);
    Paddle player2(player2XPos, 2);
    Ball ball;

    int scoredSide {};
    bool isFrozen { false };
    // how long the ball will be frozen after it is scored in seconds
    const double FREEZE_TIME { 1.500 };
    // when the freeze started
    double initialFreezeTime {};

    while(!WindowShouldClose()) {
        // collision
        ball.collision(player1);
        ball.collision(player2);

        // scoring
        scoredSide = ball.outOfBounds();
        if (scoredSide == 1) {
            player1.addPoint();
            initialFreezeTime = GetTime();
        } else if (scoredSide == 2) {
            player2.addPoint();
            initialFreezeTime = GetTime();
        }

        // movement
        player1.move();
        player2.move();

        // freeze ball movement if needed
        isFrozen = GetTime() - initialFreezeTime < FREEZE_TIME;

        if (!isFrozen) {
            ball.move();
        }

        // drawing
        BeginDrawing();
            ClearBackground(BLACK);
            player1.draw();
            player2.draw();
            ball.draw();
        EndDrawing();
    }

    return 0;
}

