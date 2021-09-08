#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_WIDTH  640

class Window {
public:
    Window(const char* name, uint32_t w, uint32_t h, bool fullscreen);
    ~Window();

    void handleEvents(); 

    bool isOpen();
    SDL_Window* getWindow();

private:
    /* Methods */
    bool init();
    void close();

    bool initWindow();    

    /* Variables */
    SDL_Window*  gWindow = NULL;

    const char*  name;
    unsigned int width, height;
    bool         running;
    bool         fullscreen;
};

#endif /* WINDOW_H */