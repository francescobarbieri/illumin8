find_package(Catch2 3 PATHS /usr/local/opt/homebrew/Cellar/catch2/3.7.0)
add_executable(RunTests tests_main.cpp
    core/test_tuple.cpp
    ../src/core/tuple.cpp
    core/test_color.cpp
    ../src/core/color.cpp
    core/test_matrix.cpp
    ../src/core/matrix.cpp
    display/test_canvas.cpp
    ../src/display/canvas.cpp
)

target_link_libraries(RunTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(RunTests)