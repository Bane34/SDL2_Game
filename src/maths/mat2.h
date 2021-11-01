#ifndef MAT2_H
#define MAT2_H

#include "vector.h"
#include "../utils/logger.h"

#include <cmath>
#include <iostream>


struct Mat2 {
    union {
        float elements[2 * 2];
        Vec2  rows[2];
    };
    

    Mat2();
    Mat2(Vec2 p_diagonal);
    Mat2(Vec2 p_row1, Vec2 p_row2);

    static Mat2 identity(); 
    static Mat2 scale(float p_scaleFactor);
    static Mat2 rotation(float p_angle);
    static Mat2 shear(Vec2 p_vec);
    
    Mat2& multiply(const Mat2& p_other);
    float determinant();
    Mat2& transpose();

    friend Mat2 operator*(Mat2 left, const Mat2& right);
    friend std::ostream& operator<<(std::ostream& stream, const Mat2& mat);

    Mat2& operator*=(const float& k);
    Mat2& operator/=(const float& k);

};

#endif /* MAT2_H */