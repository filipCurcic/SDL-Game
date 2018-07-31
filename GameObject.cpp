#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    destinationRect.x = 0;
    destinationRect.y = 0;


}

void GameObject::update()
{
    destinationRect.w = 64;
    destinationRect.h = 64;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destinationRect);
}

void GameObject::move(int dx, int dy)
{
    destinationRect.x += dx;
    destinationRect.y += dy;
}










