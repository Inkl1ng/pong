#include "text.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "raylib.h"
#include "types.hpp"
#include <string>

void text::drawScore(Paddle& player_1, Paddle& player_2) {
    DrawText(TextFormat("%i", player_1.getScore()),
         x_padding, y_padding,
             score_size, BLUE);
    int player_2_text_width = MeasureText(TextFormat("%i", player_2.getScore()),
            score_size);
    DrawText(TextFormat("%i", player_2.getScore()),
             constants::width - player_2_text_width - x_padding, 
             y_padding,
             score_size, RED);
}

void text::drawWinText(GameStatus& game_status) {
    std::string win_text {};
    std::string replay_text { "Play again? (Press Y/N)" };
    if (game_status == GameStatus::PLAYER_1_WIN) {
        win_text = "Player 1 wins!";
    } else {
        win_text = "Player 2 wins!";
    }

    int win_text_width = MeasureText(win_text.c_str(), win_size);
    DrawText(win_text.c_str(), (constants::width/2) - (win_text_width/2), 300,
             win_size, WHITE);
   
    int replay_text_width = MeasureText(replay_text.c_str(), win_size);
    DrawText(replay_text.c_str(), (constants::width/2) - (replay_text_width/2),
             350, win_size, WHITE);
}

void text::drawTitleText() {
    const int title_x {
        constants::width/2 - MeasureText(title_text, title_size)/2 };
    DrawText(title_text, title_x, 400, title_size, WHITE);
}
