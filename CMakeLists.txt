# CMake minimun version required to compile
cmake_minimum_required(VERSION 2.6)

message("====================================")
message("Building Makefile for Quantum Engine")
message("====================================")
message("Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message("Binary Dir: ${CMAKE_CURRENT_BINARY_DIR}")

# =================================================================
# Project properties
# =================================================================
project("${PROJECT_NAME}")

# Specify build output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

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
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

message("-- Source Files (.cpp)")
foreach(file ${SOURCE_FILES})
    message("    ${file}")
endforeach()

# =================================================================
# Include directories (containing .h files)
# =================================================================
# SUBDIRLIST(INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

message("-- Header Files (.h)")
foreach(file ${HEADER_FILES})
    message("    ${file}")
endforeach()

# =================================================================
# Libraries
# =================================================================
# Artemis-Cpp
find_library(ARTEMIS_LIB NAMES artemis HINTS "/usr/local/lib")

# JsonCpp
find_library(JSON_LIB NAMES json HINTS "/usr/local/lib")

# OpenGL
if(APPLE)
    find_library(OPENGL_LIB OpenGL)
    if(NOT OPENGL_LIB)
        message (FATAL_ERROR "Failed to find OpenGL in your Frameworks directory")
    endif(NOT OPENGL_LIB)
endif(APPLE)

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
add_library(QuantumEngine SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(QuantumEngine ${OPENGL_LIB} ${ARTEMIS_LIB} ${JSON_LIB} ${SDL2_LIB} ${SDL2_IMAGE_LIB} ${SDL2_TTF_LIB})

message("====================================")
message("Quantum Engine Finished")
message("====================================")