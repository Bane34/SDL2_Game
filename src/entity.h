#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

class Entity {
public:
    Entity(SDL_Texture* texture, float xpos, float ypos);
    ~Entity();

    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect     getCurrentFrame();

    void init();
private:
    float gX = 0;
    float gY = 0;
    SDL_Rect     gCurrentFrame;
    SDL_Texture* gTexture = NULL;
};

#endif /* ENTITY_H */