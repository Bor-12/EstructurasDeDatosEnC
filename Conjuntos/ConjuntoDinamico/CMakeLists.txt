cmake_minimum_required(VERSION 3.30)
project(ConjuntoDinamico C)

set(CMAKE_C_STANDARD 11)

add_executable(ConjuntoDinamico main.c tElemento.c tElemento.h Conjunto.c Conjunto.h)
