cmake_minimum_required(VERSION 3.6)

project(cpp-tests)

#find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#include_directories(
#    ${GTEST_INCLUDE_DIRS}
#)

add_executable(main testbed/test.cpp)

#target_link_libraries(
#  main ${GTEST_LIBRARIES} Threads::Threads)
