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
    // measure right side of pong text length
    const int right_width { MeasureText(title_text_right, title_size/2) };
    // draw left side of pong text
    const int title_left_x { constants::width/2
        - MeasureText(title_text_left, title_size)/2 - right_width };
    DrawText(title_text_left, title_left_x, title_y, title_size, BLUE);

    // draw right side of pong text
    // subtract 18 to maintain correct spacing between letters, random
    // were guessed and checked until the pixel spacing was correct
    const int title_right_x { constants::width/2
        - MeasureText(title_text_right, title_size)/2 + right_width + 18 };
    DrawText(title_text_right, title_right_x, title_y, title_size, RED);
    // const int test { constants::width/2
    //     - MeasureText("Pong", title_size)/2};
    // DrawText("Pong", test, title_y, title_size, WHITE);
}
