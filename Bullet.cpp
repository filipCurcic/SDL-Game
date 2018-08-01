#include "Bullet.h"

Bullet::Bullet(int x, int y) : GameObject("assets/bullet.png")
{
    destinationRect.x = x;
    destinationRect.y = y;
};


