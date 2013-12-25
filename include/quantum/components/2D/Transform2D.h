#ifndef QUANTUM_TRANSFORM2D_H
#define QUANTUM_TRANSFORM2D_H

#include "quantum/components/Component.h"
#include "quantum/Vector2.h"

namespace components2D
{

class Transform2D : public components::Component
{
public:
    Transform2D(GameObject& owner);
    ~Transform2D();

    void                setPosition(float x, float y);
    void                setPosition(const Vector2& position);
    void                setScale(float x, float y);
    void                setScale(const Vector2& scale);
    void                setRotation(float angle);

    Vector2             getPosition();
    Vector2             getRelativePosition();

    Vector2             getScale();
    Vector2             getRelativeScale();

    float               getRotation();
    float               getRelativeRotation();

    void                move(const Vector2& movement);
    void                rescale(const Vector2& scaleFactor);
    void                rotate(float angle);
    void                lookAt(const float x, const float y);
    void inline         lookAt(Vector2& point) { return lookAt(point.getX(), point.getY()); }

private:
    Vector2             position;
    Vector2             scale;
    float               rotation;

};

}

#endif // QUANTUM_TRANSFORM2D_H
