cmake_minimum_required(VERSION 3.14)
project(alessio C CXX)
set(CMAKE_CXX_STANDARD 11)

list(APPEND SOURCES 
    src/main.cpp
    core/block/block.hpp
    core/block/block.cpp 
    core/network/network.cpp 
    core/network/network.hpp
)

add_executable(alessio ${SOURCES})