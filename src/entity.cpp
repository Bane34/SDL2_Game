#include "entity.h"

Entity::Entity(SDL_Texture* texture, float xpos, float ypos){
    gTexture = texture;
    gX = xpos;
    gY = ypos;
    
    gCurrentFrame.x = 0;
    gCurrentFrame.y = 0;
    gCurrentFrame.w = 32;
    gCurrentFrame.h = 32;
}

Entity::~Entity(){

}

float Entity::getX(){
    return gX;
}

float Entity::getY(){
    return gY;
}

SDL_Texture* Entity::getTexture(){
    return gTexture;
}

SDL_Rect Entity::getCurrentFrame(){
    return gCurrentFrame;
}