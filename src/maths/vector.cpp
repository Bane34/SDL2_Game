#include "vectors.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(const float& p_x, const float& p_y){
    x = p_x;
    y = p_y;
}

Vec2& Vec2::add(const Vec2& p_other){
    x = x + p_other.x;
    y = y + p_other.y;

    return *this;
}

Vec2& Vec2::substract(const Vec2& p_other){
    x = x - p_other.x;
    y = y - p_other.y;

    return *this;
}

Vec2 operator+(Vec2 left, const Vec2& right){
    return left.add(right);
}

Vec2 operator-(Vec2 left, const Vec2& right){
    return left.substract(right);
}

bool Vec2::operator==(const Vec2& other){
    return (x == other.x && y == other.y);
}

bool Vec2::operator!=(const Vec2& other){
    return (x != other.x && y != other.y);
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector){
    stream << "(" << vector.x << ", " << vector.y << ")\n";

    return stream;
}

float Vec2::length(){
    return SDL_sqrt(x * x + y * y);
}