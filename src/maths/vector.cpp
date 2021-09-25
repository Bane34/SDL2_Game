#include "vectors.h"

Vector2i::Vector2i(){
    x = 0;
    y = 0;
}

Vector2i::Vector2i(int p_x, int p_y){
    x = p_x;
    y = p_y;
}

float Vector2i::length(){
    return SDL_sqrt(x * x + y * y);
}

Vector2f::Vector2f(){
    x = 0.f;
    y = 0.f;
}

Vector2f::Vector2f(float p_x, float p_y){
    x = p_x;
    y = p_y;
}

float Vector2f::length(){
    return SDL_sqrt(x * x + y * y);
}