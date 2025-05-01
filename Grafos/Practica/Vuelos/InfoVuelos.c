//
// Created by borja on 01/05/2025.
//

#include "InfoVuelos.h"
#include <stdio.h>
#include <string.h>


void mostrarDatosVuelo(tDatosVuelo datos) {
    printf("(Compania: %s, Tiempo: %d min, Precio: %.2f euros)", datos.compania, datos.tiempo, datos.precio);
}

void asignarDatosVuelo(tDatosVuelo *destino, const char *compania, int tiempo, float precio) {
    strcpy(destino->compania, compania);
    destino->tiempo = tiempo;
    destino->precio = precio;
}

