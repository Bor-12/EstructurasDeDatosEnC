cmake_minimum_required(VERSION 3.30)
project(Polinomio C)

set(CMAKE_C_STANDARD 11)

add_executable(Polinomio main.c tElemento.c tLista.c
        tPolinomio.c
        tPolinomio.h)
