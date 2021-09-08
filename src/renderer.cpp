#include "renderer.h"

Renderer::Renderer(SDL_Window* renderingWindow){
    gRendererWindow = renderingWindow;

    if(!init())
        return;
}

Renderer::~Renderer(){
    close();
}

void Renderer::clear(Color color = {0xFF, 0xFF, 0xFF, 0xFF}){
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(gRenderer);
}

void Renderer::draw(){
    SDL_RenderPresent(gRenderer);
}

SDL_Texture* Renderer::loadTexture(const char* file){
    SDL_Surface* temp = NULL;
    SDL_Texture* texture = NULL;

    temp = IMG_Load(file);
    texture = SDL_CreateTextureFromSurface(gRenderer, temp);

    SDL_FreeSurface(temp);

    return texture;
}

void Renderer::drawEntity(Entity& entity){
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getX();
    dst.y = entity.getY();
    dst.w = entity.getCurrentFrame().w; 
    dst.h = entity.getCurrentFrame().h;

    SDL_RenderCopy(gRenderer, entity.getTexture(), &src, &dst);
}

void Renderer::destroyEntity(Entity* entity){
    SDL_DestroyTexture(entity->getTexture());
}

SDL_Renderer* Renderer::getRenderer(){
    return gRenderer;
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