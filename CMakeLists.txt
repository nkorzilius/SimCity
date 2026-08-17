cmake_minimum_required(VERSION 3.16)
project(SimCity LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(GOOGLETEST_VERSION 1.15.2)

enable_testing() #to  discover tests in test explorer 

# Build library from src so tests can link against it
add_library(simcity_lib
	src/MapGenerator.cpp
	src/OptimalRouteFinder.cpp
	src/DisplayPrint.cpp
)

target_include_directories(simcity_lib PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_compile_options(simcity_lib PRIVATE -Wall -Wextra -Wpedantic)

# Main executable links against the library
add_executable(SimCity src/main.cpp)
target_link_libraries(SimCity PRIVATE simcity_lib)
target_compile_options(SimCity PRIVATE -Wall -Wextra -Wpedantic)

install(TARGETS SimCity DESTINATION bin)

# Add tests subdirectory after library is defined so tests can link to simcity_lib
add_subdirectory(tests)