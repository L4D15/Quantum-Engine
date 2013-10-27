#ifndef QUANTUM_TRANSFORM2D_H
#define QUANTUM_TRANSFORM2D_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace components2D
{

class Transform2D : public components::Component
{
public:
    Transform2D(GameObject& owner);
    ~Transform2D();

    void                SetPosition(float x, float y);
    void                SetPosition(const Vector2D& position);
    void                SetScale(float x, float y);
    void                SetScale(const Vector2D& scale);
    void                SetRotation(float angle);

    Vector2D            GetPosition();
    Vector2D            GetRelativePosition();

    Vector2D            GetScale();
    Vector2D            GetRelativeScale();

    float               GetRotation();
    float               GetRelativeRotation();

    void                Move(const Vector2D& movement);
    void                Scale(const Vector2D& scaleFactor);
    void                Rotate(float angle);

private:
    Vector2D            position;
    Vector2D            scale;
    float               rotation;

};

}

#endif // QUANTUM_TRANSFORM2D_H
