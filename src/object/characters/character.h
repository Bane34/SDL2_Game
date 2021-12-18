#ifndef CHARACTER_H
#define CHARACTER_H

#include "../gameObject.h"

class Character: public GameObject {
public:
    Character(const std::string& p_textureID, const Vec3& p_position, const int& p_width, const int& p_height, SDL_RendererFlip p_flip = SDL_FLIP_NONE): GameObject(p_textureID, p_position, p_width, p_height, p_flip) {}
    virtual ~Character();

    virtual void draw() = 0;
    virtual void clean() = 0;
    virtual void update(float dt) = 0;
protected:
    std::string m_Name;
};

#endif /* CHARACTER_H */