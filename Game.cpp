#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <utility>



Map* map;
Player* player;

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
            static Player *a = new Player();
            objects.push_back(a);
            break;
    }
    for(vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
            (*it)->update();
            (*it)->render();
    }




}



void Game::update()
{
    player->update();
    player->control(player);


}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    SDL_RenderPresent(renderer);

}






