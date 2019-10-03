cmake_minimum_required(VERSION 3.15)
project(Floats C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Floats
        floats.c
        floats.h)
