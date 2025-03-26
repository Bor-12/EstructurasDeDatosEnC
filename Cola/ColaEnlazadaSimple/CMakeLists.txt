cmake_minimum_required(VERSION 3.30)
project(ColaEnlazadaSimple C)

set(CMAKE_C_STANDARD 11)

add_executable(ColaEnlazadaSimple main.c Cola.c tElemento.c)
