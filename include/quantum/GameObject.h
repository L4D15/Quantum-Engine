#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "quantum/Libraries.h"
#include "quantum/Vector2.h"
#include "quantum/Vector3.h"

// Prototype
class Scene;

class GameObject {
    // We add Scene as a friend class so it can access the constructor and destructor
    friend class Scene;
public:
    void                                setTag(std::string tagName);
    inline std::string                  getTag() { return currentTag; }
    inline artemis::Entity&             getEntity() { return entity; }

    inline std::string                  getName() { return name; }

    void                                makeChildOfObject(GameObject* parent);
    void                                unmakeChildOfObject();
    inline GameObject*                  getParentObject() { return this->parent; }

    Vector2                             getPosition2D();
    Vector2                             getRelativePosition2D();
    Vector2                             getRealPosition2D();
    Vector2                             getRealPosition2D(float offsetX, float offsetY);
    inline Vector2                      getRealPosition2D(Vector2& offset) { return getRealPosition2D(offset.getX(), offset.getY()); }

    void                                setPosition(float x, float y);

    template<typename c>
        inline artemis::Component*      getComponent() { return entity.getComponent<c>(); }

    void                                addComponent(artemis::Component* component) { entity.addComponent(component); entity.refresh();}

private:
    GameObject(std::string name, artemis::Entity& entity);

private:
    artemis::Entity&                    entity;
    std::string                         name;
    std::string                         currentTag;
    GameObject*                         parent;
};

#endif // GAMEOBJECT_H
