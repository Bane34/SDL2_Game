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
    m_WindowFlags  = flags;

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

void Window::clear(Color p_color) {
    SDL_SetRenderDrawColor(m_Renderer, p_color.r, p_color.g, p_color.b, p_color.a);
    SDL_RenderClear(m_Renderer);
}

void Window::render(){

}

void Window::windowDraw(){
    SDL_RenderPresent(m_Renderer);
}

void Window::update(){

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

SDL_Window* Window::getWindow() const{
    return m_Window;
}

SDL_Renderer* Window::getRenderer() const{
    return m_Renderer;
}


void Window::getVersion(){
    SDL_version compiled;
    SDL_version linked;

    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);

    printf("We compiled against SDL version %d.%d.%d ...\n",
       compiled.major, compiled.minor, compiled.patch);
    printf("But we are linking against SDL version %d.%d.%d.\n",
       linked.major, linked.minor, linked.patch);
}

bool Window::initWindow(){
    m_Window = SDL_CreateWindow(
        m_Name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        m_Width,
        m_Height,
        m_WindowFlags
    );

    return (m_Window)? true : false;
}

bool Window::initRenderer(){
    m_Renderer = SDL_CreateRenderer(m_Window, -1, m_RenderFlags);

    if(!m_Renderer)
        return false;

    return true;
}

void Window::close(){
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);

    SDL_Quit();
    IMG_Quit();
}