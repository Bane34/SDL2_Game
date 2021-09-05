#include "window.h"

Window::Window(const char* name, uint32_t w, uint32_t h){ 
    this->name = name;
    
    // If the width or the height are 0
    // The window will use the default width and height
    // 480 and 640 respectively
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

void Window::handleEvents(){
    //--- Poll the events ---//    
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) {
            running = false;
        }
    }
}

bool Window::isOpen(){
    return (running)? true : false;
}

SDL_Window* Window::getWindow(){
    return gWindow;
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