#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "quantum/EventListener.h"
#include <Artemis/Artemis.h>
#include "quantum/GameObject.h"
#include <map>
#include <list>

class Scene : public EventListener {
public:
    Scene(std::string name);
    virtual ~Scene();

    virtual void onActivate() = 0;
    virtual void onDeactivate() = 0;

    virtual void onLoop();
    virtual void onRender();

    GameObject* createGameObject(std::string name);
    void destroyGameObject(GameObject*& object);
    void destroyGameObject(std::string name);

    artemis::EntitySystem* addSystem(artemis::EntitySystem* system);

    inline std::string getName() { return name; }
    inline GameObject* getMainCamera() { return mainCamera; }
    inline void setMainCamera(GameObject* camera) { mainCamera = camera; }
    inline std::map<std::string, GameObject* >& getObjects() { return objectsMapping; }

protected:
    void renderScene();

protected:
    std::string name;   // Name of the Scene
    GameObject* mainCamera; // Main camera of the scene

public:
    artemis::World* world;  // Artemis systems container

    std::map<std::string, GameObject* > objectsMapping;

};

#endif // SCENE_H
