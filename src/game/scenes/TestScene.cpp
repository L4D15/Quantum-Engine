#include "TestScene.h"
#include "quantum/Game.h"
#include "quantum/Math.h"

TestScene::TestScene() :
    Scene("Test Scene")
{

}

TestScene::~TestScene()
{

}

void TestScene::OnActivate()
{
    initialPos1.SetX(20.0f);
    initialPos1.SetY(20.0f);

    initialPos2.SetX(20.0f);
    initialPos2.SetY(60.0f);

    initialPos3.SetX(20.0f);
    initialPos3.SetY(100.0f);

    initialPos4.SetX(20.0f);
    initialPos4.SetY(140.0f);

    finalPos1.SetX(500.0f);
    finalPos1.SetY(20.0f);

    finalPos2.SetX(500.0f);
    finalPos2.SetY(60.0f);

    finalPos3.SetX(500.0f);
    finalPos3.SetY(100.0f);

    finalPos4.SetX(500.0f);
    finalPos4.SetY(140.0f);

    this->initialTime = Game::GetTime();
    this->duration = 1000;

    this->movement.SetX(100);
}

void TestScene::OnDeactivate()
{

}

void TestScene::OnLoop()
{

    if (Game::GetTime() < this->initialTime + this->duration)
    {
        pos1 = Math::Interpolate(Math::Interpolation::Linear, initialPos1, finalPos1, Math::Normalize(this->initialTime, this->initialTime + this->duration, Game::GetTime()));
        pos2 = Math::Interpolate(Math::Interpolation::EasyIn, initialPos2, finalPos2, Math::Normalize(this->initialTime, this->initialTime + this->duration, Game::GetTime()));
        pos3 = Math::Interpolate(Math::Interpolation::EasyOut, initialPos3, finalPos3, Math::Normalize(this->initialTime, this->initialTime + this->duration, Game::GetTime()));
        pos4 = Math::Interpolate(Math::Interpolation::EasyInEasyOut, initialPos4, finalPos4, Math::Normalize(this->initialTime, this->initialTime + this->duration, Game::GetTime()));
    }
}

void TestScene::OnRender()
{

    SDL_Rect rect1;
    SDL_Rect rect2;
    SDL_Rect rect3;
    SDL_Rect rect4;
    SDL_Rect field;

    rect1.x = pos1.GetX();
    rect1.y = pos1.GetY();
    rect1.w = 20;
    rect1.h = 20;

    rect2.x = pos2.GetX();
    rect2.y = pos2.GetY();
    rect2.w = 20;
    rect2.h = 20;

    rect3.x = pos3.GetX();
    rect3.y = pos3.GetY();
    rect3.w = 20;
    rect3.h = 20;

    rect4.x = pos4.GetX();
    rect4.y = pos4.GetY();
    rect4.w = 20;
    rect4.h = 20;

    field.x = 20;
    field.y = 20;
    field.w = 500;
    field.h = 140;

    Uint8 red, green, blue, alpha;

    SDL_GetRenderDrawColor(Game::window->GetRenderer(), &red, &green, &blue, &alpha);

    // Draw field
    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 0, 255, 0, 255);
    SDL_RenderDrawRect(Game::window->GetRenderer(), &field);
    SDL_RenderDrawLine(Game::window->GetRenderer(), 120, 20, 120, 160);
    SDL_RenderDrawLine(Game::window->GetRenderer(), 220, 20, 220, 160);
    SDL_RenderDrawLine(Game::window->GetRenderer(), 320, 20, 320, 160);
    SDL_RenderDrawLine(Game::window->GetRenderer(), 420, 20, 420, 160);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 255, 0, 0, 255);
    SDL_RenderDrawRect(Game::window->GetRenderer(), &rect1);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 0, 0, 255, 255);
    SDL_RenderDrawRect(Game::window->GetRenderer(), &rect2);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 255, 0, 255, 255);
    SDL_RenderDrawRect(Game::window->GetRenderer(), &rect3);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), 0, 255, 255, 255);
    SDL_RenderDrawRect(Game::window->GetRenderer(), &rect4);

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), red, green, blue, alpha);
}


void TestScene::OnKeyDown(SDL_Keycode key, Uint16 mod)
{
    switch (key)
    {
    case SDLK_ESCAPE:
        Game::Terminate();
        break;
    }
}
