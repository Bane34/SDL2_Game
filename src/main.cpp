#include "window.h"

int main(int argc, char** argv){
    int flags = WINDOW_SHOWN | OPENGL | RESIZABLE;

    Window window("SDL window", 640, 480, flags);

    while(window.isOpen()){
        window.handleEvents();
    }

    return 0;
}