#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED
#include "GameObject.h"

class Unit : public GameObject {

public:
    Unit();
    ~Unit();
    void setHp(int nhp) {hp = nhp;};
    int getHp() {return hp;};

private:

    int hp, curHp, speed;



};


#endif // UNIT_H_INCLUDED
