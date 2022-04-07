cmake_minimum_required(VERSION 3.17)
project(task2)

set(CMAKE_CXX_STANDARD 14)
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(task2 main.cpp)

target_link_libraries(task2 PRIVATE nlohmann_json::nlohmann_json)