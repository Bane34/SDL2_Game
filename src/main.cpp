#include "window.h"
#include "textureManager.h"

int main(int argc, char** argv){
    int flags = WINDOW_SHOWN | OPENGL | RESIZABLE;

    Window window("SDL window", 640, 480, flags);
    Color color = {0xFF, 0xFF, 0xFF, 0xFF};
    
    while(window.isOpen()){
        window.handleEvents();
        
        window.clear(color);
        window.render();
        window.update();
        window.windowDraw();
    }

    return 0;
}