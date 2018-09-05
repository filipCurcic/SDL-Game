#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(char* texturesheet, string type)
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

void GameObject::move(float dx, float dy)
{

    if(destinationRect.x > 1200) {
        destinationRect.x -= 1;
    }
    else {
        if (destinationRect.x < 16) {
            destinationRect.x += 1;
        }
        else {
            destinationRect.x += dx;
        }
    }

    if(destinationRect.y > 688) {
        destinationRect.y -= 1;
    }
    else {
        if(destinationRect.y < 16) {
            destinationRect.y += 1;
        }
        else {
            destinationRect.y += dy;
        }
    }
}

void GameObject::setType(std::string t)
{
    type = t;
}

void GameObject::changeTexture(char* newT)
{
    objTexture = TextureManager::LoadTexture(newT);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(objTexture);
}









