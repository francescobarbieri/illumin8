include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.0 # You can change this to the latest Catch2 version
)

FetchContent_MakeAvailable(Catch2)