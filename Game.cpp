#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Human.h"
#include "cmath"
#include <vector>
#include <utility>
#include <windows.h>



Map* map;
Player* player;
GameObject* b;
Enemy* e;
Bullet* bullet;
Human* human;
int bulletDirection;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<Enemy*> objects;
vector<Bullet*> bullets;
vector<Player*> players;
vector<Human*> humans;
vector<Enemy*> enemies;


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
    players.push_back(player);

    map = new Map();
    e = new Enemy(0, 0);
    bullet = new Bullet(NULL, NULL);
    human = new Human(200, 200);

}


void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            delete bullet;
        case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        bullet = new Bullet(player->getX(), player->getY());
                        bullets.push_back(bullet);
                        bulletDirection = 1;
                        break;
                    case SDLK_RIGHT:
                        bullet = new Bullet(player->getX(), player->getY());
                        bullets.push_back(bullet);
                        bulletDirection = 2;
                        break;
                    case SDLK_UP:
                        bullet = new Bullet(player->getX(), player->getY());
                        bullets.push_back(bullet);
                        bulletDirection = 3;
                        break;
                    case SDLK_DOWN:
                        bullet = new Bullet(player->getX(), player->getY());
                        bullets.push_back(bullet);
                        bulletDirection = 4;
                        break;
                    default:
                        break;
    }
}

}


void Game::update()
{
    player->update();
    player->control(player);
    e->bulletCollision(e, bullet, objects);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    Game::spawnUnits();
    Game::spawnBullets();
    SDL_RenderPresent(renderer);



}

void Game::spawnUnits()
{

    for(vector<Player*>::iterator it3 = players.begin(); it3 != players.end(); it3++) {
       for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {

                (*it)->render();
                (*it)->update();
                (*it)->move();
                int xDist = ((*it)->getXCentre() - (*it3)->getXCentre()) * ((*it)->getXCentre() - (*it3)->getXCentre());
                int yDist = ((*it)->getYCentre() - (*it3)->getYCentre()) * ((*it)->getYCentre() - (*it3)->getYCentre());
                double dist = sqrt(xDist+yDist);
                int rad = (*it3)->getRadius() + (*it)->getRadius();
                if(dist <= rad/2-2){

                    (*it)->changeTexture("assets/npc/h1.png");
                    (*it)->setType("z");

                }
                while((*it3)->checkCollision(*it3, *it))
                {
                    (*it)->setFr(false);
                    break;
                };
                while(!(*it3)->checkCollision(*it3, *it))
                {
                    (*it)->setFr(true);
                    break;
                };


    }

}
for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
    for(vector<Enemy*>::iterator it2 = enemies.begin(); it2 != enemies.end(); it2++) {
        int xDist1 = ((*it2)->getXCentre() - (*it)->getXCentre()) * ((*it2)->getXCentre() - (*it)->getXCentre());
        int yDist1 = ((*it2)->getYCentre() - (*it)->getYCentre()) * ((*it2)->getYCentre() - (*it)->getYCentre());
        double dist1 = sqrt(xDist1+yDist1);
        int rad22 = (*it)->getRadius() + (*it2)->getRadius();
        if(dist1 <= rad22/2-2){
            if ( (*it)->getType() == "z" ) {
                (*it2)->changeTexture("assets/npc/iu.png");
                (*it2)->setType("z");
            }


        }
    }

}
}
void Game::spawnBullets()
{
    for(vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
            (*it)->render();
            (*it)->update();
            switch(bulletDirection){
            case 1:
                (*it)->move(-20, 0);
                break;
            case 2:
                (*it)->move(20, 0);
                break;
            case 3:
                (*it)->move(0, -20);
                break;
            case 4:
                (*it)->move(0, 20);
                break;
            }

    }
}


Game::randNum()
//the parameters must be min = 3, max = 3;
{
int x = rand()%(798-1 + 1) + 1;
return x;

}

void Game::fillVector()
{
    Enemy* e1 = new Enemy(randNum(), randNum());
    enemies.push_back(e1);
    Enemy* e2 = new Enemy(randNum(), randNum());
    enemies.push_back(e2);
    Enemy* e3 = new Enemy(randNum(), randNum());
    enemies.push_back(e3);
    Enemy* e4 = new Enemy(randNum(), randNum());
    enemies.push_back(e4);
    Enemy* e5 = new Enemy(randNum(), randNum());
    enemies.push_back(e5);
    Enemy* e6 = new Enemy(randNum(), randNum());
    enemies.push_back(e6);
    Enemy* e7 = new Enemy(randNum(), randNum());
    enemies.push_back(e7);
    Enemy* e8 = new Enemy(randNum(), randNum());
    enemies.push_back(e8);
    Enemy* e9 = new Enemy(randNum(), randNum());
    enemies.push_back(e9);
    Enemy* e10 = new Enemy(randNum(), randNum());
    enemies.push_back(e10);
}



void Game::spawnEnemies()
{



    /*for (int i = 0; i<20; i++) {
        e = new Enemy(randNum(), randNum());
        objects.push_back(e);
        human = new Human(randNum(), randNum());
        humans.push_back(human);
    }*/
}

