#include "quantum/SceneManager.h"

using namespace systems2D;

SceneManager::SceneManager()
{
    this->currentScene = NULL;
}

SceneManager::~SceneManager()
{

}

void SceneManager::onEvent(SDL_Event* event)
{
    this->currentScene->onEvent(event);
}

void SceneManager::onRender()
{
    this->currentScene->onRender();
}

void SceneManager::onLoop()
{
    this->currentScene->world->loopStart();
    this->currentScene->onLoop();
}

/**
 * @brief SceneManager::addScene
 * @param scene
 */
void SceneManager::addScene(Scene *scene)
{
    if (scene != NULL)
    {
        std::pair<std::string, Scene* > mappedObject(scene->getName(), scene);

        this->sceneMapper.insert(mappedObject);
    }
}

/**
 * @brief SceneManager::changeScene
 * @param sceneName
 * @return
 */
Scene* SceneManager::changeToScene(std::string sceneName)
{
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end())
    {
        if (this->currentScene != NULL)
        {
            this->currentScene->onDeactivate();
        }

        this->currentScene = mappedScene->second;

        this->currentScene->onActivate();
        return this->currentScene;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief SceneManager::deleteScene
 * @param sceneName
 */
void SceneManager::deleteScene(std::string sceneName)
{
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end())
    {
        delete mappedScene->second;
        this->sceneMapper.erase(mappedScene);
    }
}
