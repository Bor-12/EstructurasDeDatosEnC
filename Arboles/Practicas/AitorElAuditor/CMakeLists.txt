cmake_minimum_required(VERSION 3.30)
project(AitorElAuditor C)

set(CMAKE_C_STANDARD 11)

add_executable(AitorElAuditor main.c ArbolBinario.c tElemento.c tLista.c)
