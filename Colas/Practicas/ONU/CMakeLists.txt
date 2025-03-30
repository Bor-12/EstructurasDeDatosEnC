cmake_minimum_required(VERSION 3.30)
project(ONU C)

set(CMAKE_C_STANDARD 11)

add_executable(ONU main.c Cola.c Cola.h tElemento.c tElemento.h)
