#pragma once

#ifndef PONG_TEXT_HPP
#define PONG_TEXT_HPP

#include <SFML/Graphics.hpp>
#include "../Paddle.hpp"

namespace Pong
{
    namespace Text
    {
        void center_text(sf::RenderWindow& r_window, sf::Text& r_text, const float yPos);
        void move_link_text(sf::RenderWindow& r_window, sf::Text& r_text);
        void move_attribution_text(sf::RenderWindow& r_window, sf::Text& r_text);
        void move_score_text(sf::RenderWindow& r_window, sf::Text& r_text, Pong::Paddle_side side);
    }
}

#endif