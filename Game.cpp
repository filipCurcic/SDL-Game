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
Bullet* bullet;



SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<Enemy*> objects;
vector<Bullet*> bullets;


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

    player = new Player(356,256);

   // protivnik = new Enemy();
    map = new Map();
    e = new Enemy(0, 0);

}


void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            bullet = new Bullet(player->getX(), player->getY());
            bullets.push_back(bullet);

            //player->shoot(bullet, bullets, player);
            /*e = new Enemy(event.button.x, event.button.y);
            objects.push_back(e);
            break;*/
    }
}




void Game::update()
{
    player->update();
    //protivnik->update();
    player->control(player);
    player->checkCollision(player, e);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
   // protivnik->render();
   // Game::spawnUnits();
    Game::spawnBullets();
    SDL_RenderPresent(renderer);



}

void Game::spawnUnits()
{
    for(vector<Enemy*>::iterator it = objects.begin(); it != objects.end(); it++) {

            (*it)->render();
            (*it)->update();
            (*it)->move();

    }

}

void Game::spawnBullets()
{
    for(vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
            (*it)->render();
            (*it)->update();
            (*it)->move(10, 0);
    }
}


Game::randNum()
//the parameters must be min = 3, max = 3;
{
int x = rand()%(798-1 + 1) + 1;
return x;

}

void Game::spawnEnemies()
{
    for (int i = 0; i<20; i++) {
        e = new Enemy(randNum(), randNum());
        objects.push_back(e);
    }
}



