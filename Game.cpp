#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"

#include <vector>
#include <utility>
#include <windows.h>



Map* map;
Player* player;
GameObject* b;
Enemy* e;
Enemy* protivnik;
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
    protivnik = new Enemy();
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
            e = new Enemy();
            objects.push_back(e);
            player->shoot(200, 200);


            break;
    }
}




void Game::update()
{
    player->update();
    protivnik->update();
    player->control(player);
    //cout << player->getXCentre() << "," << player->getYCentre() << endl;
    player->checkCollision(player, protivnik);

}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    protivnik->render();
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




