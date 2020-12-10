#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
project(tests)
add_subdirectory(lib)

add_executable(runTests library_test.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests_run test1.cpp tests2.cpp)
target_link_libraries(tests_run gtest gtest_main)
