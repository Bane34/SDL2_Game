#include "entity.h"

Entity::Entity(SDL_Texture* texture, float xpos, float ypos, float w, float h){
    gTexture = texture;
    gX = xpos;
    gY = ypos;
    
    gCurrentFrame.x = 0;
    gCurrentFrame.y = 0;
    gCurrentFrame.w = w;
    gCurrentFrame.h = h;
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

void Entity::update(){
    gCurrentFrame.x = 32 * int((SDL_GetTicks() / 1000) % 4);
}