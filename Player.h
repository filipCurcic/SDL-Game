#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameObject.h"
#include "Enemy.h"

class Player : public GameObject {
public:
    Player();

    void shoot();
    void control(Player *player);
    void checkCollision(Player *a, Enemy *b);

    ~Player();



};


#endif // PLAYER_H_INCLUDED
