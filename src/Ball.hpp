#pragma once

#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP

#include <random>
#include <SFML/Graphics.hpp>

namespace Pong
{
    class Ball
    {
    public:
        enum Bounce_dir 
        {
            bounce_rand,
            bounce_left,
            bounce_right,
        };

        Ball(sf::RenderWindow& r_window);

        void update();
        void draw();
        void reset();
        void set_rand_angle(Pong::Ball::Bounce_dir bounce_dir);
        void freeze();
        bool is_frozen();
        bool check_collisiion();

        sf::Vector2f& get_pos()      { return m_pos; }
        float         get_radius()   { return sc_radius; }
        sf::Vector2f& get_vel()      { return m_vel; }
        sf::Vector2f  get_next_pos() { return {m_pos.x + m_vel.x, m_pos.y + m_vel.y}; };

    private:
        sf::RenderWindow& mr_window;
        sf::CircleShape   m_body{};
        sf::Vector2f      m_pos{};
        sf::Vector2f      m_vel{};
        sf::Clock         m_clock{};
        sf::Time          m_initial_freeze_time{};

        static constexpr float sc_radius {6.0f};
    };
}

#endif