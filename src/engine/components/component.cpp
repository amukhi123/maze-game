#include "engine/components/component.h"

String Component::TypeToStr(const ComponentType Type)
{
    switch (Type)
    {
        case ComponentType::Transform:
            return "Transform";
        case ComponentType::None:
        default:
            return "No Component";
    }
}

Component::Component(const String& Name, const ComponentType Type) : BaseObject {Name}, m_Type {Type}
{
}
