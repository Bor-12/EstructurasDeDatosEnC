cmake_minimum_required(VERSION 3.30)
project(Politos C)

set(CMAKE_C_STANDARD 11)

add_executable(Politos main.c Conjunto.c Conjunto.h tElemento.c tElemento.h)
