include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v${GOOGLETEST_VERSION}
)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests MapGeneratorTest.cpp OptimalRouteFinderTest.cpp)
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(unit_tests PRIVATE gtest_main simcity_lib)

include(GoogleTest)
gtest_discover_tests(unit_tests)

add_test(NAME unit_tests COMMAND unit_tests)
