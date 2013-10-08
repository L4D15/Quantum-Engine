#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "quantum/Libraries.h"
#include "quantum/Vector2D.h"
#include "quantum/Vector3D.h"

// Prototype
class Scene;

class GameObject {
    // We add Scene as a friend class so it can access the constructor and destructor
    friend class Scene;
public:
    void                                SetTag(std::string tagName);
    inline std::string                  GetTag() { return currentTag; }

    inline std::string                  GetName() { return name; }

    inline void                         MakeChildOfObject(GameObject* parent) { this->parent = parent; }
    inline void                         UnmakeChildOfObject() { this->parent = NULL; }
    inline GameObject*                  GetParentObject() { return this->parent; }

    Vector2D                            GetPosition2D();
    Vector2D                            GetRelativePosition2D();

    void                                SetPosition(float x, float y);

    template<typename c>
        inline artemis::Component*      GetComponent() { return entity.getComponent<c>(); }

    void                         AddComponent(artemis::Component* component) { entity.addComponent(component); entity.refresh();}

private:
    GameObject(std::string name, artemis::Entity& entity);

private:
    artemis::Entity&                    entity;
    std::string                         name;
    std::string                         currentTag;
    GameObject*                         parent;
};

#endif // GAMEOBJECT_H
