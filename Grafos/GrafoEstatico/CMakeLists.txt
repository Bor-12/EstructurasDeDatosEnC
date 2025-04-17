cmake_minimum_required(VERSION 3.30)
project(GrafoEstatico C)

set(CMAKE_C_STANDARD 11)

add_executable(GrafoEstatico main.c
        Grafo.c
        Grafo.h
        tElemento.c
        tElemento.h
)
