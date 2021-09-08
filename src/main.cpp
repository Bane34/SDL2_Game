#include "window.h"
#include "renderer.h"
#include "entity.h"

int main(int argc, char** argv){
    Window window("SDL test", 0, 0);
    Renderer renderer(window.getWindow());

    Color color = {0xFF, 0xFF, 0xFF, 0xFF};
    Entity entity1(renderer.loadTexture("images/sprite_sheet.png"), 50.f, 50.f, 32, 32);

    while(window.isOpen()){
        window.handleEvents();
        renderer.clear(color);
        renderer.drawEntity(entity1);
        entity1.update();

        renderer.draw();
    }

    renderer.destroyEntity(&entity1);

    return 0;
}