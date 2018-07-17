#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

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
}
void Game::update()
{
    player->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Cleaned" << endl;
}
