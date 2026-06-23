#include "engine/system/engine.h"
#include "engine/types.h"

void Engine::Start()
{
    constexpr int kWidth {500};
    constexpr int kHeight {500};
    
    m_Renderer.Start(kWidth, kHeight);

    Run();
}

void Engine::Run()
{
    while (!m_Renderer.ShouldWindowClose())
    {
        m_Renderer.BeginDraw();
 
        for (UniquePtr<GameObject>& gameObject : m_ActiveScene->GetGameObjects())
        {
            gameObject->Update();
        }
        
        m_Renderer.EndDraw();
    }

    Shutdown();
}

void Engine::Shutdown()
{
    m_Renderer.Destroy();
}

void Engine::LoadScene(UniquePtr<Scene>&& SceneToLoad)
{
    m_ActiveScene.reset(SceneToLoad.get());
}
