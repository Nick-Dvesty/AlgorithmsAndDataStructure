cmake_minimum_required(VERSION 3.29)
project(Mini_8 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Mini_8
        InversionCounter.c
        InversionCounter.h
        Program.c)
