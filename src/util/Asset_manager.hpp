#pragma once

#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace Pong
{
    class Asset_manager
    {
    public:
        sf::Font&        load_font(std::string file_name);
        sf::SoundBuffer& load_sound(std::string file_name);


    private:
        std::map<std::string_view, sf::Font>        m_font_map{};
        std::map<std::string_view, sf::SoundBuffer> m_sound_map{};
    };
}

#endif