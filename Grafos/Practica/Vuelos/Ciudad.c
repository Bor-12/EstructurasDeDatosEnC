//
// Created by borja on 01/05/2025.
//

#include "Ciudad.h"
#include <string.h>
#include <stdio.h>


int sonIguales(tCiudad c1, tCiudad c2) {
    return strcmp(c1, c2) == 0;
}

void copiarCiudad(tCiudad destino, tCiudad origen) {
    strcpy(destino, origen);
}

void mostrarCiudad(tCiudad ciudad) {
    printf("%s", ciudad);
}

