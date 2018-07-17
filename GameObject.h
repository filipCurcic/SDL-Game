#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include "Game.h"


class GameObject {

public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();

    void update();
    void render();


private:
    int xpos, ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destinationRect;




};


#endif // GAMEOBJECT_H_INCLUDED
