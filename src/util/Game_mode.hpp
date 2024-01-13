#pragma once

#ifndef PONG_GAME_STATE_HPP
#define PONG_GAME_STATE_HPP

namespace Pong
{
    namespace Game_mode
    {
        enum Mode
        {
            main_menu,
            player_vs_player,
            player_vs_bot,
            bot_vs_bot,
            quit,
        };

        inline Pong::Game_mode::Mode ms_current_mode {Pong::Game_mode::main_menu};

        inline void set_mode(Pong::Game_mode::Mode new_mode)
        {
            ms_current_mode = new_mode;
        }

        inline Pong::Game_mode::Mode get_mode()
        {
            return ms_current_mode;
        }
        
    }
}

#endif