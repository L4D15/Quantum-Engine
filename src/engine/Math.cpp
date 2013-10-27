#include "quantum/Math.h"
#include "quantum/Vector2D.h"
#include "quantum/Vector3D.h"
#include "quantum/Color.h"
#include <cmath>
#include <iostream>

/**
 Inverse Square root.
 * @param number    Number to calculate the inverse square root.
 * @return          Inverse square root of the number.
 */
float Math::inverseSquareRoot(float number)
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
float Math::squareRoot(float x) {
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
int Math::max(int a, int b) {
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
int Math::min(int a, int b) {
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
float Math::interpolate(Interpolation::Type type, float start, float end, float time)
{
    if (time > 1.0f)
    {
        time = 1.0f;
    }

    if (time < 0.0f)
    {
        time = 0.0f;
    }

    switch (type) {
    case Interpolation::Linear:
        return (start + (end - start) * Interpolation::linearFunction(time));
        break;

    case Interpolation::EasyIn:
        return (start + (end - start) * Interpolation::easyInFunction(time));
        break;

    case Interpolation::EasyOut:
        return (start + (end - start) * Interpolation::easyOutFunction(time));
        break;

    case Interpolation::EasyInEasyOut:
        return (start + (end - start) * Interpolation::easyInEasyOutFunction(time));
        break;

    case Interpolation::Boomerang:
        return (start + (end - start) * Interpolation::boomerangFunction(time));
        break;

    default:
        return 0.0f;
        break;
    }
}

float Math::Interpolation::linearFunction(float x)
{
    return x;
}

float Math::Interpolation::easyInFunction(float x)
{
    return x * x;
}

float Math::Interpolation::easyOutFunction(float x)
{
    return sin(x * Math::PI / 2.0f);
}

float Math::Interpolation::easyInEasyOutFunction(float x)
{
    return (x * x) / ((x *x) + ((1-x) * (1-x)));
}

float Math::Interpolation::boomerangFunction(float x)
{
    return (sin(x * Math::PI));
}

/**
 * @brief Math::Interpolate
 * @param type
 * @param start
 * @param end
 * @param time
 * @return
 */
Vector2D Math::interpolate(Interpolation::Type type, Vector2D start, Vector2D end, float time)
{
    float x;
    float y;

    x = interpolate(type, start.getX(), end.getX(), time);
    y = interpolate(type, start.getY(), end.getY(), time);

    return Vector2D(x, y);
}

/**
 * @brief Math::Interpolate
 * @param type
 * @param start
 * @param end
 * @param time
 * @return
 */
Color Math::interpolate(Interpolation::Type type, Color start, Color end, float time)
{
    float red;
    float green;
    float blue;
    float alpha;

    red = interpolate(type, start.getRed(), end.getRed(), time);
    green = interpolate(type, start.getGreen(), end.getGreen(), time);
    blue = interpolate(type, start.getBlue(), end.getBlue(), time);
    alpha = interpolate(type, start.getAlpha(), end.getAlpha(), time);

    return Color(red, green, blue, alpha);
}
