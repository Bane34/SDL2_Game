#ifndef VECTOR_H
#define VECTOR_H

#include <SDL2/SDL_stdinc.h>
#include <iostream>

struct Vec2{
    float x, y;

    Vec2() = default;
    Vec2(const float& p_x, const float& p_y);

    Vec2& add(const Vec2& p_other);
    Vec2& substract(const Vec2& p_other);
    
    friend Vec2 operator+(Vec2 left, const Vec2& right);
    friend Vec2 operator-(Vec2 left, const Vec2& right);

    // We multiply or divide a vector with an scalar !!NOT TO VECTORS, ONLY A SCALAR!!
    Vec2 operator*(const float& k);
    Vec2 operator/(const float& k);

    Vec2 operator+=(const Vec2& other);
    Vec2 operator-=(const Vec2& other);

    bool operator==(const Vec2& other);
    bool operator!=(const Vec2& other);

    friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

    float length();
    Vec2& makeUnitary();
    static Vec2 getUnitary(float p_x, float p_y);
};

#endif /* VECTOR_H */