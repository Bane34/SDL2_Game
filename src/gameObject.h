#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

#include "textureManager.h"
#include "maths/vectors.h"

class GameObject{
public:
    void load(float p_x, float p_y, int p_width, int p_height, std::string p_fileName, std::string p_textureID, SDL_Renderer* p_renderer);
    void draw();
    void update();
    void clean();

    void updateXY(Vec2 p_vector);
protected:
    std::string m_TextureID;
    std::string m_FileName;
    int m_CurrentFrame;
    int m_CurrentRow;

    int m_Height;
    int m_Width;

    float m_X, m_Y;

    SDL_Renderer* m_Renderer;
};

#endif /* GAMEOBJECT_H */