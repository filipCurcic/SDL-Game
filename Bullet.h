#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"

class Bullet : public GameObject
{
    public:
        Bullet(int x, int y);
        ~Bullet();

    private:
        int startingX,startingY;

};

#endif // BULLET_H
