#include "raylib/raylib.h"

#include "engine/util/logger.h"

#include "game/player.h"

#include "engine/component/transform.h"

namespace
{
    constexpr float kMovementSpeed {10.f};
}

Player::Player(const String& Name) : GameObject {Name}, m_MovementSpeed {kMovementSpeed}
{
}

void Player::Update()
{
    GameObject::Update();
    
    Move();
}

void Player::Move() const
{
    const float adjustedMovementSpeed {GetFrameTime() * m_MovementSpeed};
    
    Vec3<float> movementVector {}; 
    
    if (IsKeyDown(KEY_W))
    {
        movementVector = {0.0f, 0.0f, -adjustedMovementSpeed};
    }
    
    if (IsKeyDown(KEY_A))
    {
        movementVector = {-adjustedMovementSpeed, 0.0f, 0.0f};
    }
    
    if (IsKeyDown(KEY_S))
    {
        movementVector = {0.0f, 0.0f, adjustedMovementSpeed};
    }
    
    if (IsKeyDown(KEY_D))
    {
        movementVector = {adjustedMovementSpeed, 0.0f, 0.0f};
    }
    
    m_TransformComponent->SetPosition(m_TransformComponent->GetPosition() + movementVector);
    
    DrawCube(static_cast<Vector3>(m_TransformComponent->GetPosition()), 10, 10, 10, RED);
}
