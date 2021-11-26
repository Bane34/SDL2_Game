#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL_render.h>

#include "IObject.h"
#include "../maths/maths.h"

struct Properties{
    Properties(const std::string& p_textureID, const float& p_x, const float& p_y, const int& p_width, const int& p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE){
        textureID = p_textureID;
        x = p_x;
        y = p_y;
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
    GameObject(Properties* p_props): m_TextureID(p_props->textureID), m_Width(p_props->width), m_Height(p_props->height), m_Flip(p_props->flip){
        m_Transform = new Mat4(1.f);
        m_Transform->elements[3 + 0 * 4] = p_props->x;
        m_Transform->elements[3 + 1 * 4] = p_props->y;
    } 

    virtual void draw() = 0;
    virtual void update(float p_dt) = 0;
    virtual void clean() = 0;

    inline void printTransform() { std::cout << m_Transform; }

protected:
    Mat4* m_Transform;
    int m_Width, m_Height;
    std::string m_TextureID;
    SDL_RendererFlip m_Flip; 
private:
};

#endif /* GAMEOBJECT_H */