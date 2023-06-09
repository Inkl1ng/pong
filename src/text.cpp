#include "text.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "raylib.h"
#include "types.hpp"
#include <string>

void text::drawTextCentered(const char* text, int font_size, int y_pos, Color color) {
    int text_width { MeasureText(text, font_size) };

    DrawText(text, constants::width/2 - text_width/2, y_pos, font_size, color);
}

void text::drawScore(Paddle& player_1, Paddle& player_2) {
    DrawText(TextFormat("%i", player_1.getScore()),
            score_x_padding, score_y_padding,
            score_size, BLUE);

    // measure thickness of text to apply the correct offset to make
    // the two displayed texts symmetrical
    int player_2_text_width = MeasureText(TextFormat("%i", player_2.getScore()),
            score_size);
    DrawText(TextFormat("%i", player_2.getScore()),
            constants::width - player_2_text_width - score_x_padding, 
            score_y_padding,
            score_size, RED);
}

void text::drawWinText(GameStatus& game_status) {
    // check which player won and use the right text
    const char* win_text {};
    (game_status == GameStatus::PLAYER_1_WIN) ? win_text = "Player 1 wins!"
            : win_text = "Player 2 wins!";

    // draw text for which player won
    int win_text_width = MeasureText(win_text, win_size);
    DrawText(win_text, (constants::width/2) - (win_text_width/2), 300,
             win_size, WHITE);
   
    // draw text for replay promt
    int replay_text_width = MeasureText(replay_text, win_size);
    DrawText(replay_text, (constants::width/2) - (replay_text_width/2),
             350, win_size, WHITE);
}

void text::drawTitleScreen() {
    // measure right side of pong text length
    const int right_width { MeasureText(title_text_right, title_size/2) };
    // draw left side of pong text
    const int title_left_x { constants::width/2
            - MeasureText(title_text_left, title_size)/2 - right_width };
    DrawText(title_text_left, title_left_x, title_y, title_size, BLUE);

    // measure and draw right side of pong text
    // subtract 18 to maintain correct spacing between letters, random
    // were guessed and checked until the pixel spacing was correct
    // it might not be pixel perfect but it is close enough
    const int title_right_x { constants::width/2
            - MeasureText(title_text_right, title_size)/2 + right_width + 38 };
    DrawText(title_text_right, title_right_x, title_y, title_size, RED);

    // draw play button
    const int play_x { constants::width/2
            - MeasureText(play_text, options_size)/2 };
    DrawText(play_text, play_x, play_y, options_size, WHITE);

    // draw settings button
    const int settings_x { constants::width/2
            - MeasureText(settings_text, options_size)/2 };
    DrawText(settings_text, settings_x, settings_y, options_size, WHITE);

    const int quit_x { constants::width/2
            - MeasureText(quit_text, options_size)/2 };
    DrawText(quit_text, quit_x, quit_y, options_size, WHITE);
}