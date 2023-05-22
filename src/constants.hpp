#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constants {
    inline constexpr int width { 1000 }; // screen width
    inline constexpr int height { 800 }; // screen height
    inline constexpr int points_to_win { 1 }; // points needed to win

    /// x-position of player 1's paddle
    const int player_1_x_pos { 25 };
    /// x-position of player 2's paddle
    const int player_2_x_pos { width - 25 };
};

#endif
