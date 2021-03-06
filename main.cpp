#include <iostream>
#include "Game.h"


Game *game = nullptr;

using namespace std;

int main(int argc, char *argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Title", 1280, 768, false);
    game->fillVector();
    for (int i = 0; i<1;i++){
            game->spawnEnemies();
        }

    while(game->running()){

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();




        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }


}
    delete game;
    return 0;
}
