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

    running = true;
}

Window::~Window(){
    close();    
}

void Window::update(){
    //--- Poll the events ---//    

    SDL_Event event;

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Window::clear(){
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    SDL_RenderPresent(gRenderer);
}

bool Window::isOpen(){
    return (running)? true : false;
}

bool Window::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not init! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    IMG_Init(IMG_INIT_PNG);

    return (initWindow() && initRenderer())? true : false;    
}

void Window::close(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);

    IMG_Quit();
    SDL_Quit();
}

bool Window::initWindow(){
    gWindow = SDL_CreateWindow(
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

    return true;
}

bool Window::initRenderer(){
    gRenderer = SDL_CreateRenderer(
        gWindow,
        -1,
        0
    );

    if(!gRenderer){
        printf("Could not create the renderer! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    return true;
}