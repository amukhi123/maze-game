#pragma once

#include "engine/types.h"
#include "engine/base_object.h"

#include "engine/components/component.h"

class GameObject : public BaseObject
{
public:
    GameObject(const String Name);
    
    // No-op
    virtual void Start()
    {
    }
    
    // No-op
    virtual void Update()
    {
    }
    
    // No-op
    virtual void End()
    {
    }
    
    void AddComponent(UniquePtr<Component>&& ComponentToAdd);
    
    Component* GetComponent(const ComponentType Type);
private:
    Vector<UniquePtr<Component>> m_Components;
};
