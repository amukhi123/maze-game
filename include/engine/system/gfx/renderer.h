#pragma once

#include "engine/types.h"

#include "engine/system/gfx/window.h"

class Renderer
{
public:
    void Start(const uint32 WindowWidth, const uint32 WindowHeight);

    void BeginDraw() const;
    
    void EndDraw() const;

    bool ShouldWindowClose() const;

    void Destroy();
private:
    Window m_Window;
};
