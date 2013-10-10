#include "quantum/SceneManager.h"

using namespace Systems2D;

SceneManager::SceneManager()
{
    this->currentScene = NULL;
}

SceneManager::~SceneManager()
{

}

void SceneManager::OnEvent(SDL_Event* event)
{
    this->currentScene->OnEvent(event);
}

void SceneManager::OnRender()
{
    this->currentScene->OnRender();
}

void SceneManager::OnLoop()
{
    this->currentScene->world->loopStart();
    this->currentScene->OnLoop();
}

/**
 * @brief SceneManager::addScene
 * @param scene
 */
void SceneManager::AddScene(Scene *scene)
{
    if (scene != NULL)
    {
        std::pair<std::string, Scene* > mappedObject(scene->GetName(), scene);

        this->sceneMapper.insert(mappedObject);
    }
}

/**
 * @brief SceneManager::changeScene
 * @param sceneName
 * @return
 */
Scene* SceneManager::ChangeToScene(std::string sceneName)
{
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end())
    {
        if (this->currentScene != NULL)
        {
            this->currentScene->OnDeactivate();
        }

        this->currentScene = mappedScene->second;

        this->currentScene->OnActivate();
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
void SceneManager::DeleteScene(std::string sceneName)
{
    std::map<std::string, Scene* >::iterator mappedScene;

    mappedScene = this->sceneMapper.find(sceneName);

    if (mappedScene != this->sceneMapper.end())
    {
        delete mappedScene->second;
        this->sceneMapper.erase(mappedScene);
    }
}
