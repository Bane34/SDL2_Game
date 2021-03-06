#include "vec2.h"

Vec2::Vec2(){
    x = 0.f;
    y = 0.f;
}

Vec2::Vec2(const float& p_x, const float& p_y){
    x = p_x;
    y = p_y;
}

Vec2& Vec2::add(const Vec2& p_other){
    x = x + p_other.x;
    y = y + p_other.y;

    return *this;
}

Vec2& Vec2::substract(const Vec2& p_other){
    x = x - p_other.x;
    y = y - p_other.y;

    return *this;
}

Vec2 operator+(Vec2 left, const Vec2& right){
    return left.add(right);
}

Vec2 operator-(Vec2 left, const Vec2& right){
    return left.substract(right);
}

Vec2 Vec2::operator*(const float& k){
    x = x * k;
    y = y * k;

    return *this;
}

Vec2 Vec2::operator/(const float& k){
    if(k == 0.f)
        printf("Cant divide by 0\n");
    else {
        x = x / k;
        y = y / k;
    }

    return *this;
}

Vec2 Vec2::operator+=(const Vec2& other){
    return this->add(other);
}

Vec2 Vec2::operator-=(const Vec2& other){
    return this->substract(other);
}

bool Vec2::operator==(const Vec2& other){
    return (x == other.x && y == other.y);
}

bool Vec2::operator!=(const Vec2& other){
    return (x != other.x && y != other.y);
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector){
    stream << "(" << vector.x << ", " << vector.y << ")\n";

    return stream;
}

float Vec2::length(){
    return sqrt(x * x + y * y);
}

Vec2& Vec2::normalize(){
    float length = this->length();

    x = x / length;
    y = y / length;

    return *this;
}

Vec2 Vec2::getNormal(const float& p_x, const float& p_y){
    Vec2 retVec(p_x, p_y);
    return (retVec / retVec.length());
}