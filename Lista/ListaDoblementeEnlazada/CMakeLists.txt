cmake_minimum_required(VERSION 3.30)
project(ListaDoblementeEnlazada C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaDoblementeEnlazada main.c tElemento.c tElemento.h tLista.c tLista.h)
