#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Unit.h"

class Player : public Unit {
public:
    Player();

    void shoot();

    ~Player();



};


#endif // PLAYER_H_INCLUDED
