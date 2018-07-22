#ifndef GAME_H
#define GAME_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GameObject.h"

using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        bool running() {return isRunning;}

        static SDL_Renderer *renderer;
        static SDL_Event event;


    private:
        bool isRunning;
        SDL_Window *window;
        int counter = 0;
};

#endif // GAME_H
