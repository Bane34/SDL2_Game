#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL_render.h>

#include "IObject.h"
#include "../maths/maths.h"

struct Properties{
    Properties(const std::string& p_textureID, const float& p_x, const float& p_y, const int& p_width, const int& p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE){
        m_TextureID = p_textureID;
        x = p_x;
        width = p_width;
        height = p_height;
        flip = p_flip;
    }

    std::string textureID;
    int width, height;
    float x, y;
    SDL_RendererFlip flip; 
};

class GameObject: public IObject{
public:
    GameObject() {}

    virtual void draw() = 0;
    virtual void update(float p_dt) = 0;
    virtual void clean() = 0;

protected:
    Mat4* m_Transform;
    int m_Width, m_Height;
    std::string m_TextureID;
    SDL_RendererFlip m_Flip; 
private:
};

#endif /* GAMEOBJECT_H */