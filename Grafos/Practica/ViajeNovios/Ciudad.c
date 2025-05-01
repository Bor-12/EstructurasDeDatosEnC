//
// Created by borja on 01/05/2025.
//

#include "Ciudad.h"
#include <string.h>
#include <stdio.h>

void crearCiudad(tCiudad ciudad, const char *nombre) {
    strncpy(ciudad, nombre, 50);
    ciudad[49] = '\0';
}
int sonIguales(tCiudad c1, tCiudad c2) {
    return strcmp(c1, c2) == 0;
}

void copiarCiudad(tCiudad destino, tCiudad origen) {
    strcpy(destino, origen);
}

void mostrarCiudad(tCiudad ciudad) {
    printf("%s", ciudad);
}

