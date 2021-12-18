#include "core/window.h"
#include "maths/maths.h"

#include "object/IObject.h"
#include "object/gameObject.h"

int main(int, char**){    
    Window window("Test", 1280, 720, Window::OPENGL | Window::WINDOW_SHOWN, true);

    window.getVersion();

    Vec4 clearColor = Vec4(0.45f, 0.55f, 0.60f, 1.00f);
    
    while(window.isOpen()){
        window.handleEvents();

        window.imGuiCreate();
        {
            ImGui::Begin("Color changer");
            ImGui::Text("Usefull text");
            ImGui::ColorEdit3("clear color", (float*) &clearColor);
            ImGui::NewLine();
            ImGui::Text("Application aveage %.3f ms/frame (%.1f FPS)", 1000.f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
        window.imGuiRender();

        window.clear({(uint8_t) (clearColor.x * 255), (uint8_t) (clearColor.y * 255), (uint8_t) (clearColor.z *  255), (uint8_t) (clearColor.w * 255)});
        window.render();
        window.windowDraw();
    }

    return 0;
}