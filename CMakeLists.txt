cmake_minimum_required(VERSION 3.16)
project(SimCity LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SimCity src/main.cpp src/MapGenerator.cpp src/OptimalRouteFinder.cpp)

target_compile_options(SimCity PRIVATE -Wall -Wextra -Wpedantic)

install(TARGETS SimCity DESTINATION bin)