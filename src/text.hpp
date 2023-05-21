#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"
#include "raylib.h"
#include "types.hpp"
#include "constants.hpp"
#include <string_view>

namespace text {
    // x distance from score number to boarder
    inline const int score_x_padding { 100 };
    // y distance from score number to boarder
    inline const int score_y_padding { 100 };

    inline const int score_size { 100 }; 
    inline const int win_size { 30 };
    inline const int title_size { 120 };
    inline const int title_y { 100 };

    inline const char *replay_text { "Play again? (Y/N)" };
    inline const char *title_text_left { "Po" };
    inline const char *title_text_right { "ng" };

    void drawScore(Paddle& player_1, Paddle& player_2);
    void drawWinText(GameStatus& game_status);
    void drawTitleText();
}

#endif
