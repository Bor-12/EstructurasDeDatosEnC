cmake_minimum_required(VERSION 3.30)
project(FakeNews C)

set(CMAKE_C_STANDARD 11)

add_executable(FakeNews main.c tElemento.c tLista.c)
