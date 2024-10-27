find_package(Catch2 3 PATHS /usr/local/opt/homebrew/Cellar/catch2/3.7.0)
add_executable(RunTests tests_main.cpp
    # Core
    core/test_tuple.cpp
    ../src/core/tuple.cpp
    core/test_color.cpp
    ../src/core/color.cpp
    core/test_matrix.cpp
    ../src/core/matrix.cpp
    core/test_transformation.cpp
    ../src/core/transformation.cpp
    core/test_ray.cpp
    ../src/core/ray.cpp
    # Shapes
    shapes/test_sphere.cpp
    ../src/shapes/sphere.cpp
    # Display
    display/test_canvas.cpp
    ../src/display/canvas.cpp
    # Helpers
    helpers/test_intersection.cpp
    ../src/helpers/intersection.cpp
)

target_link_libraries(RunTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(RunTests)