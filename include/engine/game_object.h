#pragma once

#include "engine/types.h"
#include "engine/base_object.h"

#include "engine/component/component.h"
#include "engine/component/transform.h"

class Scene;

class GameObject : public BaseObject
{
public:
    explicit GameObject(const String& Name);

    virtual ~GameObject() = default;
    
    // No-op
    virtual void Start()
    {
    }
    
    // No-op
    virtual void Update()
    {
    }
    
    // No-op
    virtual void Destroy()
    {
    }
    
    void AddComponent(UniquePtr<Component>&& ComponentToAdd);
    
    Component* GetComponent(const ComponentType Type) const;
    
    Vector<UniquePtr<Component>>& GetComponents()
    {
        return m_Components;
    }

    Scene* GetScene() const
    {
        return m_Scene;
    }
protected:
    UniquePtr<TransformComponent> m_TransformComponent;
private:
    Vector<UniquePtr<Component>> m_Components;
    
    Scene* m_Scene;
};
