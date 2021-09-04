#include "window.h"
#include "renderer.h"
#include "sprite.h"

int main(int argc, char** argv){
    Window window("SDL test", 0, 0);
    Renderer renderer(window.getWindow());

    Sprite sprite1;
    sprite1.texture = renderer.loadSprite("images/stickman.png");

    while(window.isOpen()){
        window.update();
        renderer.clear();
        renderer.drawSprite(sprite1, 100, 100, 107, 240);

        renderer.draw();
    }

    renderer.destroyTexture(sprite1.texture);

    return 0;
}