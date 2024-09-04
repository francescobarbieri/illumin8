cmake_minimum_required(VERSION 3.10)

# Project Name
project(MyProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 14)

# Add the source code
add_executable(my_project src/main.cpp)

# Use FetchContent to download Catch2
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.7  # Specific Catch2 version
)

FetchContent_MakeAvailable(Catch2)

# Add tests
add_executable(test_my_project tests/test.cpp)

# Link Catch2 to the test executable
target_link_libraries(test_my_project Catch2::Catch2)

# Enable CTest to run tests with `make test`
enable_testing()
add_test(NAME test_my_project COMMAND test_my_project)