cmake_minimum_required(VERSION 3.30)
project(ListaEstatica C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaEstatica main.c
        tLista.c
        tLista.h tElemento.c)
