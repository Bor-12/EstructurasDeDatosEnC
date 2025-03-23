//
// Created by borja on 27/02/2025.
//


#include <stdio.h>
#include <string.h>
#include "tElemento.h"

void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        strcpy(PunteroElemento->pais, valor.pais);
        strcpy(PunteroElemento->descripcion, valor.descripcion);
        PunteroElemento->nivelAlerta = valor.nivelAlerta;
    }
}
tElemento crearElemento(const char* pais, const char* descripcion, int nivelAlerta) {
    tElemento e;
    strncpy(e.pais, pais, MAX_PAIS);
    strncpy(e.descripcion, descripcion, MAX_ACCION);
    e.nivelAlerta = nivelAlerta;
    return e;
}


int esMenor(tElemento e1, tElemento e2) {
    return e1.nivelAlerta < e2.nivelAlerta;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.nivelAlerta == e2.nivelAlerta;
}

void mostrarElemento(tElemento e) {
    printf("País: %s\n", e.pais);
    printf("Descripción: %s\n", e.descripcion);
    printf("Nivel de alerta: %d\n", e.nivelAlerta);
    printf("-----------------------------\n");
}

tElemento elementoVacio() {
    tElemento e;
    strcpy(e.pais, "");
    strcpy(e.descripcion, "");
    e.nivelAlerta = -1; // valor inválido
    return e;
}
