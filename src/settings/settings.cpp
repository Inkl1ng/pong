#include "settings.hpp"
#include "types.hpp"
#include "raylib.h"

void settings::settingsScreen(GameStatus &game_status) {
    while (game_status == GameStatus::SETTINGS) {
        BeginDrawing();
            ClearBackground(BLACK);

            DrawFPS(0, 0);
        
            if (IsKeyPressed(KEY_Q)) { game_status = GameStatus::MAIN_MENU; }
        EndDrawing();
    }
}
