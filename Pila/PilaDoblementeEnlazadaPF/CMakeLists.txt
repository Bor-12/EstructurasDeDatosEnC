cmake_minimum_required(VERSION 3.30)
project(PilaDoblementeEnlazadaPF C)

set(CMAKE_C_STANDARD 11)

add_executable(PilaDoblementeEnlazadaPF main.c tElemento.c tElemento.h
        Pila.c
        Pila.h)
