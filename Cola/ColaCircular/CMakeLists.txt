cmake_minimum_required(VERSION 3.30)
project(ColaCircular C)

set(CMAKE_C_STANDARD 11)

add_executable(ColaCircular
        main.c
        Cola.c
        Cola.h
        tElemento.c
        tElemento.h)
