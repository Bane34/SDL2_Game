#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL_render.h>

#include "IObject.h"
#include "../maths/maths.h"

class GameObject: public IObject{
public:
    GameObject(const std::string& p_textureID, const Vec3& p_position, const int& p_width, const int& p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE){
        m_TextureID = p_textureID;
        m_Width     = p_width;
        m_Height    = p_height;
        m_Flip      = p_flip;
        
        m_Transform = new Mat4(1.f);
        m_Transform->elements[3 + 0 * 4] = p_position.x;
        m_Transform->elements[3 + 1 * 4] = p_position.y;
        m_Transform->elements[3 + 2 * 4] = p_position.z;
    }

    ~GameObject(){
        delete m_Transform;
    }

    virtual void draw() = 0;
    virtual void update(float p_dt) = 0;
    virtual void clean() = 0;
protected:
    Mat4* m_Transform;
    int m_Width, m_Height;
    std::string m_TextureID;
    SDL_RendererFlip m_Flip; 
};

#endif /* GAMEOBJECT_H */