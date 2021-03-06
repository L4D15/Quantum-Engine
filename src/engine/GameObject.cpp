#include "quantum/GameObject.h"
#include "quantum/Scene.h"
#include "quantum/components/ComponentsList.h"
#include "quantum/Game2D.h"


/**
 * @brief Creates a new object in the scene.
 * @param name      Name of the object.
 * @param scene     Scene the objects belong to.
 */
GameObject::GameObject(std::string name, artemis::Entity& entity):
    entity(entity)
{
    this->name = name;
    this->parent = NULL;
}

/**
 * @brief Sets the tag for the object.
 *
 * This is usually used to diferenciate between GameObjects. Common tags are "Player", "Enemy", "UI"...
 * @param tagName   Name of the tag to be applied to the object.
 */
void GameObject::setTag(std::string tagName)
{
    //this->entity.setTag(tagName);
    this->currentTag = tagName;
}

/**
 * @brief GameObject::GetPosition2D
 * @return
 */
Vector2 GameObject::getPosition2D()
{
    components2D::Transform2D* posComponent;

    posComponent = (components2D::Transform2D*)this->entity.getComponent<components2D::Transform2D>();

    return posComponent->getPosition();
}

/**
 * @brief GameObject::GetRelativePosition2D
 * @return
 */
Vector2 GameObject::getRelativePosition2D()
{
    components2D::Transform2D* posComponent;

    posComponent = (components2D::Transform2D*)this->entity.getComponent<components2D::Transform2D>();

    return posComponent->getRelativePosition();
}

/**
 * @brief GameObject::getRealPosition2D
 * @return
 */
Vector2 GameObject::getRealPosition2D()
{
    Vector2 position;
    Vector2 cameraPosition;
    int distance;

    position = this->getPosition2D();

    components2D::AssetRenderer* rendererComp;

    rendererComp = (components2D::AssetRenderer*) getComponent<components2D::AssetRenderer>();

    if (rendererComp != NULL)
    {
        cameraPosition = rendererComp->getCamera()->getPosition2D();
        distance = rendererComp->getDistance();
    }
    else
    {
        distance = Game2D::parallaxScrolling.getBackgroundDistance();
    }

    return Game2D::parallaxScrolling.applyParallaxScrolling(cameraPosition, position, distance);
}

/**
 * @brief GameObject::getRealPosition2D
 * @param offsetX
 * @param offsetY
 * @return
 */
Vector2 GameObject::getRealPosition2D(float offsetX, float offsetY)
{
    Vector2 position;
    Vector2 cameraPosition;
    int distance;

    position = this->getPosition2D() + Vector2(offsetX, offsetY);

    components2D::AssetRenderer* rendererComp;

    rendererComp = (components2D::AssetRenderer*) getComponent<components2D::AssetRenderer>();

    if (rendererComp != NULL)
    {
        cameraPosition = rendererComp->getCamera()->getPosition2D();
        distance = rendererComp->getDistance();
    }
    else
    {
        distance = Game2D::parallaxScrolling.getBackgroundDistance();
    }

    return Game2D::parallaxScrolling.applyParallaxScrolling(cameraPosition, position, distance);
}

void GameObject::setPosition(float x, float y)
{
    components2D::Transform2D* posComponent;

    posComponent = (components2D::Transform2D*)this->entity.getComponent<components2D::Transform2D>();

    posComponent->setPosition(x, y);
}

void GameObject::makeChildOfObject(GameObject *parent)
{
    this->parent = parent;

    // 2D
    components2D::Transform2D* transformParent = (components2D::Transform2D*) parent->getComponent<components2D::Transform2D>();
    components2D::Transform2D* transform = (components2D::Transform2D*) getComponent<components2D::Transform2D>();

    // Check if both objects have the Transform2D component
    if (transformParent != NULL && transform != NULL)
    {
        Vector2 parentPos = parent->getPosition2D();
        Vector2 relativePos = getRelativePosition2D() - parentPos;

        setPosition(relativePos.getX(), relativePos.getY());

        float parentRotation = transformParent->getRotation();
        float relativeRotation = transform->getRotation() - parentRotation;

        transform->setRotation(relativeRotation);
    }

    // 3D
    // TODO
}

void GameObject::unmakeChildOfObject()
{
    // 2D
    components2D::Transform2D* transform = (components2D::Transform2D*) getComponent<components2D::Transform2D>();

    if (transform != NULL)
    {
        Vector2 globalPosition;
        globalPosition = this->getPosition2D();
        setPosition(globalPosition.getX(), globalPosition.getY());
    }

    // 3D
    // TODO

    this->parent = NULL;

}
