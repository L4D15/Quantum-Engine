#ifndef TESTSCENE3D_H
#define TESTSCENE3D_H

#include "quantum/Scene.h"

class TestScene3D : public Scene
{
public:
    TestScene3D();
    ~TestScene3D();

    void onActivate();

    void onDeactivate();

    void onRender();

    void onLoop();

    void onKeyDown(SDL_Keycode key, Uint16 mod);
};

#endif // TESTSCENE3D_H
