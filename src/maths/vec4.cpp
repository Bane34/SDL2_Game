#include "vec4.h"   

Vec4::Vec4(){
    x = 0.f;
    y = 0.f;
    z = 0.f;
    w = 0.f;
}

Vec4::Vec4(const float& p_x, const float& p_y, const float& p_z, const float& p_w){
    x = p_x;
    y = p_y;
    z = p_z;
    w = p_w;
}

Vec4& Vec4::add(const Vec4& p_other){
    x = x + p_other.x;
    y = y + p_other.y;
    z = z + p_other.z;
    w = w + p_other.w;

    return *this;
}

Vec4& Vec4::substract(const Vec4& p_other){
    x = x - p_other.x;
    y = y - p_other.y;
    z = z - p_other.z;
    w = w - p_other.w;
    
    return *this;
}

Vec4 operator+(Vec4 left, const Vec4& right){
    return left.add(right);
}

Vec4 operator-(Vec4 left, const Vec4& right){
    return left.substract(right); 
}

Vec4 Vec4::operator*(const float& k){
    x = x * k;
    y = y * k;
    z = z * k;
    w = w * k;

    return *this;
}

Vec4 Vec4::operator/(const float& k){
    if(k == 0.f)
        printf("Cant divide by 0\n");
    else{
        x = x / k;
        y = y / k;
        z = z / k;
        w = w / k;
    }

    return *this;
}

Vec4 Vec4::operator+=(const Vec4& other){
    return this->add(other);
}

Vec4 Vec4::operator-=(const Vec4& other){
    return this->substract(other);
}

bool Vec4::operator==(const Vec4& other){
    return (x == other.x && y == other.y && z == other.z && w == other.w)? true : false;
}

bool Vec4::operator!=(const Vec4& other){
    return (x != other.x || y != other.y || z != other.z || w != other.w)? true : false;
}

std::ostream& operator<<(std::ostream& stream, const Vec4& vector){
    stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")\n";

    return stream;
}