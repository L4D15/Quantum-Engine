#include "quantum/components/2D/Transform2D.h"
#include "quantum/GameObject.h"

using namespace components2D;

Transform2D::Transform2D(GameObject &owner) :
    Component(owner),
    position(0.0f, 0.0f),
    scale(1.0f, 1.0f),
    rotation(0.0f)
{

}

Transform2D::~Transform2D()
{

}

void Transform2D::setPosition(float x, float y)
{
    this->position.setX(x);
    this->position.setY(y);
}

void Transform2D::setPosition(const Vector2D &position)
{
    this->position = position;
}

void Transform2D::setScale(float x, float y)
{
    this->scale.setX(x);
    this->scale.setY(y);
}

void Transform2D::setScale(const Vector2D &scale)
{
    this->scale = scale;
}

void Transform2D::setRotation(float angle)
{
    this->rotation = angle;
}

/**
 * @brief Return the global position.
 *
 * This uses the parent to calculate the real global position. If the object
 * has no parent then this will return the same result as GetRelativePosition().
 * @return  Global position on the screen.
 */
Vector2D Transform2D::getPosition()
{
    Vector2D globalPosition(this->position);

    GameObject* parent;
    parent = owner.getParentObject();

    while (parent != NULL)
    {
        Transform2D* parentTransform = (Transform2D*)parent->getComponent<Transform2D>();
        globalPosition = globalPosition + parentTransform->getPosition();

        // Advance up to the parent of the parent
        parent = parent->getParentObject();
    }

    return globalPosition;
}

/**
 * @brief Relative position. If the object does not have a parent this is the global position.
 * @return  Relative position to the parent (the Window if no parent is set for the object).
 */
Vector2D Transform2D::getRelativePosition()
{
    return this->position;
}

/**
 * @brief Get the total scale.
 *
 * This applies any scale from the parent objects.
 * @return
 */
Vector2D Transform2D::getScale()
{
    Vector2D totalScale(this->scale);

    GameObject* parent;
    parent = owner.getParentObject();

    while (parent != NULL)
    {
        Transform2D* parentTransform = (Transform2D*)parent->getComponent<Transform2D>();
        totalScale = totalScale + parentTransform->getScale();

        // Advance up to the parent of the parent
        parent = parent->getParentObject();
    }
    return totalScale;
}

/**
 * @brief Get the relative scale.
 *
 * If the object does not have a parent this is equal to GetScale().
 * @return  Relative scale of the object.
 */
Vector2D Transform2D::getRelativeScale()
{
    return this->scale;
}

/**
 * @brief Transform2D::GetRotation
 * @return
 */
float Transform2D::getRotation()
{
   float totalRotation;
   totalRotation = this->rotation;

   GameObject* parent;
   parent = owner.getParentObject();

   while (parent != NULL)
   {
       Transform2D* parentTransform = (Transform2D*)parent->getComponent<Transform2D>();
       totalRotation = totalRotation + parentTransform->getRotation();

       // Advance up to the parent of the parent
       parent = parent->getParentObject();
   }
   return totalRotation;
}

/**
 * @brief Transform2D::GetRelativeRotation
 * @return
 */
float Transform2D::getRelativeRotation()
{
    return this->rotation;
}

/**
 * @brief Updates the objects position.
 * @param movement  Vector that will be added to the position vector.
 */
void Transform2D::move(const Vector2D &movement)
{
    this->position = this->position + movement;
}

/**
 * @brief Transform2D::Scale
 * @param scaleFactor
 */
void Transform2D::rescale(const Vector2D& scaleFactor)
{
   this->scale = this->scale + scaleFactor;
}

/**
 * @brief Transform2D::Rotate
 * @param angle
 */
void Transform2D::rotate(float angle)
{
    this->rotation = this->rotation + angle;
}
