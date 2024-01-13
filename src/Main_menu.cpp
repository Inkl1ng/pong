#include "Main_menu.hpp"

#include <map>
#include <memory>
#include <string_view>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "util/Asset_manager.hpp"
#include "util/Game_mode.hpp"
#include "util/Text.hpp"

// pong::main_menu::main_menu(sf::RenderWindow& window) : mr_window(window)
// {
//     init_text();
//     draw_main_menu();
// }
Pong::Main_menu::Main_menu(sf::RenderWindow& r_window)
    : mr_window {r_window}
{
    // clear prevoiusly loaded assets
    init_assets();
    draw_main_menu();
}

Pong::Main_menu::~Main_menu()
{
    
}

void Pong::Main_menu::init_assets()
{
    // create all the sf::Text objects at once to avoid creating the text
    // objects each frame
    sf::Font& font {m_asset_manager.load_font("VCR_OSD_MONO.ttf")};
    m_text_map["title"]  = sf::Text {"Pong!", font, 150};
    m_text_map["play1"]  = sf::Text {"[1] Human vs. Human", font, 30};
    m_text_map["play2"]  = sf::Text {"[2] Human vs. Computer", font, 30};
    m_text_map["play3"]  = sf::Text {"[3] Computer vs. Computer", font, 30};
    m_text_map["quit"]   = sf::Text {"[Q] Quit", font, 30};
    m_text_map["link"]   = sf::Text {"                V 1.0.0\ngithub.com/Inkl1ng/pong", font, 15};
    m_text_map["author"] = sf::Text {"Made by Inkl1ng with SFML", font, 15};

    Pong::Text::center_text(mr_window, m_text_map["title"],  150.0f);
    Pong::Text::center_text(mr_window, m_text_map["play1"],  250.0f);
    Pong::Text::center_text(mr_window, m_text_map["play2"],  300.0f);
    Pong::Text::center_text(mr_window, m_text_map["play3"],  350.0f);
    Pong::Text::center_text(mr_window, m_text_map["quit"],   400.0f);
    Pong::Text::move_link_text(mr_window, m_text_map["link"]);
    Pong::Text::move_attribution_text(mr_window, m_text_map["author"]);
}

void Pong::Main_menu::draw_main_menu()
{
    while (Pong::Game_mode::get_mode() == Pong::Game_mode::main_menu)
    {
        poll_events();
        user_input();

        mr_window.clear();

        draw_text();

        mr_window.display();
    }
}

void Pong::Main_menu::poll_events()
{
    sf::Event event {};
    while (mr_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mr_window.close();
        } 
    }
}

void Pong::Main_menu::user_input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // player vs player
    {
        Pong::Game_mode::set_mode(Pong::Game_mode::player_vs_player);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) // player vs computer
    {
        Pong::Game_mode::set_mode(Pong::Game_mode::player_vs_bot); 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) // computer vs computer
    {
        Pong::Game_mode::set_mode(Pong::Game_mode::bot_vs_bot);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Pong::Game_mode::set_mode(Pong::Game_mode::quit);
    }
}

void Pong::Main_menu::draw_text()
{
    for (auto element : m_text_map)
    {
        mr_window.draw(element.second);
    }
}