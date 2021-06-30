cmake_minimum_required(VERSION 3.19)
project(computorv1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(computorv1
        parcer.cpp
        parcer.hpp main.cpp computor.cpp computor.hpp)
