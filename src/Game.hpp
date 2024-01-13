#pragma once

#ifndef PONG_GAME_HPP
#define PONG_GAME_HPP

#include <SFML/Graphics.hpp>
#include "bot/Bot.hpp"
#include "util/Asset_manager.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

namespace Pong
{
    class Game
    {
    public:
        Game(sf::RenderWindow& r_window);

    private:
        sf::RenderWindow&   mr_window;
        Pong::Asset_manager m_asset_manager{};
        Pong::Paddle        m_left_paddle{mr_window, Pong::Paddle_side::left};
        Pong::Paddle        m_right_paddle{mr_window, Pong::Paddle_side::right};
        Pong::Ball          m_ball{mr_window};
        int                 m_left_score  {0};
        int                 m_right_score {0};
        sf::Text            m_left_score_text{std::to_string(m_left_score),
                                              m_asset_manager.load_font("VCR_OSD_MONO.ttf"),
                                              60};
        sf::Text            m_right_score_text{std::to_string(m_right_score),
                                               m_asset_manager.load_font("VCR_OSD_MONO.ttf"),
                                               60};
        Pong::Bot           m_left_bot{mr_window, m_left_paddle, m_ball};
        Pong::Bot           m_right_bot{mr_window, m_right_paddle, m_ball};
        

        void init_assets();
        void draw_game();
        void poll_events();
        void user_input();
        bool update_score();
    };
}

#endif