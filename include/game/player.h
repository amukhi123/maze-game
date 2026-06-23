#pragma once

#include "engine/game_object.h"

class Player final : public GameObject
{
public:
    Player(const String& Name);
    
    void Update() override;
};
