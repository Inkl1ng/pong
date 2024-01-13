#include "Game.hpp"

#include <array>
#include <iostream> // TODO: delete when done with testing
#include <SFML/Graphics.hpp>
#include "util/Asset_manager.hpp"
#include "util/Game_mode.hpp"
#include "util/Text.hpp"
#include "Paddle.hpp"

Pong::Game::Game(sf::RenderWindow& r_window)
    : mr_window      {r_window}
{
    init_assets();
    Pong::Text::move_score_text(mr_window, m_left_score_text, Pong::Paddle_side::left);
    Pong::Text::move_score_text(mr_window, m_right_score_text, Pong::Paddle_side::right);
    draw_game();
}

void Pong::Game::init_assets()
{
}

void Pong::Game::draw_game()
{
    sf::Sound sound{m_asset_manager.load_sound("bounce.wav")};
    while (Pong::Game_mode::get_mode() != Pong::Game_mode::main_menu
           && Pong::Game_mode::get_mode() != Pong::Game_mode::quit)
    {
        poll_events();
        user_input();

        if (m_ball.check_collisiion()) { sound.play(); }
        if (m_left_paddle.check_collisiion(m_ball)) { sound.play(); }
        if (m_right_paddle.check_collisiion(m_ball)) { sound.play(); }

        m_ball.update();
        m_left_paddle.update();
        m_right_paddle.update();

        if (update_score()) { sound.play(); }

        mr_window.clear();

        m_ball.draw();
        m_left_paddle.draw();
        m_right_paddle.draw();
        mr_window.draw(m_left_score_text);
        mr_window.draw(m_right_score_text);

        mr_window.display();
    }
}

void Pong::Game::poll_events()
{
    sf::Event event {};
    while (mr_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Pong::Game_mode::set_mode(Pong::Game_mode::quit);
        } 
    }
}

void Pong::Game::user_input()
{
    switch (Pong::Game_mode::get_mode())
    {
        case Pong::Game_mode::bot_vs_bot:
            m_left_bot.make_move();
            m_right_bot.make_move();
            break;
        case Pong::Game_mode::player_vs_player:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))   { m_right_paddle.move_up(); }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { m_right_paddle.move_down(); }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))    { m_left_paddle.move_up(); }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))    { m_left_paddle.move_down(); }
            break;
        case Pong::Game_mode::player_vs_bot:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { m_left_paddle.move_up(); }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { m_left_paddle.move_down(); }
            m_right_bot.make_move();
            break;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Pong::Game_mode::set_mode(Pong::Game_mode::main_menu);
    }
    
}

bool Pong::Game::update_score()
{
    // check if the ball is within the bounds of the game, if it is, then don't
    // do anything
    const bool is_in_bounds {m_ball.get_pos().x > m_ball.get_radius()
                             && m_ball.get_pos().x < mr_window.getSize().x - m_ball.get_radius()};
    if (is_in_bounds)
    {
        return false;
    }

    m_ball.freeze();
    m_ball.reset();

    if (m_ball.get_vel().x > 0) // left side scores on right side
    {
        ++m_left_score;
        m_left_score_text.setString(std::to_string(m_left_score));
        Pong::Text::move_score_text(mr_window, m_left_score_text, Pong::Paddle_side::left);
    }
    else if (m_ball.get_vel().x < 0) // right side scores on left side
    {
        ++m_right_score;
        m_right_score_text.setString(std::to_string(m_right_score));
        Pong::Text::move_score_text(mr_window, m_right_score_text, Pong::Paddle_side::right);
    }
    return true;
}
