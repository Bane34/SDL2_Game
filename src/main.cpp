#include "window.h"
#include "renderer.h"

int main(int argc, char** argv){
    Window window("SDL test", 0, 0);
    Renderer renderer(window.getWindow());

    SDL_Texture* texture1 = renderer.loadSprite("images/stickman.png");

    while(window.isOpen()){
        window.update();
        renderer.clear();
        renderer.drawSprite(texture1, 100, 100, 107, 240);
    }

    renderer.destroyTexture(texture1);

    return 0;
}