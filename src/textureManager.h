#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

class TextureManager{
public:
    bool load(std::string p_fileName, std::string p_id, SDL_Renderer* p_renderer);
    void draw(std::string p_id, int p_x, int p_y, int p_width, int p_height, SDL_Renderer* p_renderer, SDL_RendererFlip p_flip);
    void drawFrame(std::string p_id, int p_x, int p_y, int p_width, int p_height, int p_currentRow, int p_currentFrame, SDL_Renderer* p_renderer, SDL_RendererFlip p_flip);
    void dropTexture(std::string p_id);

    static TextureManager* getInstance(){
        if(s_pInstance == 0){
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }
private:
    TextureManager() {}
    
    std::map<std::string, SDL_Texture*> m_TextureMap;

    static TextureManager* s_pInstance;
};

#endif /* TEXTUREMANAGER_H */