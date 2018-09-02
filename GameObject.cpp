#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, string type)
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

    if(destinationRect.x > 756) {
        destinationRect.x -= 1;
    }
    else {
        if (destinationRect.x < 0) {
            destinationRect.x += 1;
        }
        else {
            destinationRect.x += dx;
        }
    }

    if(destinationRect.y > 594) {
        destinationRect.y -= 1;
    }
    else {
        if(destinationRect.y < 0) {
            destinationRect.y += 1;
        }
        else {
            destinationRect.y += dy;
        }

    }


}

GameObject::~GameObject()
{
    SDL_DestroyTexture(objTexture);
}









