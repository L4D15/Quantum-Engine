#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"
#include "quantum/Vector2D.h"
#include "quantum/Libraries.h"
#include "quantum/systems/2D/Physics.h"
#include "quantum/systems/2D/AssetRendering.h"
#include "quantum/SpriteSheet.h"
#include "quantum/AnimatedSprite.h"

class TestScene : public Scene
{
public:
    TestScene();
    ~TestScene();

    void OnActivate();

    void OnDeactivate();

    void OnRender();

    void OnLoop();

    void OnKeyDown(SDL_Keycode key, Uint16 mod);
    void OnKeyUp(SDL_Keycode key, Uint16 mod);

private:
    GameObject* object;
    GameObject* background;

    Assets2D::SpriteSheet* image;
    Assets2D::AnimatedSprite* sprite;
    Assets2D::SpriteSheet* bgImage;

    Systems2D::Physics* physicsSystem;
    Systems2D::AssetRendering* renderingSystem;

    // Control related
    int timeKeyUp;
    bool keyDown;

};

#endif // TESTSCENE_H
