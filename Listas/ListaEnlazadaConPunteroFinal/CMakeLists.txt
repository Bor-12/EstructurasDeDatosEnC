cmake_minimum_required(VERSION 3.30)
project(ListaEnlazadaConPunteroFinal C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaEnlazadaConPunteroFinal main.c
        tLista.c
        tLista.h
        tElemento.c
        tElemento.h
)
