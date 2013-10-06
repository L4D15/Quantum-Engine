# CMake minimun version required to compile
cmake_minimum_required(VERSION 2.6)

# =================================================================
# Project variables
# =================================================================
# Setup these variables and the rest of the CMakeLists.txt won't need more changes.
set(PROJECT_NAME "Quantum_Engine")
set(PROJECT_EXECUTABLE_NAME "Quantum_Engine")
set(PROJECT_LIBRARY_NAME "QuantumEngine")
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(PROJECT_HEADERS_DIR "${CMAKE_SOURCE_DIR}/include")
set(PROJECT_MAIN_FILE "${PROJECT_SOURCE_DIR}/main.cpp")
set(PROJECT_RESOURCES_DIR "${CMAKE_SOURCE_DIR}/res")

# =================================================================
# Project properties
# =================================================================
project("${PROJECT_NAME}")

# Specify build output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")



# =================================================================
# Macros
# =================================================================
# Find all directories inside a given directory
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# =================================================================
# Source Files
# =================================================================
cmake_policy( SET CMP0009 NEW)      # Prevents cmake from following symbolic links using GLOB
file(GLOB_RECURSE PROJECT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# =================================================================
# Include directories
# =================================================================
SUBDIRLIST(PROJECT_INCLUDE_DIRECTORIES ${PROJECT_HEADERS_DIR})
file(GLOB_RECURSE PROJECT_HEADER_FILES "${PROJECT_HEADERS_DIR}/*.h")
include_directories(${PROJECT_HEADERS_DIR} ${PROJECT_INCLUDE_DIRECTORIES})
set(PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})

# =================================================================
# Link sources
# =================================================================
# Define executable to be created
add_executable(${PROJECT_EXECUTABLE_NAME} ${PROJECT_SOURCE_FILES})

# =================================================================
# Libraries
# =================================================================
if(APPLE)
    # OpenGL
    include_directories("/System/Library/Frameworks")
    find_library(OpenGL_LIBRARY OpenGL)

    if(NOT OpenGL_LIBRARY)
        message (FATAL_ERROR "Failed to find OpenGL in your Frameworks directory")
    endif(NOT OpenGL_LIBRARY)
    message("-- Added Mac OS X OpenGL Framework")

    include_directories("/Library/Frameworks")

    # SDL2
    find_library(SDL2_LIBRARY SDL2)

    if(NOT SDL2_LIBRARY)
        message(FATAL_ERROR "Failed to find SDL2 in your Frameworks directory.")
    endif(NOT SDL2_LIBRARY)
    message("-- Added Mac OS X SDL2 Framework")

    # SDL2_image
    find_library(SDL2_IMAGE_LIBRARY SDL2_image)

    if(NOT SDL2_IMAGE_LIBRARY)
        message(FATAL_ERROR "Failed to find SDL2_image in your Frameworks directory.")
    endif(NOT SDL2_IMAGE_LIBRARY)
    message("-- Added Mac OS X SDL2_image Framework")

    # SDL2_ttf
    find_library(SDL2_TTF_LIBRARY SDL2_ttf)

    if(NOT SDL2_TTF_LIBRARY)
        message(FATAL_ERROR "Failed to find SDL2_ttf in your Frameworks directory.")
    endif(NOT SDL2_TTF_LIBRARY)
    message("-- Added Mac OS X SDL2_ttf Framework")

    # Libraries not supplied as frameworks must be installed in the system
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")

    # Artemis-Cpp
    if(NOT EXISTS "/usr/local/lib/libartemis.a")
        message(FATAL_ERROR "Failed to find Artemis-Cpp in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libartemis.a")
    set(ARTEMIS_LIBRARY "artemis")

    # JsonCpp
    if(NOT EXISTS "/usr/local/lib/libjson.a")
        message(FATAL_ERROR "Failed to find JsonCpp in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libjson.a")
    set(JSONCPP_LIBRARY "json")

    # Link the frameworks
    mark_as_advanced(OpenGL_LIBRARY SDL2_LIBRARY SDL2_IMAGE_LIBRARY SDL2_TTF_LIBRARY)
    set(EXTRA_LIBS ${OpenGL_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${ARTEMIS_LIBRARY} ${JSONCPP_LIBRARY})

    message("-- Linking libraries:")
    foreach(lib ${EXTRA_LIBS})
        message("    ${lib}")
    endforeach(lib)

    target_link_libraries(${PROJECT_EXECUTABLE_NAME} ${EXTRA_LIBS})
endif(APPLE)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")

    #OpenGL
    set(OPENGL_LIBRARY "gl")

    # Libraries directories
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")

    # SDL2
    if(NOT EXISTS "/usr/local/lib/libSDL2.a")
        message(FATAL_ERROR "Failed to find SDL2 in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libSDL2.a")
    set(SDL2_LIBRARY "SDL2")

    # SDL2_image
    if(NOT EXISTS "/usr/local/lib/libSDL2_image.a")
        message(FATAL_ERROR "Failed to find SDL2_image in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libSDL2_image.a")
    set(SDL2_IMAGE_LIBRARY "SDL2_image")

    # SDL2_ttf
    if(NOT EXISTS "/usr/local/lib/libSDL2_ttf.a")
        message(FATAL_ERROR "Failed to find SDL2_ttf in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libSDL2_ttf.a")
    set(SDL2_TTF_LIBRARY "SDL2_ttf")

    # Artemis-Cpp
    if(NOT EXISTS "/usr/local/lib/libartemis.a")
        message(FATAL_ERROR "Failed to find Artemis-Cpp in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libartemis.a")
    set(ARTEMIS_LIBRARY "artemis")

    # JsonCpp
    if(NOT EXISTS "/usr/local/lib/libjson.a")
        message(FATAL_ERROR "Failed to find JsonCpp in /usr/local/lib.")
    endif(NOT EXISTS "/usr/local/lib/libjson.a")
    set(JSONCPP_LIBRARY "json")

    # Link libraries
    set(EXTRA_LIBS ${OPENGL_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${ARTEMIS_LIBRARY} ${JSONCPP_LIBRARY})
    target_link_libraries(${PROJECT_EXECUTABLE_NAME} ${EXTRA_LIBS})

endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# =================================================================
# Fix Include Path
# =================================================================
include_directories(${PROJECT_HEADERS_DIR} ${PROJECT_INCLUDE_DIRECTORIES})

# =================================================================
# Post scripts
# =================================================================
# Create symbolic link to assets folder
# message("Creating symbolic link from ${CMAKE_SOURCE_DIR}/assets to ${CMAKE_BINARY_DIR}/bin/assets")
# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ln -s "${CMAKE_SOURCE_DIR}/assets" "${CMAKE_BINARY_DIR}/bin/assets"
# )
