cmake_minimum_required(VERSION 3.30)
project(ArbolBinario C)

set(CMAKE_C_STANDARD 11)

add_executable(ArbolBinario main.c tElemento.h tElemento.c
        ArbolBinario.c
        ArbolBinario.h)
