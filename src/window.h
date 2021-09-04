#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_WIDTH  640

class Window {
public:
    Window(const char* name, unsigned const int w, unsigned const int h);
    ~Window();

    void update();

    bool isOpen();
    SDL_Window* getWindow();

private:
    /* Methods */
    bool init();
    void close();

    bool initWindow();    

    /* Variables */
    SDL_Window*   gWindow   = NULL;

    const char* name;
    unsigned int width, height;
    bool running;
};

#endif /* WINDOW_H */