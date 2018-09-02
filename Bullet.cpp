#include "Bullet.h"

Bullet::Bullet(int x, int y) : GameObject("assets/bullet.png", "bullet")
{
    destinationRect.x = x;
    destinationRect.y = y;
};

/*
int Bullet::getNewYpos(int startingY, int rectX, int startingX, int targetY, int targetX)
{
    int newYpos = startingY + (rectX - startingX) * (targetY-startingY)/(targetX-startingX);
    return newYpos;
}

*/
