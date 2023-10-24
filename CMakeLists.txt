cmake_minimum_required(VERSION 3.6)

project(.
        VERSION 1.0.0
        DESCRIPTION "Build all: mtl and testbed"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(main testbed/test.cpp)
