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
* [Boost](http://www.boost.org/)
* [json-spirit](https://github.com/L4D15/json-spirit)
* [lua](https://github.com/LuaDist/lua)

You just need to clone using the recursive argument and most of these libraries will be cloned alongside the project so you don't have to download, compile and install them. They will be bundled with Quantum-Engine.

`git clone --recursive https://github.com/L4D15/Quantum-Engine.git`

### OS X

1. Clone the repository with the recursive flag `git clone --recursive https://github.com/L4D15/Quantum-Engine.git`
2. Install SDL2 libraries:
  1. Download development libraries for OS X:
    1. [SDL2](http://www.libsdl.org/release/SDL2-2.0.3.dmg).
    2. [SDL2_image](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.dmg).
    3. [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.dmg).
  2. Copy the `.framework` files to `/Library/Frameworks`
3. Install boost library for C++.
  1. The easiest way is using [homebrew](http://brew.sh/).
  2. Once _homebrew_ is installed just run `brew install boost` from your terminal.
4. Enjoy.


### Linux
OpenGL should be present in the systems but the development libraries may be missing, so make sure the packages _mesa-common-dev_ and _libgl1-mesa-dev_ is installed.

For SDL2 libraries (SDL2, SDL2_image and SDL2_ttf) the best option is to download the source code from their respective websites and compile it yourself. It's a very straight forward process since you only need to run these three commands inside the folder of each library:

1. `./configure`
2. `make`
3. `sudo make install`

This will install the libraries into `/usr/local/lib` and the header files in `/usr/local/include`.

The rest of libraries are compiled alongside Quantum-Engine, so you don't need to care of them ;-)

### Windows

Install MinGW + MSYS and add its respective *bin* directories to your system's PATH variable. Install CMake and add it to PATH too.

You'll need some third party libraries to make work SDL2_image and SDL2_ttf properly. Install this libraries in the given order following the steps provided in its respectives websites.
* [zlib](http://www.zlib.net/)
* [libpng](http://www.libpng.org/pub/png/libpng.html)
* [FreeType](http://www.freetype.org/)

Download the SDL2 development libraries (SDL2, SDL2_image and SDL2_ttf) for MinGW and follow these steps for each library:

1. Copy the *lib* folder to C:\MinGW merging with the existing *lib* folder.
2. Copy the *include* folder to C:\MinGW merging with the existing *include* folder.
3. Copy the .dll files inside *bin* folder to  the Quantum-Engine's _res_ folder. It already have the .dll files for the latest version at the moment of writting this guide, but replace them just in case you are using a newer versión of the library.

The rest of libraries are compiled alongside Quantum-Engine, so you don't need to care of them ;-)

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

## Troubleshoot

### SDL can't initialize video driver

If you get a message error like "No available video device" in Linux you are probably missing the required 32bits libraries, so install the package _ia32-libs_. If the problem persists, make sure you have compiled all the SDL2 libraries __after__ installing the required OpenGL libraries.

### SDL_ttf complains about missing Freetype library

Just install the development library of Freetype for your system's OS and try again. You can find it [here](http://freetype.org/) or using your system's repository manager if you are using Linux (_libfreetype6-dev_).

### Problem loading .png images

You are probably missing the required PNG library (this is more likely to happen in fresh installs of Linux). Install _libpng-12-dev_ through your package manager.

## Need more information?
Refer to the [Wiki](https://github.com/L4D15/Quantum-Engine/wiki) page for further instructions and tutorials on how to use Quantum Engine.
