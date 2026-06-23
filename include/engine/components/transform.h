#pragma once

#include "raylib/raylib.h"

#include "engine/components/component.h"

#include "engine/types.h"

class TransformComponent : public Component
{
public:
    TransformComponent(const String& Name);

    Vector3 GetPosition() const
    {
        return m_Position;
    }
    
    Vector3 GetRotation() const
    {
        return m_Rotation;
    }
    
    Vector3 GetScale() const
    {
        return m_Scale;
    }
private:
    Vector3 m_Position;
    Vector3 m_Rotation;
    Vector3 m_Scale;
};
