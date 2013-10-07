#ifndef QUANTUM_MATH_H
#define QUANTUM_MATH_H

class Vector2D;
class Vector3D;

namespace Math
{

float InverseSquareRoot(float number);
float SquareRoot(float x);
int Max(int a, int b);
int Min(int a, int b);

float Normalize(float start, float end, float current);

// ===========================================================================
// Interpolation
// ===========================================================================
// Interpolation functions
namespace Interpolation
{
typedef enum
{
    Linear,
    EasyIn,
    EasyOut,
    EasyInEasyOut
}Type;

float LinearFunction(float x);
float EasyInFunction(float x);
float EasyOutFunction(float x);
float EasyInEasyOutFunction(float x);

}

float Interpolate(Interpolation::Type type, float start, float end, float time);
Vector2D Interpolate(Interpolation::Type type, Vector2D start, Vector2D end, float time);


}

#endif  // QUANTUM_MATH_H
