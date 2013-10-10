#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "quantum/Scene.h"
#include <map>
#include <SDL2/SDL.h>

namespace Systems2D {

class SceneManager {
public:
    SceneManager();
    virtual ~SceneManager();

    void                                OnEvent(SDL_Event* event);
    void                                OnLoop();
    void                                OnRender();

    Scene*                              ChangeToScene(std::string sceneName);
    void                                AddScene(Scene* scene);
    void                                DeleteScene(std::string sceneName);

private:
    Scene*                              currentScene;
    std::map<std::string, Scene* >      sceneMapper;
};
}

#endif // SCENEMANAGER_H
