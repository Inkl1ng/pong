#include "text.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "raylib.h"

namespace text {
    void drawScore(Paddle& player1, Paddle &player2) {
        DrawText(TextFormat("%i", player1.getScore()),
                 TEXT_X_PADDING, TEXT_Y_PADDING,
                 TEXT_SIZE, BLUE);
        int player2TextWith = MeasureText(TextFormat("%i", player2.getScore()),
                TEXT_SIZE);
        DrawText(TextFormat("%i", player2.getScore()),
                 constants::WIDTH - player2TextWith - TEXT_X_PADDING, 
                 TEXT_Y_PADDING,
                 TEXT_SIZE, RED);
    }
}

