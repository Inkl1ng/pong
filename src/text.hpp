#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"
#include "types.hpp"

namespace text {
    const int TEXT_X_PADDING { 100 };
    const int TEXT_Y_PADDING { 100 };
    const int SCORE_SIZE { 100 }; 
    const int WIN_SIZE { 30 };

    void DrawScore(Paddle& player1, Paddle& player2);
    void DrawWinText(GameStatus& gameStatus);
    GameStatus drawReplayButton(GameStatus& gameStatus);
}

#endif
