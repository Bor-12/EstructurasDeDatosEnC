cmake_minimum_required(VERSION 3.30)
project(GrafoDinamico C)

set(CMAKE_C_STANDARD 11)

add_executable(GrafoDinamico main.c
        Grafo.c
        Grafo.h
        tElemento.c
        tElemento.c
)
