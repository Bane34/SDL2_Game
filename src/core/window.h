#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include <imgui/src/imgui.h>
#include <imgui/src/imgui_impl_sdl.h>
#include <imgui/src/imgui_impl_sdlrenderer.h>

#include "utils/colors.h"
#include "utils/logger.h"
#include "textureManager.h"
class Window {
public:
    enum flags {
        FULLSCREEN   = SDL_WINDOW_FULLSCREEN,
        WINDOW_SHOWN = SDL_WINDOW_SHOWN,
        OPENGL       = SDL_WINDOW_OPENGL,
        RESIZABLE    = SDL_WINDOW_RESIZABLE
    };

    Window(const char* p_name, uint32_t p_width, uint32_t p_height, int p_flags, bool p_imGuiEnabled);
    ~Window();

    void imGuiCreate();
    void imGuiRender();
    void clear(Color p_color);
    void render();
    void windowDraw();
    void update();
    void handleEvents(); 

    bool isOpen();
    SDL_Window*   getWindow()   const;
    SDL_Renderer* getRenderer() const;
    void getVersion();

private:
    /* Methods */
    bool initWindow();    
    bool initRenderer();
    bool initImgui();

    void close();
    
    /* Variables */
    SDL_Window*    m_Window = NULL;
    SDL_Renderer*  m_Renderer = NULL;
    const char*    m_Name;
    unsigned int   m_Width, m_Height;
    int            m_RenderFlags = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
    int            m_WindowFlags;
    bool           m_Running, m_ImGuiEnabled;
};

#endif /* WINDOW_H */