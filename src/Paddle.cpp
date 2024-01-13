#include "Paddle.hpp"

#include <iostream> // TODO: delete when done with testing
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

Pong::Paddle::Paddle(sf::RenderWindow& r_window, Pong::Paddle_side side)
    : mr_window     {r_window}
    , mc_dimensions {sf::Vector2f{10.0f, 80.0f}}
    , mc_move_speed {12.0f}
    , m_body        {sf::RectangleShape{mc_dimensions}}
    , m_pos         {sf::Vector2f{0.0f, 0.0f}}
    , mc_side       {side}
{
    m_body.setOrigin({mc_dimensions.x / 2.0f, mc_dimensions.y / 2.0f});

    // sets the paddles to be in the center with a certain offset from the edge
    // of the screen
    constexpr float c_offset {50.0f};
    m_pos.x = (mc_side == Pong::Paddle_side::left ? c_offset : mr_window.getSize().x - c_offset);
    m_pos.y = mr_window.getSize().y / 2.0f;
    m_body.setPosition(m_pos);
}

void Pong::Paddle::update()
{
    m_body.setPosition(m_pos);
}

void Pong::Paddle::draw()
{
    mr_window.draw(m_body);
}

void Pong::Paddle::move_up()
{
    if (m_pos.y - (mc_dimensions.y / 2.0f) > 0.0f)
    {
        m_pos.y -= mc_move_speed;
    }
}

void Pong::Paddle::move_down()
{
    if (m_pos.y + (mc_dimensions.y / 2.0f) < mr_window.getSize().y)
    {
        m_pos.y += mc_move_speed;
    }
}

bool Pong::Paddle::check_collisiion(Pong::Ball& ball)
{
    const float d_x     {std::abs(ball.get_next_pos().x - m_pos.x)};
    const float d_y     {std::abs(ball.get_next_pos().y - m_pos.y)};
    const bool within_x {d_x < (ball.get_radius() + mc_dimensions.x) / 2.0f};
    const bool within_y {d_y < (ball.get_radius() + mc_dimensions.y) / 2.0f};

    if (!(within_x && within_y)) { return false; }

    if (ball.get_vel().x > 0.0f) { ball.set_rand_angle(Pong::Ball::Bounce_dir::bounce_left); }
    else { ball.set_rand_angle(Pong::Ball::Bounce_dir::bounce_right); }
    return true;
}
