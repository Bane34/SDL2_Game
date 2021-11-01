#include "textureManager.h"

bool TextureManager::load(std::string p_fileName, std::string p_id, SDL_Renderer* p_renderer){
    SDL_Surface* pTempSurface = IMG_Load(p_fileName.c_str());

    if(!pTempSurface)
        return false;

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(p_renderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if(pTexture != 0){
        m_TextureMap[p_id] = pTexture;
        return true;
    }

    return false;
}

void TextureManager::draw(std::string p_id, int p_x, int p_y, int p_width, int p_height, SDL_Renderer* p_renderer, SDL_RendererFlip p_flip = SDL_FLIP_NONE){
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = p_width;
    srcRect.h = destRect.h = p_height;
    destRect.x = p_x;
    destRect.y = p_y;

    SDL_RenderCopyEx(p_renderer, m_TextureMap[p_id], &srcRect, &destRect, 0, 0, p_flip);
}

void TextureManager::drawFrame(std::string p_id, int p_x, int p_y, int p_width, int p_height, int p_currentRow, int p_currentFrame, SDL_Renderer* p_renderer, SDL_RendererFlip p_flip = SDL_FLIP_NONE){
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = p_width * p_currentFrame;
    srcRect.y = p_height * (p_currentRow - 1);
    srcRect.w = destRect.w = p_width;
    srcRect.h = destRect.h = p_height;
    destRect.x = p_x;
    destRect.y = p_y;

    SDL_RenderCopyEx(p_renderer, m_TextureMap[p_id], &srcRect, &destRect, 0, 0, p_flip);

}

void TextureManager::dropTexture(std::string p_id){
    SDL_DestroyTexture(m_TextureMap[p_id]);
    m_TextureMap.erase(p_id);
}