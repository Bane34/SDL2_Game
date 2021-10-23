#include "gameObject.h"

void GameObject::load(float p_x, float p_y, int p_width, int p_height, std::string p_fileName, std::string p_textureID, SDL_Renderer* p_renderer){
    m_X = p_x;
    m_Y = p_y;

    m_Width  = p_width;
    m_Height = p_height;

    m_FileName  = p_fileName;
    m_TextureID = p_textureID;

    m_Renderer = p_renderer;

    m_CurrentRow   = 1;
    m_CurrentFrame = 1;

    TextureManager::getInstance()->load(m_FileName, m_TextureID, p_renderer);
}

void GameObject::draw(){
    TextureManager::getInstance()->drawFrame(
        m_TextureID,
        m_X,
        m_Y,
        m_Width,
        m_Height,
        m_CurrentRow,
        m_CurrentFrame,
        m_Renderer,
        SDL_FLIP_NONE
    );
}

void GameObject::update(){
    m_CurrentFrame = int((SDL_GetTicks() / 500) % 4);
}

void GameObject::updateXY(const Vec2& p_vector){
    m_X = m_X + p_vector.x;
    m_Y = m_Y + p_vector.y;
}