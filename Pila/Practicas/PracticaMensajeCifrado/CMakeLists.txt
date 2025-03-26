cmake_minimum_required(VERSION 3.30)
project(PracticaMensajeCifrado C)

set(CMAKE_C_STANDARD 11)

add_executable(PracticaMensajeCifrado main.c tElemento.c tElemento.h Pila.c tLista.c tLista.h)
