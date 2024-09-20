cmake_minimum_required(VERSION 3.15...3.30)
project(Illumin8 VERSION 1.0 LANGUAGES CXX)

# Set up directories and standards
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
add_executable(Illumin8 src/main.cpp)