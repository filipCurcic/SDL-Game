#include "Player.h"
#include "cmath"
#include "Bullet.h"

Player::Player(int x, int y) : GameObject("assets/h1.png")
{
    destinationRect.x = x;
    destinationRect.y = y;
};
void Player::control(Player *player) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_W]) {
        player->move(0,-3);
    }
    else if(state[SDL_SCANCODE_A]) {
        player->move(-3,0);
    }
    else if(state[SDL_SCANCODE_S]) {
        player->move(0,3);
    }
    else if(state[SDL_SCANCODE_D]) {
        player->move(3,0);
    }

    else if(state[SDL_SCANCODE_D] && state[SDL_SCANCODE_W]) {
        player->move(1,1);
    }

}

void Player::checkCollision(Player *a,Enemy *b)
{
    int xDist = (b->getXCentre() - a->getXCentre()) * (b->getXCentre() - a->getXCentre());
    int yDist = (b->getYCentre() - a->getYCentre()) * (b->getYCentre() - a->getYCentre());

    double dist = sqrt(xDist+yDist);
    int rad = a->getRadius() + b->getRadius();
    if(dist <= rad/2-2){
        cout << "Kolizija" << endl;
    }
}
