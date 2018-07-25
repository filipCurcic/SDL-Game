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


    destinationRect.x = xpos;
    destinationRect.y = ypos;
    destinationRect.w = 64;
    destinationRect.h = 64;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destinationRect);
}

void GameObject::move(int dx, int dy)
{
    xpos += dx;
    ypos += dy;
}










