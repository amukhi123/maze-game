#include "engine/game_object.h"

#include "engine/types.h"
#include "engine/util/logger.h"

#include "engine/component/transform.h"

GameObject::GameObject(const String& Name) : BaseObject {Name}, m_TransformComponent {std::make_unique<TransformComponent>("Transform")}
{
}

void GameObject::AddComponent(UniquePtr<Component>&& ComponentToAdd)
{
    if (GetComponent(ComponentToAdd->GetType()))
    {
        LOG_E("Cannot have more than one component of the same type.");
        return;
    }

    const auto componentName {ComponentToAdd->GetName()};
    
    m_Components.emplace_back(std::move(ComponentToAdd));
    
    LOG_D("Added " + componentName + " to " + GetName() + ".")
}

Component* GameObject::GetComponent(const ComponentType Type) const
{
    if (Type == ComponentType::Transform)
    {
        return m_TransformComponent.get();
    }
    
    for (const UniquePtr<Component>& component : m_Components)
    {
        if (component->GetType() == Type)
        {
            return component.get();
        }
    }

    LOG_D("Component of type " + Component::TypeToStr(Type) + " not found.")
    
    return nullptr;
}
