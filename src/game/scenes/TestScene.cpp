#include "TestScene.h"
#include "quantum/Game.h"
#include "quantum/Math.h"

TestScene::TestScene() :
    Scene("Test Scene")
{
    // This Scene will have a Physics system
    this->physicsSystem = (Systems2D::Physics*) AddSystem(new Systems2D::Physics());

    // Resources
    image = new Assets2D::SpriteSheet("BG", "assets/images/bg.png");

    // Objects
    object = CreateGameObject("Object");
    object->AddComponent(new Components2D::Physics(*object));
    object->SetPosition(Game::window->GetWidth()/2 - 50, Game::window->GetHeight()/2 - 50);

}

TestScene::~TestScene()
{

}

void TestScene::OnActivate()
{

}

void TestScene::OnDeactivate()
{

}

void TestScene::OnLoop()
{
    Scene::OnLoop();

    // Process systems
    physicsSystem->process();
}

void TestScene::OnRender()
{

    Scene::OnRender();
}


void TestScene::OnKeyDown(SDL_Keycode key, Uint16 mod)
{
    Components2D::Physics* p;
    switch (key)
    {
    case SDLK_ESCAPE:
        Game::Terminate();
        break;

    case SDLK_RIGHT:
        p = (Components2D::Physics*) object->GetComponent<Components2D::Physics>();
        p->AddAceleration(5, 0);
        break;

    case SDLK_LEFT:
        p = (Components2D::Physics*) object->GetComponent<Components2D::Physics>();
        p->AddAceleration(-5, 0);
        break;
    }
}
