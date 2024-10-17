cmake_minimum_required(VERSION 3.28)
project(testingUnitTest)
add_subdirectory(googletest)

include_directories(googletest/googletest/include)
set(CMAKE_CXX_STANDARD 17)

add_executable(testingUnitTest main.cpp)
target_link_libraries(testingUnitTest gtest gtest_main)
