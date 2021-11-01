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

Mat2& Mat2::multiply(const Mat2& other){
    int sum = 0;

    Mat2 aux = *this;

    for(int k = 0; k < 2; k++){
        for(int i = 0; i < 2; i++){
            for(int j =0 ; j < 2; j++){
                //std::cout << elements[j + k * 2] << " * " << other.elements[i + j * 2] << std::endl;
                sum += aux.elements[j + k * 2] * other.elements[i + j * 2];
            }

            elements[i + k * 2] = sum;
            sum = 0;
        }
    }

    return *this;
}

Mat2 operator*(Mat2 left, const Mat2& right){
    return left.multiply(right);
}

Mat2& Mat2::operator*=(const float& k){
    for(int i = 0; i < 4; i++){
        elements[i] *= k;
    }

    return *this;
}

Mat2& Mat2::operator/=(const float& k){
    if(k == 0){
        Logger::getInstance()->log(Logger::WARNING, "dividing by 0, setting all the elements to 0");

        for(int i = 0; i < 4; i++){
            elements[i] = 0;
        }
    }
    else{
        for(int i = 0; i < 4; i++){
            elements[i] /= k;
        }
    }

    return *this;
}