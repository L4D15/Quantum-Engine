#include "quantum/components/2D/BoxCollider.h"
#include "quantum/components/2D/AssetRenderer.h"

using namespace components2D;

BoxCollider::BoxCollider(GameObject& owner) :
    Collisions(owner)
{
    // Check if there is an asset renderer attached to automatically set width and height
    AssetRenderer* rendererComp;

    rendererComp = (AssetRenderer*) owner.getComponent<AssetRenderer>();

    if (rendererComp != NULL)
    {
        this->width = rendererComp->getRenderizableAsset()->getWidth();
        this->height = rendererComp->getRenderizableAsset()->getHeight();
    }
    else
    {
        // If no asset attached, make the box 1x1
        this->width = 1.0f;
        this->height = 1.0f;
    }

    // Check owner has a Collisions component. If not, add it
    Collisions* collisionsComp;

    collisionsComp = (Collisions*) owner.getComponent<Collisions>();

    if (collisionsComp == NULL)
    {
        owner.addComponent(new Collisions(owner));
    }
}
