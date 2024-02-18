cmake_minimum_required(VERSION 3.27)
project(VectorC C)

set(CMAKE_C_STANDARD 23)

add_executable(VectorC main.c
        VectorLibInC/VectorInC.c
        VectorLibInC/VectorInC.h)
