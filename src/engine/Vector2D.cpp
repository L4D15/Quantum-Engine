#include "quantum/Vector2D.h"
#include <sstream>
#include "quantum/ExtraTools.h"
#include "quantum/Vector3D.h"

/**
 Default constructor. Coordinates are set to 0.
 */
Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

/**

 @param x     X coordinate.
 @param y     Y coordinate.
 */
Vector2D::Vector2D(float x, float y)
: x(x), y(y) {

}

/**
 Copy constructor.
 @param orig  Vector to copy.
 */
Vector2D::Vector2D(const Vector2D& orig) {
    x = orig.x;
    y = orig.y;
}

/**
 Destructor.
 */
Vector2D::~Vector2D() {

}

/**
 Assignment operator.
 @param vector  Vector to copy values from.
 @return        Final vector.
 */
Vector2D& Vector2D::operator =(const Vector2D& vector) {
    x = vector.x;
    y = vector.y;
    return *this;
}

/**
 Sum operator.
 @param vector  Vector to sum with this one.
 @return        Final vector.
 */
Vector2D Vector2D::operator +(const Vector2D& vector) {
    return Vector2D(x + vector.x, y + vector.y);
}

/**
 Resizes vector by a factor.
 @param f   Resize factor.
 @return    Vector resized.
 */
Vector2D Vector2D::operator *(float f) {
    return Vector2D(x * f,y * f);
}

/**
 Subtraction operator.
 @param vector  Vector to subtrate from.
 @return        Final vector.
 */
Vector2D Vector2D::operator -(const Vector2D& vector) {
    return Vector2D(x - vector.x, y - vector.y);
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if the vector aren't equal, false otherwise.
 */
bool Vector2D::operator !=(const Vector2D &vector) {
    return x - vector.x != 0.0f || y - vector.y != 0.0f;
}

/**
 Comparison operator.
 @param vector  Vector to compare with.
 @return        true if they are equal, false otherwise.
 */
bool Vector2D::operator ==(const Vector2D &vector) {
    return x - vector.x == 0.0f && y - vector.y == 0.0f;
}

/**
 Perform the dot product of two vectors.
 @param vector  The other vector to operate with.
 @return        Value resulting of the operation.
 */
float Vector2D::dotProduct(const Vector2D &vector) {
    float result = 0.0;

    result += this->x * vector.x;
    result += this->y * vector.y;

    return result;
}

Vector2D Vector2D::operator *(const Vector2D& vector) {
    return Vector2D(this->x + vector.x, this->y + vector.y);
}

/**
 Length of the vector (without applying the square root to the result).
 @return    Quadratic length.
 */
float Vector2D::GetLengthQuadratic() {
    return (x * x + y * y);
}

/**
 Length fo the vector.
 @return    Length.
 */

float Vector2D::GetLength() {
    return Math::SquareRoot(x * x + y * y);
}

/**
 Quadratic distance to other vector.
 @param vector    The other vector.
 @return          Quadratic distance.
 */
float Vector2D::DistanceQuadratic(const Vector2D& vector) {
    float Ax,Ay;

    Ax = x - vector.x;
    Ay = y - vector.y;

    return (Ax*Ax + Ay*Ay);
}

/**
 Distance to other vector.
 @param vector      The other vector.
 @return            Distante to the other vector.
 */
float Vector2D::Distance(const Vector2D& vector) {
    float Ax,Ay;

    Ax = x - vector.x;
    Ay = y - vector.y;

    return Math::SquareRoot(Ax*Ax + Ay*Ay);
}

/**
 Normalizes the vector to values between 0 and 1.
 */
Vector2D Vector2D::Normalized() {
    Vector2D normalized;
    float lengthsq = (x * x + y * y);

    if(lengthsq == 0) {
        normalized.x = 0.0f;
        normalized.y = 0.0f;
        return normalized;
    }

    float recip = Math::InverseSquareRoot(lengthsq);
    normalized.x *= recip;
    normalized.y *= recip;

    return normalized;
}

Vector3D Vector2D::ToVector3D()
{
    return Vector3D(this->x, this->y, 0.0f);
}

/**
 Format the values of the vector to represent it as a string.
 @return    String with the forma (x,y).
 */
std::string Vector2D::ToString() {
    std::stringstream str;

    str << "(" << x << "," << y << ")";

    return str.str();
}
