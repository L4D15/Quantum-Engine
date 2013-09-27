#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "quantum/Scene.h"

class TestScene : public Scene
{
public:
    TestScene();
    ~TestScene();

    void onActivate();

    void onDeactivate();

    void onRender();

    void onLoop();

    void onKeyDown(SDL_Keycode key, Uint16 mod);

private:

};

#endif // TESTSCENE_H
