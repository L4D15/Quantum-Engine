#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"
#include "quantum/Vector2D.h"
#include "quantum/Libraries.h"
#include "quantum/systems/2D/Physics.h"

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
    Uint32 initialTime;
    Uint32 duration;

    GameObject* object;
    GameObject* child;

    Systems2D::Physics* physicsSystem;

};

#endif // TESTSCENE_H
