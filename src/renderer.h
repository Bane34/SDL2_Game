#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sprite.h"
#include "colors.h"

class Renderer {
public:
    Renderer(SDL_Window* renderingWindow);
    ~Renderer();

    void clear(Color color);
    void draw();
    SDL_Texture* loadSprite(const char* file);
    void drawSprite(Sprite sprite, uint32_t xpos, uint32_t ypos, uint32_t w, uint32_t h);
    void destroyTexture(SDL_Texture* texture);

    SDL_Renderer* getRenderer();

private:
    bool init();
    void close();

    SDL_Window*   gRendererWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
};

#endif /* RENDERER_H */