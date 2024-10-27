cmake_minimum_required(VERSION 3.15...3.30)
project(Illumin8 VERSION 1.0 LANGUAGES CXX)

# Set up directories and standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Darwin)
set(CMAKE_OSX_ARCHITECTURES arm64)

# Copy all header files to the include/Illumin8 folder
if(COMMAND execute_process)
    execute_process(
        COMMAND ${CMAKE_SOURCE_DIR}/script.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
else()
    message(WARNING "Could not copy headers file into /include folder. Ensure script exists and is executable.")
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Include Catch2 setup
#include(${PROJECT_SOURCE_DIR}/cmake/Catch2.cmake)
enable_testing()
add_subdirectory(tests)

# Add executable
add_executable(Illumin8 
    src/main.cpp
    src/core/transformation.cpp
    src/core/tuple.cpp
    src/core/matrix.cpp
    src/core/ray.cpp
    src/core/color.cpp
    src/shapes/sphere.cpp
    src/helpers/intersections.cpp
    src/helpers/intersection.cpp
    src/display/canvas.cpp
)