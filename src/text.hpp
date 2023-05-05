#ifndef TEXT_HPP
#define TEXT_HPP

#include "paddle.hpp"

namespace text {
    const int TEXT_X_PADDING { 100 };
    const int TEXT_Y_PADDING { 100 };
    const int TEXT_SIZE { 100 }; 

    void drawScore(Paddle& player1, Paddle& player2);
}

#endif
