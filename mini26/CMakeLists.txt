cmake_minimum_required(VERSION 3.27)
project(mini26 C)

set(CMAKE_C_STANDARD 23)

add_executable(mini26 main.c
        avlTree.c
        avlTree.h
        LinkNode.c
        LinkNode.h)
