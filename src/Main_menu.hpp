#pragma once

#ifndef PONG_MAIN_MENU_HPP
#define PONG_MAIN_MENU_HPP

#include <map>
#include <string_view>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "util/Asset_manager.hpp"

namespace Pong
{
    class Main_menu
    {
    public:
        Main_menu(sf::RenderWindow& r_window);
        ~Main_menu();

    private:
        sf::RenderWindow&   mr_window;
        Pong::Asset_manager m_asset_manager{}; 
        // holds the sf::Text objects to improve performance so they don't have to be
        // constructed each frame
        std::map<std::string_view, sf::Text> m_text_map{};

        void init_assets();
        void draw_main_menu();
        void poll_events();
        void user_input();
        void draw_text();
    };
}

#endif