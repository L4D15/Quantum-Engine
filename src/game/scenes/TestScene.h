#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"

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

};

#endif // TESTSCENE_H
