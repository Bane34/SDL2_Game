#include "core/window.h"
#include "maths/maths.h"

#include "object/IObject.h"
#include "object/gameObject.h"

int main(int, char**){    
    Window window("Test", 1280, 720, flags::OPENGL | flags::WINDOW_SHOWN);

    window.getVersion();

    while(window.isOpen()){
        window.handleEvents();

        window.imGuiCreate();
        ImGui::ShowDemoWindow();
        window.imGuiRender();

        window.clear({0xFF, 0xFF, 0xFF, 0xFF});
        window.render();
        window.windowDraw();
    }

    return 0;
}