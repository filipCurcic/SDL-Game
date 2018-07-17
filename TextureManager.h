#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED
#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* fileName);

};


#endif // TEXTUREMANAGER_H_INCLUDED
