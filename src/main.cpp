#include "engine/system/engine.h"

#include "engine/utils/logger.h"

#include "game/player.h"

UniquePtr<Logger> Logger::m_Instance {};

int main()
{
    Logger::GetInstance()->SetLogLevel(LogLevel::Debug);

    UniquePtr<Scene> game {new Scene {"Game"}};

    UniquePtr<GameObject> player {new Player {"Player"}};
    
    game->AddGameObject(player);
    
    Engine engine {};

    engine.LoadScene(std::move(game));

    engine.Start();
}
