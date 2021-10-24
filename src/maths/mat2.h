#ifndef MAT2_H
#define MAT2_H

#include "vector.h"

#include <cmath>
#include <iostream>


struct Mat2 {
    float elements[2 * 2];

    Mat2();
    Mat2(Vec2 p_diagonal);
    Mat2(Vec2 p_row1, Vec2 p_row2);

    static Mat2 identity(); 
    static Mat2 scale(float p_scaleFactor);
    static Mat2 rotation(float p_angle);
    static Mat2 shear(Vec2 p_vec);
    
    friend std::ostream& operator<<(std::ostream& stream, const Mat2& mat);
    
    //--- NOT IMPLEMENTED ---//
    // TODO: Implement this

    Mat2& multiply(const Mat2& p_other);

    friend Mat2 operator*(Mat2 left, const Mat2& right);
    friend Mat2 operator/(Mat2 left, const Mat2& right);

};

#endif /* MAT2_H */