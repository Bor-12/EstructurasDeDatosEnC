cmake_minimum_required(VERSION 3.30)
project(Hospital C)

set(CMAKE_C_STANDARD 11)

add_executable(Hospital main.c Cola.c Cola.h
        tElemento.c
        tElemento.h
        Hospital.c
        Hospital.h
        tLista.c
        tLista.h)
