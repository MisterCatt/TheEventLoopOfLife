#include "raylib.h"
#include "level.h"
#include "Game.h"

// IMPORTANT:
// Feel free to not use the Level, and redo everything on your own. This is just some boilerplate code to get you started.

// If you want, I suggest manually copying my code from scratch. That should help with understanding how it works a bit better.

int main(void)
{    
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE | ConfigFlags::FLAG_VSYNC_HINT | ConfigFlags::FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "The Event Loop of Life");

    // SetTargetFPS(60); // Uncomment this if you want to use fixed framerate (I suggest using vsync)
    // SetExitKey(0);    // Uncomment this to disable ESC as exit key

    Game game;

    while (!WindowShouldClose())
    {
       

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}