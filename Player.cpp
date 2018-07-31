#include "Player.h"
#include "cmath"


Player::Player(int x, int y) : GameObject("assets/h1.png")
{
    destinationRect.x = x;
    destinationRect.y = y;
};
void Player::control(Player *player) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_W]) {
        player->move(0,-2);
    }
    else if(state[SDL_SCANCODE_A]) {
        player->move(-2,0);
    }
    else if(state[SDL_SCANCODE_S]) {
        player->move(0,2);
    }
    else if(state[SDL_SCANCODE_D]) {
        player->move(2,0);
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
        b->die();


    }
    else {
        cout << "Nema" << endl;
    }

}

/*
void Player::shoot(int x, int y)
{
    GameObject* p = new GameObject("assets.e1.png", x, y);
    for(int i = 32; i<x; i++){
        p->update();
        p->render();
        p->setX(i);
        cout << "aa" << endl;
    }

}
*/
