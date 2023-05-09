#include "paddle.hpp"
#include "ball.hpp"
#include "raylib.h"
#include "text.hpp"
#include "constants.hpp"
#include "types.hpp"
#include <iostream>

void mainGame(GameStatus& gameStatus) {
    int scoredSide {};
    Paddle player1(constants::player1XPos, 1);
    Paddle player2(constants::player2XPos, 2);
    Ball ball;

    while (gameStatus == GameStatus::playing) {
        // check for collision
        ball.collision(player1);
        ball.collision(player2);
        
        // scoring
        // scoredSide is the side that the ball was scored on
        scoredSide = ball.outOfBounds();
        if (scoredSide == 1) {
            player2.addPoint();
            ball.freeze();
        } else if (scoredSide == 2) {
            player1.addPoint();
            ball.freeze();
        }

        // check for a win
        if (player1.getScore() == constants::POINTS_TO_WIN) {
            gameStatus = GameStatus::player1Win;
        } else if (player2.getScore() == constants::POINTS_TO_WIN) {
            gameStatus = GameStatus::player2Win;
        }

        // check for exiting the game loop
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
        {
            gameStatus = GameStatus::exitGame;
            break;
        }

        // movement
        player1.move();
        player2.move();
        if (!ball.isFrozen()) { ball.move(); };

        // drawing
        BeginDrawing();
            ClearBackground(BLACK);
            // draw objects
            player1.draw();
            player2.draw();

            if (gameStatus == GameStatus::playing) {
                ball.draw();
            }

            // draw score
            text::drawScore(player1, player2);
        EndDrawing();
    }

    return;
}

void winScreen(GameStatus &gameStatus) {
    while (gameStatus == GameStatus::player1Win
            || gameStatus == GameStatus::player2Win) {
        BeginDrawing();
            ClearBackground((BLACK));
            text::drawWinText(gameStatus);
        EndDrawing();
        
        if (IsKeyPressed(KEY_Y)) { gameStatus = GameStatus::playing; }
        if (IsKeyPressed(KEY_N)) { gameStatus = GameStatus::exitGame; }
        
    }
}

int main() {
    const int FPS { 30 };

   int player2TextPos {};

    InitWindow(constants::WIDTH, constants::HEIGHT, "Raylib pong!");
    SetTargetFPS(FPS);
    SetExitKey(KEY_NULL);

    GameStatus gameStatus { GameStatus::playing };

    while (gameStatus == GameStatus::playing) {
        mainGame(gameStatus);
        winScreen(gameStatus);
   }

    CloseWindow();
    return 0;
}

