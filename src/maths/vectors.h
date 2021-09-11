#ifndef VECTORS_H
#define VECTORS_H

struct Vector2i{
    int x, y;

    Vector2i();
    Vector2i(int p_x, int p_y);
};

struct Vector2f{
    float x, y;

    Vector2f();
    Vector2f(float p_x, float p_y);
};

#endif /* VECTORS_H */