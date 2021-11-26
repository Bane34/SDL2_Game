#include "vec3.h"

Vec3::Vec3(){
    x = 0.f;
    y = 0.f;
    z = 0.f;
}

Vec3::Vec3(const float& p_x, const float& p_y, const float& p_z){
    x = p_x;
    y = p_y;
    z = p_z;
}

Vec3& Vec3::add(const Vec3& p_other){
    x += p_other.x;
    y += p_other.y;
    z += p_other.z;

    return *this;
}

Vec3& Vec3::substract(const Vec3& p_other){
    x -= p_other.x;
    y -= p_other.y;
    z -= p_other.z;

    return *this;
}

Vec3 operator+(Vec3 left, const Vec3& right){
    return left.add(right);
}

Vec3 operator-(Vec3 left, const Vec3& right){
    return left.substract(right);
}

Vec3 Vec3::operator*(const float& k){
    x = x * k;
    y = y * k;
    z = z * k;

    return *this;
}

Vec3 Vec3::operator/(const float& k){
    if(k == 0.f)
        printf("Cant divide by 0\n");
    else{
        x = x / k;
        y = y / k;
        z = z / k;
    }

    return *this;
}

Vec3 Vec3::operator+=(const Vec3& other){
    return this->add(other);
}

Vec3 Vec3::operator-=(const Vec3& other){
    return this->substract(other);
}

bool Vec3::operator==(const Vec3& other){
    return (x == other.x && y == other.y && z == other.z)? true : false;
}

bool Vec3::operator!=(const Vec3& other){
    return (x != other.x || y != other.y || z != other.z)? true : false;
}

std::ostream& operator<<(std::ostream& stream, const Vec3& vector){
    stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")\n";

    return stream;
}

float Vec3::length(){
    return sqrt(x * x + y * y + z * z);
}

Vec3& Vec3::normalize(){
    float length = this->length();

    x /= length;
    y /= length;
    z /= length;

    return *this;
}

Vec3 Vec3::getNormal(const float& p_x, const float& p_y, const float& p_z){
    Vec3 retVec(p_x, p_y, p_z);
    return (retVec / retVec.length());
}