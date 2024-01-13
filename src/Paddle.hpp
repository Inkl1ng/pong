#pragma once

#ifndef PONG_PADDLE_HPP
#define PONG_PADDLE_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

namespace Pong
{
    enum class Paddle_side
    {
        left,
        right,
    };

    class Paddle
    {
    public:
        Paddle(sf::RenderWindow& r_window, Pong::Paddle_side side);

        void update();
        void draw();

        void move_up();
        void move_down();
        bool check_collisiion(Pong::Ball& ball);

        const sf::RectangleShape& get_body()       { return m_body; }
        const sf::Vector2f&       get_dimensions() { return mc_dimensions; }
        Pong::Paddle_side         get_side()       { return mc_side; }
        const sf::Vector2f&       get_pos()        { return m_pos; }

    private:
        sf::RenderWindow&       mr_window;
        const sf::Vector2f      mc_dimensions;
        const float             mc_move_speed;
        sf::RectangleShape      m_body{};
        sf::Vector2f            m_pos{};
        const Pong::Paddle_side mc_side {};
    };
}

#endif