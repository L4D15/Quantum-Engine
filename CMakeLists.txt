# CMake minimun version required to compile
cmake_minimum_required(VERSION 2.6)

# Add modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

message("====================================")
message("Building Makefile for Quantum Engine")
message("====================================")
message("Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message("Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}")

# Enable C++ 11 compiling
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

# json-spirit build variables
set(JSON_SPIRIT_LIBRARY_TYPE STATIC)
set(JSON_SPIRIT_BUILD_DEMOS FALSE)
set(JSON_SPIRIT_BUILD_TESTS FALSE)

# Weird Boost Library requisites (damn you json-spirit)
set(Boots_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_STATIC_RUNTIME OFF)
set(Boost_DEBUG ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/lua")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/Artemis-Cpp")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/json-spirit/build")

# =================================================================
# Project properties
# =================================================================
project("${PROJECT_NAME}")

# Specify build output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Prevents cmake from following symbolic links using GLOB
cmake_policy( SET CMP0009 NEW)

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
# Source Files (.cpp files)
# =================================================================
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# =================================================================
# Include directories (containing .h files)
# =================================================================
# SUBDIRLIST(INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# =================================================================
# Libraries
# =================================================================
set(EXTRA_LIBS "")
# Artemis-Cpp
set(EXTRA_LIBS ${EXTRA_LIBS} ArtemisCpp)
set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} "${CMAKE_CURRENT_SOURCE_DIR}/lib/Artemis-Cpp/include")

# json-spirit
set(EXTRA_LIBS ${EXTRA_LIBS} json_spirit)
set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} "${CMAKE_CURRENT_SOURCE_DIR}/lib/json-spirit/include")

# OpenGL
if(APPLE)
    find_library(OPENGL_LIB OpenGL)
    if(NOT OPENGL_LIB)
        message (FATAL_ERROR "Failed to find OpenGL in your Frameworks directory")
    endif(NOT OPENGL_LIB)
endif(APPLE)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(OpenGL REQUIRED)
    if(NOT OPENGL_FOUND)
        message(ERROR "OpenGL not found!")
    endif(NOT OPENGL_FOUND)
    set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${OPENGL_INCLUDE_DIRS})
    set(EXTRA_LIBS ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
    #add_definitions(${OPENGL_DEFINITIONS})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    find_package(OpenGL REQUIRED)
    if(NOT OPENGL_FOUND)
        message(ERROR "OpenGL not found!")
    endif(NOT OPENGL_FOUND)
    set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${OPENGL_INCLUDE_DIRS})
    set(EXTRA_LIBS ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# SDL2 Libraries
if(APPLE)
    find_library(SDL2_LIB SDL2)
    if(NOT SDL2_LIB)
        message(FATAL_ERROR "Failed to find SDL2 in your Frameworks directory.")
    endif(NOT SDL2_LIB)

    find_library(SDL2_IMAGE_LIB SDL2_image)
    if(NOT SDL2_IMAGE_LIB)
        message(FATAL_ERROR "Failed to find SDL2_image in your Frameworks directory.")
    endif(NOT SDL2_IMAGE_LIB)

    find_library(SDL2_TTF_LIB SDL2_ttf)
    if(NOT SDL2_TTF_LIB)
        message(FATAL_ERROR "Failed to find SDL2_ttf in your Frameworks directory.")
    endif(NOT SDL2_TTF_LIB)
endif(APPLE)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_library(SDL2_LIB NAMES SDL2 HINTS "/usr/local/lib")
    find_library(SDL2_IMAGE_LIB NAMES SDL2_image HINTS "/usr/local/lib")
    find_library(SDL2_TTF_LIB NAMES SDL2_ttf HINTS "/usr/local/lib")
    set(EXTRA_LIBS ${EXTRA_LIBS} ${SDL2_LIB} ${SDL2_IMAGE_LIB} ${SDL2_TTF_LIB})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(WIN32)
    if(MSVC)
        find_library(SDL2_LIB)
        find_library(SDL2_IMAGE_LIB)
        find_library(SDL2_TTF_LIB)
        find_library(SDL2_MAIN_LIB)
    endif(MSVC)

    if(MINGW OR MSYS)
        find_library(SDL2_LIB NAMES SDL2 HINTS "C:/MinGW/lib")
        find_library(SDL2_IMAGE_LIB NAMES SDL2_image HINTS "C:/MinGW/lib")
        find_library(SDL2_TTF_LIB NAMES SDL2_ttf HINTS "C:/MinGW/lib")
        find_library(SDL2_MAIN_LIB NAMES SDL2main HINTS "C:/MinGW/lib")
        find_library(MINGW_LIB NAMES mingw32 HINTS "C:/MinGW/lib")
        set(EXTRA_LIBS ${EXTRA_LIBS} ${MINGW_LIB})
    endif(MINGW OR MSYS)

    set(EXTRA_LIBS ${EXTRA_LIBS} ${SDL2_MAIN_LIB} ${SDL2_LIB} ${SDL2_IMAGE_LIB} ${SDL2_TTF_LIB})
endif(WIN32)

# Lua
set(EXTRA_LIBS ${EXTRA_LIBS} liblua)
set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} "${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/src" "${CMAKE_CURRENT_BINARY_DIR}/lib/lua" ${CMAKE_BINARY_DIR})

# Boost
find_package(Boost REQUIRED system filesystem)


# Additional step for Mac OS X
if(APPLE)
    mark_as_advanced(OPENGL_LIB SDL2_LIB SDL2_IMAGE_LIB SDL2_TTF_LIB)
endif(APPLE)

# =================================================================
# Output Library
# =================================================================
include_directories(${INCLUDE_DIRECTORIES})

message("Directories included in the Header search:")
foreach(dir ${INCLUDE_DIRECTORIES})
    message("    ${dir}")
endforeach(dir)

# Create the library
add_library(QuantumEngine STATIC ${SOURCE_FILES} ${HEADER_FILES})

    message("Linking libraries:")
    foreach(lib ${EXTRA_LIBS})
        message("    ${lib}")
    endforeach(lib)

# Artemis-Cpp and JsonCpp are in the scope of CMake from the subdirs
if(APPLE)
    target_link_libraries(QuantumEngine
                          ${OPENGL_LIB}
                          ${ARTEMIS_LIB}
                          ${JSON_LIB}
                          ${SDL2_LIB}
                          ${SDL2_IMAGE_LIB}
                          ${SDL2_TTF_LIB}
                          ${EXTRA_LIBS}
                          ${Boost_SYSTEM_LIBRARY}
                          ${Boost_FILESYSTEM_LIBRARY})
endif(APPLE)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(QuantumEngine ${EXTRA_LIBS})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(WIN32)
    target_link_libraries(QuantumEngine ${EXTRA_LIBS})
endif(WIN32)

message("====================================")
message("Quantum Engine Finished")
message("====================================")
