#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

#define WIDTH  640
#define HEIGHT 480

int main(int argc, char** argv){
    bool running = true;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //--- Init SDL2 and SDL2_image ---//

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL couldnt init! SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }
    IMG_Init(IMG_INIT_PNG);

    //--- Create the window and the renderer ---//

    window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Error creating the window! SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error creating the renderer! SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }

    //--- Loading a texture onto the screen ---//
    SDL_Texture* texture = NULL;
    SDL_Surface* temp = IMG_Load("images/stickman.png");

    texture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);

    // To load the texture we need to define
    // A SDL_Rect with his dimensions and position
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 200;
    rect.w = 107;
    rect.h = 240;

    //--- Loop of the screen ---//

    SDL_Event event;

    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderPresent(renderer);
    }    

    //--- Destroying the objects ---//

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);

    //--- Quitting the program ---//

    IMG_Quit();
    SDL_Quit();

    return 0;
}