#include "Enemy.h"
#include <windows.h>
#include "cmath"
#include <vector>

Enemy::Enemy(int x, int y) : GameObject("assets/e1.png")
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
    switch(currentState){
    case move_left:
        GameObject::move(-1, 0);
        break;
    case move_right:
        GameObject::move(1, 0);
        break;
    case move_up:
        GameObject::move(0, -1);
        break;
    case move_down:
        GameObject::move(0, 1);
        break;
    case move_diag_left_up:
        GameObject::move(-1, -1);
        break;
    case move_diag_right_up:
        GameObject::move(1, 1);
        break;
    case move_diag_left_down:
        GameObject::move(-1, 1);
        break;
    case move_diag_right_down:
        GameObject::move(1, -1);
        break;
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
void Enemy::changeState()
{
    int randNum = rand()%(9-1 + 1) + 1;

    switch(randNum){
    case 1:
        currentState = move_left;
        break;
    case 2:
        currentState = move_right;
        break;
    case 3:
        currentState = move_up;
        break;
    case 4:
        currentState = move_down;
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
        cout << "Col" << endl;
    }
}

