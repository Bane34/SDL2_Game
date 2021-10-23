#include "window.h"
#include "textureManager.h"
#include "gameObject.h"
#include "maths/vector.h"
#include "utils/colors.h"
#include "utils/logger.h"

#include <iostream> // Only for printing vectors, use printf whenever is possible
#include <string>

TextureManager* TextureManager::s_pInstance = 0;

int main(int argc, char** argv){
    int flags = WINDOW_SHOWN | OPENGL | RESIZABLE;

    Window window("SDL window", 640, 480, flags);
    Color color = {0xFF, 0x00, 0xFF, 0xFF};
    
    uint64_t NOW = SDL_GetPerformanceCounter();
    uint64_t LAST = 0l;
    double deltaTime = 0;

    Vec2 vec(3.f, 4.f);

    Logger::getInstance()->logFormat(Logger::BROADCAST, "Logging with: %s", "format");
    Logger::getInstance()->log(Logger::WARNING, "Loggin without format");
    Logger::getInstance()->logFormat(Logger::DEBUG, "Vector: (%.2f, %.2f)\n", vec.x, vec.y);

    GameObject obj1;
    obj1.load(10.f, 100.f, 64, 256, "images/sprite_sheet.png", "Animate1", window.getRenderer());

    while(window.isOpen()){
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double) ( (NOW - LAST) * 1000 / (double) SDL_GetPerformanceFrequency() );
        //std::cout << "Delta time: " << deltaTime << '\n';

        window.handleEvents();
        window.clear(color);

        obj1.draw();
        obj1.updateXY({0.1f * deltaTime, 0.f});
        obj1.update();

        window.windowDraw();
    }

    return 0;
}