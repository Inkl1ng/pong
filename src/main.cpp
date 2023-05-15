#include "paddle.hpp"
#include "ball.hpp"
#include "text.hpp"
#include "constants.hpp"
#include "types.hpp"
#include "raylib.h"

void mainGame(GameStatus& gameStatus, Paddle& player1, Paddle& player2) {
    int scoredSide {};
    Ball ball;

    while (gameStatus == GameStatus::PLAYING) {
        // check for collision
        ball.Collision(player1);
        ball.Collision(player2);
        
        // scoring
        // scoredSide is the side that the ball was scored on
        scoredSide = ball.OutOfBounds();
        if (scoredSide == 1) {
            player2.AddPoint();
            ball.Freeze();
        } else if (scoredSide == 2) {
            player1.AddPoint();
            ball.Freeze();
        }

        // check for a win
        if (player1.GetScore() == constants::pointsToWin) {
            gameStatus = GameStatus::PLAYER_1_WIN;
        } else if (player2.GetScore() == constants::pointsToWin) {
            gameStatus = GameStatus::player2Win;
        }

        // check for exiting the game loop
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
        {
            gameStatus = GameStatus::EXIT_GAME;
            break;
        }

        // movement
        player1.Move();
        player2.Move();
        if (!ball.IsFrozen()) { ball.Move(); };

        // drawing
        BeginDrawing();
            ClearBackground(BLACK);
            // draw objects
            player1.Draw();
            player2.Draw();

            if (gameStatus == GameStatus::PLAYING) {
                ball.Draw();
            }

            // draw score
            text::DrawScore(player1, player2);

            // draw vertical line down the middle
            DrawLineV({constants::width/2.0,0},
                      {constants::width/2.0, constants::height},
                      WHITE);
        EndDrawing();
    }

    return;
}

void winScreen(GameStatus &gameStatus, Paddle& player1, Paddle& player2) {
    while (gameStatus == GameStatus::PLAYER_1_WIN
            || gameStatus == GameStatus::player2Win) {
        BeginDrawing();
            ClearBackground((BLACK));

            player1.Draw();
            player2.Draw();
            text::DrawScore(player1, player2);
            text::DrawWinText(gameStatus);
        EndDrawing();
        
        if (IsKeyPressed(KEY_Y)) {
            gameStatus = GameStatus::PLAYING;
            player1.Reset();
            player2.Reset();
        }
        if (IsKeyPressed(KEY_N)) { gameStatus = GameStatus::EXIT_GAME; }
    }
}

int main() {
    // initialization
    const int FPS { 30 };
    InitWindow(constants::width, constants::height, "Raylib pong!");
    SetTargetFPS(FPS);

    // there are custom keybinds for exitting the game so the ESCAPE
    // key will be unbinded from exitting the game
    SetExitKey(KEY_NULL);
    
    // gameStatus gets passed around through a reference so it changes
    // a lot
    GameStatus gameStatus { GameStatus::PLAYING };
 
    // initialize players
    Paddle player1(constants::player1XPos, 1);
    Paddle player2(constants::player2XPos, 2);
    
    // title screen loop
    while (gameStatus != GameStatus::EXIT_WINDOW) {
        // draw title screen text
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Pong!", 0, 0, 40, WHITE);
        EndDrawing();

        // check if the players want to start playing
        if (IsKeyPressed(KEY_SPACE)) {
            gameStatus = GameStatus::PLAYING;

            // enter game
            while (gameStatus == GameStatus::PLAYING) {
                mainGame(gameStatus, player1, player2);
                winScreen(gameStatus, player1, player2);
            }
        }
        // check if the players want to quit
        if (IsKeyPressed(KEY_Q)) {
            gameStatus = GameStatus::EXIT_WINDOW;
        }
    }

    // end program
    CloseWindow();
    return 0;
}

