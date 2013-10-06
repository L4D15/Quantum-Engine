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
    float                   DotProduct(const Vector3D& other);

    inline float            GetX() { return x; }
    inline float            GetY() { return y; }
    inline float            GetZ() { return z; }

    float                   GetLengthQuadratic();
    float                   GetLength();
    float                   DistanceQuadratic(const Vector3D& other);
    float                   Distance(const Vector3D& other);

    Vector3D                Normalized();

    Vector2D                ToVector2D();

    std::string             ToString();

private:
    float                   x;
    float                   y;
    float                   z;
};

#endif // VECTOR3D_H
