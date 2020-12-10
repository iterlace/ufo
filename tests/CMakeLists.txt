#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
cmake_minimum_required(VERSION 3.17)
project(ufo_tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest)
enable_testing()

#set(gtest_SOURCE_DIR lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_libraries(ufo)


add_executable(tests_run library_test.cpp utils_test.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
#target_link_libraries(tests_run ufo)
target_link_libraries(tests_run gtest gtest_main)
