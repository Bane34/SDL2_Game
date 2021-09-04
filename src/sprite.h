#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Sprite{
    SDL_Texture* texture = NULL;
    SDL_Rect    rect;
};

#endif /* SPRITE_H */