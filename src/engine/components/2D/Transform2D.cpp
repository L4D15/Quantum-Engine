#include "quantum/components/2D/Transform2D.h"
#include "quantum/GameObject.h"

using namespace Components;

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

void Transform2D::SetPosition(float x, float y)
{
    this->position.SetX(x);
    this->position.SetY(y);
}

void Transform2D::SetPosition(const Vector2D &position)
{
    this->position = position;
}

void Transform2D::SetScale(float x, float y)
{
    this->scale.SetX(x);
    this->scale.SetY(y);
}

void Transform2D::SetScale(const Vector2D &scale)
{
    this->scale = scale;
}

void Transform2D::SetRotation(float angle)
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
Vector2D Transform2D::GetPosition()
{
    Vector2D globalPosition(this->position);

    GameObject* parent;
    parent = owner.GetParentObject();

    while (parent != NULL)
    {
        Transform2D* parentTransform = (Transform2D*)parent->GetComponent<Transform2D>();
        globalPosition = globalPosition + parentTransform->GetPosition();

        // Advance up to the parent of the parent
        parent = parent->GetParentObject();
    }

    return globalPosition;
}

/**
 * @brief Relative position. If the object does not have a parent this is the global position.
 * @return  Relative position to the parent (the Window if no parent is set for the object).
 */
Vector2D Transform2D::GetRelativePosition()
{
    return this->position;
}

/**
 * @brief Get the total scale.
 *
 * This applies any scale from the parent objects.
 * @return
 */
Vector2D Transform2D::GetScale()
{
    Vector2D totalScale(this->scale);

    GameObject* parent;
    parent = owner.GetParentObject();

    while (parent != NULL)
    {
        Transform2D* parentTransform = (Transform2D*)parent->GetComponent<Transform2D>();
        totalScale = totalScale + parentTransform->GetScale();

        // Advance up to the parent of the parent
        parent = parent->GetParentObject();
    }
    return totalScale;
}

/**
 * @brief Get the relative scale.
 *
 * If the object does not have a parent this is equal to GetScale().
 * @return  Relative scale of the object.
 */
Vector2D Transform2D::GetRelativeScale()
{
    return this->scale;
}

/**
 * @brief Transform2D::GetRotation
 * @return
 */
float Transform2D::GetRotation()
{
   float totalRotation;
   totalRotation = this->rotation;

   GameObject* parent;
   parent = owner.GetParentObject();

   while (parent != NULL)
   {
       Transform2D* parentTransform = (Transform2D*)parent->GetComponent<Transform2D>();
       totalRotation = totalRotation + parentTransform->GetRotation();

       // Advance up to the parent of the parent
       parent = parent->GetParentObject();
   }
   return totalRotation;
}

/**
 * @brief Transform2D::GetRelativeRotation
 * @return
 */
float Transform2D::GetRelativeRotation()
{
    return this->rotation;
}

/**
 * @brief Updates the objects position.
 * @param movement  Vector that will be added to the position vector.
 */
void Transform2D::Move(const Vector2D &movement)
{
    this->position = this->position + movement;
}

/**
 * @brief Transform2D::Scale
 * @param scaleFactor
 */
void Transform2D::Scale(const Vector2D& scaleFactor)
{
   this->scale = this->scale + scaleFactor;
}

/**
 * @brief Transform2D::Rotate
 * @param angle
 */
void Transform2D::Rotate(float angle)
{
    this->rotation = this->rotation + angle;
}
