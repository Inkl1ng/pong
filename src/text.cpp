#include "text.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "raylib.h"
#include "types.hpp"
#include <string>

namespace text {
    void drawScore(Paddle& player1, Paddle &player2) {
        DrawText(TextFormat("%i", player1.getScore()),
                 TEXT_X_PADDING, TEXT_Y_PADDING,
                 SCORE_SIZE, BLUE);
        int player2TextWidth = MeasureText(TextFormat("%i", player2.getScore()),
                SCORE_SIZE);
        DrawText(TextFormat("%i", player2.getScore()),
                 constants::WIDTH - player2TextWidth - TEXT_X_PADDING, 
                 TEXT_Y_PADDING,
                 SCORE_SIZE, RED);
    }



    void drawWinText(GameStatus& gameStatus) {
        std::string winText {};
        std::string replayText { "Play again? (Press Y/N)" };
        if (gameStatus == GameStatus::player1Win) {
            winText = "Player 1 wins!";
        } else {
            winText = "Player 2 wins!";
        }

        int winTextWidth = MeasureText(winText.c_str(), WIN_SIZE);
        DrawText(winText.c_str(), (constants::WIDTH/2) - (winTextWidth/2), 300,
                 WIN_SIZE, WHITE);
       
        int replayTextWidth = MeasureText(replayText.c_str(), WIN_SIZE);
        DrawText(replayText.c_str(), (constants::WIDTH/2) - (replayTextWidth/2),
                 350, WIN_SIZE, WHITE);
    }
}

