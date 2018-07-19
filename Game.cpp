#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Unit.h"
#include <vector>
#include <utility>

GameObject* player;
Unit* u1;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
vector<GameObject*> objects;


Game::Game()
{

}

Game::~Game()
{}
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

    player = new GameObject("assets/h1.png", 0, 0);
    u1 = new Unit();
    map = new Map();

}





void Game::update()
{
    player->update();
    u1->update();
    u1->move(0,1);

}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    u1->render();
    SDL_RenderPresent(renderer);

}

void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
            case SDLK_w:
                player->move(0,1);
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            Unit *a = new Unit();
            objects.push_back(a);
    }
    for(vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
            (*it)->update();
            (*it)->render();
        }

}


void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Cleaned" << endl;
}


