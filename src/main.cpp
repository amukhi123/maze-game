#include "raylib/raylib.h"

int main()
{
    constexpr int kWidth {500};
    constexpr int kHeight {500};
    
    InitWindow(kWidth, kHeight, "MazeGame");

    constexpr int kTargetFps {60};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        constexpr int kFont {40};
        
        DrawText("Hello window!", 0, 0, kFont, LIGHTGRAY);
        
        EndDrawing();
    }

    CloseWindow();
}
