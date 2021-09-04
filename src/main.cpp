#include "window.h"

int main(int argc, char** argv){
    Window window("SDL engine", 0, 0); // 0 and 0 for the default dimensions

    while(window.isOpen()){
        window.update();
        window.clear();
    }

    return 0;
}