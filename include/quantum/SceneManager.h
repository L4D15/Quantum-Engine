#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "quantum/Scene.h"
#include <map>
#include <SDL2/SDL.h>

namespace systems2D {

class SceneManager {
public:
    SceneManager();
    virtual ~SceneManager();

    void onEvent(SDL_Event* event);
    void onLoop();
    void onRender();

    Scene* changeToScene(std::string sceneName);
    void addScene(Scene* scene);
    void deleteScene(std::string sceneName);

    inline Scene* getCurrentScene() { return currentScene; }

private:
    Scene* currentScene;
    std::map<std::string, Scene* > sceneMapper;
};
}

#endif // SCENEMANAGER_H
