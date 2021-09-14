#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "utils/colors.h"
#include "textureManager.h"

// Definition of the window flags //

enum flags {
    FULLSCREEN   = SDL_WINDOW_FULLSCREEN,
    WINDOW_SHOWN = SDL_WINDOW_SHOWN,
    OPENGL       = SDL_WINDOW_OPENGL,
    RESIZABLE    = SDL_WINDOW_RESIZABLE
};

class Window {
public:
    Window(const char* p_name, uint32_t p_width, uint32_t p_height, int flags);
    ~Window();

    void clear(Color p_color);
    void render();
    void windowDraw();
    void update();
    void handleEvents(); 

    bool isOpen();
    SDL_Window*   getWindow();
    SDL_Renderer* getRenderer();

private:
    /* Methods */
    bool initWindow();    
    bool initRenderer();

    void close();
    
    /* Variables */
    SDL_Window*    m_Window = NULL;
    SDL_Renderer*  m_Renderer = NULL;
    const char*    m_Name;
    unsigned int   m_Width, m_Height;
    int            m_Flags = 0;
    bool           m_Running;

    int            m_CurrentFrame;
};

#endif /* WINDOW_H */