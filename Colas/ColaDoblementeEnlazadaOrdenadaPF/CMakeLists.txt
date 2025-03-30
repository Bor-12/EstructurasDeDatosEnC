cmake_minimum_required(VERSION 3.30)
project(ColaDoblementeEnlazadaOrdenadaPF C)

set(CMAKE_C_STANDARD 11)

add_executable(ColaDoblementeEnlazadaOrdenadaPF main.c
        Cola.c
        Cola.h
        tElemento.c
        tElemento.h)
