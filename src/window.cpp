#include "window.h"

Window::Window(const char* p_name, uint32_t p_width, uint32_t p_height, int flags){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Could not init SDL! SDL_ERROR: %s\n", SDL_GetError());
        return;
    }

    if(!IMG_Init(IMG_INIT_PNG)){
        printf("Could not init IMG_PNG! IMG_Error: %s\n", IMG_GetError());
        return;
    }
    
    m_Name   = p_name;
    m_Width  = p_width;
    m_Height = p_height;
    m_Flags  = flags;

    if(!initWindow()){
        printf("Could not create the window! SDL_ERROR: %s\n", SDL_GetError());
        return;
    }

    if(!initRenderer()){
        printf("Could not create the renderer! SDL_ERROR: %s\n", SDL_GetError());
        return;
    }

    m_Running = true;
    printf("Window working!\n");
}

Window::~Window(){
    close();
}

void Window::clear(Color p_color){
    SDL_SetRenderDrawColor(m_Renderer, p_color.r, p_color.g, p_color.b, p_color.a);
    SDL_RenderClear(m_Renderer);
}

void Window::render(){
    m_TextureManager.load("images/sprite_sheet.png", "animate", m_Renderer);
    //m_TextureManager.draw("animate", 0, 0, 64, 256, m_Renderer, SDL_FLIP_NONE);
    m_TextureManager.drawFrame("animate", 100, 100, 64, 256, 1, m_CurrentFrame, m_Renderer, SDL_FLIP_NONE);
}

void Window::windowDraw(){
    SDL_RenderPresent(m_Renderer);
}

void Window::update(){
    m_CurrentFrame = int((SDL_GetTicks() / 500) % 4);
}

void Window::handleEvents(){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
                m_Width  = event.window.data1;
                m_Height = event.window.data2;
            }
            break;
        default:
            continue;
        }
    }
}

bool Window::isOpen(){
    return m_Running;
}

SDL_Window* Window::getWindow(){
    return m_Window;
}

SDL_Renderer* Window::getRenderer(){
    return m_Renderer;
}

bool Window::initWindow(){
    m_Window = SDL_CreateWindow(
        m_Name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        m_Width,
        m_Height,
        m_Flags
    );

    if(!m_Window)
        return false;

    return true;
}

bool Window::initRenderer(){
    m_Renderer = SDL_CreateRenderer(
        m_Window,
        -1,
        0
    );

    if(!m_Renderer)
        return false;

    return true;
}

void Window::close(){
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);

    SDL_Quit();
    IMG_Quit();
}