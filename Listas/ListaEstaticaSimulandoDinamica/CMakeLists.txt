cmake_minimum_required(VERSION 3.30)
project(ListaEstaticaSimulandoDinamica C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaEstaticaSimulandoDinamica main.c tElemento.c tLista.c)
