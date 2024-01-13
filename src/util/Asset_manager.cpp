#include "Asset_manager.hpp"

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

sf::Font& Pong::Asset_manager::load_font(std::string file_name)
{
    for (const auto element : m_font_map)
    {
        if (element.first == "data/fonts/" + file_name)
        {
            return m_font_map[element.first];
        }
    }

    sf::Font font;
    if (!font.loadFromFile("data/fonts/" + file_name))
    {
        // TODO: error handling
    }
    m_font_map[file_name] = font;
    return m_font_map[file_name];
}

sf::SoundBuffer& Pong::Asset_manager::load_sound(std::string file_name)
{
    for (const auto element : m_sound_map)
    {
        if (element.first == "data/sounds/" + file_name)
        {
            return m_sound_map[element.first];
        }
    }

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("data/sounds/" + file_name))
    {
        // TODO: error handling
    }
    m_sound_map[file_name] = buffer;
    return m_sound_map[file_name];
}
