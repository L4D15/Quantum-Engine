Quantum Engine
=======

Quantum Engine is an Open Source crossplatform game engine. It is designed using components, so it is very easy to use and expand its features.

## Compiling

Quantum Engine uses CMake build system so it can be compiled across Windows, Mac OS X and Linux using a single tool. You can find more information about CMake [here](http://www.cmake.org/).

#### Prerequisites

Quantum Engine uses multiple libraries that need to be present in the system before compiling.
* OpenGL
* [SDL2](http://www.libsdl.org/download-2.0.php)
* [SDL2_image](http://www.libsdl.org/projects/SDL_image/)
* [SDL2_ttf](http://www.libsdl.org/projects/SDL_ttf/)
* [Artemis-Cpp](https://github.com/L4D15/Artemis-Cpp)
* [JsonCpp](https://github.com/L4D15/jsoncpp)

After cloning the repository you need to initialize its submodules running the following commands:

1. `git submodules init`
2. `git submodules update`

### Mac OS X
OpenGL, SDL2, SDL2_image and SDL2_ttf are loaded from its Frameworks containers that must be present in the system. OpenGL.framework should be installed in the system by default (commonly in /System/Library/Frameworks.

In the case of SDL2 libraries, install the development libraries available in their respective websites (copy them to /Library/Frameworks).

For Artemis-Cpp and JsonCpp follow the steps in their GitHub's page.

### Linux
OpenGL should be present in the systems but the development libraries may be missing, so make sure the package _mesa-common-dev_ is installed.

For SDL2 libraries (SDL2, SDL2_image and SDL2_ttf) the best option is to download the source code from their respective websites and compile it yourself. It's a very straight forward process since you only need to run these three commands inside the folder of each library:

1. `./configure`
2. `make`
3. `make install`

This will install the libraries into `/usr/local/lib` and the header files in `/usr/local/include`.

For Artemis-Cpp y JsonCpp the process is almost the same except we have included CMake compiling support so you just need to run the following:

1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`
5. `make install`

### Windows

Install MinGW + MSYS and add its respective *bin* directories to your system's PATH variable. Install CMake and add it to PATH too.

You'll need some third libraries to make work SDL2_image and SDL2_ttf properly. Install this libraries in the given order following the steps provided in its respectives websites.
* [zlib](http://www.zlib.net/)
* [libpng](http://www.libpng.org/pub/png/libpng.html)
* [FreeType](http://www.freetype.org/)

Download the SDL2 development libraries (base, image and ttf) for MinGW and follow these steps for each library:

1. Copy the *lib* folder to C:\MinGW merging with the existing *lib* folder.
2. Copy the *include* folder to C:\MinGW merging with the existing *include* folder.
3. Copy the .dll files inside *bin* folder to  the output folder where the executable will be placed (commonly in ./build/bin).

## Build Quantum Engine
Follow these steps to compile Quantum Engine:

1. Install CMake if you don't have it already (minimun version 2.6).
2. Make sure `cmake` command is accessible from your `$PATH` system's variable. You can check this out calling `cmake --version` from the terminal.
3. Open a new terminal and navigate to the Quantum Engine's folder.
4. `mkdir build`
5. `cd build`
6. `cmake ..` (if you are in Windows use the generator "MSYS Makefiles")
7. `make`
8. Enjoy.

## Using Quantum Engine

Just link the library file created in the `lib` folder to your project and add the header files in the `include` folder to the headers file search path.

If you are using CMake in your project you can add Quantum Engine as a submodule so it will be compiled with your project. That way you won't need to include different builds of Quantum Engine for each platform. You can do this adding the following lines to you CMakeLists.txt:

````CMake
add_subdirectory("path/to/Quantum-Engine/source/code")
target_link_libraries(nameOfYourApp QuantumEngine)
````

You can take a look at [this CMakeLists.txt](https://github.com/L4D15/Quantum/blob/master/Source%20Code/CMakeLists.txt) for some example code on the subject.

## Need more information?
Refer to the [Wiki](https://github.com/L4D15/Quantum-Engine/wiki) page for further instructions and tutorials on how to use Quantum Engine.