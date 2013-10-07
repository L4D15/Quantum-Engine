#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>

class Vector3D;

class Vector2D {
public:
    Vector2D();
    Vector2D(float GetX, float GetY);
    Vector2D(const Vector2D& orig);
    ~Vector2D();

    Vector2D&                   operator=(const Vector2D& vector);
    Vector2D                    operator+(const Vector2D& vector);
    Vector2D                    operator*(float f);
    Vector2D                    operator-(const Vector2D& vector);
    bool                        operator!=(const Vector2D& vector);
    bool                        operator==(const Vector2D& vector);
    float                       dotProduct(const Vector2D& vector);
    Vector2D                    operator*(const Vector2D& vector);

    inline float                GetX() { return x; }
    inline float                GetY() { return y; }

    inline void                 SetX(float x) { this->x = x; }
    inline void                 SetY(float y) { this->y = y; }

    float                       GetLengthQuadratic();
    float                       GetLength();
    float                       DistanceQuadratic(const Vector2D& vector);
    float                       Distance(const Vector2D& vector);

    Vector2D                    Normalized();

    Vector3D                    ToVector3D();

    std::string                 ToString();

private:
    float                       x;
    float                       y;

};

#endif	/* VECTOR2D_H */

