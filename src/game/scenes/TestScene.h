#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"
#include "quantum/Vector2D.h"
#include "quantum/Libraries.h"
#include "quantum/systems/2D/Physics.h"
#include "quantum/SpriteSheet.h"

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

private:
    GameObject* object;

    Assets2D::SpriteSheet* image;

    Systems2D::Physics* physicsSystem;

};

#endif // TESTSCENE_H
