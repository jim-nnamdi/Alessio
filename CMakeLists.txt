cmake_minimum_required(VERSION 3.14)
project(alessio c cxx)
set(CMAKE_CXX_STANDARD 17)

list(APPEND SOURCES 
    src/main.cpp
)

add_executable(alessio ${SOURCES})
target_link_libraries(alessio lib/)