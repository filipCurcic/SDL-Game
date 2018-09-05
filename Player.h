#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameObject.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

enum playerDirection{UP, DOWN, LEFT, RIGHT};

class Player : public GameObject {
public:
    Player(int x, int y);
    void control(Player *player);
    bool checkCollision(Player *a, Enemy *b);
    playerDirection getDir() {return curD;}
    void setDir(playerDirection dir) {curD = dir;}
    playerDirection changeDirection(Player *p, Enemy *e);
    ~Player();
private:
    playerDirection curD;



};


#endif // PLAYER_H_INCLUDED
