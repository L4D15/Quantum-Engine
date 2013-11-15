#ifndef QUANTUM_PHYSICS_COMPONENT_H
#define QUANTUM_PHYSICS_COMPONENT_H

#include "quantum/components/Component.h"
#include "quantum/Vector2.h"

namespace components2D
{

class Physics : public components::Component
{
public:
    Physics(GameObject& owner);
    ~Physics();

    void                    setVelocity(float x, float y);
    void                    setVelocity(Vector2& v);
    void                    setAceleration(float x, float y);
    void                    setAceleration(Vector2& a);
    void                    setRotationVelocity(float x, float y);
    void                    setRotationVelocity(Vector2& v);
    void                    setRotationAceleration(float x, float y);
    void                    setRotationAceleration(Vector2& v);
    void                    setMass(float value);
    void                    setLinearDrag(float value);
    void                    setAngularDrag(float value);
    void                    setGravityScale(float value);
    void                    setKinematic(bool value);

    inline Vector2          getVelocity() { return velocity; }
    inline Vector2          getAceleration() { return aceleration; }
    inline Vector2          getRotationVelocity() { return rotationVelocity; }
    inline Vector2          getRotationAceleration() { return rotationAceleration; }
    inline float            getMass() { return mass; }
    inline float            getLinearDrag() { return linearDrag; }
    inline float            getAngularDrag() { return angularDrag; }
    inline float            getGravityScale() { return gravityScale; }

    void                    addVelocity(float x, float y);
    void                    addVelocity(Vector2& v);
    void                    addAceleration(float x, float y);
    void                    addAceleration(Vector2& a);
    void                    addRotationVelocity(float x, float y);
    void                    addRotationVelocity(Vector2& v);
    void                    addRotationAceleration(float x, float y);
    void                    addRotationAceleration(Vector2& v);

    void                    update();

private:
    Vector2                 velocity;
    Vector2                 aceleration;

    Vector2                 rotationVelocity;
    Vector2                 rotationAceleration;

    float                   mass;           // Mass that will be used for gravity
    float                   linearDrag;     // Resistance to linear forces
    float                   angularDrag;    // Resistance to rotational forces
    float                   gravityScale;   // Strenght of the gravity
    bool                    isKinematic;
};

}


#endif // QUANTUM_PHYSICS_COMPONENT_H
