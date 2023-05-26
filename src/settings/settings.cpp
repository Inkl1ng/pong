#include "settings.hpp"
#include "types.hpp"
#include "text.hpp"
#include "constants.hpp"
#include "raylib.h"
#include "rini.h"
#include <filesystem>
#include <fstream>

void settings::settingsScreen(GameStatus &game_status) {
    const int header_x = constants::width/2
            - MeasureText(header_text, header_size)/2;
    while (game_status == GameStatus::SETTINGS) {
        BeginDrawing();
            ClearBackground(BLACK);
                DrawText(header_text, header_x, header_y, header_size, WHITE);
                // if (checkIniFile()) {
                    // DrawFPS(0,0);
                // }

            if (IsKeyPressed(KEY_Q)) { game_status = GameStatus::MAIN_MENU; }
        EndDrawing();
    }
}
