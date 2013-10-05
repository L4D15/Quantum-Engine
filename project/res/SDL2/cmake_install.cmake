# Install script for directory: /Users/ladis/Projects/Quantum-Engine/res/SDL2

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/ladis/Projects/Quantum-Engine/project/lib/libSDL2.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/ladis/Projects/Quantum-Engine/project/lib/libSDL2-2.0.0.0.0.dylib"
    "/Users/ladis/Projects/Quantum-Engine/project/lib/libSDL2-2.0.0.dylib"
    "/Users/ladis/Projects/Quantum-Engine/project/lib/libSDL2-2.0.dylib"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.0.0.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.dylib"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libSDL2-2.0.0.dylib"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/ladis/Projects/Quantum-Engine/project/lib/libSDL2main.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/begin_code.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/close_code.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_assert.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_atomic.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_audio.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_bits.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_blendmode.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_clipboard.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_android.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_iphoneos.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_macosx.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_minimal.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_pandora.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_psp.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_windows.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_config_wiz.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_copying.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_cpuinfo.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_endian.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_error.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_events.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_gamecontroller.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_gesture.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_haptic.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_hints.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_joystick.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_keyboard.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_keycode.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_loadso.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_log.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_main.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_messagebox.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_mouse.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_mutex.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_name.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_opengl.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_opengles.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_opengles2.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_pixels.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_platform.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_power.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_quit.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_rect.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_render.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_revision.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_rwops.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_scancode.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_shape.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_stdinc.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_surface.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_system.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_syswm.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_assert.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_common.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_compare.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_crc32.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_font.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_fuzzer.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_harness.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_images.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_log.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_md5.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_test_random.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_thread.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_timer.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_touch.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_types.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_version.h"
    "/Users/ladis/Projects/Quantum-Engine/res/SDL2/include/SDL_video.h"
    "/Users/ladis/Projects/Quantum-Engine/project/res/SDL2/include/SDL_config.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
    execute_process(COMMAND /usr/local/Cellar/cmake/2.8.11.2/bin/cmake -E create_symlink
    "libSDL2-2.0.so" "libSDL2.so")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/ladis/Projects/Quantum-Engine/project/res/SDL2/libSDL2.so")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/ladis/Projects/Quantum-Engine/project/res/SDL2/sdl2.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/Users/ladis/Projects/Quantum-Engine/project/res/SDL2/sdl2-config")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/Users/ladis/Projects/Quantum-Engine/res/SDL2/sdl2.m4")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

