#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
project(tests)
add_subdirectory(lib/googletest)

set(gtest_SOURCE_DIR lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests_run library_test.cpp)
target_link_libraries(tests_run gtest gtest_main)
