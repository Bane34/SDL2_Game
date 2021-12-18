#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"
#include "vec3.h"
#include "../utils/logger.h"

#include <cmath>
#include <iostream>

struct Mat4 {
    union {
        float elements[4 * 4];
        Vec4  rows[4];
    };
    
    Mat4();
    Mat4(float p_escalar);
    Mat4(Vec4 p_diagonal);
    Mat4(Vec4 p_row1, Vec4 p_row2, Vec4 p_row3, Vec4 p_row4);

    static Mat4 identity();
    static Mat4 translation(const Vec3& p_translation);
    
    Mat4& multiply(const Mat4& p_other);
    Mat4& transpose();
    Mat4& translate(const Vec3& p_translation);

    friend Mat4 operator*(Mat4 left, const Mat4& right);
    Mat4& operator*(const float& k);
    friend std::ostream& operator<<(std::ostream& stream, const Mat4& mat);

    Mat4& operator*=(const float& k);
    Mat4& operator/=(const float& k);

};

/// Alias for Mat4 (4 * 4 matrices)
using m4 = Mat4;

#endif /* MAT4_H */