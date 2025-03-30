cmake_minimum_required(VERSION 3.30)
project(PilaDinamica C)

set(CMAKE_C_STANDARD 11)

add_executable(PilaDinamica main.c
        Pila.c
        Pila.h
        tElemento.c
        tElemento.h)
