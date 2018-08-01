#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include "Game.h"


class GameObject {

public:
    GameObject(const char* texturesheet);
    ~GameObject(){};

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
    SDL_Rect destinationRect;



private:
    int xpos, ypos;
    int xCentre = destinationRect.x+(destinationRect.w/2);
    int yCentre = destinationRect.y-(destinationRect.h/2);
    int radius = destinationRect.w/2;
    int testx = destinationRect.x;
    SDL_Texture* objTexture;





};


#endif // GAMEOBJECT_H_INCLUDED
