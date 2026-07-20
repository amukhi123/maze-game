#pragma once

#include "engine/component/component.h"

#include "engine/types.h"

#include "engine/math/Vector.h"

class TransformComponent final : public Component
{
public:
    explicit TransformComponent(const String& Name);

    Vec3<float> GetPosition() const
    {
        return m_Position;
    }
    
    void SetPosition(const Vec3<float>& NewPosition)
    {
        m_Position = NewPosition;
    }
    
    Vec3<float> GetRotation() const
    {
        return m_Rotation;
    }
    
    Vec3<float> GetScale() const
    {
        return m_Scale;
    }
    
    String ToString() const;
private:
    Vec3<float> m_Position;
    Vec3<float> m_Rotation;
    Vec3<float> m_Scale;
};
