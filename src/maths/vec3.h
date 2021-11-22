#ifndef VEC3_H
#define VEC3_H

#include <ostream>
#include <stdio.h>
#include <cmath>

struct Vec3{
    float x, y, z;

    Vec3();
    Vec3(const float& p_x, const float& p_y, const float& p_z);

    Vec3& add(const Vec3& p_other);
    Vec3& substract(const Vec3& p_other);
    
    friend Vec3 operator+(Vec3 left, const Vec3& right);
    friend Vec3 operator-(Vec3 left, const Vec3& right);

    // We multiply or divide a vector with an scalar !!NOT TO VECTORS, ONLY A SCALAR!!
    Vec3 operator*(const float& k);
    Vec3 operator/(const float& k);

    Vec3 operator+=(const Vec3& other);
    Vec3 operator-=(const Vec3& other);

    bool operator==(const Vec3& other);
    bool operator!=(const Vec3& other);

    friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

    float length();
    Vec3& normalize();
    static Vec3 getNormal(const float& p_x, const float& p_y, const float& p_z);
};

typedef Vec3 v3;

#endif /* VEC3_H */