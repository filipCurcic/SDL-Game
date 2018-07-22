#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameObject.h"

class Player : public GameObject {
public:
    Player();

    void shoot();
    void control(Player *player);

    ~Player();



};


#endif // PLAYER_H_INCLUDED
