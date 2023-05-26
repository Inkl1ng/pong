#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "types.hpp"

namespace settings {
    inline const char* header_text { "Settings" };
    inline const int header_y { 100 };    
    inline const int header_size { 125 };

    void settingsScreen(GameStatus &game_status);
}

#endif
