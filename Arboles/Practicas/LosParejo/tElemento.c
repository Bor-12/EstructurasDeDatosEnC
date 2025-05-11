//
// Created by borja on 27/02/2025.
//

#include <stdio.h>
#include <string.h>
#include "tElemento.h"
tElemento crearElemento(const char* nombre) {
    tElemento e;
    strncpy(e.nombre, nombre, MAX_NOMBRE);
    e.nombre[MAX_NOMBRE - 1] = '\0';
    return e;
}
void asignarElemento(tElemento *destino, tElemento origen) {
    strcpy(destino->nombre, origen.nombre);
}

int esMenor(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) < 0;
}

int esIgual(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0;
}

void mostrarElemento(tElemento e) {
    printf("%s ", e.nombre);
}
