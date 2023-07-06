#include "settings.hpp"
#include "types.hpp"
#include "text.hpp"
#include "constants.hpp"
#include "raylib.h"
#include "ini.h"
#include <filesystem>

void settings::settingsScreen(GameStatus &game_status) {
    const int header_x = constants::width/2
            - MeasureText(header_text, header_size)/2;
    while (game_status == GameStatus::SETTINGS) {
        BeginDrawing();
            ClearBackground(BLACK);
                DrawText(header_text, header_x, header_y, header_size, WHITE);


            if (IsKeyPressed(KEY_Q)) { game_status = GameStatus::MAIN_MENU; }
        EndDrawing();
    }
}

void settings::saveColors(Color player_1_color, Color player_2_color) {
    mINI::INIFile colors_ini(settings::colors_path);
    mINI::INIStructure ini;

    ini["Colors"]["player_1_color_r"] = std::to_string(player_1_color.r);
    ini["Colors"]["player_1_color_g"] = std::to_string(player_1_color.g);
    ini["Colors"]["player_1_color_b"] = std::to_string(player_1_color.b);
    ini["Colors"]["player_2_color_r"] = std::to_string(player_2_color.r);
    ini["Colors"]["player_2_color_g"] = std::to_string(player_2_color.g);
    ini["Colors"]["player_2_color_b"] = std::to_string(player_2_color.b);

    colors_ini.write(ini);
}

Color settings::readColor(int playerNumber) {
    mINI::INIFile colors_ini(settings::colors_path);
    mINI::INIStructure ini;

    Color color {};

    if (playerNumber == 1) {
        color.r = std::stoi(ini["Colors"]["player_1_color_r"]);
        color.g = std::stoi(ini["Colors"]["player_1_color_g"]);
        color.b = std::stoi(ini["Colors"]["player_1_color_b"]);
    } else if (playerNumber == 2) {
        color.r = std::stoi(ini["Colors"]["player_2_color_r"]);
        color.g = std::stoi(ini["Colors"]["player_2_color_g"]);
        color.b = std::stoi(ini["Colors"]["player_2_color_b"]);
    }
    
    return color;
}