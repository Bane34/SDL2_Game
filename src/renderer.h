#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer {
public:
    Renderer(SDL_Window* renderingWindow);
    ~Renderer();

    void clear();
    SDL_Texture* loadSprite(const char* file);
    void drawSprite(SDL_Texture* texture, uint32_t xpos, uint32_t ypos, uint32_t w, uint32_t h);
    void destroyTexture(SDL_Texture* texture);

private:
    bool init();
    void close();

    SDL_Window*   gRendererWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
};

#endif /* RENDERER_H */