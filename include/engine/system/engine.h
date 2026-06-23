#pragma once

#include "engine/scene.h"

#include "engine/system/gfx/renderer.h"

class Engine final
{
public:
    void Start();

    void Run();
    
    void Shutdown();

    void LoadScene(UniquePtr<Scene>&& SceneToLoad);
private:
    UniquePtr<Scene> m_ActiveScene;

    Renderer m_Renderer;
};
