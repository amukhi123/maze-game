#pragma once

#include "engine/types.h"
#include "engine/base_object.h"

enum class ComponentType : uint8
{
    None = 0,
    Transform,
};

class Component : public BaseObject
{
public:
    static String TypeToStr(const ComponentType ComponentType);
    
    Component(const String& Name, const ComponentType Type);
    
    ComponentType GetType() const
    {
        return m_Type;
    }
private:
    ComponentType m_Type;
};
