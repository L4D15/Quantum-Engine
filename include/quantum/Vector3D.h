#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string>

class Vector2D;

class Vector3D
{
public:
    Vector3D();
    Vector3D(float x, float y);
    Vector3D(float x, float y, float z);
    Vector3D(const Vector3D& other);
    ~Vector3D();

    Vector3D&               operator=(const Vector3D& other);
    Vector3D                operator+(const Vector3D& other);
    Vector3D                operator-(const Vector3D& other);
    Vector3D                operator*(const Vector3D& other);
    Vector3D                operator*(const float f);
    bool                    operator!=(const Vector3D& other);
    bool                    operator==(const Vector3D& other);
    float                   dotProduct(const Vector3D& other);

    inline float            getX() { return x; }
    inline float            getY() { return y; }
    inline float            getZ() { return z; }

    float                   getLengthQuadratic();
    float                   getLength();
    float                   distanceQuadratic(const Vector3D& other);
    float                   distance(const Vector3D& other);

    Vector3D                normalized();

    Vector2D                toVector2D();

    std::string             toString();

private:
    float                   x;
    float                   y;
    float                   z;
};

#endif // VECTOR3D_H
