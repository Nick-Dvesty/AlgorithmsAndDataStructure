cmake_minimum_required(VERSION 3.28)
project(Mini_36)
add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 17)

include_directories(googletest/googletest/include)
add_executable(Mini_36 main.cpp
        UnionFind.cpp
        UnionFind.h
        unitTests.h
        sheduleFine.h)

include_directories(googletest/googletest/include)
target_link_libraries(Mini_36 gtest gtest_main)
