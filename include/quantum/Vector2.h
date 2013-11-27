#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>

class Vector3;

class Vector2 {
public:
    Vector2();
    Vector2(float getX, float getY);
    Vector2(const Vector2& orig);
    ~Vector2();

    Vector2&            operator=(const Vector2& vector);
    Vector2             operator+(const Vector2& vector);
    Vector2             operator*(float f);
    Vector2             operator-(const Vector2& vector);
    bool                operator!=(const Vector2& vector);
    bool                operator==(const Vector2& vector);
    float               dotProduct(const Vector2& vector);
    Vector2             operator*(const Vector2& vector);

    inline float        getX() { return x; }
    inline float        getY() { return y; }

    inline void         setX(float x) { this->x = x; }
    inline void         setY(float y) { this->y = y; }

    float               getLengthQuadratic();
    float               getLength();
    float               distanceQuadratic(const Vector2& vector);
    float               distance(const Vector2& vector);

    Vector2             normalized();

    Vector3             toVector3D();

    std::string         toString();

private:
    float               x;
    float               y;

};

#endif	/* VECTOR2D_H */

