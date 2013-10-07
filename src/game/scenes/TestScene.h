#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"
#include "quantum/Vector2D.h"
#include "quantum/Libraries.h"

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
    Vector2D initialPos1;
    Vector2D initialPos2;
    Vector2D initialPos3;
    Vector2D initialPos4;

    Vector2D pos1;
    Vector2D pos2;
    Vector2D pos3;
    Vector2D pos4;

    Vector2D finalPos1;
    Vector2D finalPos2;
    Vector2D finalPos3;
    Vector2D finalPos4;

    Vector2D movement;

    Uint32 initialTime;
    Uint32 duration;

};

#endif // TESTSCENE_H
