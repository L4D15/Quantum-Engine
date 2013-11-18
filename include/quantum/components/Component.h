#ifndef QUANTUM_COMPONENT_H
#define QUANTUM_COMPONENT_H

#include "quantum/Libraries.h"

class GameObject;

namespace components
{

/**
 * @brief Basic component class that abstracs the Artemis-Cpp component.
 *
 * Inherit from this class when creating your own components.
 */
class Component : public artemis::Component
{
public:
    Component(GameObject& owner);

    GameObject&             GetOwner();

    virtual std::string     toString() { }

protected:
    GameObject&             owner;
};

}

#endif // QUANTUM_COMPONENT_H
