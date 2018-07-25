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
    int getXCentre() {return destinationRect.x+32;}
    int getYCentre() {return destinationRect.y+32;}
    int getRadius() {return 32;}
    int getX() {return destinationRect.x;}
    int getY() {return destinationRect.y;}
    void setX(int x) {destinationRect.x = x;}
    void setY(int y) {destinationRect.y = y;}




private:
    int xpos, ypos;
    int xCentre = xpos+(destinationRect.w/2);
    int yCentre = ypos-(destinationRect.h/2);
    int radius = destinationRect.w/2;
    int testx = destinationRect.x;

    SDL_Texture* objTexture;
    SDL_Rect destinationRect;




};


#endif // GAMEOBJECT_H_INCLUDED
