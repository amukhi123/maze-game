#include "raylib/raylib.h"

#include "engine/system/engine.h"

#include "engine/util/logger.h"

#include "engine/types.h"

#include "game/player.h"
#include "game/map.h"

#include "engine/component/camera.h"

UniquePtr<Logger> Logger::m_Instance {};

int main()
{
    Logger::GetInstance()->SetLogLevel(LogLevel::Debug);

    auto game {std::make_unique<Scene>("Game")};

    UniquePtr<GameObject> player {std::make_unique<Player>("Player")};
    UniquePtr<GameObject> map {std::make_unique<Map>("Map")};

    const Vector3 cameraPosition {0.0f, 10.0f, 100.0f};
    const Vector3 cameraTarget {0.0f, 0.0f, 00.0f};
    
    UniquePtr<Component> camera {std::make_unique<CameraComponent>("Camera", cameraPosition, cameraTarget)};

    player->AddComponent(std::move(camera));
    
    game->AddGameObject(std::move(player));
    game->AddGameObject(std::move(map));
    
    Engine engine {};

    engine.LoadScene(std::move(game));

    engine.Start();
}
