#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"
#include "types.hpp"

namespace text {
    const int x_padding { 100 };
    const int y_padding { 100 };
    const int score_size { 100 }; 
    const int win_size { 30 };

    void DrawScore(Paddle& player_1, Paddle& player_2);
    void DrawWinText(GameStatus& game_status);
    GameStatus drawReplayButton(GameStatus& game_status);
}

#endif
