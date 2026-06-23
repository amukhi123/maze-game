#pragma once

#include "engine/types.h"

class Window
{
public:
    void Init(const uint32 WindowWidth, const uint32 WindowHeight);

    void Destroy();

    bool ShouldWindowClose() const;
};
