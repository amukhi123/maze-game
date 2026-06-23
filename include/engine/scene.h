#pragma once

#include "engine/types.h"
#include "engine/game_object.h"

class Scene
{
public:
    Scene(const String& Name) : m_Name {Name}
    {
    }

    Scene(const Scene& Scene) = delete;
    Scene operator=(const Scene& Scene) = delete;

    String GetName() const
    {
        return m_Name;
    };

    void AddGameObject(UniquePtr<GameObject>& GameObjectToAdd)
    {
        m_GameObjects.emplace_back(std::move(GameObjectToAdd));
    }

    Vector<UniquePtr<GameObject>>& GetGameObjects()
    {
        return m_GameObjects;
    }
private:
    String m_Name;

    Vector<UniquePtr<GameObject>> m_GameObjects;
};
