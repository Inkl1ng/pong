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

    inline const char *title_text { "Pong!" }; 
    inline const int title_size { 40 };

    void drawScore(Paddle& player_1, Paddle& player_2);
    void drawWinText(GameStatus& game_status);
    void drawTitleText();
}

#endif
