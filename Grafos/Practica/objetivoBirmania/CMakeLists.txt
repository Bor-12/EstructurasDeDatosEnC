cmake_minimum_required(VERSION 3.30)
project(objetivoBirmania C)

set(CMAKE_C_STANDARD 11)

add_executable(objetivoBirmania main.c
        Persona.c
        Persona.h
        grafo.c
        grafo.h)
