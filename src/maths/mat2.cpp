#include "mat2.h"

Mat2::Mat2(){
    for (int i = 0; i < 2 * 2; i++){
        elements[i] = 0.f;
    }
}

Mat2::Mat2(Vec2 p_diagonal){
    for (int i = 0; i < 2 * 2; i++){
        elements[i] = 0.f;
    }

    elements[0 + 0 * 2] = p_diagonal.x;
    elements[1 + 1 * 2] = p_diagonal.y;
}

Mat2::Mat2(Vec2 p_row1, Vec2 p_row2) {
    elements[0 + 0 * 2] = p_row1.x;
    elements[1 + 0 * 2] = p_row1.y;
    elements[0 + 1 * 2] = p_row2.x;
    elements[1 + 1 * 2] = p_row2.y;
}

Mat2 Mat2::identity(){
    return Mat2({1, 1});
}

Mat2 Mat2::scale(float p_scaleFactor){
    return Mat2({p_scaleFactor, p_scaleFactor});
}

Mat2 Mat2::rotation(float p_angle){
    float radAngle = (p_angle * 3.141592654f ) / 180.f;

    Mat2 retMat;
    retMat.elements[0 + 0 * 2] = cos(radAngle);
    retMat.elements[1 + 0 * 2] = sin(radAngle);
    retMat.elements[0 + 1 * 2] = -sin(radAngle);
    retMat.elements[1 + 1 * 2] = cos(radAngle);

    return retMat;
}

Mat2 Mat2::shear(Vec2 p_vec){
    Mat2 retMat({1, 1});

    retMat.elements[0 + 0 * 2] = p_vec.x;
    retMat.elements[1 + 1 * 2] = p_vec.y;

    return retMat;
}       

std::ostream& operator<<(std::ostream& stream, const Mat2& mat){
    for(int i = 0; i < 4; i++){
        if(i % 2 != 0)
            stream << mat.elements[i] << "|\n";
        else
            stream << "|" << mat.elements[i] << ", ";
    }

    return stream;
}