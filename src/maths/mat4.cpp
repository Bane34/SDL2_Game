#include "mat4.h"

Mat4::Mat4(){
    for (int i = 0; i < 4 * 4; i++){
        elements[i] = 0.f;
    }
}

Mat4::Mat4(float p_escalar){
    for(int i = 0; i < 4 * 4; i++)
        elements[i] = 0.f;
    
    elements[0 + 0 * 4] = p_escalar;
    elements[1 + 1 * 4] = p_escalar;
    elements[2 + 2 * 4] = p_escalar;
    elements[3 + 3 * 4] = p_escalar; 
}

Mat4::Mat4(Vec4 p_diagonal){
    for (int i = 0; i < 4 * 4; i++){
        elements[i] = 0.f;
    }
    
    elements[0 + 0 * 4] = p_diagonal.x;
    elements[1 + 1 * 4] = p_diagonal.y;
    elements[2 + 2 * 4] = p_diagonal.z;
    elements[3 + 3 * 4] = p_diagonal.w; 
}

Mat4::Mat4(Vec4 p_row1, Vec4 p_row2, Vec4 p_row3, Vec4 p_row4) {   
    rows[0] = p_row1;
    rows[1] = p_row2;
    rows[2] = p_row3;
    rows[3] = p_row4;
}

Mat4 Mat4::identity(){
    return Mat4({1, 1, 1, 1});
}

Mat4 Mat4::translation(const Vec3& p_translation){
    Mat4 result(1.f);
    
    result.elements[3 + 0 * 4] = p_translation.x;
    result.elements[3 + 1 * 4] = p_translation.y;
    result.elements[3 + 2 * 4] = p_translation.z;

    return result;
}

Mat4& Mat4::multiply(const Mat4& p_other){
    int sum = 0;

    Mat4 aux = *this;

    for(int k = 0; k < 4; k++){
        for(int i = 0; i < 4; i++){
            for(int j =0 ; j < 4; j++){
                //std::cout << elements[j + k * 2] << " * " << other.elements[i + j * 2] << std::endl;
                sum += aux.elements[j + k * 4] * p_other.elements[i + j * 4];
            }

            elements[i + k * 4] = sum;
            sum = 0;
        }
    }

    return *this;
}

Mat4& Mat4::transpose(){
    Mat4 aux = *this;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            elements[j + i * 4] = aux.elements[i + j * 4];
        }
    }

    return *this;
}

Mat4& Mat4::translate(const Vec3& p_translation){
    elements[3 + 0 * 4] = p_translation.x;
    elements[3 + 1 * 4] = p_translation.y;
    elements[3 + 2 * 4] = p_translation.z;

    return *this;
}

Mat4 operator*(Mat4 left, const Mat4& right){
    return left.multiply(right);
}

Mat4& Mat4::operator*(const float& k){
    for(int i = 0; i < 16; i++)
        elements[i] *= k;
    
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Mat4& mat){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j == 3)
                stream << mat.elements[j + i * 4]; 
            else
            stream << mat.elements[j + i * 4] << ", "; 

        }

        std::cout << "\n";
    }

    return stream;
}

Mat4& Mat4::operator*=(const float& k){
    for(int i = 0; i < 16; i++){
        elements[i] *= k;
    }

    return *this;
}

Mat4& Mat4::operator/=(const float& k){
    if(k == 0){
        Logger::getInstance()->log(Logger::WARNING, "dividing by 0, setting all the elements to 0");

        for(int i = 0; i < 16; i++){
            elements[i] = 0;
        }
    }
    else{
        for(int i = 0; i < 16; i++){
            elements[i] /= k;
        }
    }

    return *this;
}