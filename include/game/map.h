#pragma once

#include "engine/game_object.h"

class Map : public GameObject
{
public:
    Map(const String& Name);

    void Update() override;
};
