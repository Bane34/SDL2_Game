#include "renderer.h"

Renderer::Renderer(SDL_Window* renderingWindow){
    gRendererWindow = renderingWindow;

    if(!init())
        return;
}

Renderer::~Renderer(){
    close();
}

void Renderer::clear(){
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
}

SDL_Texture* Renderer::loadSprite(const char* file){
    SDL_Surface* temp = NULL;
    SDL_Texture* texture = NULL;

    temp = IMG_Load(file);
    texture = SDL_CreateTextureFromSurface(gRenderer, temp);

    SDL_FreeSurface(temp);

    return texture;
}

void Renderer::drawSprite(SDL_Texture* texture, uint32_t xpos, uint32_t ypos, uint32_t w, uint32_t h){
    SDL_Rect rect;
    rect.x = xpos;
    rect.y = ypos;
    rect.w = w;
    rect.h = h;
    
    SDL_RenderCopy(gRenderer, texture, NULL, &rect);
    SDL_RenderPresent(gRenderer);
}

void Renderer::destroyTexture(SDL_Texture* texture){
    SDL_DestroyTexture(texture);
}

bool Renderer::init(){
    gRenderer = SDL_CreateRenderer(
        gRendererWindow,
        -1,
        0
    );

    if(!gRenderer){
        printf("Could not create the renderer! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void Renderer::close(){
    SDL_DestroyRenderer(gRenderer);
}