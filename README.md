Quantum Engine
=======

Quantum Engine is an Open Source crossplatform game engine. It is designed using components, so it is very easy to use and expand its features.

## Compiling

Quantum Engine uses CMake build system so it can be compiled across Windows, Mac OS X and Linux using a single tool. You can find more information about CMake [here](http://www.cmake.org/).

### Prerequisites

Quantum Engine uses multiple libraries that need to be present in the system before compiling.
* OpenGL (mesa-common-dev package in Linux)
* [SDL2](http://www.libsdl.org/download-2.0.php)
* [SDL2_image](http://www.libsdl.org/projects/SDL_image/)
* [SDL2_ttf](http://www.libsdl.org/projects/SDL_ttf/)
* [Artemis-Cpp](https://github.com/L4D15/Artemis-Cpp)
* [JsonCpp](https://github.com/L4D15/jsoncpp)

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

Just link the library file created in the `lib` folder to your project and add the header files in the `include` folder to the headers file search path.

Refer to the [Wiki](https://github.com/L4D15/Quantum-Engine/wiki) page for further instructions and tutorials on how to use Quantum Engine.