#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

void GameObject::update()
{



    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destinationRect.x = xpos;
    destinationRect.y = ypos;
    destinationRect.w = srcRect.w * 2;
    destinationRect.h = srcRect.h * 2;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destinationRect);
}

void GameObject::move(int dx, int dy)
{
    xpos += dx;
    ypos += dy;
}










