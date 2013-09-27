Quantum Engine
=======

Quantum Engine is an Open Source crossplatform game engine. It is designed using components, so it is very easy to use and expand its features.

## Compiling

Quantum Engine uses CMake build system so it can be compiled across Windows, Mac OS X and Linux using a single tool. You can find more information about CMake [here](http://www.cmake.org/).

Before compiling you need to initialize some git submodules used by Quantum Engine (that means that we have other git repositories cloned inside Quantum Engine). From a terminal run the following command inside Quantum Engine's folder:

`git submodule init`

Now you just need to follow these steps to compile Quantum Engine:

1. Install CMake if you don't have it already (minimun version 2.6).
2. Make sure `cmake` command is accessible from your `$PATH` system's variable. You can check this out calling `cmake --version` from the terminal.
3. Open a new terminal and navigate to the Quantum Engine's folder.
4. `mkdir build`
5. `cd build`
6. `cmake ..`
7. `make`
8. Enjoy.

## Using Quantum Engine

Fork this repository and play with the code. If you create some new component or system you think could be useful to the community just *pull request* me with the commits containing the new feature and I will add it to the main project so every one can use it. That way Quantum Engine can expand its functionality while being used by others to create amazing games!

You should separate your code between *engine* code and *game* code. The main porpuse of this is not to change the core of the engine for every game. That way new components and systems can be separated from the game instance and easily delivered to the main project's repository.

For example: We have the abstract class Scene to represent a Scene in the game. It is stored in the `engine` folder. While making the game we want to create an intro scene to present our game with some fancy images. To do so, we create a new class called IntroScene that inherits from the class Scene from the engine. This new class will be stored in the `game` folder, since it is specifid to the game you are doing. You can ask yourself "This new class can be used by any one using this engine no matter the game he/she is doing, or is it specifig of _my_ game?". If the answer falls into the first option, the class will go into the `engine` folder (and if you feel like sharing that feature you can do it using the `pull request` feature in GitHub!) otherwise, use the `game` folder.

Refer to the [Wiki](https://github.com/L4D15/Quantum-Engine/wiki) page for further instructions and tutorials on how to use Quantum Engine.