#include "Player.h"
#include "cmath"
#include "Bullet.h"

Player::Player(int x, int y) : GameObject("assets/player/zu.png", "player")
{
    destinationRect.x = x;
    destinationRect.y = y;
};
void Player::control(Player *player) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_W]) {
        player->move(0,-3);
        setDir(UP);
        GameObject::changeTexture("assets/player/zu.png");
    }
    else if(state[SDL_SCANCODE_A]) {
        player->move(-3,0);
        setDir(LEFT);
        GameObject::changeTexture("assets/player/zl.png");
    }
    else if(state[SDL_SCANCODE_S]) {
        player->move(0,3);
        setDir(DOWN);
        GameObject::changeTexture("assets/player/zd.png");
    }
    else if(state[SDL_SCANCODE_D]) {
        player->move(3,0);
        setDir(RIGHT);
        GameObject::changeTexture("assets/player/zr.png");
    }

    else if(state[SDL_SCANCODE_D] && state[SDL_SCANCODE_W]) {
        player->move(1,1);
    }

}

bool Player::checkCollision(Player *a,Enemy *b)
{
    int index;
    int xDist = (b->getXCentre() - a->getXCentre()) * (b->getXCentre() - a->getXCentre());
    int yDist = (b->getYCentre() - a->getYCentre()) * (b->getYCentre() - a->getYCentre());
    double dist = sqrt(xDist+yDist);
    int rad = (a->getRadius() + b->getRadius()) + 150;
        if(dist <= rad/2-2){
            return true;
        }
        return false;
}

playerDirection Player::changeDirection(Player *p, Enemy *e)
{
    if(e->getType() != "z") {
        switch(p->getDir())
        {
            case UP:
                e->setState(move_up);
                break;
            case DOWN:
                e->setState(move_down);
                break;
            case LEFT:
                e->setState(move_left);
                break;
            case RIGHT:
                e->setState(move_right);
                break;
        }
    }

}
