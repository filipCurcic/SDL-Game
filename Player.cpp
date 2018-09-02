#include "Player.h"
#include "cmath"
#include "Bullet.h"

Player::Player(int x, int y) : GameObject("assets/p1.png", "player")
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

int Player::checkCollision(Player *a,Enemy *b, vector<Enemy*> enm)
{
    int index;
    int xDist = (b->getXCentre() - a->getXCentre()) * (b->getXCentre() - a->getXCentre());
    int yDist = (b->getYCentre() - a->getYCentre()) * (b->getYCentre() - a->getYCentre());
    double dist = sqrt(xDist+yDist);
    int rad = a->getRadius() + b->getRadius();
    for(vector<Enemy*>::iterator it = enm.begin(); it != enm.end(); it++) {
        if(dist <= rad/2-2){
            if(b==(*it)) {
                cout << "aaa" << endl;
            }

            return index;
        }

    }
}


int Player::colCheck(vector<Player*> pl, vector<Enemy*> en){

    for(vector<Player*>::iterator it = pl.begin(); it != pl.end(); it++) {
        for(vector<Enemy*>::iterator it1 = en.begin(); it1 != en.end(); it++){

            int xDist = ((*it1)->getXCentre() - (*it)->getXCentre()) * ((*it1)->getXCentre() - (*it)->getXCentre());
            int yDist = ((*it1)->getYCentre() - (*it)->getYCentre()) * ((*it1)->getYCentre() - (*it)->getYCentre());
            double dist = sqrt(xDist+yDist);
            int rad = (*it)->getRadius() + (*it1)->getRadius();
                if(dist <= rad/2-2){
                    int index = std::distance(en.begin(), it1);;
                    return index;
                }
        }
    }
}
