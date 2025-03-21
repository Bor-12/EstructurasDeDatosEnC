cmake_minimum_required(VERSION 3.30)
project(PilaEstaticaSimulandoDinamica C)

set(CMAKE_C_STANDARD 11)

add_executable(PilaEstaticaSimulandoDinamica main.c Pila.c Pila.h tElemento.h tElemento.c)
