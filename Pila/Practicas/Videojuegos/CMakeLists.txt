cmake_minimum_required(VERSION 3.30)
project(Videojuegos C)

set(CMAKE_C_STANDARD 11)

add_executable(Videojuegos main.c Pila.c tElemento.c)
