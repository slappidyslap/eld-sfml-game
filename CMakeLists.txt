cmake_minimum_required(VERSION 3.28)
project(DegredachSFMLGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(DegredachSFMLGame
    src/main.cpp
    src/Window.cpp
    src/Game.cpp)
target_compile_features(DegredachSFMLGame PRIVATE cxx_std_17)
target_link_libraries(DegredachSFMLGame PRIVATE sfml-graphics)