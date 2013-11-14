#ifndef QUANTUM_PHYSICS_COMPONENT_H
#define QUANTUM_PHYSICS_COMPONENT_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace components2D
{

class Physics : public components::Component
{
public:
    Physics(GameObject& owner);
    ~Physics();

    void                    setVelocity(float x, float y);
    void                    setVelocity(Vector2D& v);
    void                    setAceleration(float x, float y);
    void                    setAceleration(Vector2D& a);
    void                    setRotationVelocity(float x, float y);
    void                    setRotationVelocity(Vector2D& v);
    void                    setRotationAceleration(float x, float y);
    void                    setRotationAceleration(Vector2D& v);
    void                    setMass(float value);
    void                    setLinearDrag(float value);
    void                    setAngularDrag(float value);
    void                    setGravityScale(float value);
    void                    setKinematic(bool value);

    inline Vector2D         getVelocity() { return velocity; }
    inline Vector2D         getAceleration() { return aceleration; }
    inline Vector2D         getRotationVelocity() { return rotationVelocity; }
    inline Vector2D         getRotationAceleration() { return rotationAceleration; }
    inline float            getMass() { return mass; }
    inline float            getLinearDrag() { return linearDrag; }
    inline float            getAngularDrag() { return angularDrag; }
    inline float            getGravityScale() { return gravityScale; }

    void                    addVelocity(float x, float y);
    void                    addVelocity(Vector2D& v);
    void                    addAceleration(float x, float y);
    void                    addAceleration(Vector2D& a);
    void                    addRotationVelocity(float x, float y);
    void                    addRotationVelocity(Vector2D& v);
    void                    addRotationAceleration(float x, float y);
    void                    addRotationAceleration(Vector2D& v);

    void                    update();

private:
    Vector2D                velocity;
    Vector2D                aceleration;

    Vector2D                rotationVelocity;
    Vector2D                rotationAceleration;

    float                   mass;           // Mass that will be used for gravity
    float                   linearDrag;     // Resistance to linear forces
    float                   angularDrag;    // Resistance to rotational forces
    float                   gravityScale;   // Strenght of the gravity
    bool                    isKinematic;
};

}


#endif // QUANTUM_PHYSICS_COMPONENT_H
