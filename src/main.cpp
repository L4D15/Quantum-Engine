#include <iostream>
#include "game/TestGame2D.h"
#include "game/TestGame3D.h"

int main(int argc, char** argv)
{
    std::cout << "Hello world" << std::endl;

//    TestGame2D* game;

//    game = new TestGame2D();
//    game->start();

//    delete game;

    TestGame3D* game;

    game = new TestGame3D();
    game->start();

    delete game;

    return 0;
}
