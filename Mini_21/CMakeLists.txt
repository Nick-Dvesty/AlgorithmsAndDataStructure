cmake_minimum_required(VERSION 3.27)
project(Mini_21 C)

set(CMAKE_C_STANDARD 23)

add_executable(Mini_21 main.c
        binomialHeap.c
        binomialHeap.h
        orderedList.c
        orderedList.h)
