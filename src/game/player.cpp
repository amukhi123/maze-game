#include "raylib/raylib.h"

#include "game/player.h"

Player::Player(const String& Name) : GameObject {Name}
{
}

void Player::Update()
{
    GameObject::Update();
    
    constexpr int kFont {40};
    
    DrawText("Hello window!", 0, 0, kFont, LIGHTGRAY);
}
