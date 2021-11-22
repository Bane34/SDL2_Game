#include "core/window.h"
#include "maths/maths.h"

int main(int, char**){
    m4 position = m4::translation({0.f, 0.f, 0.f});

    std::cout << position << std::endl;

    position.translate({1, 2, 0});

    std::cout << position;
    
    Window window("Test", 640, 480, flags::OPENGL | flags::WINDOW_SHOWN);

    window.getVersion();

    while(window.isOpen()){
        window.handleEvents();

        window.clear({0xFF, 0xFF, 0xFF, 0xFF});
        window.windowDraw();
    }

    return 0;
}