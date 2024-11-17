cmake_minimum_required(VERSION 3.28)
project(MIni_42)

add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 17)

include_directories(googletest/googletest/include)
add_executable(MIni_42 main.cpp
        Treap.h)

include_directories(googletest/googletest/include)
target_link_libraries(MIni_42 gtest gtest_main)
