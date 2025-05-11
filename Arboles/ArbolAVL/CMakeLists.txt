cmake_minimum_required(VERSION 3.30)
project(ArbolBinarioOdenado C)

set(CMAKE_C_STANDARD 11)

add_executable(ArbolBinarioOdenado main.c tElemento.c tElemento.h ArbolBinario.c ArbolBinario.h)
