#include "Ball.hpp"

#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>
#include "util/Asset_manager.hpp"
#include "util/Random.hpp"

Pong::Ball::Ball(sf::RenderWindow& r_window)
    : mr_window {r_window}
    , m_body    {sf::CircleShape{sc_radius}}
{
    // use as initilizaiton
    reset();

    m_body.setOrigin({sc_radius / 2.0f, sc_radius / 2.0f});
    m_body.setPosition(m_pos);
}

void Pong::Ball::update()
{
    
    /* alternative collision approach
    if (pos.x - radius < 0.0f || pos.x + radius > window->getSize().x)
    {
        vel.x *= -1;
    }
    if (pos.y - radius < 0.0f || pos.y + radius > window->getSize().y)
    {
        vel.y *= -1;
    }
    */

    if (is_frozen())
    {
        m_pos.x += m_vel.x;
        m_pos.y += m_vel.y;
        m_body.setPosition(m_pos);
    }
    
}

void Pong::Ball::draw()
{
    mr_window.draw(m_body);
}

void Pong::Ball::reset()
{
    m_pos.x = mr_window.getSize().x / 2.0f;
    m_pos.y = Pong::Random::get_rand_int(
        static_cast<int>(sc_radius),
        static_cast<int>(mr_window.getSize().y - sc_radius)
    );

    set_rand_angle(Pong::Ball::bounce_rand);
}

void Pong::Ball::set_rand_angle(Pong::Ball::Bounce_dir bounce_dir)
{
    typedef float Radians;
    constexpr float c_vel {5.0f};

    Radians new_angle {Pong::Random::get_rand<float>(M_PI / -3.0f, M_PI / 3.0f)};
    float new_x_vel {m_vel.x = c_vel * std::cos(new_angle)};
    switch (bounce_dir)
    {
        case Pong::Ball::bounce_rand:
            (Pong::Random::get_rand_int(1, 2) % 2 == 1) ? new_x_vel *= -1 : new_x_vel *= 1;
            break;
        case Pong::Ball::bounce_left:
            (new_x_vel > 0) ? new_x_vel *= -1 : new_x_vel *= 1;
            break;
        case Pong::Ball::bounce_right:
            (new_x_vel < 0) ? new_x_vel *= -1 : new_x_vel *= 1;
            break;
    }

    m_vel.x = new_x_vel;
    m_vel.y = c_vel * std::sin(new_angle);
}

void Pong::Ball::freeze()
{
    m_clock.restart();
}

bool Pong::Ball::is_frozen()
{
    // check if the ball is frozen
    const sf::Time freeze_time {sf::seconds(1.5f)};
    return m_clock.getElapsedTime() > freeze_time;
}

bool Pong::Ball::check_collisiion()
{
    // collision
    const float next_y {m_pos.y + m_vel.y};
    if (next_y - sc_radius < 0.0f || next_y + sc_radius > mr_window.getSize().y)
    {
        m_vel.y *= -1;
        return true;
        // the sound file will have already been loaded
    }
    return false;
}