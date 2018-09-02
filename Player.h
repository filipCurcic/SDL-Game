#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameObject.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>


class Player : public GameObject {
public:
    Player(int x, int y);
    void control(Player *player);
    int checkCollision(Player *a, Enemy *b, vector<Enemy*> enm);
    int colCheck(vector<Player*> pl, vector<Enemy*> en);
    ~Player();



};


#endif // PLAYER_H_INCLUDED
