#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"

class Bullet : public GameObject
{
    public:
        Bullet(int x, int y);
        int getNewYpos(int startingY, int rectX, int startingX, int targetY, int targetX);

    private:
        int startingX,startingY;
        int targetX, targetY;

       // int newYpos = startingY + (destinationRect.x - startingX) * (targetY-startingY)/(targetX-startingX);

};

#endif // BULLET_H
