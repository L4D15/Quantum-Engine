#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <Artemis/Artemis.h>

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

    template<typename c>
        inline artemis::Component*      GetComponent() { return entity.getComponent<c>(); }

    inline void                         AddComponent(artemis::Component* component) { entity.addComponent(component);}

private:
    GameObject(std::string name, artemis::Entity& entity);

private:
    artemis::Entity&                    entity;
    std::string                         name;
    std::string                         currentTag;
    GameObject*                         parent;
};

#endif // GAMEOBJECT_H
