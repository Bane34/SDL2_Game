#ifndef VECTORS_H
#define VECTORS_H

#include <SDL2/SDL_stdinc.h>

struct Vector2i{
    int x, y;

    Vector2i();
    Vector2i(int p_x, int p_y);

    float length();
};

struct Vector2f{
    float x, y;

    Vector2f();
    Vector2f(float p_x, float p_y);

    float length();
};

#endif /* VECTORS_H */