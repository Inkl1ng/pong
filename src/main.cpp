#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "util/Game_mode.hpp"
#include "Main_menu.hpp"
#include "Game.hpp"
#include "Paddle.hpp"

int main()
{
    sf::VideoMode video_mode{800, 600};
    sf::RenderWindow window{video_mode, "pong", sf::Style::Close | sf::Style::Titlebar};
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Pong::Game_mode::Mode current_mode {Pong::Game_mode::get_mode()};
        
        switch (current_mode)
        {
            case Pong::Game_mode::main_menu:
            {
                Pong::Main_menu{window};
                break;
            }
            case Pong::Game_mode::player_vs_player:
                [[fallthrough]];
            case Pong::Game_mode::player_vs_bot:
                [[fallthrough]];
            case Pong::Game_mode::bot_vs_bot:
            {
                Pong::Game{window};
                break;
            }
            case Pong::Game_mode::quit:
                window.close();
        }
    }
    
    return 0;
}
