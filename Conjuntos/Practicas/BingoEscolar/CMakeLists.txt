cmake_minimum_required(VERSION 3.30)
project(BingoEscolar C)

set(CMAKE_C_STANDARD 11)

add_executable(BingoEscolar main.c tElemento.h tElemento.c tLista.h tLista.c Conjunto.h Conjunto.c)
