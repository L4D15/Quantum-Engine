#ifndef TESTSCENE3D_H
#define TESTSCENE3D_H

#include "quantum/Scene.h"

class TestScene3D : public Scene
{
public:
    TestScene3D();
    ~TestScene3D();

    void OnActivate();

    void OnDeactivate();

    void OnRender();

    void OnLoop();

    void OnKeyDown(SDL_Keycode key, Uint16 mod);
};

#endif // TESTSCENE3D_H
