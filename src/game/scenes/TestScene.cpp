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
    this->initialTime = Game::GetTime();
    this->duration = 5000;

    this->initialColor = presetcolors::LightPurple;
    this->finalColor = presetcolors::Orange;
}

void TestScene::OnDeactivate()
{

}

void TestScene::OnLoop()
{
    currentColor = Math::Interpolate(Math::Interpolation::Boomerang, initialColor, finalColor,
                                     Math::Normalize(this->initialTime, this->initialTime + this->duration, Game::GetTime()));
    if (currentColor == initialColor)
    {
        // Reset Interpolation
        this->initialTime = Game::GetTime();
    }
}

void TestScene::OnRender()
{
    Uint8 red, green, blue, alpha;

    SDL_GetRenderDrawColor(Game::window->GetRenderer(), &red, &green, &blue, &alpha);

    // Render
    SDL_Rect rect;

    rect.x = 100;
    rect.y = 100;
    rect.w = 100;
    rect.h = 100;

    SDL_SetRenderDrawColor(Game::window->GetRenderer(), currentColor.GetRed(), currentColor.GetGreen(), currentColor.GetBlue(), currentColor.GetAlpha());
    SDL_RenderFillRect(Game::window->GetRenderer(), &rect);

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
