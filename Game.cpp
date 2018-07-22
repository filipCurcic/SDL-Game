#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <utility>
#include <windows.h>
#include "cmath"



Map* map;
Player* player;
GameObject* b;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<GameObject*> objects;


Game::Game()
{

}

Game::~Game()
{SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        }

        isRunning = true;
    }else {isRunning = false;}

    player = new Player();
    map = new Map();

}

void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            b = new GameObject("assets/e1.png", event.button.x, event.button.y);
            objects.push_back(b);

            break;
    }
}




void Game::update()
{
    player->update();
    player->control(player);
    /*if(Game::checkCollision(player, b)){
        cout<< "radi" << endl;
    }*/




}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    Game::spawnUnits();
    SDL_RenderPresent(renderer);


}

void Game::spawnUnits()
{
    for(vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
            (*it)->update();
            (*it)->render();
            //(*it)->move(0,2);
    }

}


Game::randNum()
//the parameters must be min = 3, max = 3;
{
int x = rand()%(798-1 + 1) + 1;
return x;

}


/*bool Game::checkCollision(Player *a, Enemy *b)
{
    int xDist = (b->getXCentre() - a->getXCentre()) * (b->getXCentre() - a->getXCentre());
    int yDist = (b->getYCentre() - a->getYCentre()) * (b->getYCentre() - a->getYCentre());
    double dist = sqrt(xDist+yDist);
    if(dist<=a->getRadius()+b->getRadius()){
        return true;
    }
    return false;
}

*/

