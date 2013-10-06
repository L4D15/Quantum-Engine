#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "quantum/EventListener.h"
#include <Artemis/Artemis.h>
#include "quantum/GameObject.h"
#include <map>

class Scene : public EventListener {
public:
    Scene(std::string name);
    virtual ~Scene();

    virtual void                        OnActivate();
    virtual void                        OnDeactivate();

    virtual void                        OnLoop();
    virtual void                        OnRender() = 0;
    GameObject*                         CreateGameObject(std::string name);
    void                                DestroyGameObject(GameObject*& object);
    void                                DestroyGameObject(std::string name);

    inline std::string                  GetName() { return name; }

    inline GameObject*                  GetMainCamera() { return mainCamera; }
    inline void                         SetMainCamera(GameObject* camera) { mainCamera = camera; }

protected:
    std::string                         name;   // Name of the Scene
    GameObject*                         mainCamera; // Main camera of the scene

public:
    artemis::World*                     world;  // Artemis systems container

    std::map<std::string, GameObject* > objectsMapping;

};

#endif // SCENE_H
