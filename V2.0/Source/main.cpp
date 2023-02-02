#include "raylib.h"
#include "EventLoopOfLife.h"

int main(void)
{    
    EventLoopOfLife elol;

    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE | ConfigFlags::FLAG_VSYNC_HINT | ConfigFlags::FLAG_MSAA_4X_HINT);
    InitWindow(elol.GetWindowWidth(), elol.GetWindowHeight(), "The Event Loop of Life");

    SetTargetFPS(60);
    // SetExitKey(0);    // Uncomment this to disable ESC as exit key

    while (!WindowShouldClose())
    {

        BeginDrawing();

        elol.Run();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}