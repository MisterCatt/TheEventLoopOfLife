#include "raylib.h"

int main(void)
{    
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE | ConfigFlags::FLAG_VSYNC_HINT | ConfigFlags::FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "The Event Loop of Life");

    // SetTargetFPS(60); // Uncomment this if you want to use fixed framerate (I suggest using vsync)

    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}