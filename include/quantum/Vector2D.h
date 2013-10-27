#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>

class Vector3D;

class Vector2D {
public:
    Vector2D();
    Vector2D(float getX, float getY);
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

    inline float                getX() { return x; }
    inline float                getY() { return y; }

    inline void                 setX(float x) { this->x = x; }
    inline void                 setY(float y) { this->y = y; }

    float                       getLengthQuadratic();
    float                       getLength();
    float                       distanceQuadratic(const Vector2D& vector);
    float                       distance(const Vector2D& vector);

    Vector2D                    normalized();

    Vector3D                    toVector3D();

    std::string                 toString();

private:
    float                       x;
    float                       y;

};

#endif	/* VECTOR2D_H */

