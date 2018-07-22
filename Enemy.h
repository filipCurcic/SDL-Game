#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "GameObject.h"


class Enemy : public GameObject
{
public:
    Enemy();
    void die();
    ~Enemy();
};



#endif // ENEMY_H_INCLUDED
