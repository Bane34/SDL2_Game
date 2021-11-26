#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

struct Vec4{
    float x, y, z, w;

    Vec4();
    Vec4(const float& p_x, const float& p_y, const float& p_z, const float& p_w);

    Vec4& add(const Vec4& p_other);
    Vec4& substract(const Vec4& p_other);
    
    friend Vec4 operator+(Vec4 left, const Vec4& right);
    friend Vec4 operator-(Vec4 left, const Vec4& right);

    // We multiply or divide a vector with an scalar !!NOT TO VECTORS, ONLY A SCALAR!!
    Vec4 operator*(const float& k);
    Vec4 operator/(const float& k);

    Vec4 operator+=(const Vec4& other);
    Vec4 operator-=(const Vec4& other);

    bool operator==(const Vec4& other);
    bool operator!=(const Vec4& other);

    friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);

    float length();
    Vec4& normalize();
    static Vec4 getNormal(const float& p_x, const float& p_y);
};

/// Alias for Vec4 (4 dimensional vectors)
using v4 = Vec4;

#endif /* VEC4_H */