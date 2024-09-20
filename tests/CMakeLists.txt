find_package(Catch2 3 PATHS /usr/local/opt/homebrew/Cellar/catch2/3.7.0)
add_executable(RunTests tests_main.cpp)

target_link_libraries(RunTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(RunTests)