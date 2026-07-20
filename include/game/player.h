#pragma once

#include "engine/game_object.h"

class Player final : public GameObject
{
public:
    explicit Player(const String& Name);
    
    void Update() override;
private:
    float m_MovementSpeed;
    
    void Move() const;
};
