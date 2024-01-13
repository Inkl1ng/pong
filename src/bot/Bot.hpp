#pragma once

#ifndef PONG_BOT_HPP
#define PONG_BOT_HPP

#include <SFML/Graphics.hpp>
#include "../Ball.hpp"
#include "../Paddle.hpp"

namespace Pong
{
    class Bot
    {
    public:
        Bot(sf::RenderWindow& window, Pong::Paddle& paddle, Pong::Ball& ball);
        void make_move();

    private:
        enum Ball_state
        {
            approaching,
            retreating
        };

        sf::RenderWindow&     r_window;
        Pong::Paddle&         r_paddle;
        Pong::Ball&           r_ball;
        Pong::Bot::Ball_state ball_state;
        bool                  made_move{false};
        float                 move_y_pos{};
    };
}

#endif
