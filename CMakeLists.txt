cmake_minimum_required(VERSION 3.19)
project(computorv1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(computorv1
        computor.cpp
        computor.h)
