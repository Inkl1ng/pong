#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"
#include "raylib.h"
#include "types.hpp"
#include "constants.hpp"
#include <string_view>

namespace title_screen {
    // x distance from score number to boarder
    inline const int score_x_padding { 100 };
    // y distance from score number to boarder
    inline const int score_y_padding { 100 };

    inline const int score_size { 100 }; 
    inline const int win_size { 30 };

    inline const int title_size { 250 };
    inline const int title_y { 30 };
    inline const char *title_text_left { "Po" };
    inline const char *title_text_right { "ng" };

    // font size for all title screen options
    inline const int options_size { 60 };

    inline const int play_y { 300 };
    inline const char *play_text { "Play [SPC]" };

    inline const int settings_y { 380 };
    inline const char *settings_text { "Settings [o]" };

    inline const int quit_y { 460 };
    inline const char *quit_text { "Quit [q]" };

    inline const char *replay_text { "Play again? (Y/N)" };

    void drawScore(Paddle& player_1, Paddle& player_2);
    void drawWinText(GameStatus& game_status);
    void drawTitleScreen();
    void drawSettingsScreen();
}

#endif
