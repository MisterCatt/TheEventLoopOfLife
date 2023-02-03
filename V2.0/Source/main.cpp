#include "raylib.h"
#include "EventLoopOfLife.h"

int main(void)
{    
    

    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE | ConfigFlags::FLAG_VSYNC_HINT | ConfigFlags::FLAG_MSAA_4X_HINT);
    InitWindow(800, 800, "The Event Loop of Life");

    EventLoopOfLife elol;

    //SetTargetFPS(60);
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