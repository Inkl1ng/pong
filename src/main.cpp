#include "paddle.hpp"
#include "ball.hpp"
#include "raylib.h"
#include "text.hpp"
#include "constants.hpp"
#include "types.hpp"
#include <iostream>

void mainGame(GameStatus& gameStatus, Paddle& player1, Paddle& player2) {
    int scoredSide {};
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

            // draw vertical line down the middle
            DrawLineV({constants::WIDTH/2.0,0},
                      {constants::WIDTH/2.0, constants::HEIGHT},
                      WHITE);
        EndDrawing();
    }

    return;
}

void winScreen(GameStatus &gameStatus, Paddle& player1, Paddle& player2) {
    while (gameStatus == GameStatus::player1Win
            || gameStatus == GameStatus::player2Win) {
        BeginDrawing();
            ClearBackground((BLACK));

            player1.draw();
            player2.draw();
            text::drawScore(player1, player2);
            text::drawWinText(gameStatus);
        EndDrawing();
        
        if (IsKeyPressed(KEY_Y)) {
            gameStatus = GameStatus::playing;
            player1.reset();
            player2.reset();
        }
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
    Paddle player1(constants::player1XPos, 1);
    Paddle player2(constants::player2XPos, 2);
 
    while (gameStatus == GameStatus::playing) {
        mainGame(gameStatus, player1, player2);
        winScreen(gameStatus, player1, player2);
    }

    CloseWindow();
    return 0;
}

