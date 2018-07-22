#include "Player.h"


Player::Player() : GameObject("assets/h1.png", 32, 32)
{

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
