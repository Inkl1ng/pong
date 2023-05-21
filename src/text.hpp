#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"
#include "raylib.h"
#include "types.hpp"
#include "constants.hpp"
#include <string_view>

namespace text {
    inline const int x_padding { 100 };
    inline const int y_padding { 100 };
    inline const int score_size { 100 }; 
    inline const int win_size { 30 };

    inline const char *title_text_left { "Po" };
    inline const char *title_text_right { "ng" };
    inline const int title_size { 120 };
    inline const int title_y { 100 };

    void drawScore(Paddle& player_1, Paddle& player_2);
    void drawWinText(GameStatus& game_status);
    void drawTitleText();
}

#endif
