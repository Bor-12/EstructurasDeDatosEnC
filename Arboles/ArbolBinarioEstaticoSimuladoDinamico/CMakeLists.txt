cmake_minimum_required(VERSION 3.30)
project(ArbolBinarioEstaticoSimuladoDinamico C)

set(CMAKE_C_STANDARD 11)

add_executable(ArbolBinarioEstaticoSimuladoDinamico main.c ArbolBinario.c ArbolBinario.h tElemento.c tElemento.h)
