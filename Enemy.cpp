#include "Enemy.h"
#include <windows.h>
#include "cmath"
#include <vector>

Enemy::Enemy(int x, int y) : GameObject("assets/npc/hu.png", "enemy")
{
    destinationRect.x = x;
    destinationRect.y = y;
    currentState = stop;
};


void Enemy::updateEnemy()
{
    destinationRect.x = xp;
    destinationRect.y = yp;
}

void Enemy::move()
{
    if(fr)
    {
        switch(currentState){
        case move_left:
        while(checkBorders()){

            GameObject::move(-2, 0);
            break;
            }

        case move_right:
            while(checkBorders()){

                GameObject::move(2, 0);
                break;
            }
        case move_up:
            while(checkBorders()){

                GameObject::move(0, -3);
                break;
            }

        case move_down:
            while(checkBorders()) {

                GameObject::move(0, 1);
                break;
            }

        case move_diag_left_up:
            while(checkBorders()) {
                GameObject::move(-1, -1);
                break;
            }

        case move_diag_right_up:
            while(checkBorders()) {
               GameObject::move(1, 1);
                break;
            }

        case move_diag_left_down:
            while(checkBorders()) {
                GameObject::move(-1, 1);
                break;
            }

        case move_diag_right_down:
            while(checkBorders()) {
                GameObject::move(1, -1);
                break;
            }

        case stop:
            GameObject::move(0,0);
            break;

        }
        moved++;
        if(moved>35) {
            changeState();
            moved = 0;
        }

    }

    if(!fr)
    {

    }


}
void Enemy::changeState()
{
    int randNum = rand()%(10-1 + 1) + 1;

    switch(randNum){
    case 1:
        currentState = move_left;
        GameObject::changeTexture("assets/npc/hl.png");
        break;
    case 2:
        currentState = move_right;
        GameObject::changeTexture("assets/npc/hr.png");
        break;
    case 3:
        currentState = move_up;
        GameObject::changeTexture("assets/npc/hu.png");
        break;
    case 4:
        currentState = move_down;
        GameObject::changeTexture("assets/npc/hd.png");
        break;


    case 5:
        currentState = move_diag_left_up;
        break;
    case 6:
        currentState = move_diag_right_up;
        break;
    case 7:
        currentState = move_diag_left_down;
        break;
    case 8:
        currentState = move_diag_right_down;
        break;
    case 9:
        currentState = stop;
        break;

    }

}


void Enemy::bulletCollision(Enemy *enemy, Bullet *bullet, vector<Enemy*> enemies)
{
    int xDist = (bullet->getXCentre() - enemy->getXCentre()) * (bullet->getXCentre() - enemy->getXCentre());
    int yDist = (bullet->getYCentre() - enemy->getYCentre()) * (bullet->getYCentre() - enemy->getYCentre());
    double dist = sqrt(xDist+yDist);
    int rad = enemy->getRadius() + bullet->getRadius();
    if(dist <= rad/2-2){

    }
}

bool Enemy::checkBorders()
{
    if(xp > 800 || yp > 640){
        return false;
    }
    else {
        return true;
    }

}







