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
void GameObject::SetTag(std::string tagName)
{
    this->entity.setTag(tagName);
    this->currentTag = tagName;
}

/**
 * @brief GameObject::GetPosition2D
 * @return
 */
Vector2D GameObject::GetPosition2D()
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    return posComponent->GetPosition();
}

/**
 * @brief GameObject::GetRelativePosition2D
 * @return
 */
Vector2D GameObject::GetRelativePosition2D()
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    return posComponent->GetRelativePosition();
}

void GameObject::SetPosition(float x, float y)
{
    Components2D::Transform2D* posComponent;

    posComponent = (Components2D::Transform2D*)this->entity.getComponent<Components2D::Transform2D>();

    posComponent->SetPosition(x, y);
}
