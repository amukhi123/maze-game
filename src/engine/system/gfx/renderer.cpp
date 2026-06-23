#include "raylib/raylib.h"

#include "engine/system/gfx/renderer.h"

void Renderer::Start(const uint32 WindowWidth, const uint32 WindowHeight)
{
    m_Window.Init(WindowWidth, WindowHeight);
}

void Renderer::BeginDraw() const
{
    BeginDrawing();
}

void Renderer::EndDraw() const
{
    EndDrawing();
}

bool Renderer::ShouldWindowClose() const
{
    return m_Window.ShouldWindowClose();
}

void Renderer::Destroy()
{
    m_Window.Destroy();
}
