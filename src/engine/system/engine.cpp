#include "engine/system/engine.h"
#include "engine/types.h"

#include "engine/util/logger.h"

void Engine::Start()
{
    constexpr int kWidth {1000};
    constexpr int kHeight {1000};
    
    m_Renderer.Start(kWidth, kHeight);

    Run();
}

void Engine::Run()
{
    if (!m_ActiveScene)
    {
        LOG_E("Skipping Engine::Run as there is no active scene.")
        return;
    }
    
    while (!m_Renderer.ShouldWindowClose())
    {
        m_Renderer.BeginDraw();
 
        for (const UniquePtr<GameObject>& gameObject : m_ActiveScene->GetGameObjects())
        {
            for (const UniquePtr<Component>& component : gameObject->GetComponents())
            {
                component->StartDraw();
            }
        }
        
        for (const UniquePtr<GameObject>& gameObject : m_ActiveScene->GetGameObjects())
        {
            gameObject->Update();
        }
        
        for (const UniquePtr<GameObject>& gameObject : m_ActiveScene->GetGameObjects())
        {
            for (const UniquePtr<Component>& component : gameObject->GetComponents())
            {
                component->EndDraw();
            }
        }
        
        m_Renderer.EndDraw();
    }

    Shutdown();
}

void Engine::Shutdown()
{
    m_Renderer.Destroy();
}

void Engine::LoadScene(UniquePtr<Scene> SceneToLoad)
{
    m_ActiveScene = std::move(SceneToLoad);
}
