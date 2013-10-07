#include "quantum/components/Component.h"

using namespace Components;

Component::Component(GameObject &owner) :
    owner(owner)
{

}

GameObject& Component::GetOwner()
{
    return owner;
}
