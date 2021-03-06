#include "quantum/Vector3.h"
#include "quantum/Vector2.h"
#include "quantum/Math.h"
#include <sstream>

/**
 * @brief Default constructor.
 *
 * It doesn't initialize variables to any value for efficiency.
 */
Vector3::Vector3()
{

}

/**
 * @brief Constructor for 2D spaces. The z value is set to 0.
 * @param x Horizontal coordinate.
 * @param y Vertical coordinate.
 */
Vector3::Vector3(float x, float y) :
    x(x),
    y(y),
    z(0.0f)
{

}

/**
 * @brief Constructor for 3D spaces.
 * @param x Horizontal coordinate.
 * @param y Vertical coordinate.
 * @param z Depth coordinate.
 */
Vector3::Vector3(float x, float y, float z) :
    x(x),
    y(y),
    z(z)
{

}

/**
 * @brief Copy constructor.
 * @param Reference vector to copy.
 */
Vector3::Vector3(const Vector3 &other) :
    x(other.x),
    y(other.y),
    z(other.z)
{

}

/**
 * @brief Destructor.
 */
Vector3::~Vector3()
{

}

/**
 * @brief Assignment operator.
 * @param other Vector from which assignate values.
 * @return Reference to modified vector.
 */
Vector3& Vector3::operator =(const Vector3& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;

    return (*this);
}

/**
 * @brief Sum operator.
 * @param other Vector to sum with.
 * @return  New vector with the sum's operation result.
 */
Vector3 Vector3::operator +(const Vector3& other)
{
    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

/**
 * @brief Substraction operator.
 * @param other Vector to substract from.
 * @return      Resulting vector.
 */
Vector3 Vector3::operator -(const Vector3& other)
{
    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

/**
 * @brief Scale operator.
 * @param f Scale factor.
 * @return  Result of the scaling.
 */
Vector3 Vector3::operator *(const float f)
{
    return Vector3(this->x * f, this->y * f, this->z * f);
}

/**
 * @brief Product operator.
 *
 * This multiplies each coordinate with the other vectors coordinate.
 * @param other Other vector to multiplie with.
 * @return  Resulting vector.
 */
Vector3 Vector3::operator *(const Vector3& other)
{
    return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

/**
 * @brief Comparison operator.
 * @param other Vector to compare with.
 * @return  True if the vectors and different, false if they are equal.
 */
bool Vector3::operator !=(const Vector3& other)
{
    if (this->x != other.x)
    {
        return true;
    }
    else if (this->y != other.y)
    {
        return true;
    }
    else if (this->z != other.z)
    {
        return true;
    }
    return false;
}

/**
 * @brief Comparison operator.
 * @param other Vector to compare with.
 * @return  Trie of vectors are equal, false otherwise.
 */
bool Vector3::operator ==(const Vector3& other)
{
    if (this->x != other.x)
    {
        return false;
    }
    else if (this->y != other.y)
    {
        return false;
    }
    else if (this->z != other.z)
    {
        return false;
    }
    return true;
}

/**
 * @brief Dot product.
 * @param other Vector to make the product.
 * @return Result of the dot product (x1 * x2 + y1 * y2 + z1 * z2).
 */
float Vector3::dotProduct(const Vector3 &other)
{
    return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
}

/**
 * @brief Length of the vector without applying the final square root operation.
 * @return  Length of the vector (no square root applied).
 */
float Vector3::getLengthQuadratic()
{
    return (this->x * this->x + this->y * this->y + this->z * this->z);
}

/**
 * @brief Length of the vector.
 * @return  Length of the vector.
 */
float Vector3::getLength()
{
    return math::squareRoot(x * x + y * y + z * z);
}

/**
 * @brief Distance to another vector.
 * @param other Other vector.
 * @return  Distance to another vector (square root not applied).
 */
float Vector3::distanceQuadratic(const Vector3 &other)
{
    return ((x - other.x) + (y - other.y) + (z - other.z));
}

/**
 * @brief Distance to another vector.
 * @param other Other vector to calculate distance to.
 * @return  Distance to another vector.
 */
float Vector3::distance(const Vector3 &other)
{
    return math::squareRoot((x - other.x) + (y - other.y) + (z - other.z));
}

/**
 * @brief Normalized the vector values so they range from 0.0f to 1.0f.
 * @return
 */
Vector3 Vector3::normalized()
{
    Vector3 normalized;
    float lengthsq = (x * x + y * y + z * z);

    if(lengthsq == 0) {
        normalized.x = 0.0f;
        normalized.y = 0.0f;
        normalized.z = 0.0f;
        return normalized;
    }

    float recip = math::inverseSquareRoot(lengthsq);
    normalized.x *= recip;
    normalized.y *= recip;
    normalized.z *= recip;

    return normalized;
}

/**
 * @brief Vector3D::ToVector2D
 * @return
 */
Vector2 Vector3::toVector2D()
{
    return Vector2(this->x, this->y);
}

/**
 * @brief Vector3D::ToString
 * @return
 */
std::string Vector3::toString()
{
    std::stringstream str;

    str << "(" << x << "," << y << "," << z << ")";

    return str.str();
}
