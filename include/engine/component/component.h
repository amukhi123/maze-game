#pragma once

#include "engine/types.h"
#include "engine/base_object.h"

enum class ComponentType : uint8
{
    None = 0,
    Transform,
    Camera,
};

class Component : public BaseObject
{
public:
    static String TypeToStr(const ComponentType ComponentType);
    
    Component(const String& Name, const ComponentType Type);
    
    virtual ~Component() = default;
    
    ComponentType GetType() const
    {
        return m_Type;
    }

    // No-op
    virtual void Start()
    {
    }
    
    // No-op
    virtual void StartDraw()
    {
    }
    
    // No-op
    virtual void Update()
    {
    }
    // 
    // No-op
    virtual void EndDraw()
    {
    }
    
    // No-op
    virtual void Destroy()
    {
    }
private:
    ComponentType m_Type;
};
