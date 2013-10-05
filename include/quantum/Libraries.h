// This file contains the include directives for each library used for each platform.
// Include this file whenever you want to use any of the libraries instead of doing it
// yourself. This way you won't need to take care of platform-specific directives.

#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <SDL2/SDL.h>

#ifdef __APPLE__
// Mac OS X
#include <OpenGL/gl.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
// Linux and Windows (MinGW)
#include <GL/gl.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#endif	// LIBRARIES_H