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

    void                setPosition(float x, float y);
    void                setPosition(const Vector2D& position);
    void                setScale(float x, float y);
    void                setScale(const Vector2D& scale);
    void                setRotation(float angle);

    Vector2D            getPosition();
    Vector2D            getRelativePosition();

    Vector2D            getScale();
    Vector2D            getRelativeScale();

    float               getRotation();
    float               getRelativeRotation();

    void                move(const Vector2D& movement);
    void                rescale(const Vector2D& scaleFactor);
    void                rotate(float angle);

private:
    Vector2D            position;
    Vector2D            scale;
    float               rotation;

};

}

#endif // QUANTUM_TRANSFORM2D_H
