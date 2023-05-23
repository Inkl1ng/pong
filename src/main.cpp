#include "paddle.hpp"
#include "ball.hpp"
#include "text.hpp"
#include "constants.hpp"
#include "types.hpp"
#include "raylib.h"

void mainGame(GameStatus& game_status, Paddle& player_1, Paddle& player_2) {
    // which side the ball was scored on
    int scored_side {};
    Ball ball;

    while (game_status == GameStatus::PLAYING) {
        // check for collision
        ball.collision(player_1);
        ball.collision(player_2);
        
        // scoring and freezing the ball
        scored_side = ball.outOfBounds();
        if (scored_side == 1) {
            player_2.addPoint();
            ball.freeze();
        } else if (scored_side == 2) {
            player_1.addPoint();
            ball.freeze();
        }

        // check for a win
        if (player_1.getScore() == constants::points_to_win) {
            game_status = GameStatus::PLAYER_1_WIN;
            break; // immediately exit game loop
        } else if (player_2.getScore() == constants::points_to_win) {
            game_status = GameStatus::PLAYER_2_WIN;
            break;
        }

        // check for exiting the game loop
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) {
            game_status = GameStatus::EXIT_GAME;
            break;
        }

        // movement
        player_1.move();
        player_2.move();
        if (!ball.isFrozen()) { ball.move(); };

        // drawing
        BeginDrawing();
            ClearBackground(BLACK);
            // draw objects
            player_1.draw();
            player_2.draw();
            ball.draw();

            // draw score
            text::drawScore(player_1, player_2);

            // draw vertical line down the middle
            DrawLineV({constants::width/2.0,0},
                      {constants::width/2.0, constants::height},
                      WHITE);
        EndDrawing();
    }
}

void winScreen(GameStatus &game_status, Paddle& player_1, Paddle& player_2) {
    while (game_status == GameStatus::PLAYER_1_WIN
            || game_status == GameStatus::PLAYER_2_WIN) {
        BeginDrawing();
            ClearBackground(BLACK);

            player_1.draw();
            player_2.draw();
            text::drawScore(player_1, player_2);
            text::drawWinText(game_status);
        EndDrawing();

        // check for inputs to play game or exit
        if (IsKeyPressed(KEY_Y)) {
            game_status = GameStatus::PLAYING;
            player_1.reset();
            player_2.reset();
        }
        if (IsKeyPressed(KEY_N)) { game_status = GameStatus::EXIT_GAME; }
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
    Paddle player1(constants::player_1_x_pos, 1);
    Paddle player2(constants::player_2_x_pos, 2);
    
    // title screen loop
    while (gameStatus != GameStatus::EXIT_WINDOW) {
        // draw title screen text
        BeginDrawing();
            ClearBackground(BLACK);
            text::drawTitleScreen();
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
