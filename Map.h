#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Game.h"

class Map {

public:

    Map();
    ~Map();

    void LoadMap(int arr[24][40]);
    void DrawMap();

private:

    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;


    int map[24][40];



};


#endif // MAP_H_INCLUDED
