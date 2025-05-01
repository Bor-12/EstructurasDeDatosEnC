cmake_minimum_required(VERSION 3.30)
project(Vuelos C)

set(CMAKE_C_STANDARD 11)

add_executable(Vuelos main.c Grafo.c InfoVuelos.c Ciudad.c Pila.c)


