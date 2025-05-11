cmake_minimum_required(VERSION 3.30)
project(LosParejo C)

set(CMAKE_C_STANDARD 11)

add_executable(LosParejo main.c ArbolBinario.c tElemento.c)
