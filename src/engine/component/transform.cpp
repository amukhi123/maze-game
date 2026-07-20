#include "engine/component/transform.h"

TransformComponent::TransformComponent(const String& Name) : Component(Name, ComponentType::Transform), m_Position {}, m_Rotation {}, m_Scale {}
{
}

String TransformComponent::ToString() const
{
    const String positionStr {"\nPosition: " + m_Position.ToString()};
    const String rotationStr {"\nRotation: " + m_Rotation.ToString()};
    const String scaleStr {"\nScale: " + m_Scale.ToString()};
    
    return positionStr + rotationStr + scaleStr;
}
