#include <iostream>
#include "game/TestGame2D.h"
#include "game/TestGame3D.h"

int main(int argc, char** argv)
{
    TestGame2D* game;

    game = new TestGame2D();
    game->Start();

    delete game;

    return 0;
}
