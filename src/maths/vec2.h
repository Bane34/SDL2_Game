#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

struct Vec2{
    float x, y;

    Vec2();
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
    Vec2& normalize();
    static Vec2 getNormal(const float& p_x, const float& p_y);
};

typedef Vec2 v2;

#endif /* VEC2_H */