#include "quantum/Scene.h"

Scene::Scene(std::string name):
    name(name)
{
    // Setup Artemis systems
    world = new artemis::World();

    // Create the main camera

}

Scene::~Scene()
{
    // Empty the objects mapper
    std::map<std::string, GameObject* >::iterator mappedObject;

    for (mappedObject = this->objectsMapping.begin(); mappedObject != this->objectsMapping.end(); ++mappedObject)
    {
        delete (*mappedObject).second;
    }

    this->objectsMapping.clear();

    delete this->mainCamera;
    delete this->world;
}

void Scene::OnActivate()
{

}

void Scene::OnDeactivate()
{

}

void Scene::OnLoop()
{
    world->loopStart();
}

void Scene::OnRender()
{

}

/**
 * @brief Scene::createGameObject
 * @param name
 * @return
 */
GameObject* Scene::CreateGameObject(std::string name)
{
    GameObject* object;

    artemis::Entity& objectEntity = world->createEntity();
    object = new GameObject(name, objectEntity);

    std::pair<std::string, GameObject* > objectMapped(name, object);
    this->objectsMapping.insert(objectMapped);

    return object;
}

/**
 * @brief Scene::destroyGameObject
 * @param object
 */
void Scene::DestroyGameObject(GameObject*& object)
{
    world->deleteEntity(object->entity);
    delete object;
    object = NULL;
}

/**
 * @brief Scene::destroyGameObject
 * @param name
 */
void Scene::DestroyGameObject(std::string name)
{
    std::map<std::string, GameObject* >::iterator object;

    object = this->objectsMapping.find(name);

    if (object != this->objectsMapping.end())
    {
        this->objectsMapping.erase(object);
    }
}
