cmake_minimum_required(VERSION 3.30)
project(estatico C)

set(CMAKE_C_STANDARD 11)

add_executable(estatico main.c tElemento.c tElemento.h
        Conjunto.c
        Conjunto.h
)
