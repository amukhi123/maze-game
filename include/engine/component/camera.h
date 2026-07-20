#pragma once

#include "raylib/raylib.h"

#include "engine/component/component.h"

#include "engine/types.h"

enum class CameraType : uint8
{
    Perspective = 0,
    Orthographic = 1,
};

class CameraComponent final : public Component
{
public:
    CameraComponent(const String& Name, const Vector3 Position, const Vector3 Target, const Vector3 Up = Vector3 {0.0f, 1.0f, 0.0f}, const float FovY = 45.0f, const CameraType Type = CameraType::Perspective);

    void StartDraw() override;
    
    void EndDraw() override;
private:
    Camera m_Camera;
};
