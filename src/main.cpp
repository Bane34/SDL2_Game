#include "window.h"
#include "textureManager.h"
#include "maths/vectors.h"

#include <iostream> // Only for printing vectors, use printf whenever is possible

TextureManager* TextureManager::s_pInstance = 0;

int main(int argc, char** argv){
    int flags = WINDOW_SHOWN | OPENGL | RESIZABLE;

    Window window("SDL window", 640, 480, flags);
    Color color = {0xFF, 0x00, 0xFF, 0xFF};
    
    Vec2 vec1(4, 3);
    std::cout << vec1;
    
    vec1.add({4, 3});
    std::cout << vec1;
    std::cout << "Length of vec1: " << vec1.length() << '\n';

    while(window.isOpen()){
        window.handleEvents();
        
        window.clear(color);
        window.render();
        window.update();
        window.windowDraw();
    }

    return 0;
}