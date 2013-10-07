#include "quantum/Math.h"
#include "quantum/Vector2D.h"
#include "quantum/Vector3D.h"
#include <cmath>
#include <iostream>

/**
 Inverse Square root.
 * @param number    Number to calculate the inverse square root.
 * @return          Inverse square root of the number.
 */
float Math::InverseSquareRoot(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

/**
 Square root.
 @param x   Number to calculate the square root.
 @return    Square root of the number.
 */
float Math::SquareRoot(float x) {
    const float xhalf = 0.5f*x;

    union // get bits for floating value
    {
        float x;
        int i;
    } u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
    return x*u.x*(1.5f - xhalf*u.x*u.x);// Newton step, repeating increases accuracy
}

/**
 * @brief max
 * @param a
 * @param b
 * @return
 */
int Math::Max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

/**
 * @brief min
 * @param a
 * @param b
 * @return
 */
int Math::Min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

/**
 * @brief Math::Normalize
 * @param start
 * @param end
 * @param current
 * @return
 */
float Math::Normalize(float start, float end, float current)
{
    return (current - start) / (end - start);
}

// ===========================================================================
// Interpolation
// ===========================================================================
/**
 * @brief Math::Interpolate
 * @param type
 * @param start
 * @param end
 * @param current   Normalized time (commonly currentTime/finalTime)
 * @return
 */
float Math::Interpolate(Interpolation::Type type, float start, float end, float time)
{
    switch (type) {
    case Interpolation::Linear:
        return (start + (end - start) * Interpolation::LinearFunction(time));
        break;
    case Interpolation::EasyIn:
        return (start + (end - start) * Interpolation::EasyInFunction(time));
        break;
    case Interpolation::EasyOut:
        return (start + (end - start) * Interpolation::EasyOutFunction(time));
        break;
    case Interpolation::EasyInEasyOut:
        return (start + (end - start) * Interpolation::EasyInEasyOutFunction(time));
        break;
    default:
        return 0.0f;
        break;
    }
}

float Math::Interpolation::LinearFunction(float x)
{
    return x;
}

float Math::Interpolation::EasyInFunction(float x)
{
    return x * x;
}

float Math::Interpolation::EasyOutFunction(float x)
{
    return sin(x * Math::PI / 2.0f);
}

float Math::Interpolation::EasyInEasyOutFunction(float x)
{
    return (x * x) / ((x *x) + ((1-x) * (1-x)));
}

/**
 * @brief Math::Interpolate
 * @param type
 * @param start
 * @param end
 * @param time
 * @return
 */
Vector2D Math::Interpolate(Interpolation::Type type, Vector2D start, Vector2D end, float time)
{
    float x;
    float y;

    x = Interpolate(type, start.GetX(), end.GetX(), time);
    y = Interpolate(type, start.GetY(), end.GetY(), time);

    return Vector2D(x, y);
}
