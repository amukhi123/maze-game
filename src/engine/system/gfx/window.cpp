#include "raylib/raylib.h"

#include "engine/system/gfx/window.h"

void Window::Init(const uint32 WindowWidth, const uint32 WindowHeight)
{
    InitWindow(WindowWidth, WindowHeight, "MazeGame");
}

void Window::Destroy()
{
    CloseWindow();
}

bool Window::ShouldWindowClose() const
{
    return WindowShouldClose();
}
