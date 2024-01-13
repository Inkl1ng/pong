#include "Text.hpp"

#include <SFML/Graphics.hpp>
#include "../Paddle.hpp"

// Sets the origin of the text to be in the center of the text
static void set_origin_center(sf::Text& r_text)
{
    r_text.setOrigin(r_text.getLocalBounds().left + r_text.getLocalBounds().width / 2.0f,
                     r_text.getLocalBounds().top + r_text.getLocalBounds().height / 2.0f);
}

void Pong::Text::center_text(sf::RenderWindow& r_window, sf::Text& r_text, const float yPos)
{
    const float windowHalfway {r_window.getSize().x / 2.0f};
    // set the origin of the text to the center of the text
    set_origin_center(r_text);
    r_text.setPosition({windowHalfway, yPos});
}

void Pong::Text::move_link_text(sf::RenderWindow &r_window, sf::Text& r_text)
{
    // set the origin of the text to the bottom right corner
    // will make aligning the text to the bottom right corner easier
    r_text.setOrigin(r_text.getLocalBounds().left + r_text.getLocalBounds().width,
                     r_text.getLocalBounds().top + r_text.getLocalBounds().height);
    r_text.setPosition(r_window.getSize().x - 4.0f, r_window.getSize().y - 3.0f);
}

void Pong::Text::move_attribution_text(sf::RenderWindow &r_window, sf::Text& r_text)
{
    // set the origin of the text to the bottom left corner for easier alignment
    r_text.setOrigin(r_text.getLocalBounds().left,
                     r_text.getLocalBounds().top + r_text.getLocalBounds().height);
    r_text.setPosition(4.0f, r_window.getSize().y - 3.0f);
}

void Pong::Text::move_score_text(sf::RenderWindow &r_window, sf::Text &r_text, Pong::Paddle_side side)
{
    set_origin_center(r_text);

    constexpr float c_score_y_pos {100.0f};
    if (side == Pong::Paddle_side::left)
    {
        r_text.setPosition(r_window.getSize().x / 4.0f, c_score_y_pos);
    }
    else if (side == Pong::Paddle_side::right)
    {
        r_text.setPosition(r_window.getSize().x * 3 / 4.0f, c_score_y_pos);
    }
}
