#ifndef QUANTUM_MATH_H
#define QUANTUM_MATH_H

#include <cmath>

class Vector2D;
class Vector3D;
class Color;

namespace math
{

static double PI = atan(1) * 4;

float inverseSquareRoot(float number);
float squareRoot(float x);
int max(int a, int b);
int min(int a, int b);

float Normalize(float start, float end, float current);

// ===========================================================================
// Interpolation
// ===========================================================================
// Interpolation functions
namespace interpolation
{
typedef enum
{
    Linear,
    EasyIn,
    EasyOut,
    EasyInEasyOut,
    Boomerang
}Type;

float linearFunction(float x);
float easyInFunction(float x);
float easyOutFunction(float x);
float easyInEasyOutFunction(float x);
float boomerangFunction(float x);

}

float interpolate(interpolation::Type type, float start, float end, float time);
Vector2D interpolate(interpolation::Type type, Vector2D start, Vector2D end, float time);
Color interpolate(interpolation::Type type, Color start, Color end, float time);

}

#endif  // QUANTUM_MATH_H
