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

    while(!WindowShouldClose()) {
        // movement
        player1.move();
        player2.move();
        ball.move();

        // drawing
        BeginDrawing();
            ClearBackground(BLACK);
            player1.draw();
            player2.draw();
        EndDrawing();
    }

    return 0;
}

