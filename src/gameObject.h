#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

#include "textureManager.h"

class GameObject{
public:
    void load(int p_x, int p_y, int p_width, int p_height, std::string p_textureID);
    void draw(SDL_Renderer* p_renderer);
    void update();
    void clean();
protected:
    std::string m_TextureID;
    int m_CurrentFrame;
    int m_CurrentRow;

    int m_X, m_Y;
    int m_Height;
    int m_Width;
};

#endif /* GAMEOBJECT_H */