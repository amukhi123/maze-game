#include "engine/component/camera.h"

CameraComponent::CameraComponent(const String& Name, const Vector3 Position, const Vector3 Target, const Vector3 Up, const float FovY, const CameraType Type) : Component {Name, ComponentType::Camera}, m_Camera {}
{
    m_Camera.position = Position;
    m_Camera.target = Target;
    m_Camera.up = Up;
    m_Camera.fovy = FovY;
    m_Camera.projection = static_cast<int>(Type);
}

void CameraComponent::StartDraw()
{
    BeginMode3D(m_Camera);
}

void CameraComponent::EndDraw()
{
    EndMode3D();
}
