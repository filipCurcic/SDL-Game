#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "GameObject.h"
#include "Bullet.h"
#include <vector>

enum State{move_left =1, move_right=3, move_up=0, move_down=2, move_diag_left_up = 4, move_diag_right_up = 5, move_diag_left_down = 6, move_diag_right_down = 7, stop = 8};

class Enemy : public GameObject
{
public:
    Enemy(int x, int y);
    ~Enemy(){};
    void setXpos(int x) {xp = x;}
    void setYpos(int y) {yp = y;}
    void updateEnemy();
    virtual void move();
    void changeState();
    void bulletCollision(Enemy *enemy, Bullet *bullet,vector<Enemy*> enemies);
private:
    int xp;
    int yp;
    int moved = 0;
    State currentState;
};



#endif // ENEMY_H_INCLUDED
