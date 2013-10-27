#include "quantum/components/Component.h"

using namespace components;

Component::Component(GameObject &owner) :
    owner(owner)
{

}

GameObject& Component::GetOwner()
{
    return owner;
}
