#include "quantum/GameObject.h"
#include "quantum/Scene.h"
#include "quantum/components/ComponentsList.h"


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
Vector2D GameObject::getPosition2D()
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    return posComponent->GetPosition();
}

/**
 * @brief GameObject::GetRelativePosition2D
 * @return
 */
Vector2D GameObject::getRelativePosition2D()
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    return posComponent->GetRelativePosition();
}

void GameObject::setPosition(float x, float y)
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    posComponent->SetPosition(x, y);
}

void GameObject::makeChildOfObject(GameObject *parent)
{
    this->parent = parent;

    // 2D
    Components2D::Transform2D* transformParent = (Components2D::Transform2D*) parent->getComponent<Components2D::Transform2D>();
    Components2D::Transform2D* transform = (Components2D::Transform2D*) getComponent<Components2D::Transform2D>();

    // Check if both objects have the Transform2D component
    if (transformParent != NULL && transform != NULL)
    {
        Vector2D parentPos = parent->getPosition2D();
        Vector2D relativePos = getRelativePosition2D() - parentPos;

        setPosition(relativePos.getX(), relativePos.getY());

        float parentRotation = transformParent->GetRotation();
        float relativeRotation = transform->GetRotation() - parentRotation;

        transform->SetRotation(relativeRotation);
    }

    // 3D
    // TODO
}

void GameObject::unmakeChildOfObject()
{
    // 2D
    Components2D::Transform2D* transform = (Components2D::Transform2D*) getComponent<Components2D::Transform2D>();

    if (transform != NULL)
    {
        Vector2D globalPosition;
        globalPosition = this->getPosition2D();
        setPosition(globalPosition.getX(), globalPosition.getY());
    }

    // 3D
    // TODO

    this->parent = NULL;

}
