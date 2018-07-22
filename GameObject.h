#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include "Game.h"


class GameObject {

public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();

    void update();
    void render();
    void move(int dx, int dy);
    int getXCentre() {return xCentre;}
    int getYCentre() {return yCentre;}
    int getRadius() {return radius;}




private:
    int xpos, ypos;
    int xCentre = xpos+destinationRect.w;
    int yCentre = ypos-destinationRect.h;
    int radius = destinationRect.w/2;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destinationRect;




};


#endif // GAMEOBJECT_H_INCLUDED
