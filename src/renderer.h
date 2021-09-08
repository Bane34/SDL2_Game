#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "colors.h"
#include "entity.h"

class Renderer {
public:
    Renderer(SDL_Window* renderingWindow);
    ~Renderer();

    void clear(Color color);
    void draw();
    SDL_Texture* loadTexture(const char* file);
    void drawEntity(Entity& entity);
    void destroyEntity(Entity* entity);

    SDL_Renderer* getRenderer();

private:
    bool init();
    void close();

    SDL_Window*   gRendererWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
};

#endif /* RENDERER_H */