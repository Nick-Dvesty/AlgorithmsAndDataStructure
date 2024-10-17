cmake_minimum_required(VERSION 3.28)
project(Mini_33)
add_subdirectory(googletest)

include_directories(googletest/googletest/include)
set(CMAKE_CXX_STANDARD 17)

add_executable(Mini_33 main.cpp
        Solution.h
        Solution.cpp
        1.asm)
target_link_libraries(Mini_33 gtest gtest_main)
