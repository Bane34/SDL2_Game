#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#define WIDTH  640
#define HEIGHT 480

int main(int argc, char** argv){
    bool running = true;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL couldnt init! SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }

    // Creating the window
    window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Error creating the window! SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }
    
    int r = 0, g = 0, b = 0;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                running = false;
            else if(event.type == SDL_KEYDOWN){
                r = rand() % 255;
                g = rand() % 255;
                b = rand() % 255;
            }

        }

        SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }    

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}