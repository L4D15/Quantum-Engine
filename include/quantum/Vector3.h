#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string>

class Vector2;

class Vector3
{
public:
    Vector3();
    Vector3(float x, float y);
    Vector3(float x, float y, float z);
    Vector3(const Vector3& other);
    ~Vector3();

    Vector3&            operator=(const Vector3& other);
    Vector3             operator+(const Vector3& other);
    Vector3             operator-(const Vector3& other);
    Vector3             operator*(const Vector3& other);
    Vector3             operator*(const float f);
    bool                operator!=(const Vector3& other);
    bool                operator==(const Vector3& other);
    float               dotProduct(const Vector3& other);

    inline float        getX() { return x; }
    inline float        getY() { return y; }
    inline float        getZ() { return z; }

    float               getLengthQuadratic();
    float               getLength();
    float               distanceQuadratic(const Vector3& other);
    float               distance(const Vector3& other);

    Vector3             normalized();

    Vector2             toVector2D();

    std::string         toString();

private:
    float               x;
    float               y;
    float               z;
};

#endif // VECTOR3D_H
