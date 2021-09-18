#include "gameObject.h"

void GameObject::load(int p_x, int p_y, int p_width, int p_height, std::string p_textureID){
    m_X = p_x;
    m_Y = p_y;

    m_Width  = p_width;
    m_Height = p_height;

    m_TextureID = p_textureID;

    m_CurrentRow   = 1;
    m_CurrentFrame = 1;
}

void GameObject::draw(SDL_Renderer* p_renderer){
    TextureManager::getInstance()->drawFrame(
        m_TextureID,
        m_X,
        m_Y,
        m_Width,
        m_Height,
        m_CurrentRow,
        m_CurrentFrame,
        p_renderer,
        SDL_FLIP_NONE
    );
}