#include "window.h"

// If the width or the height are 0
// The window will use the default width and height
// 480 and 640 respectively
Window::Window(const char* name, unsigned const int w, unsigned const int h){ 
    this->name = name;

    if(w == 0 || h == 0){
        this->width = DEFAULT_WINDOW_WIDTH;         
        this->height = DEFAULT_WINDOW_HEIGHT;
    }
    else{
        this->width = w;
        this->height = h;
    }

    if(!init()){
        printf("Could not init the window\n");
        return;
    }
}

Window::~Window(){
    close();    
}

bool Window::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not init! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    IMG_Init(IMG_INIT_PNG);

    return (initWindow())? true : false;    
}

void Window::close(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);

    IMG_Quit();
    SDL_Quit();
}

bool Window::initWindow(){
    this->gWindow = SDL_CreateWindow(
        this->name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->width,
        this->width,
        SDL_WINDOW_SHOWN
    );

    if(!gWindow){
        printf("Could not make a window! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    return (render())? true : false;
}

bool Window::render(){
    this->gRenderer = SDL_CreateRenderer(
        this->gWindow,
        -1,
        0
    );

    SDL_Texture* texture = NULL;
    SDL_Surface* temp = IMG_Load("images/stickman.png");
    
    texture = SDL_CreateTextureFromSurface(gRenderer, temp);
    SDL_FreeSurface(temp);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 250;
    rect.w = 107;
    rect.h = 240;

    SDL_Event event;
    running = true;
    
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                running = false;
        }

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        SDL_RenderCopy(gRenderer, texture, NULL, &rect);
        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyTexture(texture);

    return true;
}