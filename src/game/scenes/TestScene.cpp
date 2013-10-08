#include "TestScene.h"
#include "quantum/Game.h"
#include "quantum/Math.h"

TestScene::TestScene() :
    Scene("Test Scene")
{
    // This Scene will have a Physics system
    this->physicsSystem = (Systems2D::Physics*) AddSystem(new Systems2D::Physics());

    // Objects
    object = CreateGameObject("Object");
    object->AddComponent(new Components2D::Physics(*object));
    object->SetPosition(Game::window->GetWidth()/2 - 50, Game::window->GetHeight()/2 - 50);

    child = CreateGameObject("Child");
    child->SetPosition(100, 100);
}

TestScene::~TestScene()
{

}

void TestScene::OnActivate()
{
    this->initialTime = Game::GetTime();
    this->duration = 5000;
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
    Uint8 red, green, blue, alpha;

    SDL_GetRenderDrawColor(Game::window->GetRenderer(), &red, &green, &blue, &alpha);

    // Render
    Vector2D pos;
    SDL_Rect rect;

    pos = object->GetPosition2D();
    rect.x = pos.GetX();
    rect.y = pos.GetY();
    rect.w = 100;
    rect.h = 100;

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 255, 0, 255, 255);
    SDL_RenderFillRect(Game::window->GetRenderer(), &rect);

    rect.x = child->GetPosition2D().GetX();
    rect.y = child->GetPosition2D().GetY();
    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 0, 0, 0, 255);
    SDL_RenderFillRect(Game::window->GetRenderer(), &rect);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), red, green, blue, alpha);
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

    case SDLK_1:
        if (child->GetParentObject() == NULL)
        {
            child->MakeChildOfObject(object);
        }
        else
        {
            child->UnmakeChildOfObject();
        }
        break;

    case SDLK_2:
        child->SetPosition(100, 100);
        break;
    }
}
