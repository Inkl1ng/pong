#include "paddle.hpp"
#include "ball.hpp"
#include "text.hpp"
#include "constants.hpp"
#include "types.hpp"
#include "settings.hpp"
#include "raylib.h"

void mainGame(GameStatus& game_status, Paddle& player_1, Paddle& player_2) {
    // which side the ball was scored on
    int scored_side {};
    Ball ball;

    const int score_x_padding { 100 };
    const int score_y_pos { 100 };
    const int score_font_size { 100 };
    int player_2_text_width {};

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
        // measures width of player 2's score for when it needs to be drawn so
        // both player 1's and player 2's score texts look like they're the same
        // distance away from the border of the screen
        player_2_text_width = MeasureText(TextFormat("%i", player_2.getScore()),
                score_font_size);

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
            game_status = GameStatus::MAIN_MENU;
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
            DrawText(TextFormat("%i", player_1.getScore()), score_x_padding,
                    score_y_pos, score_font_size, BLUE);
            DrawText(TextFormat("%i", player_2.getScore()), 
                    constants::width - score_x_padding -  player_2_text_width,
                    score_y_pos, score_font_size, RED);

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
        if (IsKeyPressed(KEY_N)) { game_status = GameStatus::MAIN_MENU; }
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
    GameStatus game_status { GameStatus::PLAYING };
 
    // initialize players
    Paddle player1(constants::player_1_x_pos, 1);
    Paddle player2(constants::player_2_x_pos, 2);
    
    // title screen loop
    while (game_status != GameStatus::EXIT_GAME) {
        // draw title screen text
        BeginDrawing();
            ClearBackground(BLACK);
            text::drawTitleScreen();
        EndDrawing();

        // check if the players want to start playing
        if (IsKeyPressed(KEY_SPACE)) {
            game_status = GameStatus::PLAYING;

            // enter game
            while (game_status == GameStatus::PLAYING) {
                mainGame(game_status, player1, player2);
                winScreen(game_status, player1, player2);
            }
        }
        // check if the players want to quit
        if (IsKeyPressed(KEY_Q)) {
            game_status = GameStatus::EXIT_GAME;
        }
        if (IsKeyPressed(KEY_O)) {
            game_status = GameStatus::SETTINGS;
            settings::saveColors({ 0,1,2 }, { 3,4,5 });
            settings::settingsScreen(game_status);
        }
    }

    // end program
    CloseWindow();
    return 0;
}
