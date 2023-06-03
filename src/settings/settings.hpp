#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "types.hpp"
#include "raylib.h"
#include <string>
#include <cstring>

namespace settings {
    // casts the path of this file into a cpp-style string and then 
    // gets a substring of just the path
    inline const std::string colors_path { static_cast<std::string>(__FILE__)
                .substr(0, std::strlen(__FILE__) - 13) + "/colors.ini"};

    inline const char* header_text { "Settings" };
    inline const int header_y { 100 };    
    inline const int header_size { 125 };

    void settingsScreen(GameStatus &game_status);
    void saveColors(Color player_1_color, Color player_2_color);
}

#endif
