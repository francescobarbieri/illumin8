# Set minimum CMake version
cmake_minimum_required(VERSION 3.14)

# Set the project name and version
project(Illumin8)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# CMake generate an executable
add_executable(Illumin8 src/test.cpp)

target_link_libraries(
    Illumin8
    gtest_main
)

target_include_directories(Illumin8 PUBLIC ${gtest_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(Illumin8)